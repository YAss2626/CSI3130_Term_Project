/*-------------------------------------------------------------------------
 *
 * nodeHashjoin.c
 *	  Routines to handle hash join nodes
 *
 * Portions Copyright (c) 1996-2005, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  $PostgreSQL: pgsql/src/backend/executor/nodeHashjoin.c,v 1.75.2.3 2005/11/28 23:46:24 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"
#include "executor/executor.h"
#include "executor/hashjoin.h"
#include "executor/nodeHash.h"
#include "executor/nodeHashjoin.h"
#include "optimizer/clauses.h"
#include "utils/memutils.h"
//#define HASHJOIN_NSLOTS 10  /* CSI3130: bumped for symmetric hash join */


static TupleTableSlot *ExecHashJoinOuterGetTuple(PlanState *outerNode,
						  HashJoinState *hjstate,
						  uint32 *hashvalue);
static TupleTableSlot *ExecHashJoinGetSavedTuple(HashJoinState *hjstate,
						  BufFile *file,
						  uint32 *hashvalue,
						  TupleTableSlot *tupleSlot);
static int	ExecHashJoinNewBatch(HashJoinState *hjstate);


/* ----------------------------------------------------------------
 *		ExecHashJoin
 *
 *		CSI3130: This function is completly editted to implement the new symmetric hash join algorithm.
 *
 * ----------------------------------------------------------------
 */

TupleTableSlot *
ExecHashJoin(HashJoinState *node){
    HashState      *inner_hashNode;   /* CSI3130: inner hash node */
    HashState      *outer_hashNode;   /* CSI3130: outer hash node */
    List           *joinqual;
    List           *otherqual;
    TupleTableSlot *inntuple;
    TupleTableSlot *outtuple;         /* CSI3130: tuple from hash table */
    ExprContext    *econtext;
    ExprDoneCond    isDone;
    HashJoinTable   inner_hashtable;  /* CSI3130: inner hash table */
    HashJoinTable   outer_hashtable;  /* CSI3130: outer hash table */
    HeapTuple       curtuple;
    TupleTableSlot *outerTupleSlot;
    TupleTableSlot *innerTupleSlot;   /* CSI3130: tuple from plan */
    uint32          hashvalue;
    int             batchno;

    elog(WARNING, "SYMMETRIC HASH JOIN");  /* CSI3130: debug marker */
	elog(WARNING, "SHJ: entered ExecHashJoin"); /* CSI3130: debug marker */


    /* CSI3130: get info from HashJoin state */
    joinqual   = node->js.joinqual;
    otherqual  = node->js.ps.qual;
    inner_hashNode = (HashState *) innerPlanState(node);
    outer_hashNode = (HashState *) outerPlanState(node);

    inner_hashtable = node->inner_hj_HashTable;
    outer_hashtable = node->outer_hj_HashTable;
    econtext = node->js.ps.ps_ExprContext;

	/* CSI3130: Diagnostic: log hashtable pointer values to help locate crashes */
	if (inner_hashtable == NULL)
		elog(LOG, "CSI3130: ExecHashJoin: inner_hashtable = NULL");
	else
		elog(LOG, "CSI3130: ExecHashJoin: inner_hashtable=%p nbuckets=%d",
			 (void *) inner_hashtable, inner_hashtable->nbuckets);

	if (outer_hashtable == NULL)
		elog(LOG, "CSI3130: ExecHashJoin: outer_hashtable = NULL");
	else
		elog(LOG, "CSI3130: ExecHashJoin: outer_hashtable=%p nbuckets=%d",
			 (void *) outer_hashtable, outer_hashtable->nbuckets);

    /* IN join: one result per outer tuple */
    if (node->js.jointype == JOIN_IN && node->hj_MatchedOuter)
        node->hj_NeedNewOuter = true;

    /* reset per-tuple memory */
    ResetExprContext(econtext);

	//CSI3130: edits to build hash tables if not already built
	if (node->inner_hj_HashTable == NULL)
{
    MemoryContext oldcxt;
    
    oldcxt = MemoryContextSwitchTo(node->js.ps.state->es_query_cxt);
    
    inner_hashtable = ExecHashTableCreate((Hash *) inner_hashNode->ps.plan,
                                        node->hj_HashOperators);
    if (inner_hashtable == NULL)
        elog(ERROR, "could not initialize inner hash table");
        
    node->inner_hj_HashTable = inner_hashtable;
    
    /* CSI3130: Initialize hash table properly */
    inner_hashtable->curbatch = 0;
    inner_hashtable->nbatch = 1;
    
    MemoryContextSwitchTo(oldcxt);
}

/* CSI3130: Removed duplicate outer-hashtable creation earlier; keep a
 * single initialization site below. This comment documents that the
 * outer hash table is created once and initialized for symmetric hash
 * join usage.
 */
if (node->outer_hj_HashTable == NULL)
{
	MemoryContext oldcxt;
    
	oldcxt = MemoryContextSwitchTo(node->js.ps.state->es_query_cxt);
    
	outer_hashtable = ExecHashTableCreate((Hash *) outer_hashNode->ps.plan,
										node->hj_HashOperators);
	if (outer_hashtable == NULL)
		elog(ERROR, "could not initialize outer hash table");
        
	node->outer_hj_HashTable = outer_hashtable;
    
	/* CSI3130: Initialize hash table properly */
	outer_hashtable->curbatch = 0;
	outer_hashtable->nbatch = 1;
    
	MemoryContextSwitchTo(oldcxt);
}

    /* CSI3130: hook new tables to Hash child nodes for pipelined ExecHash */
    inner_hashNode->hashtable = inner_hashtable;
    outer_hashNode->hashtable = outer_hashtable;

    /*
     * CSI3130: symmetric hash join main loop
     */
    for (;;)
    {
        /*
         * CSI3130: Get new tuples independently for each side when needed
         * This fixes the logic where both sides had to be ready simultaneously
         */
        if (node->hj_NeedNewInner && !node->inner_exhausted)
        {
            innerTupleSlot = ExecProcNode((PlanState *) inner_hashNode);
            node->isNextFetchInner = false;    /* next: probe OUTER hash */
            node->js.ps.ps_InnerTupleSlot = innerTupleSlot;

            if (!TupIsNull(innerTupleSlot))
            {
                ExprContext *iecontext = node->js.ps.ps_ExprContext;

                node->hj_NeedNewInner = false;
                node->hj_InnerNotEmpty = true;

                /* hash value of INNER tuple for probing OUTER table */
                iecontext->ecxt_innertuple = innerTupleSlot;
                iecontext->ecxt_outertuple = innerTupleSlot;
                hashvalue = ExecHashGetHashValue(outer_hashtable,
                                                 iecontext,
                                                 node->hj_InnerHashKeys);

                node->inner_hj_CurHashValue = hashvalue;
                ExecHashGetBucketAndBatch(outer_hashtable, hashvalue,
                                          &node->outer_hj_CurBucketNo,
                                          &batchno);
                node->outer_hj_CurTuple = NULL; /* start new bucket scan */
            }
            else
            {
                node->inner_exhausted = true;
                node->hj_NeedNewInner = true;  /* CSI3130: Ensure flag is set on exhaustion */
            }
        }

        if (node->hj_NeedNewOuter && !node->outer_exhausted)
        {
            outerTupleSlot = ExecProcNode((PlanState *) outer_hashNode);
            node->isNextFetchInner = true;  /* next: probe INNER hash */
            node->js.ps.ps_OuterTupleSlot = outerTupleSlot;

            if (!TupIsNull(outerTupleSlot))
            {
                ExprContext *oecontext = node->js.ps.ps_ExprContext;

                node->hj_OuterNotEmpty = true;
                oecontext->ecxt_outertuple = outerTupleSlot;
                oecontext->ecxt_innertuple = outerTupleSlot;

                /* hash value of OUTER tuple for probing INNER table */
                hashvalue = ExecHashGetHashValue(inner_hashtable,
                                                 oecontext,
                                                 node->hj_OuterHashKeys);

                node->hj_NeedNewOuter = false;
                node->hj_MatchedOuter = false;  /* assume no match yet */

                node->outer_hj_CurHashValue = hashvalue;
                ExecHashGetBucketAndBatch(inner_hashtable, hashvalue,
                                          &node->inner_hj_CurBucketNo,
                                          &batchno);
                node->inner_hj_CurTuple = NULL;  /* start new bucket */

                Assert(batchno == inner_hashtable->curbatch);
            }
            else
            {
                node->outer_exhausted = true;
                node->hj_NeedNewOuter = true;  /* CSI3130: Ensure flag is set on exhaustion */
            }
        }

        /* CSI3130: Improved termination condition with additional checks */
        if (node->inner_exhausted && node->outer_exhausted && 
            node->hj_NeedNewInner && node->hj_NeedNewOuter)
        {
            if (inner_hashtable && outer_hashtable) {
                printf("both inner (%f tuples) and outer (%f tuples) exhausted\n",
                       inner_hashtable->totalTuples,
                       outer_hashtable->totalTuples);
                printf("Got %d matches by probing inner hash table\n",
                       node->matches_by_probing_inner);
                printf("Got %d matches by probing outer hash table\n",
                       node->matches_by_probing_outer);
            }
            return NULL;
        }

        /*
         * STEP 1: Probe OUTER hash table using current INNER tuple
         *
         * CSI3130: Guard against NULL ps_InnerTupleSlot. ExecProcNode returns
         * a valid TupleTableSlot*, but we explicitly set this pointer to NULL
         * when the current INNER tuple is finished. Calling TupIsNull() on
         * a NULL pointer causes SIGSEGV, so check pointer first.
         */
        if (node->js.ps.ps_InnerTupleSlot != NULL &&
            !TupIsNull(node->js.ps.ps_InnerTupleSlot))

        {
            for (;;)
            {
                ExprContext *pecontext = node->js.ps.ps_ExprContext;

                node->isNextFetchInner = false; /* probing OUTER hash */
                pecontext->ecxt_innertuple = node->js.ps.ps_InnerTupleSlot;

                curtuple = ExecScanHashBucket(node, pecontext);
                if (curtuple == NULL)
                    break;

                /* put OUTER-side hash-tuple in its slot */
                outtuple = ExecStoreTuple(curtuple,
                                          node->outer_hj_HashTupleSlot,
                                          InvalidBuffer,
                                          false);
                pecontext->ecxt_outertuple = outtuple;

                ResetExprContext(pecontext);

                if (joinqual == NIL || ExecQual(joinqual, pecontext, false))
                {
                    if (otherqual == NIL ||
                        ExecQual(otherqual, pecontext, false))
                    {
                        TupleTableSlot *result;

                        result = ExecProject(node->js.ps.ps_ProjInfo, &isDone);
                        if (isDone != ExprEndResult)
                        {
                            node->matches_by_probing_outer++;
                            node->js.ps.ps_TupFromTlist =
                                (isDone == ExprMultipleResult);
                            return result;
                        }
                    }
                }
            }
        }

        /* no more matches for this INNER tuple */
        node->hj_NeedNewInner = true;
        node->js.ps.ps_InnerTupleSlot = NULL;

        /*
         * STEP 2: Probe INNER hash table using current OUTER tuple
         *
         * CSI3130: Same protection as above: ps_OuterTupleSlot is set to NULL
         * when we are done with the current OUTER tuple. We must not call
         * TupIsNull() on a NULL pointer.
         */
        if (node->js.ps.ps_OuterTupleSlot != NULL &&
            !TupIsNull(node->js.ps.ps_OuterTupleSlot))

        {
            for (;;)
            {
                ExprContext *pecontext = node->js.ps.ps_ExprContext;

                node->isNextFetchInner = true;  /* probing INNER hash */
                pecontext->ecxt_outertuple = node->js.ps.ps_OuterTupleSlot;

                curtuple = ExecScanHashBucket(node, pecontext);
                if (curtuple == NULL)
                    break;

                /* put INNER-side hash-tuple in its slot */
                inntuple = ExecStoreTuple(curtuple,
                                          node->inner_hj_HashTupleSlot,
                                          InvalidBuffer,
                                          false);
                pecontext->ecxt_innertuple = inntuple;

                ResetExprContext(pecontext);

                if (joinqual == NIL || ExecQual(joinqual, pecontext, false))
                {
                    node->hj_MatchedOuter = true;

                    if (otherqual == NIL ||
                        ExecQual(otherqual, pecontext, false))
                    {
                        TupleTableSlot *result;

                        result = ExecProject(node->js.ps.ps_ProjInfo, &isDone);
                        if (isDone != ExprEndResult)
                        {
                            node->matches_by_probing_inner++;
                            node->js.ps.ps_TupFromTlist =
                                (isDone == ExprMultipleResult);
                            return result;
                        }
                    }

                    if (node->js.jointype == JOIN_IN)
                    {
                        node->hj_NeedNewOuter = true;
                        break;  /* stop scanning this bucket */
                    }
                }
            }
        }

        /* done with this OUTER tuple */
        node->hj_NeedNewOuter = true;
        node->js.ps.ps_OuterTupleSlot = NULL;

        if (!node->hj_MatchedOuter &&
            node->js.jointype == JOIN_LEFT)
        {
            /* LEFT JOIN: emit NULL-extended row */
            econtext->ecxt_innertuple = node->hj_NullInnerTupleSlot;

            if (ExecQual(otherqual, econtext, false))
            {
                TupleTableSlot *result;

                result = ExecProject(node->js.ps.ps_ProjInfo, &isDone);
                if (isDone != ExprEndResult)
                {
                    node->js.ps.ps_TupFromTlist =
                        (isDone == ExprMultipleResult);
                    return result;
                }
            }
        }
    }
}


/* ----------------------------------------------------------------
 *		ExecInitHashJoin
 *
 *		Init routine for HashJoin node.
 * ----------------------------------------------------------------
 */
HashJoinState *
ExecInitHashJoin(HashJoin *node, EState *estate)
{
	HashJoinState *hjstate;
	Plan	   *outerNode;
	Hash	   *hashNode;
	List	   *lclauses;
	List	   *rclauses;
	List	   *hoperators;
	ListCell   *l;

	elog(LOG, "CSI3130: Entering ExecInitHashJoin");

	/*
	 * create state structure
	 */
	hjstate = makeNode(HashJoinState);
	hjstate->js.ps.plan = (Plan *) node;
	hjstate->js.ps.state = estate;

	/*
	 * Miscellaneous initialization
	 *
	 * create expression context for node
	 */
	ExecAssignExprContext(estate, &hjstate->js.ps);

	/*
	 * initialize child expressions
	 */
	hjstate->js.ps.targetlist = (List *)
		ExecInitExpr((Expr *) node->join.plan.targetlist,
					 (PlanState *) hjstate);
	hjstate->js.ps.qual = (List *)
		ExecInitExpr((Expr *) node->join.plan.qual,
					 (PlanState *) hjstate);
	hjstate->js.jointype = node->join.jointype;
	hjstate->js.joinqual = (List *)
		ExecInitExpr((Expr *) node->join.joinqual,
					 (PlanState *) hjstate);
	hjstate->hashclauses = (List *)
		ExecInitExpr((Expr *) node->hashclauses,
					 (PlanState *) hjstate);

	/*
	 * initialize child nodes
	 */
	outerNode = outerPlan(node);
	hashNode = (Hash *) innerPlan(node);

	outerPlanState(hjstate) = ExecInitNode(outerNode, estate);
	innerPlanState(hjstate) = ExecInitNode((Plan *) hashNode, estate);


		/* CSI3130: initialize result and extra tuple slots */
		ExecInitResultTupleSlot(estate, &hjstate->js.ps);
		hjstate->hj_OuterTupleSlot = ExecInitExtraTupleSlot(estate);
		hjstate->hj_InnerTupleSlot = ExecInitExtraTupleSlot(estate);

		/* CSI3130: start by probing outer hash table first (we’ll flip this flag) */
		hjstate->isNextFetchInner = false;

		switch (node->join.jointype)
		{
			case JOIN_INNER:
			case JOIN_IN:
				break;
			case JOIN_LEFT:
				hjstate->hj_NullInnerTupleSlot =
					ExecInitNullTupleSlot(estate,
									ExecGetResultType(innerPlanState(hjstate)));
				break;
			default:
				elog(ERROR, "unrecognized join type: %d",
					(int) node->join.jointype);
	}

    /* --------------------------------------------------------------------
     * CSI3130: no reusing the HashState result slots for hash-table tuples.
     * In symmetric hash join, Hash nodes produce pipelined output via
     * ExecProcNode(), so their ps_ResultTupleSlots hold live child tuples.
     *
     * If we reused those slots for hash-table matches, ExecScanHashBucket()
     * would overwrite them with pointers to tuples stored in the hash-table
     * memory context. Later, when the child HashState produces another tuple
     * or when the batchCxt resets, we would dereference freed memory SIGSEGV.
     * --------------------------------------------------------------------
     */
    hjstate->inner_hj_HashTupleSlot =
        ExecInitExtraTupleSlot(estate);

    ExecSetSlotDescriptor(hjstate->inner_hj_HashTupleSlot,
                          ExecGetResultType(innerPlanState(hjstate)),
                          false);

    hjstate->outer_hj_HashTupleSlot =
        ExecInitExtraTupleSlot(estate);

    ExecSetSlotDescriptor(hjstate->outer_hj_HashTupleSlot,
                          ExecGetResultType(outerPlanState(hjstate)),
                          false);



	/*
	 * initialize tuple type and projection info
	 */
	ExecAssignResultTypeFromTL(&hjstate->js.ps);
	ExecAssignProjectionInfo(&hjstate->js.ps);

	ExecSetSlotDescriptor(hjstate->hj_OuterTupleSlot,
						  ExecGetResultType(outerPlanState(hjstate)),
						  false);

	/*
	* CSI3130: initialize symmetric hash join state
	*/
	hjstate->inner_hj_HashTable = NULL;
	hjstate->outer_hj_HashTable = NULL;

	hjstate->hj_FirstOuterTupleSlot = NULL;
	hjstate->hj_FirstInnerTupleSlot = NULL;   

	hjstate->inner_hj_CurHashValue = 0;
	hjstate->outer_hj_CurHashValue = 0;
	hjstate->inner_hj_CurBucketNo = 0;
	hjstate->outer_hj_CurBucketNo = 0;
	hjstate->inner_hj_CurTuple = NULL;
	hjstate->outer_hj_CurTuple = NULL;

	hjstate->inner_exhausted = false;
	hjstate->outer_exhausted = false;

	hjstate->js.ps.ps_OuterTupleSlot = NULL;
	hjstate->js.ps.ps_InnerTupleSlot = NULL;
	hjstate->js.ps.ps_TupFromTlist = false;

	hjstate->hj_NeedNewOuter = true;
	hjstate->hj_NeedNewInner = true;
	hjstate->hj_MatchedOuter = false;
	hjstate->hj_OuterNotEmpty = false;


	hjstate->matches_by_probing_inner = 0;
	hjstate->matches_by_probing_outer = 0;


	/*
	 * Deconstruct the hash clauses into outer and inner argument values, so
	 * that we can evaluate those subexpressions separately.  Also make a list
	 * of the hash operator OIDs, in preparation for looking up the hash
	 * functions to use.
	 */
	lclauses = NIL;
	rclauses = NIL;
	hoperators = NIL;
	foreach (l, hjstate->hashclauses)
	{
		FuncExprState *fstate = (FuncExprState *) lfirst(l);
		OpExpr        *hclause;

		Assert(IsA(fstate, FuncExprState));
		hclause = (OpExpr *) fstate->xprstate.expr;
		Assert(IsA(hclause, OpExpr));
		lclauses = lappend(lclauses, linitial(fstate->args));
		rclauses = lappend(rclauses, lsecond(fstate->args)); // YD modif 
		hoperators = lappend_oid(hoperators, hclause->opno);
	}

	/* CSI3130: store outer/inner hash key exprs and operators */
	hjstate->hj_OuterHashKeys = lclauses;
	hjstate->hj_InnerHashKeys = rclauses;
	hjstate->hj_HashOperators = hoperators;

	/* CSI3130: both Hash children need their hashkeys set */
	((HashState *) innerPlanState(hjstate))->hashkeys = rclauses;
	((HashState *) outerPlanState(hjstate))->hashkeys = lclauses;

	hjstate->js.ps.ps_OuterTupleSlot = NULL;
	hjstate->js.ps.ps_TupFromTlist = false;
	hjstate->hj_NeedNewOuter = true;
	hjstate->hj_MatchedOuter = false;
	hjstate->hj_OuterNotEmpty = false;
	hjstate->hj_InnerNotEmpty = false;   /* CSI3130: track non-empty inner */

	return hjstate;
}


int
ExecCountSlotsHashJoin(HashJoin *node)
{
    /* CSI3130: For symmetric hash join, HashJoinState uses:
     *  - 1 result tuple slot
     *  - 2 extra tuple slots (hj_OuterTupleSlot, hj_InnerTupleSlot)
     *  - up to 1 null-inner slot (LEFT joins)
     *  - 2 extra tuple slots for hash-table output
     * That’s at most 6 local slots. We reserve a few extra for safety.
     */
    return ExecCountSlotsNode(outerPlan(node)) +
           ExecCountSlotsNode(innerPlan(node)) +
           8;    /* CSI3130: HASHJOIN_NSLOTS for symmetric hash join */
}


/* ----------------------------------------------------------------
 *		ExecEndHashJoin
 *
 *		clean up routine for HashJoin node
 * ----------------------------------------------------------------
 */
void
ExecEndHashJoin(HashJoinState *node)
{
	/* CSI3130: Free both hash tables */
	if (node->inner_hj_HashTable)
	{
		ExecHashTableDestroy(node->inner_hj_HashTable);
		node->inner_hj_HashTable = NULL;
	}
	if (node->outer_hj_HashTable)
	{
		ExecHashTableDestroy(node->outer_hj_HashTable);
		node->outer_hj_HashTable = NULL;
	}


	/*
	 * Free the exprcontext
	 */
	ExecFreeExprContext(&node->js.ps);

	/*
	 * CSI3130: clean out the tuple table
	 */
	ExecClearTuple(node->js.ps.ps_ResultTupleSlot);
	ExecClearTuple(node->hj_OuterTupleSlot);
	ExecClearTuple(node->hj_InnerTupleSlot);
	ExecClearTuple(node->inner_hj_HashTupleSlot);
	ExecClearTuple(node->outer_hj_HashTupleSlot);


	/*
	 * clean up subtrees
	 */
	ExecEndNode(outerPlanState(node));
	ExecEndNode(innerPlanState(node));
}

/*
 * ExecHashJoinOuterGetTuple
 *
 *		get the next outer tuple for hashjoin: either by
 *		executing a plan node in the first pass, or from
 *		the temp files for the hashjoin batches.
 *
 * Returns a null slot if no more outer tuples.  On success, the tuple's
 * hash value is stored at *hashvalue --- this is either originally computed,
 * or re-read from the temp file.
 */
static TupleTableSlot *
ExecHashJoinOuterGetTuple(PlanState *outerNode,
						  HashJoinState *hjstate,
						  uint32 *hashvalue)
{
	HashJoinTable hashtable = hjstate->inner_hj_HashTable;   /* CSI3130 */
	int			curbatch = hashtable->curbatch;
	TupleTableSlot *slot;

	if (curbatch == 0)
	{							/* if it is the first pass */

		/*
		 * Check to see if first outer tuple was already fetched by
		 * ExecHashJoin() and not used yet.
		 */
		slot = hjstate->hj_FirstOuterTupleSlot;
		if (!TupIsNull(slot))
			hjstate->hj_FirstOuterTupleSlot = NULL;
		else
			slot = ExecProcNode(outerNode);
		if (!TupIsNull(slot))
		{
			/*
			 * We have to compute the tuple's hash value.
			 */
			ExprContext *econtext = hjstate->js.ps.ps_ExprContext;

			econtext->ecxt_outertuple = slot;
			*hashvalue = ExecHashGetHashValue(hashtable, econtext,
											  hjstate->hj_OuterHashKeys);

			/* remember outer relation is not empty for possible rescan */
			hjstate->hj_OuterNotEmpty = true;

			return slot;
		}

		/*
		 * We have just reached the end of the first pass. Try to switch to a
		 * saved batch.
		 */
		curbatch = ExecHashJoinNewBatch(hjstate);
	}

	/*
	 * Try to read from a temp file. Loop allows us to advance to new batches
	 * as needed.  NOTE: nbatch could increase inside ExecHashJoinNewBatch, so
	 * don't try to optimize this loop.
	 */
	while (curbatch < hashtable->nbatch)
	{
		slot = ExecHashJoinGetSavedTuple(hjstate,
										 hashtable->outerBatchFile[curbatch],
										 hashvalue,
										 hjstate->hj_OuterTupleSlot);
		if (!TupIsNull(slot))
			return slot;
		curbatch = ExecHashJoinNewBatch(hjstate);
	}

	/* Out of batches... */
	return NULL;
}

/*
 * ExecHashJoinNewBatch
 *		switch to a new hashjoin batch
 *
 * Returns the number of the new batch (1..nbatch-1), or nbatch if no more.
 * We will never return a batch number that has an empty outer batch file.
 */
static int
ExecHashJoinNewBatch(HashJoinState *hjstate)
{
	HashJoinTable hashtable = hjstate->inner_hj_HashTable;   /* CSI3130 */
	int			nbatch;
	int			curbatch;
	BufFile    *innerFile;
	TupleTableSlot *slot;
	uint32		hashvalue;

start_over:
	nbatch = hashtable->nbatch;
	curbatch = hashtable->curbatch;

	if (curbatch > 0)
	{
		/*
		 * We no longer need the previous outer batch file; close it right
		 * away to free disk space.
		 */
		if (hashtable->outerBatchFile[curbatch])
			BufFileClose(hashtable->outerBatchFile[curbatch]);
		hashtable->outerBatchFile[curbatch] = NULL;
	}

	/*
	 * We can always skip over any batches that are completely empty on both
	 * sides.  We can sometimes skip over batches that are empty on only one
	 * side, but there are exceptions:
	 *
	 * 1. In a LEFT JOIN, we have to process outer batches even if the inner
	 * batch is empty.
	 *
	 * 2. If we have increased nbatch since the initial estimate, we have to
	 * scan inner batches since they might contain tuples that need to be
	 * reassigned to later inner batches.
	 *
	 * 3. Similarly, if we have increased nbatch since starting the outer
	 * scan, we have to rescan outer batches in case they contain tuples that
	 * need to be reassigned.
	 */
	curbatch++;
	while (curbatch < nbatch &&
		   (hashtable->outerBatchFile[curbatch] == NULL ||
			hashtable->innerBatchFile[curbatch] == NULL))
	{
		if (hashtable->outerBatchFile[curbatch] &&
			hjstate->js.jointype == JOIN_LEFT)
			break;				/* must process due to rule 1 */
		if (hashtable->innerBatchFile[curbatch] &&
			nbatch != hashtable->nbatch_original)
			break;				/* must process due to rule 2 */
		if (hashtable->outerBatchFile[curbatch] &&
			nbatch != hashtable->nbatch_outstart)
			break;				/* must process due to rule 3 */
		/* We can ignore this batch. */
		/* Release associated temp files right away. */
		if (hashtable->innerBatchFile[curbatch])
			BufFileClose(hashtable->innerBatchFile[curbatch]);
		hashtable->innerBatchFile[curbatch] = NULL;
		if (hashtable->outerBatchFile[curbatch])
			BufFileClose(hashtable->outerBatchFile[curbatch]);
		hashtable->outerBatchFile[curbatch] = NULL;
		curbatch++;
	}

	if (curbatch >= nbatch)
		return curbatch;		/* no more batches */

	hashtable->curbatch = curbatch;

	/*
	 * Reload the hash table with the new inner batch (which could be empty)
	 */
	ExecHashTableReset(hashtable);

	innerFile = hashtable->innerBatchFile[curbatch];

	if (innerFile != NULL)
	{
		if (BufFileSeek(innerFile, 0, 0L, SEEK_SET))
			ereport(ERROR,
					(errcode_for_file_access(),
				   errmsg("could not rewind hash-join temporary file: %m")));

		while ((slot = ExecHashJoinGetSavedTuple(hjstate,
                                         innerFile,
                                         &hashvalue,
                                         hjstate->inner_hj_HashTupleSlot))) //CSI3130: change to while statement

		{
			/*
			 * NOTE: some tuples may be sent to future batches.  Also, it is
			 * possible for hashtable->nbatch to be increased here!
			 */
			ExecHashTableInsert(hashtable,
								ExecFetchSlotTuple(slot),
								hashvalue);
		}

		/*
		 * after we build the hash table, the inner batch file is no longer
		 * needed
		 */
		BufFileClose(innerFile);
		hashtable->innerBatchFile[curbatch] = NULL;
	}

	/*
	 * If there's no outer batch file, advance to next batch.
	 */
	if (hashtable->outerBatchFile[curbatch] == NULL)
		goto start_over;

	/*
	 * Rewind outer batch file, so that we can start reading it.
	 */
	if (BufFileSeek(hashtable->outerBatchFile[curbatch], 0, 0L, SEEK_SET))
		ereport(ERROR,
				(errcode_for_file_access(),
				 errmsg("could not rewind hash-join temporary file: %m")));

	return curbatch;
}

/*
 * ExecHashJoinSaveTuple
 *		save a tuple to a batch file.
 *
 * The data recorded in the file for each tuple is its hash value,
 * then an image of its HeapTupleData (with meaningless t_data pointer)
 * followed by the HeapTupleHeader and tuple data.
 *
 * Note: it is important always to call this in the regular executor
 * context, not in a shorter-lived context; else the temp file buffers
 * will get messed up.
 */
void
ExecHashJoinSaveTuple(HeapTuple heapTuple, uint32 hashvalue,
					  BufFile **fileptr)
{
	BufFile    *file = *fileptr;
	size_t		written;

	if (file == NULL)
	{
		/* First write to this batch file, so open it. */
		file = BufFileCreateTemp(false);
		*fileptr = file;
	}

	written = BufFileWrite(file, (void *) &hashvalue, sizeof(uint32));
	if (written != sizeof(uint32))
		ereport(ERROR,
				(errcode_for_file_access(),
				 errmsg("could not write to hash-join temporary file: %m")));

	written = BufFileWrite(file, (void *) heapTuple, sizeof(HeapTupleData));
	if (written != sizeof(HeapTupleData))
		ereport(ERROR,
				(errcode_for_file_access(),
				 errmsg("could not write to hash-join temporary file: %m")));

	written = BufFileWrite(file, (void *) heapTuple->t_data, heapTuple->t_len);
	if (written != (size_t) heapTuple->t_len)
		ereport(ERROR,
				(errcode_for_file_access(),
				 errmsg("could not write to hash-join temporary file: %m")));
}

/*
 * ExecHashJoinGetSavedTuple
 *		read the next tuple from a batch file.	Return NULL if no more.
 *
 * On success, *hashvalue is set to the tuple's hash value, and the tuple
 * itself is stored in the given slot.
 */
static TupleTableSlot *
ExecHashJoinGetSavedTuple(HashJoinState *hjstate,
						  BufFile *file,
						  uint32 *hashvalue,
						  TupleTableSlot *tupleSlot)
{
	HeapTupleData htup;
	size_t		nread;
	HeapTuple	heapTuple;

	nread = BufFileRead(file, (void *) hashvalue, sizeof(uint32));
	if (nread == 0)
		return NULL;			/* end of file */
	if (nread != sizeof(uint32))
		ereport(ERROR,
				(errcode_for_file_access(),
				 errmsg("could not read from hash-join temporary file: %m")));
	nread = BufFileRead(file, (void *) &htup, sizeof(HeapTupleData));
	if (nread != sizeof(HeapTupleData))
		ereport(ERROR,
				(errcode_for_file_access(),
				 errmsg("could not read from hash-join temporary file: %m")));
	heapTuple = palloc(HEAPTUPLESIZE + htup.t_len);
	memcpy((char *) heapTuple, (char *) &htup, sizeof(HeapTupleData));
	heapTuple->t_datamcxt = CurrentMemoryContext;
	heapTuple->t_data = (HeapTupleHeader)
		((char *) heapTuple + HEAPTUPLESIZE);
	nread = BufFileRead(file, (void *) heapTuple->t_data, htup.t_len);
	if (nread != (size_t) htup.t_len)
		ereport(ERROR,
				(errcode_for_file_access(),
				 errmsg("could not read from hash-join temporary file: %m")));
	return ExecStoreTuple(heapTuple, tupleSlot, InvalidBuffer, true);
}

/* CSI3130: new ExecReScanHashJoin function*/
/* Rescan for symmetric hash join */
/* CSI3130: Rescan for symmetric hash join */
void
ExecReScanHashJoin(HashJoinState *node, ExprContext *exprCtxt)
{
    printf("rescan called\n");

    /* Always destroy BOTH hash tables so they will be rebuilt on next call */
    if (node->inner_hj_HashTable != NULL)
    {
        ExecHashTableDestroy(node->inner_hj_HashTable);
        node->inner_hj_HashTable = NULL;
    }

    if (node->outer_hj_HashTable != NULL)
    {
        ExecHashTableDestroy(node->outer_hj_HashTable);
        node->outer_hj_HashTable = NULL;
    }

    /* Reset symmetric hash join state */
    node->inner_exhausted = false;
    node->outer_exhausted = false;

    node->inner_hj_CurHashValue = 0;
    node->outer_hj_CurHashValue = 0;
    node->inner_hj_CurBucketNo = 0;
    node->outer_hj_CurBucketNo = 0;
    node->inner_hj_CurTuple = NULL;
    node->outer_hj_CurTuple = NULL;

    node->js.ps.ps_OuterTupleSlot = NULL;
    node->js.ps.ps_InnerTupleSlot = NULL;
    node->js.ps.ps_TupFromTlist = false;

    node->hj_NeedNewOuter = true;
    node->hj_NeedNewInner = true;
    node->hj_MatchedOuter = false;
    node->hj_FirstOuterTupleSlot = NULL;
    node->hj_OuterNotEmpty = false;
    node->hj_InnerNotEmpty = false;

    /* Rescan both children if needed */
    if (((PlanState *) node)->lefttree->chgParam == NULL)
        ExecReScan(((PlanState *) node)->lefttree, exprCtxt);

    if (((PlanState *) node)->righttree->chgParam == NULL)
        ExecReScan(((PlanState *) node)->righttree, exprCtxt);
}


/* CSI3130: Helper function to process inner tuple */
static void
ProcessInnerTuple(HashJoinState *node, TupleTableSlot *innerTupleSlot)
{
    ExprContext *econtext = node->js.ps.ps_ExprContext;
    uint32 hashvalue;
    int batchno;

    node->hj_NeedNewInner = false;
    node->js.ps.ps_InnerTupleSlot = innerTupleSlot;

    econtext->ecxt_innertuple = innerTupleSlot;
    econtext->ecxt_outertuple = innerTupleSlot;
    
    hashvalue = ExecHashGetHashValue(node->outer_hj_HashTable,
                                     econtext,
                                     node->hj_InnerHashKeys);

    node->inner_hj_CurHashValue = hashvalue;
    ExecHashGetBucketAndBatch(node->outer_hj_HashTable, hashvalue,
                              &node->outer_hj_CurBucketNo, &batchno);
    node->outer_hj_CurTuple = NULL;
}
