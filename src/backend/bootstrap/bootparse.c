/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or Int_yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with Int_yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bootparse.y"

/*-------------------------------------------------------------------------
 *
 * bootparse.y
 *	  yacc parser grammar for the "backend" initialization program.
 *
 * Portions Copyright (c) 1996-2005, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  $PostgreSQL: pgsql/src/backend/bootstrap/bootparse.y,v 1.78 2005/08/26 03:07:00 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include <unistd.h>

#include "access/attnum.h"
#include "access/htup.h"
#include "access/itup.h"
#include "access/skey.h"
#include "access/tupdesc.h"
#include "access/xact.h"
#include "bootstrap/bootstrap.h"
#include "catalog/catalog.h"
#include "catalog/heap.h"
#include "catalog/pg_am.h"
#include "catalog/pg_attribute.h"
#include "catalog/pg_authid.h"
#include "catalog/pg_class.h"
#include "catalog/pg_namespace.h"
#include "catalog/pg_tablespace.h"
#include "commands/defrem.h"
#include "miscadmin.h"
#include "nodes/makefuncs.h"
#include "nodes/nodes.h"
#include "nodes/parsenodes.h"
#include "nodes/pg_list.h"
#include "nodes/primnodes.h"
#include "rewrite/prs2lock.h"
#include "storage/block.h"
#include "storage/fd.h"
#include "storage/ipc.h"
#include "storage/itemptr.h"
#include "storage/off.h"
#include "storage/smgr.h"
#include "tcop/dest.h"
#include "utils/rel.h"

#define atooid(x)	((Oid) strtoul((x), NULL, 10))


static void
do_start(void)
{
	StartTransactionCommand();
	elog(DEBUG4, "start transaction");
}


static void
do_end(void)
{
	CommitTransactionCommand();
	elog(DEBUG4, "commit transaction");
	CHECK_FOR_INTERRUPTS();		/* allow SIGINT to kill bootstrap run */
	if (isatty(0))
	{
		printf("bootstrap> ");
		fflush(stdout);
	}
}


int num_columns_read = 0;


#line 152 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int Int_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum Int_yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CONST_P = 258,                 /* CONST_P  */
    ID = 259,                      /* ID  */
    OPEN = 260,                    /* OPEN  */
    XCLOSE = 261,                  /* XCLOSE  */
    XCREATE = 262,                 /* XCREATE  */
    INSERT_TUPLE = 263,            /* INSERT_TUPLE  */
    XDECLARE = 264,                /* XDECLARE  */
    INDEX = 265,                   /* INDEX  */
    ON = 266,                      /* ON  */
    USING = 267,                   /* USING  */
    XBUILD = 268,                  /* XBUILD  */
    INDICES = 269,                 /* INDICES  */
    UNIQUE = 270,                  /* UNIQUE  */
    COMMA = 271,                   /* COMMA  */
    EQUALS = 272,                  /* EQUALS  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    OBJ_ID = 275,                  /* OBJ_ID  */
    XBOOTSTRAP = 276,              /* XBOOTSTRAP  */
    XSHARED_RELATION = 277,        /* XSHARED_RELATION  */
    XWITHOUT_OIDS = 278,           /* XWITHOUT_OIDS  */
    NULLVAL = 279,                 /* NULLVAL  */
    low = 280,                     /* low  */
    high = 281                     /* high  */
  };
  typedef enum Int_yytokentype Int_yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CONST_P 258
#define ID 259
#define OPEN 260
#define XCLOSE 261
#define XCREATE 262
#define INSERT_TUPLE 263
#define XDECLARE 264
#define INDEX 265
#define ON 266
#define USING 267
#define XBUILD 268
#define INDICES 269
#define UNIQUE 270
#define COMMA 271
#define EQUALS 272
#define LPAREN 273
#define RPAREN 274
#define OBJ_ID 275
#define XBOOTSTRAP 276
#define XSHARED_RELATION 277
#define XWITHOUT_OIDS 278
#define NULLVAL 279
#define low 280
#define high 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "bootparse.y"

	List		*list;
	IndexElem	*ielem;
	char		*str;
	int			ival;
	Oid			oidval;

#line 265 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE Int_yylval;


int Int_yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum Int_yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST_P = 3,                    /* CONST_P  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_OPEN = 5,                       /* OPEN  */
  YYSYMBOL_XCLOSE = 6,                     /* XCLOSE  */
  YYSYMBOL_XCREATE = 7,                    /* XCREATE  */
  YYSYMBOL_INSERT_TUPLE = 8,               /* INSERT_TUPLE  */
  YYSYMBOL_XDECLARE = 9,                   /* XDECLARE  */
  YYSYMBOL_INDEX = 10,                     /* INDEX  */
  YYSYMBOL_ON = 11,                        /* ON  */
  YYSYMBOL_USING = 12,                     /* USING  */
  YYSYMBOL_XBUILD = 13,                    /* XBUILD  */
  YYSYMBOL_INDICES = 14,                   /* INDICES  */
  YYSYMBOL_UNIQUE = 15,                    /* UNIQUE  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_EQUALS = 17,                    /* EQUALS  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_OBJ_ID = 20,                    /* OBJ_ID  */
  YYSYMBOL_XBOOTSTRAP = 21,                /* XBOOTSTRAP  */
  YYSYMBOL_XSHARED_RELATION = 22,          /* XSHARED_RELATION  */
  YYSYMBOL_XWITHOUT_OIDS = 23,             /* XWITHOUT_OIDS  */
  YYSYMBOL_NULLVAL = 24,                   /* NULLVAL  */
  YYSYMBOL_low = 25,                       /* low  */
  YYSYMBOL_high = 26,                      /* high  */
  YYSYMBOL_YYACCEPT = 27,                  /* $accept  */
  YYSYMBOL_TopLevel = 28,                  /* TopLevel  */
  YYSYMBOL_Boot_Queries = 29,              /* Boot_Queries  */
  YYSYMBOL_Boot_Query = 30,                /* Boot_Query  */
  YYSYMBOL_Boot_OpenStmt = 31,             /* Boot_OpenStmt  */
  YYSYMBOL_Boot_CloseStmt = 32,            /* Boot_CloseStmt  */
  YYSYMBOL_Boot_CreateStmt = 33,           /* Boot_CreateStmt  */
  YYSYMBOL_34_1 = 34,                      /* $@1  */
  YYSYMBOL_35_2 = 35,                      /* $@2  */
  YYSYMBOL_Boot_InsertStmt = 36,           /* Boot_InsertStmt  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_Boot_DeclareIndexStmt = 38,     /* Boot_DeclareIndexStmt  */
  YYSYMBOL_Boot_DeclareUniqueIndexStmt = 39, /* Boot_DeclareUniqueIndexStmt  */
  YYSYMBOL_Boot_BuildIndsStmt = 40,        /* Boot_BuildIndsStmt  */
  YYSYMBOL_boot_index_params = 41,         /* boot_index_params  */
  YYSYMBOL_boot_index_param = 42,          /* boot_index_param  */
  YYSYMBOL_optbootstrap = 43,              /* optbootstrap  */
  YYSYMBOL_optsharedrelation = 44,         /* optsharedrelation  */
  YYSYMBOL_optwithoutoids = 45,            /* optwithoutoids  */
  YYSYMBOL_boot_typelist = 46,             /* boot_typelist  */
  YYSYMBOL_boot_type_thing = 47,           /* boot_type_thing  */
  YYSYMBOL_oidspec = 48,                   /* oidspec  */
  YYSYMBOL_optoideq = 49,                  /* optoideq  */
  YYSYMBOL_boot_tuplelist = 50,            /* boot_tuplelist  */
  YYSYMBOL_boot_tuple = 51,                /* boot_tuple  */
  YYSYMBOL_boot_const = 52,                /* boot_const  */
  YYSYMBOL_boot_ident = 53                 /* boot_ident  */
};
typedef enum Int_yysymbol_kind_t Int_yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ Int_yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t Int_yytype_int8;
#else
typedef signed char Int_yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ Int_yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t Int_yytype_int16;
#else
typedef short Int_yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ Int_yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t Int_yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char Int_yytype_uint8;
#else
typedef short Int_yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ Int_yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t Int_yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short Int_yytype_uint16;
#else
typedef int Int_yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef Int_yytype_int8 Int_yy_state_t;

/* State numbers in computations.  */
typedef int Int_yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about Int_yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined Int_yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined Int_yyoverflow */

#if (! defined Int_yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union Int_yyalloc
{
  Int_yy_state_t Int_yyss_alloc;
  YYSTYPE Int_yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union Int_yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (Int_yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T Int_yynewbytes;                                         \
        YYCOPY (&Int_yyptr->Stack_alloc, Stack, Int_yysize);                    \
        Stack = &Int_yyptr->Stack_alloc;                                    \
        Int_yynewbytes = Int_yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        Int_yyptr += Int_yynewbytes / YYSIZEOF (*Int_yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T Int_yyi;                      \
          for (Int_yyi = 0; Int_yyi < (Count); Int_yyi++)   \
            (Dst)[Int_yyi] = (Src)[Int_yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   78

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  85

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by Int_yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (Int_yysymbol_kind_t, Int_yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by Int_yylex.  */
static const Int_yytype_int8 Int_yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const Int_yytype_int16 Int_yyrline[] =
{
       0,   111,   111,   112,   116,   117,   121,   122,   123,   124,
     125,   126,   127,   131,   140,   146,   156,   166,   155,   219,
     218,   243,   261,   279,   289,   290,   294,   305,   306,   310,
     311,   315,   316,   320,   321,   325,   334,   338,   339,   343,
     344,   345,   349,   351,   353,   358,   362
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (Int_yysymbol_kind_t, Int_yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *Int_yysymbol_name (Int_yysymbol_kind_t Int_yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const Int_yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CONST_P", "ID",
  "OPEN", "XCLOSE", "XCREATE", "INSERT_TUPLE", "XDECLARE", "INDEX", "ON",
  "USING", "XBUILD", "INDICES", "UNIQUE", "COMMA", "EQUALS", "LPAREN",
  "RPAREN", "OBJ_ID", "XBOOTSTRAP", "XSHARED_RELATION", "XWITHOUT_OIDS",
  "NULLVAL", "low", "high", "$accept", "TopLevel", "Boot_Queries",
  "Boot_Query", "Boot_OpenStmt", "Boot_CloseStmt", "Boot_CreateStmt",
  "$@1", "$@2", "Boot_InsertStmt", "$@3", "Boot_DeclareIndexStmt",
  "Boot_DeclareUniqueIndexStmt", "Boot_BuildIndsStmt", "boot_index_params",
  "boot_index_param", "optbootstrap", "optsharedrelation",
  "optwithoutoids", "boot_typelist", "boot_type_thing", "oidspec",
  "optoideq", "boot_tuplelist", "boot_tuple", "boot_const", "boot_ident", YY_NULLPTR
};

static const char *
Int_yysymbol_name (Int_yysymbol_kind_t Int_yysymbol)
{
  return Int_yytname[Int_yysymbol];
}
#endif

#define YYPACT_NINF (-39)

#define Int_yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define Int_yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const Int_yytype_int8 Int_yypact[] =
{
      23,    11,    11,    -3,     5,    -2,     7,    22,    23,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,    12,    10,   -39,    11,    27,   -39,   -39,   -39,   -39,
      16,    11,    24,    11,    11,   -39,    11,   -39,   -39,     2,
      29,    11,    11,   -39,   -39,     0,   -39,   -39,   -39,    11,
      30,    25,     2,   -39,   -39,    33,    11,   -39,   -39,    11,
      34,    11,    31,    11,    36,   -39,    37,    11,    32,    11,
      28,    11,    -7,   -39,    11,    11,   -39,   -39,   -39,    11,
     -39,   -39,     1,   -39,   -39
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const Int_yytype_int8 Int_yydefact[] =
{
       3,     0,    15,    28,    38,     0,     0,     0,     2,     4,
       6,     7,     8,     9,    10,    11,    12,    46,    13,    14,
      27,    30,     0,    19,     0,     0,    23,     1,     5,    29,
      32,     0,     0,     0,     0,    31,     0,    37,    36,     0,
       0,     0,     0,    45,    44,     0,    39,    43,    42,     0,
       0,     0,     0,    20,    40,     0,     0,    16,    41,     0,
       0,     0,     0,     0,    17,    33,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,    34,    18,    35,     0,
      21,    26,     0,    24,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const Int_yytype_int8 Int_yypgoto[] =
{
     -39,   -39,   -39,    45,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -19,   -22,   -39,   -39,   -39,   -39,
     -10,   -31,   -39,   -39,   -38,   -39,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const Int_yytype_int8 Int_yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    12,    61,    70,    13,
      32,    14,    15,    16,    72,    73,    21,    30,    36,    64,
      65,    37,    23,    45,    46,    47,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const Int_yytype_int8 Int_yytable[] =
{
      18,    19,    40,    43,    17,    43,    17,    54,    24,    79,
      50,    51,    80,    25,    58,    17,    52,    79,    20,    53,
      84,    26,    27,    33,    44,    22,    44,    31,     1,     2,
       3,     4,     5,    41,    29,    42,     6,    34,    48,    35,
      49,    56,    39,    57,    48,    59,    63,    77,    55,    67,
      75,    48,    69,    28,    71,    60,    82,    83,    62,    76,
      66,     0,    68,     0,     0,     0,    74,     0,    66,     0,
      78,     0,     0,    81,    74,     0,     0,     0,    74
};

static const Int_yytype_int8 Int_yycheck[] =
{
       1,     2,    33,     3,     4,     3,     4,    45,    10,    16,
      41,    42,    19,    15,    52,     4,    16,    16,    21,    19,
      19,    14,     0,    24,    24,    20,    24,    17,     5,     6,
       7,     8,     9,    34,    22,    36,    13,    10,    39,    23,
      11,    11,    18,    18,    45,    12,    12,    19,    49,    18,
      18,    52,    16,     8,    17,    56,    75,    79,    59,    69,
      61,    -1,    63,    -1,    -1,    -1,    67,    -1,    69,    -1,
      71,    -1,    -1,    74,    75,    -1,    -1,    -1,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const Int_yytype_int8 Int_yystos[] =
{
       0,     5,     6,     7,     8,     9,    13,    28,    29,    30,
      31,    32,    33,    36,    38,    39,    40,     4,    53,    53,
      21,    43,    20,    49,    10,    15,    14,     0,    30,    22,
      44,    17,    37,    53,    10,    23,    45,    48,    53,    18,
      48,    53,    53,     3,    24,    50,    51,    52,    53,    11,
      48,    48,    16,    19,    51,    53,    11,    18,    51,    12,
      53,    34,    53,    12,    46,    47,    53,    18,    53,    16,
      35,    17,    41,    42,    53,    18,    47,    19,    53,    16,
      19,    53,    41,    42,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const Int_yytype_int8 Int_yyr1[] =
{
       0,    27,    28,    28,    29,    29,    30,    30,    30,    30,
      30,    30,    30,    31,    32,    32,    34,    35,    33,    37,
      36,    38,    39,    40,    41,    41,    42,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    48,    49,    49,    50,
      50,    50,    51,    51,    51,    52,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const Int_yytype_int8 Int_yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     0,     0,    11,     0,
       6,    11,    12,     2,     3,     1,     2,     1,     0,     1,
       0,     1,     0,     1,     3,     3,     1,     3,     0,     1,
       2,     3,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define Int_yyerrok         (Int_yyerrstatus = 0)
#define Int_yyclearin       (Int_yychar = YYEMPTY)

#define YYACCEPT        goto Int_yyacceptlab
#define YYABORT         goto Int_yyabortlab
#define YYERROR         goto Int_yyerrorlab
#define YYNOMEM         goto Int_yyexhaustedlab


#define YYRECOVERING()  (!!Int_yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (Int_yychar == YYEMPTY)                                        \
      {                                                           \
        Int_yychar = (Token);                                         \
        Int_yylval = (Value);                                         \
        YYPOPSTACK (Int_yylen);                                       \
        Int_yystate = *Int_yyssp;                                         \
        goto Int_yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        Int_yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (Int_yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (Int_yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      Int_yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
Int_yy_symbol_value_print (FILE *Int_yyo,
                       Int_yysymbol_kind_t Int_yykind, YYSTYPE const * const Int_yyvaluep)
{
  FILE *Int_yyoutput = Int_yyo;
  YY_USE (Int_yyoutput);
  if (!Int_yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (Int_yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
Int_yy_symbol_print (FILE *Int_yyo,
                 Int_yysymbol_kind_t Int_yykind, YYSTYPE const * const Int_yyvaluep)
{
  YYFPRINTF (Int_yyo, "%s %s (",
             Int_yykind < YYNTOKENS ? "token" : "nterm", Int_yysymbol_name (Int_yykind));

  Int_yy_symbol_value_print (Int_yyo, Int_yykind, Int_yyvaluep);
  YYFPRINTF (Int_yyo, ")");
}

/*------------------------------------------------------------------.
| Int_yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
Int_yy_stack_print (Int_yy_state_t *Int_yybottom, Int_yy_state_t *Int_yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; Int_yybottom <= Int_yytop; Int_yybottom++)
    {
      int Int_yybot = *Int_yybottom;
      YYFPRINTF (stderr, " %d", Int_yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (Int_yydebug)                                                  \
    Int_yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
Int_yy_reduce_print (Int_yy_state_t *Int_yyssp, YYSTYPE *Int_yyvsp,
                 int Int_yyrule)
{
  int Int_yylno = Int_yyrline[Int_yyrule];
  int Int_yynrhs = Int_yyr2[Int_yyrule];
  int Int_yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             Int_yyrule - 1, Int_yylno);
  /* The symbols being reduced.  */
  for (Int_yyi = 0; Int_yyi < Int_yynrhs; Int_yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", Int_yyi + 1);
      Int_yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+Int_yyssp[Int_yyi + 1 - Int_yynrhs]),
                       &Int_yyvsp[(Int_yyi + 1) - (Int_yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (Int_yydebug)                          \
    Int_yy_reduce_print (Int_yyssp, Int_yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int Int_yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
Int_yydestruct (const char *Int_yymsg,
            Int_yysymbol_kind_t Int_yykind, YYSTYPE *Int_yyvaluep)
{
  YY_USE (Int_yyvaluep);
  if (!Int_yymsg)
    Int_yymsg = "Deleting";
  YY_SYMBOL_PRINT (Int_yymsg, Int_yykind, Int_yyvaluep, Int_yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (Int_yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int Int_yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE Int_yylval;
/* Number of syntax errors so far.  */
int Int_yynerrs;




/*----------.
| Int_yyparse.  |
`----------*/

int
Int_yyparse (void)
{
    Int_yy_state_fast_t Int_yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int Int_yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow Int_yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T Int_yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    Int_yy_state_t Int_yyssa[YYINITDEPTH];
    Int_yy_state_t *Int_yyss = Int_yyssa;
    Int_yy_state_t *Int_yyssp = Int_yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE Int_yyvsa[YYINITDEPTH];
    YYSTYPE *Int_yyvs = Int_yyvsa;
    YYSTYPE *Int_yyvsp = Int_yyvs;

  int Int_yyn;
  /* The return value of Int_yyparse.  */
  int Int_yyresult;
  /* Lookahead symbol kind.  */
  Int_yysymbol_kind_t Int_yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE Int_yyval;



#define YYPOPSTACK(N)   (Int_yyvsp -= (N), Int_yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int Int_yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  Int_yychar = YYEMPTY; /* Cause a token to be read.  */

  goto Int_yysetstate;


/*------------------------------------------------------------.
| Int_yynewstate -- push a new state, which is found in Int_yystate.  |
`------------------------------------------------------------*/
Int_yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  Int_yyssp++;


/*--------------------------------------------------------------------.
| Int_yysetstate -- set current state (the top of the stack) to Int_yystate.  |
`--------------------------------------------------------------------*/
Int_yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", Int_yystate));
  YY_ASSERT (0 <= Int_yystate && Int_yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *Int_yyssp = YY_CAST (Int_yy_state_t, Int_yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (Int_yyss, Int_yyssp);

  if (Int_yyss + Int_yystacksize - 1 <= Int_yyssp)
#if !defined Int_yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T Int_yysize = Int_yyssp - Int_yyss + 1;

# if defined Int_yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        Int_yy_state_t *Int_yyss1 = Int_yyss;
        YYSTYPE *Int_yyvs1 = Int_yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if Int_yyoverflow is a macro.  */
        Int_yyoverflow (YY_("memory exhausted"),
                    &Int_yyss1, Int_yysize * YYSIZEOF (*Int_yyssp),
                    &Int_yyvs1, Int_yysize * YYSIZEOF (*Int_yyvsp),
                    &Int_yystacksize);
        Int_yyss = Int_yyss1;
        Int_yyvs = Int_yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= Int_yystacksize)
        YYNOMEM;
      Int_yystacksize *= 2;
      if (YYMAXDEPTH < Int_yystacksize)
        Int_yystacksize = YYMAXDEPTH;

      {
        Int_yy_state_t *Int_yyss1 = Int_yyss;
        union Int_yyalloc *Int_yyptr =
          YY_CAST (union Int_yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (Int_yystacksize))));
        if (! Int_yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (Int_yyss_alloc, Int_yyss);
        YYSTACK_RELOCATE (Int_yyvs_alloc, Int_yyvs);
#  undef YYSTACK_RELOCATE
        if (Int_yyss1 != Int_yyssa)
          YYSTACK_FREE (Int_yyss1);
      }
# endif

      Int_yyssp = Int_yyss + Int_yysize - 1;
      Int_yyvsp = Int_yyvs + Int_yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, Int_yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (Int_yyss + Int_yystacksize - 1 <= Int_yyssp)
        YYABORT;
    }
#endif /* !defined Int_yyoverflow && !defined YYSTACK_RELOCATE */


  if (Int_yystate == YYFINAL)
    YYACCEPT;

  goto Int_yybackup;


/*-----------.
| Int_yybackup.  |
`-----------*/
Int_yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  Int_yyn = Int_yypact[Int_yystate];
  if (Int_yypact_value_is_default (Int_yyn))
    goto Int_yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (Int_yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      Int_yychar = Int_yylex ();
    }

  if (Int_yychar <= YYEOF)
    {
      Int_yychar = YYEOF;
      Int_yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (Int_yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      Int_yychar = YYUNDEF;
      Int_yytoken = YYSYMBOL_YYerror;
      goto Int_yyerrlab1;
    }
  else
    {
      Int_yytoken = YYTRANSLATE (Int_yychar);
      YY_SYMBOL_PRINT ("Next token is", Int_yytoken, &Int_yylval, &Int_yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  Int_yyn += Int_yytoken;
  if (Int_yyn < 0 || YYLAST < Int_yyn || Int_yycheck[Int_yyn] != Int_yytoken)
    goto Int_yydefault;
  Int_yyn = Int_yytable[Int_yyn];
  if (Int_yyn <= 0)
    {
      if (Int_yytable_value_is_error (Int_yyn))
        goto Int_yyerrlab;
      Int_yyn = -Int_yyn;
      goto Int_yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (Int_yyerrstatus)
    Int_yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", Int_yytoken, &Int_yylval, &Int_yylloc);
  Int_yystate = Int_yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++Int_yyvsp = Int_yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  Int_yychar = YYEMPTY;
  goto Int_yynewstate;


/*-----------------------------------------------------------.
| Int_yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
Int_yydefault:
  Int_yyn = Int_yydefact[Int_yystate];
  if (Int_yyn == 0)
    goto Int_yyerrlab;
  goto Int_yyreduce;


/*-----------------------------.
| Int_yyreduce -- do a reduction.  |
`-----------------------------*/
Int_yyreduce:
  /* Int_yyn is the number of a rule to reduce with.  */
  Int_yylen = Int_yyr2[Int_yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  Int_yyval = Int_yyvsp[1-Int_yylen];


  YY_REDUCE_PRINT (Int_yyn);
  switch (Int_yyn)
    {
  case 13: /* Boot_OpenStmt: OPEN boot_ident  */
#line 132 "bootparse.y"
                                {
					do_start();
					boot_openrel(LexIDStr((Int_yyvsp[0].ival)));
					do_end();
				}
#line 1353 "y.tab.c"
    break;

  case 14: /* Boot_CloseStmt: XCLOSE boot_ident  */
#line 141 "bootparse.y"
                                {
					do_start();
					closerel(LexIDStr((Int_yyvsp[0].ival)));
					do_end();
				}
#line 1363 "y.tab.c"
    break;

  case 15: /* Boot_CloseStmt: XCLOSE  */
#line 147 "bootparse.y"
                                {
					do_start();
					closerel(NULL);
					do_end();
				}
#line 1373 "y.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 156 "bootparse.y"
                                {
					do_start();
					numattr = 0;
					elog(DEBUG4, "creating%s%s relation %s %u",
						 (Int_yyvsp[-5].ival) ? " bootstrap" : "",
						 (Int_yyvsp[-4].ival) ? " shared" : "",
						 LexIDStr((Int_yyvsp[-2].ival)),
						 (Int_yyvsp[-1].oidval));
				}
#line 1387 "y.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 166 "bootparse.y"
                                {
					do_end();
				}
#line 1395 "y.tab.c"
    break;

  case 18: /* Boot_CreateStmt: XCREATE optbootstrap optsharedrelation optwithoutoids boot_ident oidspec LPAREN $@1 boot_typelist $@2 RPAREN  */
#line 170 "bootparse.y"
                                {
					TupleDesc tupdesc;

					do_start();

					tupdesc = CreateTupleDesc(numattr, !((Int_yyvsp[-7].ival)), attrtypes);

					if ((Int_yyvsp[-9].ival))
					{
						if (boot_reldesc)
						{
							elog(DEBUG4, "create bootstrap: warning, open relation exists, closing first");
							closerel(NULL);
						}

						boot_reldesc = heap_create(LexIDStr((Int_yyvsp[-6].ival)),
												   PG_CATALOG_NAMESPACE,
												   (Int_yyvsp[-8].ival) ? GLOBALTABLESPACE_OID : 0,
												   (Int_yyvsp[-5].oidval),
												   tupdesc,
												   RELKIND_RELATION,
												   (Int_yyvsp[-8].ival),
												   true);
						elog(DEBUG4, "bootstrap relation created");
					}
					else
					{
						Oid id;

						id = heap_create_with_catalog(LexIDStr((Int_yyvsp[-6].ival)),
													  PG_CATALOG_NAMESPACE,
													  (Int_yyvsp[-8].ival) ? GLOBALTABLESPACE_OID : 0,
													  (Int_yyvsp[-5].oidval),
													  BOOTSTRAP_SUPERUSERID,
													  tupdesc,
													  RELKIND_RELATION,
													  (Int_yyvsp[-8].ival),
													  true,
													  0,
													  ONCOMMIT_NOOP,
													  true);
						elog(DEBUG4, "relation created with oid %u", id);
					}
					do_end();
				}
#line 1445 "y.tab.c"
    break;

  case 19: /* $@3: %empty  */
#line 219 "bootparse.y"
                                {
					do_start();
					if ((Int_yyvsp[0].oidval))
						elog(DEBUG4, "inserting row with oid %u", (Int_yyvsp[0].oidval));
					else
						elog(DEBUG4, "inserting row");
					num_columns_read = 0;
				}
#line 1458 "y.tab.c"
    break;

  case 20: /* Boot_InsertStmt: INSERT_TUPLE optoideq $@3 LPAREN boot_tuplelist RPAREN  */
#line 228 "bootparse.y"
                                {
					if (num_columns_read != numattr)
						elog(ERROR, "incorrect number of columns in row (expected %d, got %d)",
							 numattr, num_columns_read);
					if (boot_reldesc == NULL)
					{
						elog(ERROR, "relation not open");
						err_out();
					}
					InsertOneTuple((Int_yyvsp[-4].oidval));
					do_end();
				}
#line 1475 "y.tab.c"
    break;

  case 21: /* Boot_DeclareIndexStmt: XDECLARE INDEX boot_ident oidspec ON boot_ident USING boot_ident LPAREN boot_index_params RPAREN  */
#line 244 "bootparse.y"
                                {
					do_start();

					DefineIndex(makeRangeVar(NULL, LexIDStr((Int_yyvsp[-5].ival))),
								LexIDStr((Int_yyvsp[-8].ival)),
								(Int_yyvsp[-7].oidval),
								LexIDStr((Int_yyvsp[-3].ival)),
								NULL,
								(Int_yyvsp[-1].list),
								NULL, NIL,
								false, false, false,
								false, false, true, false);
					do_end();
				}
#line 1494 "y.tab.c"
    break;

  case 22: /* Boot_DeclareUniqueIndexStmt: XDECLARE UNIQUE INDEX boot_ident oidspec ON boot_ident USING boot_ident LPAREN boot_index_params RPAREN  */
#line 262 "bootparse.y"
                                {
					do_start();

					DefineIndex(makeRangeVar(NULL, LexIDStr((Int_yyvsp[-5].ival))),
								LexIDStr((Int_yyvsp[-8].ival)),
								(Int_yyvsp[-7].oidval),
								LexIDStr((Int_yyvsp[-3].ival)),
								NULL,
								(Int_yyvsp[-1].list),
								NULL, NIL,
								true, false, false,
								false, false, true, false);
					do_end();
				}
#line 1513 "y.tab.c"
    break;

  case 23: /* Boot_BuildIndsStmt: XBUILD INDICES  */
#line 280 "bootparse.y"
                                {
					do_start();
					build_indices();
					do_end();
				}
#line 1523 "y.tab.c"
    break;

  case 24: /* boot_index_params: boot_index_params COMMA boot_index_param  */
#line 289 "bootparse.y"
                                                                { (Int_yyval.list) = lappend((Int_yyvsp[-2].list), (Int_yyvsp[0].ielem)); }
#line 1529 "y.tab.c"
    break;

  case 25: /* boot_index_params: boot_index_param  */
#line 290 "bootparse.y"
                                                                                        { (Int_yyval.list) = list_make1((Int_yyvsp[0].ielem)); }
#line 1535 "y.tab.c"
    break;

  case 26: /* boot_index_param: boot_ident boot_ident  */
#line 295 "bootparse.y"
                                {
					IndexElem *n = makeNode(IndexElem);
					n->name = LexIDStr((Int_yyvsp[-1].ival));
					n->expr = NULL;
					n->opclass = list_make1(makeString(LexIDStr((Int_yyvsp[0].ival))));
					(Int_yyval.ielem) = n;
				}
#line 1547 "y.tab.c"
    break;

  case 27: /* optbootstrap: XBOOTSTRAP  */
#line 305 "bootparse.y"
                                        { (Int_yyval.ival) = 1; }
#line 1553 "y.tab.c"
    break;

  case 28: /* optbootstrap: %empty  */
#line 306 "bootparse.y"
                                                { (Int_yyval.ival) = 0; }
#line 1559 "y.tab.c"
    break;

  case 29: /* optsharedrelation: XSHARED_RELATION  */
#line 310 "bootparse.y"
                                                { (Int_yyval.ival) = 1; }
#line 1565 "y.tab.c"
    break;

  case 30: /* optsharedrelation: %empty  */
#line 311 "bootparse.y"
                                                                { (Int_yyval.ival) = 0; }
#line 1571 "y.tab.c"
    break;

  case 31: /* optwithoutoids: XWITHOUT_OIDS  */
#line 315 "bootparse.y"
                                        { (Int_yyval.ival) = 1; }
#line 1577 "y.tab.c"
    break;

  case 32: /* optwithoutoids: %empty  */
#line 316 "bootparse.y"
                                                        { (Int_yyval.ival) = 0; }
#line 1583 "y.tab.c"
    break;

  case 35: /* boot_type_thing: boot_ident EQUALS boot_ident  */
#line 326 "bootparse.y"
                                {
				   if (++numattr > MAXATTR)
						elog(FATAL, "too many columns");
				   DefineAttr(LexIDStr((Int_yyvsp[-2].ival)),LexIDStr((Int_yyvsp[0].ival)),numattr-1);
				}
#line 1593 "y.tab.c"
    break;

  case 36: /* oidspec: boot_ident  */
#line 334 "bootparse.y"
                                                                                        { (Int_yyval.oidval) = atooid(LexIDStr((Int_yyvsp[0].ival))); }
#line 1599 "y.tab.c"
    break;

  case 37: /* optoideq: OBJ_ID EQUALS oidspec  */
#line 338 "bootparse.y"
                                                                        { (Int_yyval.oidval) = (Int_yyvsp[0].oidval); }
#line 1605 "y.tab.c"
    break;

  case 38: /* optoideq: %empty  */
#line 339 "bootparse.y"
                                                                                                { (Int_yyval.oidval) = (Oid) 0; }
#line 1611 "y.tab.c"
    break;

  case 42: /* boot_tuple: boot_ident  */
#line 350 "bootparse.y"
                        { InsertOneValue(LexIDStr((Int_yyvsp[0].ival)), num_columns_read++); }
#line 1617 "y.tab.c"
    break;

  case 43: /* boot_tuple: boot_const  */
#line 352 "bootparse.y"
                        { InsertOneValue(LexIDStr((Int_yyvsp[0].ival)), num_columns_read++); }
#line 1623 "y.tab.c"
    break;

  case 44: /* boot_tuple: NULLVAL  */
#line 354 "bootparse.y"
                        { InsertOneNull(num_columns_read++); }
#line 1629 "y.tab.c"
    break;

  case 45: /* boot_const: CONST_P  */
#line 358 "bootparse.y"
                          { (Int_yyval.ival)=Int_yylval.ival; }
#line 1635 "y.tab.c"
    break;

  case 46: /* boot_ident: ID  */
#line 362 "bootparse.y"
                        { (Int_yyval.ival)=Int_yylval.ival; }
#line 1641 "y.tab.c"
    break;


#line 1645 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter Int_yychar, and that requires
     that Int_yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of Int_yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering Int_yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (Int_yysymbol_kind_t, Int_yyr1[Int_yyn]), &Int_yyval, &Int_yyloc);

  YYPOPSTACK (Int_yylen);
  Int_yylen = 0;

  *++Int_yyvsp = Int_yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int Int_yylhs = Int_yyr1[Int_yyn] - YYNTOKENS;
    const int Int_yyi = Int_yypgoto[Int_yylhs] + *Int_yyssp;
    Int_yystate = (0 <= Int_yyi && Int_yyi <= YYLAST && Int_yycheck[Int_yyi] == *Int_yyssp
               ? Int_yytable[Int_yyi]
               : Int_yydefgoto[Int_yylhs]);
  }

  goto Int_yynewstate;


/*--------------------------------------.
| Int_yyerrlab -- here on detecting error.  |
`--------------------------------------*/
Int_yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  Int_yytoken = Int_yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (Int_yychar);
  /* If not already recovering from an error, report this error.  */
  if (!Int_yyerrstatus)
    {
      ++Int_yynerrs;
      Int_yyerror (YY_("syntax error"));
    }

  if (Int_yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (Int_yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (Int_yychar == YYEOF)
            YYABORT;
        }
      else
        {
          Int_yydestruct ("Error: discarding",
                      Int_yytoken, &Int_yylval);
          Int_yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto Int_yyerrlab1;


/*---------------------------------------------------.
| Int_yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
Int_yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label Int_yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++Int_yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (Int_yylen);
  Int_yylen = 0;
  YY_STACK_PRINT (Int_yyss, Int_yyssp);
  Int_yystate = *Int_yyssp;
  goto Int_yyerrlab1;


/*-------------------------------------------------------------.
| Int_yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
Int_yyerrlab1:
  Int_yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      Int_yyn = Int_yypact[Int_yystate];
      if (!Int_yypact_value_is_default (Int_yyn))
        {
          Int_yyn += YYSYMBOL_YYerror;
          if (0 <= Int_yyn && Int_yyn <= YYLAST && Int_yycheck[Int_yyn] == YYSYMBOL_YYerror)
            {
              Int_yyn = Int_yytable[Int_yyn];
              if (0 < Int_yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (Int_yyssp == Int_yyss)
        YYABORT;


      Int_yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (Int_yystate), Int_yyvsp);
      YYPOPSTACK (1);
      Int_yystate = *Int_yyssp;
      YY_STACK_PRINT (Int_yyss, Int_yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++Int_yyvsp = Int_yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (Int_yyn), Int_yyvsp, Int_yylsp);

  Int_yystate = Int_yyn;
  goto Int_yynewstate;


/*-------------------------------------.
| Int_yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
Int_yyacceptlab:
  Int_yyresult = 0;
  goto Int_yyreturnlab;


/*-----------------------------------.
| Int_yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
Int_yyabortlab:
  Int_yyresult = 1;
  goto Int_yyreturnlab;


/*-----------------------------------------------------------.
| Int_yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
Int_yyexhaustedlab:
  Int_yyerror (YY_("memory exhausted"));
  Int_yyresult = 2;
  goto Int_yyreturnlab;


/*----------------------------------------------------------.
| Int_yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
Int_yyreturnlab:
  if (Int_yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      Int_yytoken = YYTRANSLATE (Int_yychar);
      Int_yydestruct ("Cleanup: discarding lookahead",
                  Int_yytoken, &Int_yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (Int_yylen);
  YY_STACK_PRINT (Int_yyss, Int_yyssp);
  while (Int_yyssp != Int_yyss)
    {
      Int_yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*Int_yyssp), Int_yyvsp);
      YYPOPSTACK (1);
    }
#ifndef Int_yyoverflow
  if (Int_yyss != Int_yyssa)
    YYSTACK_FREE (Int_yyss);
#endif

  return Int_yyresult;
}

#line 364 "bootparse.y"


#include "bootscanner.c"
