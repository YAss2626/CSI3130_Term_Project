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
   especially those whose name start with PLPGSQL_YY_ or plpgsql_yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with plpgsql_yy or PLPGSQL_YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define PLPGSQL_YYBISON 30802

/* Bison version string.  */
#define PLPGSQL_YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define PLPGSQL_YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define PLPGSQL_YYPURE 0

/* Push parsers.  */
#define PLPGSQL_YYPUSH 0

/* Pull parsers.  */
#define PLPGSQL_YYPULL 1




/* First part of user prologue.  */
#line 1 "gram.y"

/**********************************************************************
 * gram.y				- Parser for the PL/pgSQL
 *						  procedural language
 *
 * IDENTIFICATION
 *	  $PostgreSQL: pgsql/src/pl/plpgsql/src/gram.y,v 1.82.2.1 2006/03/23 04:22:44 tgl Exp $
 *
 *	  This software is copyrighted by Jan Wieck - Hamburg.
 *
 *	  The author hereby grants permission  to  use,  copy,	modify,
 *	  distribute,  and	license this software and its documentation
 *	  for any purpose, provided that existing copyright notices are
 *	  retained	in	all  copies  and  that	this notice is included
 *	  verbatim in any distributions. No written agreement, license,
 *	  or  royalty  fee	is required for any of the authorized uses.
 *	  Modifications to this software may be  copyrighted  by  their
 *	  author  and  need  not  follow  the licensing terms described
 *	  here, provided that the new terms are  clearly  indicated  on
 *	  the first page of each file where they apply.
 *
 *	  IN NO EVENT SHALL THE AUTHOR OR DISTRIBUTORS BE LIABLE TO ANY
 *	  PARTY  FOR  DIRECT,	INDIRECT,	SPECIAL,   INCIDENTAL,	 OR
 *	  CONSEQUENTIAL   DAMAGES  ARISING	OUT  OF  THE  USE  OF  THIS
 *	  SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF, EVEN
 *	  IF  THE  AUTHOR  HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 *	  DAMAGE.
 *
 *	  THE  AUTHOR  AND	DISTRIBUTORS  SPECIFICALLY	 DISCLAIM	ANY
 *	  WARRANTIES,  INCLUDING,  BUT	NOT  LIMITED  TO,  THE	IMPLIED
 *	  WARRANTIES  OF  MERCHANTABILITY,	FITNESS  FOR  A  PARTICULAR
 *	  PURPOSE,	AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON
 *	  AN "AS IS" BASIS, AND THE AUTHOR	AND  DISTRIBUTORS  HAVE  NO
 *	  OBLIGATION   TO	PROVIDE   MAINTENANCE,	 SUPPORT,  UPDATES,
 *	  ENHANCEMENTS, OR MODIFICATIONS.
 *
 **********************************************************************/

#include "plpgsql.h"

#include "parser/parser.h"

static PLpgSQL_expr		*read_sql_construct(int until,
											int until2,
											const char *expected,
											const char *sqlstart,
											bool isexpression,
											bool valid_sql,
											int *endtoken);
static	PLpgSQL_expr	*read_sql_stmt(const char *sqlstart);
static	PLpgSQL_type	*read_datatype(int tok);
static	PLpgSQL_stmt	*make_select_stmt(void);
static	PLpgSQL_stmt	*make_fetch_stmt(void);
static	void			 check_assignable(PLpgSQL_datum *datum);
static	PLpgSQL_row		*read_into_scalar_list(const char *initial_name,
											   PLpgSQL_datum *initial_datum);
static	void			 check_sql_expr(const char *stmt);
static	void			 plpgsql_sql_error_callback(void *arg);
static	void			 check_labels(const char *start_label,
									  const char *end_label);


#line 134 "y.tab.c"

# ifndef PLPGSQL_YY_CAST
#  ifdef __cplusplus
#   define PLPGSQL_YY_CAST(Type, Val) static_cast<Type> (Val)
#   define PLPGSQL_YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define PLPGSQL_YY_CAST(Type, Val) ((Type) (Val))
#   define PLPGSQL_YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef PLPGSQL_YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define PLPGSQL_YY_NULLPTR nullptr
#   else
#    define PLPGSQL_YY_NULLPTR 0
#   endif
#  else
#   define PLPGSQL_YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef PLPGSQL_YY_PLPGSQL_YY_Y_TAB_H_INCLUDED
# define PLPGSQL_YY_PLPGSQL_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef PLPGSQL_YYDEBUG
# define PLPGSQL_YYDEBUG 0
#endif
#if PLPGSQL_YYDEBUG
extern int plpgsql_yydebug;
#endif

/* Token kinds.  */
#ifndef PLPGSQL_YYTOKENTYPE
# define PLPGSQL_YYTOKENTYPE
  enum plpgsql_yytokentype
  {
    PLPGSQL_YYEMPTY = -2,
    PLPGSQL_YYEOF = 0,                     /* "end of file"  */
    PLPGSQL_YYerror = 256,                 /* error  */
    PLPGSQL_YYUNDEF = 257,                 /* "invalid token"  */
    K_ALIAS = 258,                 /* K_ALIAS  */
    K_ASSIGN = 259,                /* K_ASSIGN  */
    K_BEGIN = 260,                 /* K_BEGIN  */
    K_CLOSE = 261,                 /* K_CLOSE  */
    K_CONSTANT = 262,              /* K_CONSTANT  */
    K_CONTINUE = 263,              /* K_CONTINUE  */
    K_CURSOR = 264,                /* K_CURSOR  */
    K_DEBUG = 265,                 /* K_DEBUG  */
    K_DECLARE = 266,               /* K_DECLARE  */
    K_DEFAULT = 267,               /* K_DEFAULT  */
    K_DIAGNOSTICS = 268,           /* K_DIAGNOSTICS  */
    K_DOTDOT = 269,                /* K_DOTDOT  */
    K_ELSE = 270,                  /* K_ELSE  */
    K_ELSIF = 271,                 /* K_ELSIF  */
    K_END = 272,                   /* K_END  */
    K_EXCEPTION = 273,             /* K_EXCEPTION  */
    K_EXECUTE = 274,               /* K_EXECUTE  */
    K_EXIT = 275,                  /* K_EXIT  */
    K_FOR = 276,                   /* K_FOR  */
    K_FETCH = 277,                 /* K_FETCH  */
    K_FROM = 278,                  /* K_FROM  */
    K_GET = 279,                   /* K_GET  */
    K_IF = 280,                    /* K_IF  */
    K_IN = 281,                    /* K_IN  */
    K_INFO = 282,                  /* K_INFO  */
    K_INTO = 283,                  /* K_INTO  */
    K_IS = 284,                    /* K_IS  */
    K_LOG = 285,                   /* K_LOG  */
    K_LOOP = 286,                  /* K_LOOP  */
    K_NEXT = 287,                  /* K_NEXT  */
    K_NOT = 288,                   /* K_NOT  */
    K_NOTICE = 289,                /* K_NOTICE  */
    K_NULL = 290,                  /* K_NULL  */
    K_OPEN = 291,                  /* K_OPEN  */
    K_OR = 292,                    /* K_OR  */
    K_PERFORM = 293,               /* K_PERFORM  */
    K_ROW_COUNT = 294,             /* K_ROW_COUNT  */
    K_RAISE = 295,                 /* K_RAISE  */
    K_RENAME = 296,                /* K_RENAME  */
    K_RESULT_OID = 297,            /* K_RESULT_OID  */
    K_RETURN = 298,                /* K_RETURN  */
    K_RETURN_NEXT = 299,           /* K_RETURN_NEXT  */
    K_REVERSE = 300,               /* K_REVERSE  */
    K_SELECT = 301,                /* K_SELECT  */
    K_THEN = 302,                  /* K_THEN  */
    K_TO = 303,                    /* K_TO  */
    K_TYPE = 304,                  /* K_TYPE  */
    K_WARNING = 305,               /* K_WARNING  */
    K_WHEN = 306,                  /* K_WHEN  */
    K_WHILE = 307,                 /* K_WHILE  */
    T_FUNCTION = 308,              /* T_FUNCTION  */
    T_TRIGGER = 309,               /* T_TRIGGER  */
    T_STRING = 310,                /* T_STRING  */
    T_NUMBER = 311,                /* T_NUMBER  */
    T_SCALAR = 312,                /* T_SCALAR  */
    T_ROW = 313,                   /* T_ROW  */
    T_RECORD = 314,                /* T_RECORD  */
    T_DTYPE = 315,                 /* T_DTYPE  */
    T_LABEL = 316,                 /* T_LABEL  */
    T_WORD = 317,                  /* T_WORD  */
    T_ERROR = 318,                 /* T_ERROR  */
    O_OPTION = 319,                /* O_OPTION  */
    O_DUMP = 320                   /* O_DUMP  */
  };
  typedef enum plpgsql_yytokentype plpgsql_yytoken_kind_t;
#endif
/* Token kinds.  */
#define PLPGSQL_YYEMPTY -2
#define PLPGSQL_YYEOF 0
#define PLPGSQL_YYerror 256
#define PLPGSQL_YYUNDEF 257
#define K_ALIAS 258
#define K_ASSIGN 259
#define K_BEGIN 260
#define K_CLOSE 261
#define K_CONSTANT 262
#define K_CONTINUE 263
#define K_CURSOR 264
#define K_DEBUG 265
#define K_DECLARE 266
#define K_DEFAULT 267
#define K_DIAGNOSTICS 268
#define K_DOTDOT 269
#define K_ELSE 270
#define K_ELSIF 271
#define K_END 272
#define K_EXCEPTION 273
#define K_EXECUTE 274
#define K_EXIT 275
#define K_FOR 276
#define K_FETCH 277
#define K_FROM 278
#define K_GET 279
#define K_IF 280
#define K_IN 281
#define K_INFO 282
#define K_INTO 283
#define K_IS 284
#define K_LOG 285
#define K_LOOP 286
#define K_NEXT 287
#define K_NOT 288
#define K_NOTICE 289
#define K_NULL 290
#define K_OPEN 291
#define K_OR 292
#define K_PERFORM 293
#define K_ROW_COUNT 294
#define K_RAISE 295
#define K_RENAME 296
#define K_RESULT_OID 297
#define K_RETURN 298
#define K_RETURN_NEXT 299
#define K_REVERSE 300
#define K_SELECT 301
#define K_THEN 302
#define K_TO 303
#define K_TYPE 304
#define K_WARNING 305
#define K_WHEN 306
#define K_WHILE 307
#define T_FUNCTION 308
#define T_TRIGGER 309
#define T_STRING 310
#define T_NUMBER 311
#define T_SCALAR 312
#define T_ROW 313
#define T_RECORD 314
#define T_DTYPE 315
#define T_LABEL 316
#define T_WORD 317
#define T_ERROR 318
#define O_OPTION 319
#define O_DUMP 320

/* Value type.  */
#if ! defined PLPGSQL_YYSTYPE && ! defined PLPGSQL_YYSTYPE_IS_DECLARED
union PLPGSQL_YYSTYPE
{
#line 64 "gram.y"

		int32					ival;
		bool					boolean;
		char					*str;
		struct
		{
			char *name;
			int  lineno;
		}						varname;
		struct
		{
			char *name;
			int  lineno;
			PLpgSQL_rec     *rec;
			PLpgSQL_row     *row;
		}						forvariable;
		struct
		{
			char *label;
			int  n_initvars;
			int  *initvarnos;
		}						declhdr;
		struct
		{
			char *end_label;
			List *stmts;
		}						loop_body;
		List					*list;
		PLpgSQL_type			*dtype;
		PLpgSQL_datum			*scalar;	/* a VAR, RECFIELD, or TRIGARG */
		PLpgSQL_variable		*variable;	/* a VAR, REC, or ROW */
		PLpgSQL_var				*var;
		PLpgSQL_row				*row;
		PLpgSQL_rec				*rec;
		PLpgSQL_expr			*expr;
		PLpgSQL_stmt			*stmt;
		PLpgSQL_stmt_block		*program;
		PLpgSQL_condition		*condition;
		PLpgSQL_exception		*exception;
		PLpgSQL_exception_block	*exception_block;
		PLpgSQL_nsitem			*nsitem;
		PLpgSQL_diag_item		*diagitem;

#line 361 "y.tab.c"

};
typedef union PLPGSQL_YYSTYPE PLPGSQL_YYSTYPE;
# define PLPGSQL_YYSTYPE_IS_TRIVIAL 1
# define PLPGSQL_YYSTYPE_IS_DECLARED 1
#endif


extern PLPGSQL_YYSTYPE plpgsql_yylval;


int plpgsql_yyparse (void);


#endif /* !PLPGSQL_YY_PLPGSQL_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum plpgsql_yysymbol_kind_t
{
  PLPGSQL_YYSYMBOL_PLPGSQL_YYEMPTY = -2,
  PLPGSQL_YYSYMBOL_PLPGSQL_YYEOF = 0,                      /* "end of file"  */
  PLPGSQL_YYSYMBOL_PLPGSQL_YYerror = 1,                    /* error  */
  PLPGSQL_YYSYMBOL_PLPGSQL_YYUNDEF = 2,                    /* "invalid token"  */
  PLPGSQL_YYSYMBOL_K_ALIAS = 3,                    /* K_ALIAS  */
  PLPGSQL_YYSYMBOL_K_ASSIGN = 4,                   /* K_ASSIGN  */
  PLPGSQL_YYSYMBOL_K_BEGIN = 5,                    /* K_BEGIN  */
  PLPGSQL_YYSYMBOL_K_CLOSE = 6,                    /* K_CLOSE  */
  PLPGSQL_YYSYMBOL_K_CONSTANT = 7,                 /* K_CONSTANT  */
  PLPGSQL_YYSYMBOL_K_CONTINUE = 8,                 /* K_CONTINUE  */
  PLPGSQL_YYSYMBOL_K_CURSOR = 9,                   /* K_CURSOR  */
  PLPGSQL_YYSYMBOL_K_DEBUG = 10,                   /* K_DEBUG  */
  PLPGSQL_YYSYMBOL_K_DECLARE = 11,                 /* K_DECLARE  */
  PLPGSQL_YYSYMBOL_K_DEFAULT = 12,                 /* K_DEFAULT  */
  PLPGSQL_YYSYMBOL_K_DIAGNOSTICS = 13,             /* K_DIAGNOSTICS  */
  PLPGSQL_YYSYMBOL_K_DOTDOT = 14,                  /* K_DOTDOT  */
  PLPGSQL_YYSYMBOL_K_ELSE = 15,                    /* K_ELSE  */
  PLPGSQL_YYSYMBOL_K_ELSIF = 16,                   /* K_ELSIF  */
  PLPGSQL_YYSYMBOL_K_END = 17,                     /* K_END  */
  PLPGSQL_YYSYMBOL_K_EXCEPTION = 18,               /* K_EXCEPTION  */
  PLPGSQL_YYSYMBOL_K_EXECUTE = 19,                 /* K_EXECUTE  */
  PLPGSQL_YYSYMBOL_K_EXIT = 20,                    /* K_EXIT  */
  PLPGSQL_YYSYMBOL_K_FOR = 21,                     /* K_FOR  */
  PLPGSQL_YYSYMBOL_K_FETCH = 22,                   /* K_FETCH  */
  PLPGSQL_YYSYMBOL_K_FROM = 23,                    /* K_FROM  */
  PLPGSQL_YYSYMBOL_K_GET = 24,                     /* K_GET  */
  PLPGSQL_YYSYMBOL_K_IF = 25,                      /* K_IF  */
  PLPGSQL_YYSYMBOL_K_IN = 26,                      /* K_IN  */
  PLPGSQL_YYSYMBOL_K_INFO = 27,                    /* K_INFO  */
  PLPGSQL_YYSYMBOL_K_INTO = 28,                    /* K_INTO  */
  PLPGSQL_YYSYMBOL_K_IS = 29,                      /* K_IS  */
  PLPGSQL_YYSYMBOL_K_LOG = 30,                     /* K_LOG  */
  PLPGSQL_YYSYMBOL_K_LOOP = 31,                    /* K_LOOP  */
  PLPGSQL_YYSYMBOL_K_NEXT = 32,                    /* K_NEXT  */
  PLPGSQL_YYSYMBOL_K_NOT = 33,                     /* K_NOT  */
  PLPGSQL_YYSYMBOL_K_NOTICE = 34,                  /* K_NOTICE  */
  PLPGSQL_YYSYMBOL_K_NULL = 35,                    /* K_NULL  */
  PLPGSQL_YYSYMBOL_K_OPEN = 36,                    /* K_OPEN  */
  PLPGSQL_YYSYMBOL_K_OR = 37,                      /* K_OR  */
  PLPGSQL_YYSYMBOL_K_PERFORM = 38,                 /* K_PERFORM  */
  PLPGSQL_YYSYMBOL_K_ROW_COUNT = 39,               /* K_ROW_COUNT  */
  PLPGSQL_YYSYMBOL_K_RAISE = 40,                   /* K_RAISE  */
  PLPGSQL_YYSYMBOL_K_RENAME = 41,                  /* K_RENAME  */
  PLPGSQL_YYSYMBOL_K_RESULT_OID = 42,              /* K_RESULT_OID  */
  PLPGSQL_YYSYMBOL_K_RETURN = 43,                  /* K_RETURN  */
  PLPGSQL_YYSYMBOL_K_RETURN_NEXT = 44,             /* K_RETURN_NEXT  */
  PLPGSQL_YYSYMBOL_K_REVERSE = 45,                 /* K_REVERSE  */
  PLPGSQL_YYSYMBOL_K_SELECT = 46,                  /* K_SELECT  */
  PLPGSQL_YYSYMBOL_K_THEN = 47,                    /* K_THEN  */
  PLPGSQL_YYSYMBOL_K_TO = 48,                      /* K_TO  */
  PLPGSQL_YYSYMBOL_K_TYPE = 49,                    /* K_TYPE  */
  PLPGSQL_YYSYMBOL_K_WARNING = 50,                 /* K_WARNING  */
  PLPGSQL_YYSYMBOL_K_WHEN = 51,                    /* K_WHEN  */
  PLPGSQL_YYSYMBOL_K_WHILE = 52,                   /* K_WHILE  */
  PLPGSQL_YYSYMBOL_T_FUNCTION = 53,                /* T_FUNCTION  */
  PLPGSQL_YYSYMBOL_T_TRIGGER = 54,                 /* T_TRIGGER  */
  PLPGSQL_YYSYMBOL_T_STRING = 55,                  /* T_STRING  */
  PLPGSQL_YYSYMBOL_T_NUMBER = 56,                  /* T_NUMBER  */
  PLPGSQL_YYSYMBOL_T_SCALAR = 57,                  /* T_SCALAR  */
  PLPGSQL_YYSYMBOL_T_ROW = 58,                     /* T_ROW  */
  PLPGSQL_YYSYMBOL_T_RECORD = 59,                  /* T_RECORD  */
  PLPGSQL_YYSYMBOL_T_DTYPE = 60,                   /* T_DTYPE  */
  PLPGSQL_YYSYMBOL_T_LABEL = 61,                   /* T_LABEL  */
  PLPGSQL_YYSYMBOL_T_WORD = 62,                    /* T_WORD  */
  PLPGSQL_YYSYMBOL_T_ERROR = 63,                   /* T_ERROR  */
  PLPGSQL_YYSYMBOL_O_OPTION = 64,                  /* O_OPTION  */
  PLPGSQL_YYSYMBOL_O_DUMP = 65,                    /* O_DUMP  */
  PLPGSQL_YYSYMBOL_66_ = 66,                       /* ';'  */
  PLPGSQL_YYSYMBOL_67_ = 67,                       /* '<'  */
  PLPGSQL_YYSYMBOL_68_ = 68,                       /* '>'  */
  PLPGSQL_YYSYMBOL_69_ = 69,                       /* '('  */
  PLPGSQL_YYSYMBOL_70_ = 70,                       /* ')'  */
  PLPGSQL_YYSYMBOL_71_ = 71,                       /* ','  */
  PLPGSQL_YYSYMBOL_72_ = 72,                       /* '['  */
  PLPGSQL_YYSYMBOL_PLPGSQL_YYACCEPT = 73,                  /* $accept  */
  PLPGSQL_YYSYMBOL_pl_function = 74,               /* pl_function  */
  PLPGSQL_YYSYMBOL_comp_optsect = 75,              /* comp_optsect  */
  PLPGSQL_YYSYMBOL_comp_options = 76,              /* comp_options  */
  PLPGSQL_YYSYMBOL_comp_option = 77,               /* comp_option  */
  PLPGSQL_YYSYMBOL_opt_semi = 78,                  /* opt_semi  */
  PLPGSQL_YYSYMBOL_pl_block = 79,                  /* pl_block  */
  PLPGSQL_YYSYMBOL_decl_sect = 80,                 /* decl_sect  */
  PLPGSQL_YYSYMBOL_decl_start = 81,                /* decl_start  */
  PLPGSQL_YYSYMBOL_decl_stmts = 82,                /* decl_stmts  */
  PLPGSQL_YYSYMBOL_decl_stmt = 83,                 /* decl_stmt  */
  PLPGSQL_YYSYMBOL_decl_statement = 84,            /* decl_statement  */
  PLPGSQL_YYSYMBOL_85_1 = 85,                      /* $@1  */
  PLPGSQL_YYSYMBOL_decl_cursor_query = 86,         /* decl_cursor_query  */
  PLPGSQL_YYSYMBOL_decl_cursor_args = 87,          /* decl_cursor_args  */
  PLPGSQL_YYSYMBOL_decl_cursor_arglist = 88,       /* decl_cursor_arglist  */
  PLPGSQL_YYSYMBOL_decl_cursor_arg = 89,           /* decl_cursor_arg  */
  PLPGSQL_YYSYMBOL_decl_is_from = 90,              /* decl_is_from  */
  PLPGSQL_YYSYMBOL_decl_aliasitem = 91,            /* decl_aliasitem  */
  PLPGSQL_YYSYMBOL_decl_varname = 92,              /* decl_varname  */
  PLPGSQL_YYSYMBOL_decl_renname = 93,              /* decl_renname  */
  PLPGSQL_YYSYMBOL_decl_const = 94,                /* decl_const  */
  PLPGSQL_YYSYMBOL_decl_datatype = 95,             /* decl_datatype  */
  PLPGSQL_YYSYMBOL_decl_notnull = 96,              /* decl_notnull  */
  PLPGSQL_YYSYMBOL_decl_defval = 97,               /* decl_defval  */
  PLPGSQL_YYSYMBOL_decl_defkey = 98,               /* decl_defkey  */
  PLPGSQL_YYSYMBOL_proc_sect = 99,                 /* proc_sect  */
  PLPGSQL_YYSYMBOL_proc_stmts = 100,               /* proc_stmts  */
  PLPGSQL_YYSYMBOL_proc_stmt = 101,                /* proc_stmt  */
  PLPGSQL_YYSYMBOL_stmt_perform = 102,             /* stmt_perform  */
  PLPGSQL_YYSYMBOL_stmt_assign = 103,              /* stmt_assign  */
  PLPGSQL_YYSYMBOL_stmt_getdiag = 104,             /* stmt_getdiag  */
  PLPGSQL_YYSYMBOL_getdiag_list = 105,             /* getdiag_list  */
  PLPGSQL_YYSYMBOL_getdiag_list_item = 106,        /* getdiag_list_item  */
  PLPGSQL_YYSYMBOL_getdiag_kind = 107,             /* getdiag_kind  */
  PLPGSQL_YYSYMBOL_getdiag_target = 108,           /* getdiag_target  */
  PLPGSQL_YYSYMBOL_assign_var = 109,               /* assign_var  */
  PLPGSQL_YYSYMBOL_stmt_if = 110,                  /* stmt_if  */
  PLPGSQL_YYSYMBOL_stmt_else = 111,                /* stmt_else  */
  PLPGSQL_YYSYMBOL_stmt_loop = 112,                /* stmt_loop  */
  PLPGSQL_YYSYMBOL_stmt_while = 113,               /* stmt_while  */
  PLPGSQL_YYSYMBOL_stmt_for = 114,                 /* stmt_for  */
  PLPGSQL_YYSYMBOL_for_control = 115,              /* for_control  */
  PLPGSQL_YYSYMBOL_for_variable = 116,             /* for_variable  */
  PLPGSQL_YYSYMBOL_stmt_select = 117,              /* stmt_select  */
  PLPGSQL_YYSYMBOL_stmt_exit = 118,                /* stmt_exit  */
  PLPGSQL_YYSYMBOL_exit_type = 119,                /* exit_type  */
  PLPGSQL_YYSYMBOL_stmt_return = 120,              /* stmt_return  */
  PLPGSQL_YYSYMBOL_stmt_return_next = 121,         /* stmt_return_next  */
  PLPGSQL_YYSYMBOL_stmt_raise = 122,               /* stmt_raise  */
  PLPGSQL_YYSYMBOL_raise_msg = 123,                /* raise_msg  */
  PLPGSQL_YYSYMBOL_raise_level = 124,              /* raise_level  */
  PLPGSQL_YYSYMBOL_loop_body = 125,                /* loop_body  */
  PLPGSQL_YYSYMBOL_stmt_execsql = 126,             /* stmt_execsql  */
  PLPGSQL_YYSYMBOL_stmt_dynexecute = 127,          /* stmt_dynexecute  */
  PLPGSQL_YYSYMBOL_stmt_open = 128,                /* stmt_open  */
  PLPGSQL_YYSYMBOL_stmt_fetch = 129,               /* stmt_fetch  */
  PLPGSQL_YYSYMBOL_stmt_close = 130,               /* stmt_close  */
  PLPGSQL_YYSYMBOL_stmt_null = 131,                /* stmt_null  */
  PLPGSQL_YYSYMBOL_cursor_varptr = 132,            /* cursor_varptr  */
  PLPGSQL_YYSYMBOL_cursor_variable = 133,          /* cursor_variable  */
  PLPGSQL_YYSYMBOL_execsql_start = 134,            /* execsql_start  */
  PLPGSQL_YYSYMBOL_exception_sect = 135,           /* exception_sect  */
  PLPGSQL_YYSYMBOL_136_2 = 136,                    /* @2  */
  PLPGSQL_YYSYMBOL_proc_exceptions = 137,          /* proc_exceptions  */
  PLPGSQL_YYSYMBOL_proc_exception = 138,           /* proc_exception  */
  PLPGSQL_YYSYMBOL_proc_conditions = 139,          /* proc_conditions  */
  PLPGSQL_YYSYMBOL_expr_until_semi = 140,          /* expr_until_semi  */
  PLPGSQL_YYSYMBOL_expr_until_rightbracket = 141,  /* expr_until_rightbracket  */
  PLPGSQL_YYSYMBOL_expr_until_then = 142,          /* expr_until_then  */
  PLPGSQL_YYSYMBOL_expr_until_loop = 143,          /* expr_until_loop  */
  PLPGSQL_YYSYMBOL_opt_block_label = 144,          /* opt_block_label  */
  PLPGSQL_YYSYMBOL_opt_label = 145,                /* opt_label  */
  PLPGSQL_YYSYMBOL_opt_exitcond = 146,             /* opt_exitcond  */
  PLPGSQL_YYSYMBOL_opt_lblname = 147,              /* opt_lblname  */
  PLPGSQL_YYSYMBOL_lno = 148                       /* lno  */
};
typedef enum plpgsql_yysymbol_kind_t plpgsql_yysymbol_kind_t;




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
#  define PLPGSQL_YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ plpgsql_yytype_int8;
#elif defined PLPGSQL_YY_STDINT_H
typedef int_least8_t plpgsql_yytype_int8;
#else
typedef signed char plpgsql_yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ plpgsql_yytype_int16;
#elif defined PLPGSQL_YY_STDINT_H
typedef int_least16_t plpgsql_yytype_int16;
#else
typedef short plpgsql_yytype_int16;
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
typedef __UINT_LEAST8_TYPE__ plpgsql_yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined PLPGSQL_YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t plpgsql_yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char plpgsql_yytype_uint8;
#else
typedef short plpgsql_yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ plpgsql_yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined PLPGSQL_YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t plpgsql_yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short plpgsql_yytype_uint16;
#else
typedef int plpgsql_yytype_uint16;
#endif

#ifndef PLPGSQL_YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define PLPGSQL_YYPTRDIFF_T __PTRDIFF_TYPE__
#  define PLPGSQL_YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define PLPGSQL_YYPTRDIFF_T ptrdiff_t
#  define PLPGSQL_YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define PLPGSQL_YYPTRDIFF_T long
#  define PLPGSQL_YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef PLPGSQL_YYSIZE_T
# ifdef __SIZE_TYPE__
#  define PLPGSQL_YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define PLPGSQL_YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define PLPGSQL_YYSIZE_T size_t
# else
#  define PLPGSQL_YYSIZE_T unsigned
# endif
#endif

#define PLPGSQL_YYSIZE_MAXIMUM                                  \
  PLPGSQL_YY_CAST (PLPGSQL_YYPTRDIFF_T,                                 \
           (PLPGSQL_YYPTRDIFF_MAXIMUM < PLPGSQL_YY_CAST (PLPGSQL_YYSIZE_T, -1)  \
            ? PLPGSQL_YYPTRDIFF_MAXIMUM                         \
            : PLPGSQL_YY_CAST (PLPGSQL_YYSIZE_T, -1)))

#define PLPGSQL_YYSIZEOF(X) PLPGSQL_YY_CAST (PLPGSQL_YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef plpgsql_yytype_uint8 plpgsql_yy_state_t;

/* State numbers in computations.  */
typedef int plpgsql_yy_state_fast_t;

#ifndef PLPGSQL_YY_
# if defined PLPGSQL_YYENABLE_NLS && PLPGSQL_YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define PLPGSQL_YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef PLPGSQL_YY_
#  define PLPGSQL_YY_(Msgid) Msgid
# endif
#endif


#ifndef PLPGSQL_YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define PLPGSQL_YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define PLPGSQL_YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef PLPGSQL_YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define PLPGSQL_YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define PLPGSQL_YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define PLPGSQL_YY_USE(E) ((void) (E))
#else
# define PLPGSQL_YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about plpgsql_yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define PLPGSQL_YY_INITIAL_VALUE(Value) Value
#endif
#ifndef PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef PLPGSQL_YY_INITIAL_VALUE
# define PLPGSQL_YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define PLPGSQL_YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define PLPGSQL_YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef PLPGSQL_YY_IGNORE_USELESS_CAST_BEGIN
# define PLPGSQL_YY_IGNORE_USELESS_CAST_BEGIN
# define PLPGSQL_YY_IGNORE_USELESS_CAST_END
#endif


#define PLPGSQL_YY_ASSERT(E) ((void) (0 && (E)))

#if !defined plpgsql_yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef PLPGSQL_YYSTACK_USE_ALLOCA
#  if PLPGSQL_YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define PLPGSQL_YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define PLPGSQL_YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define PLPGSQL_YYSTACK_ALLOC alloca
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

# ifdef PLPGSQL_YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define PLPGSQL_YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef PLPGSQL_YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define PLPGSQL_YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define PLPGSQL_YYSTACK_ALLOC PLPGSQL_YYMALLOC
#  define PLPGSQL_YYSTACK_FREE PLPGSQL_YYFREE
#  ifndef PLPGSQL_YYSTACK_ALLOC_MAXIMUM
#   define PLPGSQL_YYSTACK_ALLOC_MAXIMUM PLPGSQL_YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined PLPGSQL_YYMALLOC || defined malloc) \
             && (defined PLPGSQL_YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef PLPGSQL_YYMALLOC
#   define PLPGSQL_YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (PLPGSQL_YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef PLPGSQL_YYFREE
#   define PLPGSQL_YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined plpgsql_yyoverflow */

#if (! defined plpgsql_yyoverflow \
     && (! defined __cplusplus \
         || (defined PLPGSQL_YYSTYPE_IS_TRIVIAL && PLPGSQL_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union plpgsql_yyalloc
{
  plpgsql_yy_state_t plpgsql_yyss_alloc;
  PLPGSQL_YYSTYPE plpgsql_yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define PLPGSQL_YYSTACK_GAP_MAXIMUM (PLPGSQL_YYSIZEOF (union plpgsql_yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define PLPGSQL_YYSTACK_BYTES(N) \
     ((N) * (PLPGSQL_YYSIZEOF (plpgsql_yy_state_t) + PLPGSQL_YYSIZEOF (PLPGSQL_YYSTYPE)) \
      + PLPGSQL_YYSTACK_GAP_MAXIMUM)

# define PLPGSQL_YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables PLPGSQL_YYSIZE and PLPGSQL_YYSTACKSIZE give the old and new number of
   elements in the stack, and PLPGSQL_YYPTR gives the new location of the
   stack.  Advance PLPGSQL_YYPTR to a properly aligned location for the next
   stack.  */
# define PLPGSQL_YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        PLPGSQL_YYPTRDIFF_T plpgsql_yynewbytes;                                         \
        PLPGSQL_YYCOPY (&plpgsql_yyptr->Stack_alloc, Stack, plpgsql_yysize);                    \
        Stack = &plpgsql_yyptr->Stack_alloc;                                    \
        plpgsql_yynewbytes = plpgsql_yystacksize * PLPGSQL_YYSIZEOF (*Stack) + PLPGSQL_YYSTACK_GAP_MAXIMUM; \
        plpgsql_yyptr += plpgsql_yynewbytes / PLPGSQL_YYSIZEOF (*plpgsql_yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined PLPGSQL_YYCOPY_NEEDED && PLPGSQL_YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef PLPGSQL_YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define PLPGSQL_YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, PLPGSQL_YY_CAST (PLPGSQL_YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define PLPGSQL_YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          PLPGSQL_YYPTRDIFF_T plpgsql_yyi;                      \
          for (plpgsql_yyi = 0; plpgsql_yyi < (Count); plpgsql_yyi++)   \
            (Dst)[plpgsql_yyi] = (Src)[plpgsql_yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !PLPGSQL_YYCOPY_NEEDED */

/* PLPGSQL_YYFINAL -- State number of the termination state.  */
#define PLPGSQL_YYFINAL  9
/* PLPGSQL_YYLAST -- Last index in PLPGSQL_YYTABLE.  */
#define PLPGSQL_YYLAST   400

/* PLPGSQL_YYNTOKENS -- Number of terminals.  */
#define PLPGSQL_YYNTOKENS  73
/* PLPGSQL_YYNNTS -- Number of nonterminals.  */
#define PLPGSQL_YYNNTS  76
/* PLPGSQL_YYNRULES -- Number of rules.  */
#define PLPGSQL_YYNRULES  139
/* PLPGSQL_YYNSTATES -- Number of states.  */
#define PLPGSQL_YYNSTATES  232

/* PLPGSQL_YYMAXUTOK -- Last valid token kind.  */
#define PLPGSQL_YYMAXUTOK   320


/* PLPGSQL_YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by plpgsql_yylex, with out-of-bounds checking.  */
#define PLPGSQL_YYTRANSLATE(PLPGSQL_YYX)                                \
  (0 <= (PLPGSQL_YYX) && (PLPGSQL_YYX) <= PLPGSQL_YYMAXUTOK                     \
   ? PLPGSQL_YY_CAST (plpgsql_yysymbol_kind_t, plpgsql_yytranslate[PLPGSQL_YYX])        \
   : PLPGSQL_YYSYMBOL_PLPGSQL_YYUNDEF)

/* PLPGSQL_YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by plpgsql_yylex.  */
static const plpgsql_yytype_int8 plpgsql_yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      69,    70,     2,     2,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    66,
      67,     2,    68,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if PLPGSQL_YYDEBUG
/* PLPGSQL_YYRLINE[PLPGSQL_YYN] -- Source line where rule number PLPGSQL_YYN was defined.  */
static const plpgsql_yytype_int16 plpgsql_yyrline[] =
{
       0,   230,   230,   234,   240,   241,   244,   245,   248,   254,
     255,   258,   280,   288,   296,   307,   313,   315,   319,   321,
     323,   327,   361,   366,   371,   370,   417,   429,   432,   461,
     465,   471,   478,   479,   481,   509,   519,   530,   531,   536,
     547,   548,   552,   554,   562,   563,   567,   570,   574,   581,
     590,   592,   594,   596,   598,   600,   602,   604,   606,   608,
     610,   612,   614,   616,   618,   620,   622,   624,   626,   630,
     643,   657,   670,   674,   680,   692,   696,   702,   710,   715,
     720,   725,   740,   756,   759,   788,   794,   811,   829,   868,
    1005,  1015,  1025,  1035,  1047,  1054,  1069,  1073,  1079,  1142,
    1187,  1230,  1236,  1240,  1244,  1248,  1252,  1256,  1262,  1269,
    1282,  1337,  1454,  1466,  1479,  1486,  1503,  1520,  1522,  1527,
    1529,  1528,  1561,  1565,  1571,  1584,  1594,  1601,  1605,  1609,
    1613,  1617,  1621,  1629,  1632,  1638,  1645,  1647,  1651,  1661
};
#endif

/** Accessing symbol of state STATE.  */
#define PLPGSQL_YY_ACCESSING_SYMBOL(State) PLPGSQL_YY_CAST (plpgsql_yysymbol_kind_t, plpgsql_yystos[State])

#if PLPGSQL_YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   PLPGSQL_YYSYMBOL.  No bounds checking.  */
static const char *plpgsql_yysymbol_name (plpgsql_yysymbol_kind_t plpgsql_yysymbol) PLPGSQL_YY_ATTRIBUTE_UNUSED;

/* PLPGSQL_YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at PLPGSQL_YYNTOKENS, nonterminals.  */
static const char *const plpgsql_yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "K_ALIAS", "K_ASSIGN",
  "K_BEGIN", "K_CLOSE", "K_CONSTANT", "K_CONTINUE", "K_CURSOR", "K_DEBUG",
  "K_DECLARE", "K_DEFAULT", "K_DIAGNOSTICS", "K_DOTDOT", "K_ELSE",
  "K_ELSIF", "K_END", "K_EXCEPTION", "K_EXECUTE", "K_EXIT", "K_FOR",
  "K_FETCH", "K_FROM", "K_GET", "K_IF", "K_IN", "K_INFO", "K_INTO", "K_IS",
  "K_LOG", "K_LOOP", "K_NEXT", "K_NOT", "K_NOTICE", "K_NULL", "K_OPEN",
  "K_OR", "K_PERFORM", "K_ROW_COUNT", "K_RAISE", "K_RENAME",
  "K_RESULT_OID", "K_RETURN", "K_RETURN_NEXT", "K_REVERSE", "K_SELECT",
  "K_THEN", "K_TO", "K_TYPE", "K_WARNING", "K_WHEN", "K_WHILE",
  "T_FUNCTION", "T_TRIGGER", "T_STRING", "T_NUMBER", "T_SCALAR", "T_ROW",
  "T_RECORD", "T_DTYPE", "T_LABEL", "T_WORD", "T_ERROR", "O_OPTION",
  "O_DUMP", "';'", "'<'", "'>'", "'('", "')'", "','", "'['", "$accept",
  "pl_function", "comp_optsect", "comp_options", "comp_option", "opt_semi",
  "pl_block", "decl_sect", "decl_start", "decl_stmts", "decl_stmt",
  "decl_statement", "$@1", "decl_cursor_query", "decl_cursor_args",
  "decl_cursor_arglist", "decl_cursor_arg", "decl_is_from",
  "decl_aliasitem", "decl_varname", "decl_renname", "decl_const",
  "decl_datatype", "decl_notnull", "decl_defval", "decl_defkey",
  "proc_sect", "proc_stmts", "proc_stmt", "stmt_perform", "stmt_assign",
  "stmt_getdiag", "getdiag_list", "getdiag_list_item", "getdiag_kind",
  "getdiag_target", "assign_var", "stmt_if", "stmt_else", "stmt_loop",
  "stmt_while", "stmt_for", "for_control", "for_variable", "stmt_select",
  "stmt_exit", "exit_type", "stmt_return", "stmt_return_next",
  "stmt_raise", "raise_msg", "raise_level", "loop_body", "stmt_execsql",
  "stmt_dynexecute", "stmt_open", "stmt_fetch", "stmt_close", "stmt_null",
  "cursor_varptr", "cursor_variable", "execsql_start", "exception_sect",
  "@2", "proc_exceptions", "proc_exception", "proc_conditions",
  "expr_until_semi", "expr_until_rightbracket", "expr_until_then",
  "expr_until_loop", "opt_block_label", "opt_label", "opt_exitcond",
  "opt_lblname", "lno", PLPGSQL_YY_NULLPTR
};

static const char *
plpgsql_yysymbol_name (plpgsql_yysymbol_kind_t plpgsql_yysymbol)
{
  return plpgsql_yytname[plpgsql_yysymbol];
}
#endif

#define PLPGSQL_YYPACT_NINF (-143)

#define plpgsql_yypact_value_is_default(Yyn) \
  ((Yyn) == PLPGSQL_YYPACT_NINF)

#define PLPGSQL_YYTABLE_NINF (-132)

#define plpgsql_yytable_value_is_error(Yyn) \
  0

/* PLPGSQL_YYPACT[STATE-NUM] -- Index in PLPGSQL_YYTABLE of the portion describing
   STATE-NUM.  */
static const plpgsql_yytype_int16 plpgsql_yypact[] =
{
     -29,   -31,   -31,    51,   -10,    -6,   -31,  -143,    -6,  -143,
    -143,     7,     3,    80,    75,  -143,     3,    26,  -143,  -143,
    -143,  -143,     4,  -143,  -143,    21,   217,  -143,    29,  -143,
      25,     4,  -143,  -143,    45,    30,  -143,  -143,  -143,  -143,
    -143,    87,  -143,    27,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,    38,    83,    59,  -143,  -143,
    -143,  -143,    34,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
       5,  -143,    62,    26,  -143,    92,  -143,  -143,  -143,  -143,
      57,  -143,    57,  -143,  -143,  -143,    58,  -143,    12,  -143,
    -143,  -143,  -143,  -143,   102,  -143,  -143,   116,   -12,  -143,
    -143,  -143,  -143,    29,    55,    63,    60,    91,  -143,    61,
     100,    73,   159,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,    76,  -143,   -12,  -143,  -143,  -143,  -143,   -34,
     333,    50,   333,  -143,    66,    65,  -143,    69,    74,     8,
     103,    16,  -143,  -143,  -143,   -48,  -143,   133,    44,  -143,
    -143,    88,  -143,  -143,  -143,  -143,  -143,   123,  -143,  -143,
    -143,  -143,  -143,   115,  -143,   333,  -143,  -143,  -143,     2,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,    73,    -4,   333,  -143,   125,  -143,    88,  -143,
    -143,   112,  -143,  -143,  -143,    74,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,   119,    26,  -143,   -12,  -143,   159,
      81,   -16,  -143,    82,    44,  -143,    26,   275,  -143,  -143,
    -143,  -143
};

/* PLPGSQL_YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when PLPGSQL_YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const plpgsql_yytype_uint8 plpgsql_yydefact[] =
{
       0,     4,     4,     0,     0,   131,     5,     7,   131,     1,
       8,     0,     9,     0,    12,     6,     9,     0,    10,     2,
     139,    15,    13,     3,   138,     0,   131,    19,     0,    35,
       0,    14,    17,    20,    37,     0,   139,    97,   139,    96,
     139,     0,   139,     0,   139,   139,   139,   139,   139,   139,
      78,    79,    80,   117,   118,     0,   119,    47,    49,    63,
      51,    64,   139,    52,    53,    54,    55,    56,    57,   139,
      58,    59,    60,    61,    62,    65,    66,    67,    68,   139,
      12,    36,     0,     0,    16,     0,    38,    24,    39,   132,
       0,   110,     0,   139,   129,   114,     0,   127,     0,    98,
      99,    94,    50,   139,     0,    48,   128,     0,   133,   109,
     139,   139,   139,     0,     0,     0,    27,    40,   116,     0,
       0,     0,   131,   115,   111,    69,   107,   102,   105,   106,
     104,   103,     0,   120,   133,    81,   127,   134,   135,     0,
     131,     0,   131,   130,     0,     0,    34,     0,     0,     0,
       0,     0,   113,   112,    77,     0,    73,     0,    83,   101,
     100,     0,    11,    70,   127,   136,    95,     0,    88,    90,
      93,    92,    91,     0,    86,   131,    23,    18,    22,     0,
      29,    39,    33,    32,    26,    41,    44,    45,    42,    21,
      43,    71,     0,     0,   131,   139,     0,   139,   121,   123,
     137,     0,    89,    87,    28,     0,    31,    25,    72,    75,
      76,    74,    85,   129,     0,     0,   122,   133,    30,   131,
       0,     0,   126,     0,    83,    82,     0,   131,   108,    84,
     125,   124
};

/* PLPGSQL_YYPGOTO[NTERM-NUM].  */
static const plpgsql_yytype_int16 plpgsql_yypgoto[] =
{
    -143,  -143,   144,  -143,   143,   134,    35,  -143,  -143,  -143,
     120,  -143,  -143,  -143,  -143,  -143,   -53,  -143,  -143,  -142,
      40,  -143,   -27,  -143,  -143,  -143,   -26,  -143,    98,  -143,
    -143,  -143,  -143,   -36,  -143,  -143,  -143,  -143,   -67,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -134,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
      67,  -143,  -143,  -143,  -143,   -40,  -143,  -117,  -143,   -52,
    -143,    48,  -130,  -143,   -81,   -35
};

/* PLPGSQL_YYDEFGOTO[NTERM-NUM].  */
static const plpgsql_yytype_uint8 plpgsql_yydefgoto[] =
{
       0,     3,     5,     6,     7,    19,    55,    13,    22,    31,
      32,    33,   116,   207,   149,   179,   180,   184,   147,    34,
      82,    88,   117,   151,   189,   190,   167,    57,    58,    59,
      60,    61,   155,   156,   211,   157,    62,    63,   196,    64,
      65,    66,   140,   173,    67,    68,    69,    70,    71,    72,
     160,   132,   168,    73,    74,    75,    76,    77,    78,   124,
     119,    79,   104,   161,   198,   199,   221,   125,   135,   122,
     175,    80,   139,   166,    25,    26
};

/* PLPGSQL_YYTABLE[PLPGSQL_YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If PLPGSQL_YYTABLE_NINF, syntax error.  */
static const plpgsql_yytype_int16 plpgsql_yytable[] =
{
      56,    90,   114,    91,   162,    92,   181,    94,   174,    96,
      97,    98,    99,   100,   101,    27,    21,   164,   191,   163,
     186,   226,   126,   192,     1,     2,   110,   107,   187,   182,
     127,   227,   165,     4,   108,   209,   111,   183,   210,   128,
      12,   203,   129,    16,   109,    28,   130,   200,    85,   137,
     138,     9,    86,    14,    87,    10,    14,   112,   121,   194,
     195,    11,   131,   181,  -131,    36,    29,    37,   133,    18,
    -131,    30,   204,   205,    17,   141,   142,   143,    38,    39,
    -131,    40,   188,    41,    42,    20,    21,   223,    24,    35,
    -131,    81,    83,    95,    43,    44,   158,    45,    89,    46,
      93,   103,    47,    48,   102,    49,   106,   169,   170,   171,
     113,  -131,   172,   115,   118,   123,    50,    51,    52,   134,
     136,    53,    54,   145,   150,   146,    11,   152,   153,   148,
     154,   159,   176,   177,   222,   178,    29,   193,   185,   197,
     201,   202,   214,   217,   220,   230,     8,   225,   228,    15,
      23,    84,   218,   144,   206,   105,   208,   229,   216,   120,
     213,   219,   215,     0,     0,    36,     0,    37,   212,     0,
       0,     0,     0,     0,   -46,   -46,   -46,     0,    38,    39,
       0,    40,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,   224,    43,    44,     0,    45,     0,    46,
       0,   231,    47,    48,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,     0,
       0,    53,    54,    36,     0,    37,    11,     0,     0,     0,
       0,     0,     0,     0,   -46,   -46,    38,    39,     0,    40,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,    45,     0,    46,     0,     0,
      47,    48,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,     0,     0,    53,
      54,    36,     0,    37,    11,     0,     0,     0,     0,     0,
       0,     0,   -46,     0,    38,    39,     0,    40,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,    44,     0,    45,     0,    46,     0,     0,    47,    48,
       0,    49,     0,     0,     0,     0,   -46,     0,     0,     0,
       0,     0,    50,    51,    52,     0,     0,    53,    54,    36,
       0,    37,    11,     0,     0,     0,     0,     0,     0,     0,
     -46,     0,    38,    39,     0,    40,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
       0,    45,     0,    46,     0,     0,    47,    48,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,    52,     0,     0,    53,    54,     0,     0,     0,
      11
};

static const plpgsql_yytype_int16 plpgsql_yycheck[] =
{
      26,    36,    83,    38,   134,    40,   148,    42,   142,    44,
      45,    46,    47,    48,    49,    11,    11,    51,    66,   136,
       4,    37,    10,    71,    53,    54,    21,    62,    12,    21,
      18,    47,    66,    64,    69,    39,    31,    29,    42,    27,
       5,   175,    30,     8,    79,    41,    34,   164,     3,    61,
      62,     0,     7,     5,     9,    65,     8,    52,    93,    15,
      16,    67,    50,   205,     5,     6,    62,     8,   103,    66,
      11,    67,    70,    71,    67,   110,   111,   112,    19,    20,
      21,    22,    66,    24,    25,     5,    11,   217,    62,    68,
      31,    62,    67,    66,    35,    36,   122,    38,    68,    40,
      13,    18,    43,    44,    66,    46,    72,    57,    58,    59,
      48,    52,    62,    21,    57,    57,    57,    58,    59,    17,
       4,    62,    63,    68,    33,    62,    67,    66,    28,    69,
      57,    55,    66,    68,   215,    66,    62,     4,    35,    51,
      17,    26,    17,    31,    25,   226,     2,    66,    66,     6,
      16,    31,   205,   113,   181,    57,   192,   224,   198,    92,
     195,   213,   197,    -1,    -1,     6,    -1,     8,   194,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    35,    36,    -1,    38,    -1,    40,
      -1,   227,    43,    44,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    62,    63,     6,    -1,     8,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,
      43,    44,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    -1,    -1,    62,
      63,     6,    -1,     8,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    -1,    22,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    38,    -1,    40,    -1,    -1,    43,    44,
      -1,    46,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    -1,    -1,    62,    63,     6,
      -1,     8,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    20,    -1,    22,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    38,    -1,    40,    -1,    -1,    43,    44,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,
      67
};

/* PLPGSQL_YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const plpgsql_yytype_uint8 plpgsql_yystos[] =
{
       0,    53,    54,    74,    64,    75,    76,    77,    75,     0,
      65,    67,    79,    80,   144,    77,    79,    67,    66,    78,
       5,    11,    81,    78,    62,   147,   148,    11,    41,    62,
      67,    82,    83,    84,    92,    68,     6,     8,    19,    20,
      22,    24,    25,    35,    36,    38,    40,    43,    44,    46,
      57,    58,    59,    62,    63,    79,    99,   100,   101,   102,
     103,   104,   109,   110,   112,   113,   114,   117,   118,   119,
     120,   121,   122,   126,   127,   128,   129,   130,   131,   134,
     144,    62,    93,    67,    83,     3,     7,     9,    94,    68,
     148,   148,   148,    13,   148,    66,   148,   148,   148,   148,
     148,   148,    66,    18,   135,   101,    72,   148,   148,   148,
      21,    31,    52,    48,   147,    21,    85,    95,    57,   133,
     133,   148,   142,    57,   132,   140,    10,    18,    27,    30,
      34,    50,   124,   148,    17,   141,     4,    61,    62,   145,
     115,   148,   148,   148,    93,    68,    62,    91,    69,    87,
      33,    96,    66,    28,    57,   105,   106,   108,    99,    55,
     123,   136,   145,   140,    51,    66,   146,    99,   125,    57,
      58,    59,    62,   116,   125,   143,    66,    68,    66,    88,
      89,    92,    21,    29,    90,    35,     4,    12,    66,    97,
      98,    66,    71,     4,    15,    16,   111,    51,   137,   138,
     140,    17,    26,   125,    70,    71,    95,    86,   106,    39,
      42,   107,    99,   148,    17,   148,   138,    31,    89,   142,
      25,   139,   147,   145,    99,    66,    37,    47,    66,   111,
     147,    99
};

/* PLPGSQL_YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const plpgsql_yytype_uint8 plpgsql_yyr1[] =
{
       0,    73,    74,    74,    75,    75,    76,    76,    77,    78,
      78,    79,    80,    80,    80,    81,    82,    82,    83,    83,
      83,    84,    84,    84,    85,    84,    86,    87,    87,    88,
      88,    89,    90,    90,    91,    92,    93,    94,    94,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     103,   104,   105,   105,   106,   107,   107,   108,   109,   109,
     109,   109,   110,   111,   111,   111,   112,   113,   114,   115,
     116,   116,   116,   116,   117,   118,   119,   119,   120,   121,
     122,   123,   124,   124,   124,   124,   124,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   134,   135,
     136,   135,   137,   137,   138,   139,   139,   140,   141,   142,
     143,   144,   144,   145,   145,   145,   146,   146,   147,   148
};

/* PLPGSQL_YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const plpgsql_yytype_int8 plpgsql_yyr2[] =
{
       0,     2,     4,     4,     0,     1,     2,     1,     2,     0,
       1,     7,     1,     2,     3,     1,     2,     1,     5,     1,
       1,     5,     5,     5,     0,     6,     0,     0,     3,     1,
       3,     2,     1,     1,     1,     1,     1,     0,     1,     0,
       0,     2,     1,     1,     1,     1,     0,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     5,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     8,     0,     5,     2,     4,     5,     4,     3,
       1,     1,     1,     1,     2,     4,     1,     1,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     5,     2,
       2,     3,     4,     4,     2,     1,     1,     1,     1,     0,
       0,     4,     2,     1,     5,     3,     1,     0,     0,     0,
       0,     0,     5,     0,     1,     1,     1,     2,     1,     0
};


enum { PLPGSQL_YYENOMEM = -2 };

#define plpgsql_yyerrok         (plpgsql_yyerrstatus = 0)
#define plpgsql_yyclearin       (plpgsql_yychar = PLPGSQL_YYEMPTY)

#define PLPGSQL_YYACCEPT        goto plpgsql_yyacceptlab
#define PLPGSQL_YYABORT         goto plpgsql_yyabortlab
#define PLPGSQL_YYERROR         goto plpgsql_yyerrorlab
#define PLPGSQL_YYNOMEM         goto plpgsql_yyexhaustedlab


#define PLPGSQL_YYRECOVERING()  (!!plpgsql_yyerrstatus)

#define PLPGSQL_YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (plpgsql_yychar == PLPGSQL_YYEMPTY)                                        \
      {                                                           \
        plpgsql_yychar = (Token);                                         \
        plpgsql_yylval = (Value);                                         \
        PLPGSQL_YYPOPSTACK (plpgsql_yylen);                                       \
        plpgsql_yystate = *plpgsql_yyssp;                                         \
        goto plpgsql_yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        plpgsql_yyerror (PLPGSQL_YY_("syntax error: cannot back up")); \
        PLPGSQL_YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use PLPGSQL_YYerror or PLPGSQL_YYUNDEF. */
#define PLPGSQL_YYERRCODE PLPGSQL_YYUNDEF


/* Enable debugging if requested.  */
#if PLPGSQL_YYDEBUG

# ifndef PLPGSQL_YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define PLPGSQL_YYFPRINTF fprintf
# endif

# define PLPGSQL_YYDPRINTF(Args)                        \
do {                                            \
  if (plpgsql_yydebug)                                  \
    PLPGSQL_YYFPRINTF Args;                             \
} while (0)




# define PLPGSQL_YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (plpgsql_yydebug)                                                            \
    {                                                                     \
      PLPGSQL_YYFPRINTF (stderr, "%s ", Title);                                   \
      plpgsql_yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      PLPGSQL_YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on PLPGSQL_YYO.  |
`-----------------------------------*/

static void
plpgsql_yy_symbol_value_print (FILE *plpgsql_yyo,
                       plpgsql_yysymbol_kind_t plpgsql_yykind, PLPGSQL_YYSTYPE const * const plpgsql_yyvaluep)
{
  FILE *plpgsql_yyoutput = plpgsql_yyo;
  PLPGSQL_YY_USE (plpgsql_yyoutput);
  if (!plpgsql_yyvaluep)
    return;
  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  PLPGSQL_YY_USE (plpgsql_yykind);
  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on PLPGSQL_YYO.  |
`---------------------------*/

static void
plpgsql_yy_symbol_print (FILE *plpgsql_yyo,
                 plpgsql_yysymbol_kind_t plpgsql_yykind, PLPGSQL_YYSTYPE const * const plpgsql_yyvaluep)
{
  PLPGSQL_YYFPRINTF (plpgsql_yyo, "%s %s (",
             plpgsql_yykind < PLPGSQL_YYNTOKENS ? "token" : "nterm", plpgsql_yysymbol_name (plpgsql_yykind));

  plpgsql_yy_symbol_value_print (plpgsql_yyo, plpgsql_yykind, plpgsql_yyvaluep);
  PLPGSQL_YYFPRINTF (plpgsql_yyo, ")");
}

/*------------------------------------------------------------------.
| plpgsql_yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
plpgsql_yy_stack_print (plpgsql_yy_state_t *plpgsql_yybottom, plpgsql_yy_state_t *plpgsql_yytop)
{
  PLPGSQL_YYFPRINTF (stderr, "Stack now");
  for (; plpgsql_yybottom <= plpgsql_yytop; plpgsql_yybottom++)
    {
      int plpgsql_yybot = *plpgsql_yybottom;
      PLPGSQL_YYFPRINTF (stderr, " %d", plpgsql_yybot);
    }
  PLPGSQL_YYFPRINTF (stderr, "\n");
}

# define PLPGSQL_YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (plpgsql_yydebug)                                                  \
    plpgsql_yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the PLPGSQL_YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
plpgsql_yy_reduce_print (plpgsql_yy_state_t *plpgsql_yyssp, PLPGSQL_YYSTYPE *plpgsql_yyvsp,
                 int plpgsql_yyrule)
{
  int plpgsql_yylno = plpgsql_yyrline[plpgsql_yyrule];
  int plpgsql_yynrhs = plpgsql_yyr2[plpgsql_yyrule];
  int plpgsql_yyi;
  PLPGSQL_YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             plpgsql_yyrule - 1, plpgsql_yylno);
  /* The symbols being reduced.  */
  for (plpgsql_yyi = 0; plpgsql_yyi < plpgsql_yynrhs; plpgsql_yyi++)
    {
      PLPGSQL_YYFPRINTF (stderr, "   $%d = ", plpgsql_yyi + 1);
      plpgsql_yy_symbol_print (stderr,
                       PLPGSQL_YY_ACCESSING_SYMBOL (+plpgsql_yyssp[plpgsql_yyi + 1 - plpgsql_yynrhs]),
                       &plpgsql_yyvsp[(plpgsql_yyi + 1) - (plpgsql_yynrhs)]);
      PLPGSQL_YYFPRINTF (stderr, "\n");
    }
}

# define PLPGSQL_YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (plpgsql_yydebug)                          \
    plpgsql_yy_reduce_print (plpgsql_yyssp, plpgsql_yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int plpgsql_yydebug;
#else /* !PLPGSQL_YYDEBUG */
# define PLPGSQL_YYDPRINTF(Args) ((void) 0)
# define PLPGSQL_YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define PLPGSQL_YY_STACK_PRINT(Bottom, Top)
# define PLPGSQL_YY_REDUCE_PRINT(Rule)
#endif /* !PLPGSQL_YYDEBUG */


/* PLPGSQL_YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef PLPGSQL_YYINITDEPTH
# define PLPGSQL_YYINITDEPTH 200
#endif

/* PLPGSQL_YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   PLPGSQL_YYSTACK_ALLOC_MAXIMUM < PLPGSQL_YYSTACK_BYTES (PLPGSQL_YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef PLPGSQL_YYMAXDEPTH
# define PLPGSQL_YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
plpgsql_yydestruct (const char *plpgsql_yymsg,
            plpgsql_yysymbol_kind_t plpgsql_yykind, PLPGSQL_YYSTYPE *plpgsql_yyvaluep)
{
  PLPGSQL_YY_USE (plpgsql_yyvaluep);
  if (!plpgsql_yymsg)
    plpgsql_yymsg = "Deleting";
  PLPGSQL_YY_SYMBOL_PRINT (plpgsql_yymsg, plpgsql_yykind, plpgsql_yyvaluep, plpgsql_yylocationp);

  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  PLPGSQL_YY_USE (plpgsql_yykind);
  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int plpgsql_yychar;

/* The semantic value of the lookahead symbol.  */
PLPGSQL_YYSTYPE plpgsql_yylval;
/* Number of syntax errors so far.  */
int plpgsql_yynerrs;




/*----------.
| plpgsql_yyparse.  |
`----------*/

int
plpgsql_yyparse (void)
{
    plpgsql_yy_state_fast_t plpgsql_yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int plpgsql_yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow plpgsql_yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    PLPGSQL_YYPTRDIFF_T plpgsql_yystacksize = PLPGSQL_YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    plpgsql_yy_state_t plpgsql_yyssa[PLPGSQL_YYINITDEPTH];
    plpgsql_yy_state_t *plpgsql_yyss = plpgsql_yyssa;
    plpgsql_yy_state_t *plpgsql_yyssp = plpgsql_yyss;

    /* The semantic value stack: array, bottom, top.  */
    PLPGSQL_YYSTYPE plpgsql_yyvsa[PLPGSQL_YYINITDEPTH];
    PLPGSQL_YYSTYPE *plpgsql_yyvs = plpgsql_yyvsa;
    PLPGSQL_YYSTYPE *plpgsql_yyvsp = plpgsql_yyvs;

  int plpgsql_yyn;
  /* The return value of plpgsql_yyparse.  */
  int plpgsql_yyresult;
  /* Lookahead symbol kind.  */
  plpgsql_yysymbol_kind_t plpgsql_yytoken = PLPGSQL_YYSYMBOL_PLPGSQL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  PLPGSQL_YYSTYPE plpgsql_yyval;



#define PLPGSQL_YYPOPSTACK(N)   (plpgsql_yyvsp -= (N), plpgsql_yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int plpgsql_yylen = 0;

  PLPGSQL_YYDPRINTF ((stderr, "Starting parse\n"));

  plpgsql_yychar = PLPGSQL_YYEMPTY; /* Cause a token to be read.  */

  goto plpgsql_yysetstate;


/*------------------------------------------------------------.
| plpgsql_yynewstate -- push a new state, which is found in plpgsql_yystate.  |
`------------------------------------------------------------*/
plpgsql_yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  plpgsql_yyssp++;


/*--------------------------------------------------------------------.
| plpgsql_yysetstate -- set current state (the top of the stack) to plpgsql_yystate.  |
`--------------------------------------------------------------------*/
plpgsql_yysetstate:
  PLPGSQL_YYDPRINTF ((stderr, "Entering state %d\n", plpgsql_yystate));
  PLPGSQL_YY_ASSERT (0 <= plpgsql_yystate && plpgsql_yystate < PLPGSQL_YYNSTATES);
  PLPGSQL_YY_IGNORE_USELESS_CAST_BEGIN
  *plpgsql_yyssp = PLPGSQL_YY_CAST (plpgsql_yy_state_t, plpgsql_yystate);
  PLPGSQL_YY_IGNORE_USELESS_CAST_END
  PLPGSQL_YY_STACK_PRINT (plpgsql_yyss, plpgsql_yyssp);

  if (plpgsql_yyss + plpgsql_yystacksize - 1 <= plpgsql_yyssp)
#if !defined plpgsql_yyoverflow && !defined PLPGSQL_YYSTACK_RELOCATE
    PLPGSQL_YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      PLPGSQL_YYPTRDIFF_T plpgsql_yysize = plpgsql_yyssp - plpgsql_yyss + 1;

# if defined plpgsql_yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        plpgsql_yy_state_t *plpgsql_yyss1 = plpgsql_yyss;
        PLPGSQL_YYSTYPE *plpgsql_yyvs1 = plpgsql_yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if plpgsql_yyoverflow is a macro.  */
        plpgsql_yyoverflow (PLPGSQL_YY_("memory exhausted"),
                    &plpgsql_yyss1, plpgsql_yysize * PLPGSQL_YYSIZEOF (*plpgsql_yyssp),
                    &plpgsql_yyvs1, plpgsql_yysize * PLPGSQL_YYSIZEOF (*plpgsql_yyvsp),
                    &plpgsql_yystacksize);
        plpgsql_yyss = plpgsql_yyss1;
        plpgsql_yyvs = plpgsql_yyvs1;
      }
# else /* defined PLPGSQL_YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (PLPGSQL_YYMAXDEPTH <= plpgsql_yystacksize)
        PLPGSQL_YYNOMEM;
      plpgsql_yystacksize *= 2;
      if (PLPGSQL_YYMAXDEPTH < plpgsql_yystacksize)
        plpgsql_yystacksize = PLPGSQL_YYMAXDEPTH;

      {
        plpgsql_yy_state_t *plpgsql_yyss1 = plpgsql_yyss;
        union plpgsql_yyalloc *plpgsql_yyptr =
          PLPGSQL_YY_CAST (union plpgsql_yyalloc *,
                   PLPGSQL_YYSTACK_ALLOC (PLPGSQL_YY_CAST (PLPGSQL_YYSIZE_T, PLPGSQL_YYSTACK_BYTES (plpgsql_yystacksize))));
        if (! plpgsql_yyptr)
          PLPGSQL_YYNOMEM;
        PLPGSQL_YYSTACK_RELOCATE (plpgsql_yyss_alloc, plpgsql_yyss);
        PLPGSQL_YYSTACK_RELOCATE (plpgsql_yyvs_alloc, plpgsql_yyvs);
#  undef PLPGSQL_YYSTACK_RELOCATE
        if (plpgsql_yyss1 != plpgsql_yyssa)
          PLPGSQL_YYSTACK_FREE (plpgsql_yyss1);
      }
# endif

      plpgsql_yyssp = plpgsql_yyss + plpgsql_yysize - 1;
      plpgsql_yyvsp = plpgsql_yyvs + plpgsql_yysize - 1;

      PLPGSQL_YY_IGNORE_USELESS_CAST_BEGIN
      PLPGSQL_YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  PLPGSQL_YY_CAST (long, plpgsql_yystacksize)));
      PLPGSQL_YY_IGNORE_USELESS_CAST_END

      if (plpgsql_yyss + plpgsql_yystacksize - 1 <= plpgsql_yyssp)
        PLPGSQL_YYABORT;
    }
#endif /* !defined plpgsql_yyoverflow && !defined PLPGSQL_YYSTACK_RELOCATE */


  if (plpgsql_yystate == PLPGSQL_YYFINAL)
    PLPGSQL_YYACCEPT;

  goto plpgsql_yybackup;


/*-----------.
| plpgsql_yybackup.  |
`-----------*/
plpgsql_yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  plpgsql_yyn = plpgsql_yypact[plpgsql_yystate];
  if (plpgsql_yypact_value_is_default (plpgsql_yyn))
    goto plpgsql_yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* PLPGSQL_YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (plpgsql_yychar == PLPGSQL_YYEMPTY)
    {
      PLPGSQL_YYDPRINTF ((stderr, "Reading a token\n"));
      plpgsql_yychar = plpgsql_yylex ();
    }

  if (plpgsql_yychar <= PLPGSQL_YYEOF)
    {
      plpgsql_yychar = PLPGSQL_YYEOF;
      plpgsql_yytoken = PLPGSQL_YYSYMBOL_PLPGSQL_YYEOF;
      PLPGSQL_YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (plpgsql_yychar == PLPGSQL_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      plpgsql_yychar = PLPGSQL_YYUNDEF;
      plpgsql_yytoken = PLPGSQL_YYSYMBOL_PLPGSQL_YYerror;
      goto plpgsql_yyerrlab1;
    }
  else
    {
      plpgsql_yytoken = PLPGSQL_YYTRANSLATE (plpgsql_yychar);
      PLPGSQL_YY_SYMBOL_PRINT ("Next token is", plpgsql_yytoken, &plpgsql_yylval, &plpgsql_yylloc);
    }

  /* If the proper action on seeing token PLPGSQL_YYTOKEN is to reduce or to
     detect an error, take that action.  */
  plpgsql_yyn += plpgsql_yytoken;
  if (plpgsql_yyn < 0 || PLPGSQL_YYLAST < plpgsql_yyn || plpgsql_yycheck[plpgsql_yyn] != plpgsql_yytoken)
    goto plpgsql_yydefault;
  plpgsql_yyn = plpgsql_yytable[plpgsql_yyn];
  if (plpgsql_yyn <= 0)
    {
      if (plpgsql_yytable_value_is_error (plpgsql_yyn))
        goto plpgsql_yyerrlab;
      plpgsql_yyn = -plpgsql_yyn;
      goto plpgsql_yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (plpgsql_yyerrstatus)
    plpgsql_yyerrstatus--;

  /* Shift the lookahead token.  */
  PLPGSQL_YY_SYMBOL_PRINT ("Shifting", plpgsql_yytoken, &plpgsql_yylval, &plpgsql_yylloc);
  plpgsql_yystate = plpgsql_yyn;
  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++plpgsql_yyvsp = plpgsql_yylval;
  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  plpgsql_yychar = PLPGSQL_YYEMPTY;
  goto plpgsql_yynewstate;


/*-----------------------------------------------------------.
| plpgsql_yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
plpgsql_yydefault:
  plpgsql_yyn = plpgsql_yydefact[plpgsql_yystate];
  if (plpgsql_yyn == 0)
    goto plpgsql_yyerrlab;
  goto plpgsql_yyreduce;


/*-----------------------------.
| plpgsql_yyreduce -- do a reduction.  |
`-----------------------------*/
plpgsql_yyreduce:
  /* plpgsql_yyn is the number of a rule to reduce with.  */
  plpgsql_yylen = plpgsql_yyr2[plpgsql_yyn];

  /* If PLPGSQL_YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets PLPGSQL_YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to PLPGSQL_YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that PLPGSQL_YYVAL may be used uninitialized.  */
  plpgsql_yyval = plpgsql_yyvsp[1-plpgsql_yylen];


  PLPGSQL_YY_REDUCE_PRINT (plpgsql_yyn);
  switch (plpgsql_yyn)
    {
  case 2: /* pl_function: T_FUNCTION comp_optsect pl_block opt_semi  */
#line 231 "gram.y"
                                        {
						plpgsql_yylval.program = (PLpgSQL_stmt_block *)(plpgsql_yyvsp[-1].stmt);
					}
#line 1713 "y.tab.c"
    break;

  case 3: /* pl_function: T_TRIGGER comp_optsect pl_block opt_semi  */
#line 235 "gram.y"
                                        {
						plpgsql_yylval.program = (PLpgSQL_stmt_block *)(plpgsql_yyvsp[-1].stmt);
					}
#line 1721 "y.tab.c"
    break;

  case 8: /* comp_option: O_OPTION O_DUMP  */
#line 249 "gram.y"
                                        {
						plpgsql_DumpExecTree = true;
					}
#line 1729 "y.tab.c"
    break;

  case 11: /* pl_block: decl_sect K_BEGIN lno proc_sect exception_sect K_END opt_label  */
#line 259 "gram.y"
                                        {
						PLpgSQL_stmt_block *new;

						new = palloc0(sizeof(PLpgSQL_stmt_block));

						new->cmd_type	= PLPGSQL_STMT_BLOCK;
						new->lineno		= (plpgsql_yyvsp[-4].ival);
						new->label		= (plpgsql_yyvsp[-6].declhdr).label;
						new->n_initvars = (plpgsql_yyvsp[-6].declhdr).n_initvars;
						new->initvarnos = (plpgsql_yyvsp[-6].declhdr).initvarnos;
						new->body		= (plpgsql_yyvsp[-3].list);
						new->exceptions	= (plpgsql_yyvsp[-2].exception_block);

						check_labels((plpgsql_yyvsp[-6].declhdr).label, (plpgsql_yyvsp[0].str));
						plpgsql_ns_pop();

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 1752 "y.tab.c"
    break;

  case 12: /* decl_sect: opt_block_label  */
#line 281 "gram.y"
                                        {
						plpgsql_ns_setlocal(false);
						(plpgsql_yyval.declhdr).label	  = (plpgsql_yyvsp[0].str);
						(plpgsql_yyval.declhdr).n_initvars = 0;
						(plpgsql_yyval.declhdr).initvarnos = NULL;
						plpgsql_add_initdatums(NULL);
					}
#line 1764 "y.tab.c"
    break;

  case 13: /* decl_sect: opt_block_label decl_start  */
#line 289 "gram.y"
                                        {
						plpgsql_ns_setlocal(false);
						(plpgsql_yyval.declhdr).label	  = (plpgsql_yyvsp[-1].str);
						(plpgsql_yyval.declhdr).n_initvars = 0;
						(plpgsql_yyval.declhdr).initvarnos = NULL;
						plpgsql_add_initdatums(NULL);
					}
#line 1776 "y.tab.c"
    break;

  case 14: /* decl_sect: opt_block_label decl_start decl_stmts  */
#line 297 "gram.y"
                                        {
						plpgsql_ns_setlocal(false);
						if ((plpgsql_yyvsp[0].str) != NULL)
							(plpgsql_yyval.declhdr).label = (plpgsql_yyvsp[0].str);
						else
							(plpgsql_yyval.declhdr).label = (plpgsql_yyvsp[-2].str);
						(plpgsql_yyval.declhdr).n_initvars = plpgsql_add_initdatums(&((plpgsql_yyval.declhdr).initvarnos));
					}
#line 1789 "y.tab.c"
    break;

  case 15: /* decl_start: K_DECLARE  */
#line 308 "gram.y"
                                        {
						plpgsql_ns_setlocal(true);
					}
#line 1797 "y.tab.c"
    break;

  case 16: /* decl_stmts: decl_stmts decl_stmt  */
#line 314 "gram.y"
                                        {	(plpgsql_yyval.str) = (plpgsql_yyvsp[0].str);	}
#line 1803 "y.tab.c"
    break;

  case 17: /* decl_stmts: decl_stmt  */
#line 316 "gram.y"
                                        {	(plpgsql_yyval.str) = (plpgsql_yyvsp[0].str);	}
#line 1809 "y.tab.c"
    break;

  case 18: /* decl_stmt: '<' '<' opt_lblname '>' '>'  */
#line 320 "gram.y"
                                        {	(plpgsql_yyval.str) = (plpgsql_yyvsp[-2].str);	}
#line 1815 "y.tab.c"
    break;

  case 19: /* decl_stmt: K_DECLARE  */
#line 322 "gram.y"
                                        {	(plpgsql_yyval.str) = NULL;	}
#line 1821 "y.tab.c"
    break;

  case 20: /* decl_stmt: decl_statement  */
#line 324 "gram.y"
                                        {	(plpgsql_yyval.str) = NULL;	}
#line 1827 "y.tab.c"
    break;

  case 21: /* decl_statement: decl_varname decl_const decl_datatype decl_notnull decl_defval  */
#line 328 "gram.y"
                                        {
						PLpgSQL_variable	*var;

						var = plpgsql_build_variable((plpgsql_yyvsp[-4].varname).name, (plpgsql_yyvsp[-4].varname).lineno,
													 (plpgsql_yyvsp[-2].dtype), true);
						if ((plpgsql_yyvsp[-3].boolean))
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->isconst = (plpgsql_yyvsp[-3].boolean);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("row or record variable cannot be CONSTANT")));
						}
						if ((plpgsql_yyvsp[-1].boolean))
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->notnull = (plpgsql_yyvsp[-1].boolean);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("row or record variable cannot be NOT NULL")));
						}
						if ((plpgsql_yyvsp[0].expr) != NULL)
						{
							if (var->dtype == PLPGSQL_DTYPE_VAR)
								((PLpgSQL_var *) var)->default_val = (plpgsql_yyvsp[0].expr);
							else
								ereport(ERROR,
										(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
										 errmsg("default value for row or record variable is not supported")));
						}
					}
#line 1865 "y.tab.c"
    break;

  case 22: /* decl_statement: decl_varname K_ALIAS K_FOR decl_aliasitem ';'  */
#line 362 "gram.y"
                                        {
						plpgsql_ns_additem((plpgsql_yyvsp[-1].nsitem)->itemtype,
										   (plpgsql_yyvsp[-1].nsitem)->itemno, (plpgsql_yyvsp[-4].varname).name);
					}
#line 1874 "y.tab.c"
    break;

  case 23: /* decl_statement: K_RENAME decl_renname K_TO decl_renname ';'  */
#line 367 "gram.y"
                                        {
						plpgsql_ns_rename((plpgsql_yyvsp[-3].str), (plpgsql_yyvsp[-1].str));
					}
#line 1882 "y.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 371 "gram.y"
                                        { plpgsql_ns_push(NULL); }
#line 1888 "y.tab.c"
    break;

  case 25: /* decl_statement: decl_varname K_CURSOR $@1 decl_cursor_args decl_is_from decl_cursor_query  */
#line 373 "gram.y"
                                        {
						PLpgSQL_var *new;
						PLpgSQL_expr *curname_def;
						char		buf[1024];
						char		*cp1;
						char		*cp2;

						/* pop local namespace for cursor args */
						plpgsql_ns_pop();

						new = (PLpgSQL_var *)
							plpgsql_build_variable((plpgsql_yyvsp[-5].varname).name, (plpgsql_yyvsp[-5].varname).lineno,
												   plpgsql_build_datatype(REFCURSOROID,
																		  -1),
												   true);

						curname_def = palloc0(sizeof(PLpgSQL_expr));

						curname_def->dtype = PLPGSQL_DTYPE_EXPR;
						strcpy(buf, "SELECT ");
						cp1 = new->refname;
						cp2 = buf + strlen(buf);
						if (strchr(cp1, '\\') != NULL)
							*cp2++ = ESCAPE_STRING_SYNTAX;
						*cp2++ = '\'';
						while (*cp1)
						{
							if (SQL_STR_DOUBLE(*cp1))
								*cp2++ = *cp1;
							*cp2++ = *cp1++;
						}
						strcpy(cp2, "'::refcursor");
						curname_def->query = pstrdup(buf);
						new->default_val = curname_def;

						new->cursor_explicit_expr = (plpgsql_yyvsp[0].expr);
						if ((plpgsql_yyvsp[-2].row) == NULL)
							new->cursor_explicit_argrow = -1;
						else
							new->cursor_explicit_argrow = (plpgsql_yyvsp[-2].row)->rowno;
					}
#line 1934 "y.tab.c"
    break;

  case 26: /* decl_cursor_query: %empty  */
#line 417 "gram.y"
                                        {
						PLpgSQL_expr *query;

						plpgsql_ns_setlocal(false);
						query = read_sql_stmt("");
						plpgsql_ns_setlocal(true);

						(plpgsql_yyval.expr) = query;
					}
#line 1948 "y.tab.c"
    break;

  case 27: /* decl_cursor_args: %empty  */
#line 429 "gram.y"
                                        {
						(plpgsql_yyval.row) = NULL;
					}
#line 1956 "y.tab.c"
    break;

  case 28: /* decl_cursor_args: '(' decl_cursor_arglist ')'  */
#line 433 "gram.y"
                                        {
						PLpgSQL_row *new;
						int i;
						ListCell *l;

						new = palloc0(sizeof(PLpgSQL_row));
						new->dtype = PLPGSQL_DTYPE_ROW;
						new->lineno = plpgsql_scanner_lineno();
						new->rowtupdesc = NULL;
						new->nfields = list_length((plpgsql_yyvsp[-1].list));
						new->fieldnames = palloc(new->nfields * sizeof(char *));
						new->varnos = palloc(new->nfields * sizeof(int));

						i = 0;
						foreach (l, (plpgsql_yyvsp[-1].list))
						{
							PLpgSQL_variable *arg = (PLpgSQL_variable *) lfirst(l);
							new->fieldnames[i] = arg->refname;
							new->varnos[i] = arg->dno;
							i++;
						}
						list_free((plpgsql_yyvsp[-1].list));

						plpgsql_adddatum((PLpgSQL_datum *) new);
						(plpgsql_yyval.row) = new;
					}
#line 1987 "y.tab.c"
    break;

  case 29: /* decl_cursor_arglist: decl_cursor_arg  */
#line 462 "gram.y"
                                        {
						(plpgsql_yyval.list) = list_make1((plpgsql_yyvsp[0].variable));
					}
#line 1995 "y.tab.c"
    break;

  case 30: /* decl_cursor_arglist: decl_cursor_arglist ',' decl_cursor_arg  */
#line 466 "gram.y"
                                        {
						(plpgsql_yyval.list) = lappend((plpgsql_yyvsp[-2].list), (plpgsql_yyvsp[0].variable));
					}
#line 2003 "y.tab.c"
    break;

  case 31: /* decl_cursor_arg: decl_varname decl_datatype  */
#line 472 "gram.y"
                                        {
						(plpgsql_yyval.variable) = plpgsql_build_variable((plpgsql_yyvsp[-1].varname).name, (plpgsql_yyvsp[-1].varname).lineno,
													(plpgsql_yyvsp[0].dtype), true);
					}
#line 2012 "y.tab.c"
    break;

  case 34: /* decl_aliasitem: T_WORD  */
#line 482 "gram.y"
                                        {
						char	*name;
						PLpgSQL_nsitem *nsi;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						if (name[0] != '$')
							plpgsql_yyerror("only positional parameters may be aliased");

						plpgsql_ns_setlocal(false);
						nsi = plpgsql_ns_lookup(name, NULL);
						if (nsi == NULL)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_UNDEFINED_PARAMETER),
									 errmsg("function has no parameter \"%s\"",
											name)));
						}

						plpgsql_ns_setlocal(true);

						pfree(name);

						(plpgsql_yyval.nsitem) = nsi;
					}
#line 2042 "y.tab.c"
    break;

  case 35: /* decl_varname: T_WORD  */
#line 510 "gram.y"
                                        {
						char	*name;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						(plpgsql_yyval.varname).name = name;
						(plpgsql_yyval.varname).lineno  = plpgsql_scanner_lineno();
					}
#line 2054 "y.tab.c"
    break;

  case 36: /* decl_renname: T_WORD  */
#line 520 "gram.y"
                                        {
						char	*name;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						/* the result must be palloc'd, see plpgsql_ns_rename */
						(plpgsql_yyval.str) = name;
					}
#line 2066 "y.tab.c"
    break;

  case 37: /* decl_const: %empty  */
#line 530 "gram.y"
                                        { (plpgsql_yyval.boolean) = false; }
#line 2072 "y.tab.c"
    break;

  case 38: /* decl_const: K_CONSTANT  */
#line 532 "gram.y"
                                        { (plpgsql_yyval.boolean) = true; }
#line 2078 "y.tab.c"
    break;

  case 39: /* decl_datatype: %empty  */
#line 536 "gram.y"
                                        {
						/*
						 * If there's a lookahead token, read_datatype
						 * should consume it.
						 */
						(plpgsql_yyval.dtype) = read_datatype(plpgsql_yychar);
						plpgsql_yyclearin;
					}
#line 2091 "y.tab.c"
    break;

  case 40: /* decl_notnull: %empty  */
#line 547 "gram.y"
                                        { (plpgsql_yyval.boolean) = false; }
#line 2097 "y.tab.c"
    break;

  case 41: /* decl_notnull: K_NOT K_NULL  */
#line 549 "gram.y"
                                        { (plpgsql_yyval.boolean) = true; }
#line 2103 "y.tab.c"
    break;

  case 42: /* decl_defval: ';'  */
#line 553 "gram.y"
                                        { (plpgsql_yyval.expr) = NULL; }
#line 2109 "y.tab.c"
    break;

  case 43: /* decl_defval: decl_defkey  */
#line 555 "gram.y"
                                        {
						plpgsql_ns_setlocal(false);
						(plpgsql_yyval.expr) = plpgsql_read_expression(';', ";");
						plpgsql_ns_setlocal(true);
					}
#line 2119 "y.tab.c"
    break;

  case 46: /* proc_sect: %empty  */
#line 567 "gram.y"
                                        {
						(plpgsql_yyval.list) = NIL;
					}
#line 2127 "y.tab.c"
    break;

  case 47: /* proc_sect: proc_stmts  */
#line 571 "gram.y"
                                        { (plpgsql_yyval.list) = (plpgsql_yyvsp[0].list); }
#line 2133 "y.tab.c"
    break;

  case 48: /* proc_stmts: proc_stmts proc_stmt  */
#line 575 "gram.y"
                                                {
							if ((plpgsql_yyvsp[0].stmt) == NULL)
								(plpgsql_yyval.list) = (plpgsql_yyvsp[-1].list);
							else
								(plpgsql_yyval.list) = lappend((plpgsql_yyvsp[-1].list), (plpgsql_yyvsp[0].stmt));
						}
#line 2144 "y.tab.c"
    break;

  case 49: /* proc_stmts: proc_stmt  */
#line 582 "gram.y"
                                                {
							if ((plpgsql_yyvsp[0].stmt) == NULL)
								(plpgsql_yyval.list) = NULL;
							else
								(plpgsql_yyval.list) = list_make1((plpgsql_yyvsp[0].stmt));
						}
#line 2155 "y.tab.c"
    break;

  case 50: /* proc_stmt: pl_block ';'  */
#line 591 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[-1].stmt); }
#line 2161 "y.tab.c"
    break;

  case 51: /* proc_stmt: stmt_assign  */
#line 593 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2167 "y.tab.c"
    break;

  case 52: /* proc_stmt: stmt_if  */
#line 595 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2173 "y.tab.c"
    break;

  case 53: /* proc_stmt: stmt_loop  */
#line 597 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2179 "y.tab.c"
    break;

  case 54: /* proc_stmt: stmt_while  */
#line 599 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2185 "y.tab.c"
    break;

  case 55: /* proc_stmt: stmt_for  */
#line 601 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2191 "y.tab.c"
    break;

  case 56: /* proc_stmt: stmt_select  */
#line 603 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2197 "y.tab.c"
    break;

  case 57: /* proc_stmt: stmt_exit  */
#line 605 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2203 "y.tab.c"
    break;

  case 58: /* proc_stmt: stmt_return  */
#line 607 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2209 "y.tab.c"
    break;

  case 59: /* proc_stmt: stmt_return_next  */
#line 609 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2215 "y.tab.c"
    break;

  case 60: /* proc_stmt: stmt_raise  */
#line 611 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2221 "y.tab.c"
    break;

  case 61: /* proc_stmt: stmt_execsql  */
#line 613 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2227 "y.tab.c"
    break;

  case 62: /* proc_stmt: stmt_dynexecute  */
#line 615 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2233 "y.tab.c"
    break;

  case 63: /* proc_stmt: stmt_perform  */
#line 617 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2239 "y.tab.c"
    break;

  case 64: /* proc_stmt: stmt_getdiag  */
#line 619 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2245 "y.tab.c"
    break;

  case 65: /* proc_stmt: stmt_open  */
#line 621 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2251 "y.tab.c"
    break;

  case 66: /* proc_stmt: stmt_fetch  */
#line 623 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2257 "y.tab.c"
    break;

  case 67: /* proc_stmt: stmt_close  */
#line 625 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2263 "y.tab.c"
    break;

  case 68: /* proc_stmt: stmt_null  */
#line 627 "gram.y"
                                                { (plpgsql_yyval.stmt) = (plpgsql_yyvsp[0].stmt); }
#line 2269 "y.tab.c"
    break;

  case 69: /* stmt_perform: K_PERFORM lno expr_until_semi  */
#line 631 "gram.y"
                                        {
						PLpgSQL_stmt_perform *new;

						new = palloc0(sizeof(PLpgSQL_stmt_perform));
						new->cmd_type = PLPGSQL_STMT_PERFORM;
						new->lineno   = (plpgsql_yyvsp[-1].ival);
						new->expr  = (plpgsql_yyvsp[0].expr);

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2284 "y.tab.c"
    break;

  case 70: /* stmt_assign: assign_var lno K_ASSIGN expr_until_semi  */
#line 644 "gram.y"
                                        {
						PLpgSQL_stmt_assign *new;

						new = palloc0(sizeof(PLpgSQL_stmt_assign));
						new->cmd_type = PLPGSQL_STMT_ASSIGN;
						new->lineno   = (plpgsql_yyvsp[-2].ival);
						new->varno = (plpgsql_yyvsp[-3].ival);
						new->expr  = (plpgsql_yyvsp[0].expr);

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2300 "y.tab.c"
    break;

  case 71: /* stmt_getdiag: K_GET K_DIAGNOSTICS lno getdiag_list ';'  */
#line 658 "gram.y"
                                        {
						PLpgSQL_stmt_getdiag	 *new;

						new = palloc0(sizeof(PLpgSQL_stmt_getdiag));
						new->cmd_type = PLPGSQL_STMT_GETDIAG;
						new->lineno   = (plpgsql_yyvsp[-2].ival);
						new->diag_items  = (plpgsql_yyvsp[-1].list);

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2315 "y.tab.c"
    break;

  case 72: /* getdiag_list: getdiag_list ',' getdiag_list_item  */
#line 671 "gram.y"
                                        {
						(plpgsql_yyval.list) = lappend((plpgsql_yyvsp[-2].list), (plpgsql_yyvsp[0].diagitem));
					}
#line 2323 "y.tab.c"
    break;

  case 73: /* getdiag_list: getdiag_list_item  */
#line 675 "gram.y"
                                        {
						(plpgsql_yyval.list) = list_make1((plpgsql_yyvsp[0].diagitem));
					}
#line 2331 "y.tab.c"
    break;

  case 74: /* getdiag_list_item: getdiag_target K_ASSIGN getdiag_kind  */
#line 681 "gram.y"
                                        {
						PLpgSQL_diag_item *new;

						new = palloc(sizeof(PLpgSQL_diag_item));
						new->target = (plpgsql_yyvsp[-2].ival);
						new->kind = (plpgsql_yyvsp[0].ival);

						(plpgsql_yyval.diagitem) = new;
					}
#line 2345 "y.tab.c"
    break;

  case 75: /* getdiag_kind: K_ROW_COUNT  */
#line 693 "gram.y"
                                        {
						(plpgsql_yyval.ival) = PLPGSQL_GETDIAG_ROW_COUNT;
					}
#line 2353 "y.tab.c"
    break;

  case 76: /* getdiag_kind: K_RESULT_OID  */
#line 697 "gram.y"
                                        {
						(plpgsql_yyval.ival) = PLPGSQL_GETDIAG_RESULT_OID;
					}
#line 2361 "y.tab.c"
    break;

  case 77: /* getdiag_target: T_SCALAR  */
#line 703 "gram.y"
                                        {
						check_assignable(plpgsql_yylval.scalar);
						(plpgsql_yyval.ival) = plpgsql_yylval.scalar->dno;
					}
#line 2370 "y.tab.c"
    break;

  case 78: /* assign_var: T_SCALAR  */
#line 711 "gram.y"
                                        {
						check_assignable(plpgsql_yylval.scalar);
						(plpgsql_yyval.ival) = plpgsql_yylval.scalar->dno;
					}
#line 2379 "y.tab.c"
    break;

  case 79: /* assign_var: T_ROW  */
#line 716 "gram.y"
                                        {
						check_assignable((PLpgSQL_datum *) plpgsql_yylval.row);
						(plpgsql_yyval.ival) = plpgsql_yylval.row->rowno;
					}
#line 2388 "y.tab.c"
    break;

  case 80: /* assign_var: T_RECORD  */
#line 721 "gram.y"
                                        {
						check_assignable((PLpgSQL_datum *) plpgsql_yylval.rec);
						(plpgsql_yyval.ival) = plpgsql_yylval.rec->recno;
					}
#line 2397 "y.tab.c"
    break;

  case 81: /* assign_var: assign_var '[' expr_until_rightbracket  */
#line 726 "gram.y"
                                        {
						PLpgSQL_arrayelem	*new;

						new = palloc0(sizeof(PLpgSQL_arrayelem));
						new->dtype		= PLPGSQL_DTYPE_ARRAYELEM;
						new->subscript	= (plpgsql_yyvsp[0].expr);
						new->arrayparentno = (plpgsql_yyvsp[-2].ival);

						plpgsql_adddatum((PLpgSQL_datum *)new);

						(plpgsql_yyval.ival) = new->dno;
					}
#line 2414 "y.tab.c"
    break;

  case 82: /* stmt_if: K_IF lno expr_until_then proc_sect stmt_else K_END K_IF ';'  */
#line 741 "gram.y"
                                        {
						PLpgSQL_stmt_if *new;

						new = palloc0(sizeof(PLpgSQL_stmt_if));
						new->cmd_type	= PLPGSQL_STMT_IF;
						new->lineno		= (plpgsql_yyvsp[-6].ival);
						new->cond		= (plpgsql_yyvsp[-5].expr);
						new->true_body	= (plpgsql_yyvsp[-4].list);
						new->false_body = (plpgsql_yyvsp[-3].list);

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2431 "y.tab.c"
    break;

  case 83: /* stmt_else: %empty  */
#line 756 "gram.y"
                                        {
						(plpgsql_yyval.list) = NIL;
					}
#line 2439 "y.tab.c"
    break;

  case 84: /* stmt_else: K_ELSIF lno expr_until_then proc_sect stmt_else  */
#line 760 "gram.y"
                                        {
						/*
						 * Translate the structure:	   into:
						 *
						 * IF c1 THEN				   IF c1 THEN
						 *	 ...						   ...
						 * ELSIF c2 THEN			   ELSE
						 *								   IF c2 THEN
						 *	 ...							   ...
						 * ELSE							   ELSE
						 *	 ...							   ...
						 * END IF						   END IF
						 *							   END IF
						 */
						PLpgSQL_stmt_if *new_if;

						/* first create a new if-statement */
						new_if = palloc0(sizeof(PLpgSQL_stmt_if));
						new_if->cmd_type	= PLPGSQL_STMT_IF;
						new_if->lineno		= (plpgsql_yyvsp[-3].ival);
						new_if->cond		= (plpgsql_yyvsp[-2].expr);
						new_if->true_body	= (plpgsql_yyvsp[-1].list);
						new_if->false_body	= (plpgsql_yyvsp[0].list);

						/* wrap the if-statement in a "container" list */
						(plpgsql_yyval.list) = list_make1(new_if);
					}
#line 2471 "y.tab.c"
    break;

  case 85: /* stmt_else: K_ELSE proc_sect  */
#line 789 "gram.y"
                                        {
						(plpgsql_yyval.list) = (plpgsql_yyvsp[0].list);
					}
#line 2479 "y.tab.c"
    break;

  case 86: /* stmt_loop: opt_block_label K_LOOP lno loop_body  */
#line 795 "gram.y"
                                        {
						PLpgSQL_stmt_loop *new;

						new = palloc0(sizeof(PLpgSQL_stmt_loop));
						new->cmd_type = PLPGSQL_STMT_LOOP;
						new->lineno   = (plpgsql_yyvsp[-1].ival);
						new->label	  = (plpgsql_yyvsp[-3].str);
						new->body	  = (plpgsql_yyvsp[0].loop_body).stmts;

						check_labels((plpgsql_yyvsp[-3].str), (plpgsql_yyvsp[0].loop_body).end_label);
						plpgsql_ns_pop();

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2498 "y.tab.c"
    break;

  case 87: /* stmt_while: opt_block_label K_WHILE lno expr_until_loop loop_body  */
#line 812 "gram.y"
                                        {
						PLpgSQL_stmt_while *new;

						new = palloc0(sizeof(PLpgSQL_stmt_while));
						new->cmd_type = PLPGSQL_STMT_WHILE;
						new->lineno   = (plpgsql_yyvsp[-2].ival);
						new->label	  = (plpgsql_yyvsp[-4].str);
						new->cond	  = (plpgsql_yyvsp[-1].expr);
						new->body	  = (plpgsql_yyvsp[0].loop_body).stmts;

						check_labels((plpgsql_yyvsp[-4].str), (plpgsql_yyvsp[0].loop_body).end_label);
						plpgsql_ns_pop();

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2518 "y.tab.c"
    break;

  case 88: /* stmt_for: opt_block_label K_FOR for_control loop_body  */
#line 830 "gram.y"
                                        {
						/* This runs after we've scanned the loop body */
						if ((plpgsql_yyvsp[-1].stmt)->cmd_type == PLPGSQL_STMT_FORI)
						{
							PLpgSQL_stmt_fori		*new;

							new = (PLpgSQL_stmt_fori *) (plpgsql_yyvsp[-1].stmt);
							new->label	  = (plpgsql_yyvsp[-3].str);
							new->body	  = (plpgsql_yyvsp[0].loop_body).stmts;
							(plpgsql_yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else if ((plpgsql_yyvsp[-1].stmt)->cmd_type == PLPGSQL_STMT_FORS)
						{
							PLpgSQL_stmt_fors		*new;

							new = (PLpgSQL_stmt_fors *) (plpgsql_yyvsp[-1].stmt);
							new->label	  = (plpgsql_yyvsp[-3].str);
							new->body	  = (plpgsql_yyvsp[0].loop_body).stmts;
							(plpgsql_yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_stmt_dynfors	*new;

							Assert((plpgsql_yyvsp[-1].stmt)->cmd_type == PLPGSQL_STMT_DYNFORS);
							new = (PLpgSQL_stmt_dynfors *) (plpgsql_yyvsp[-1].stmt);
							new->label	  = (plpgsql_yyvsp[-3].str);
							new->body	  = (plpgsql_yyvsp[0].loop_body).stmts;
							(plpgsql_yyval.stmt) = (PLpgSQL_stmt *) new;
						}

						check_labels((plpgsql_yyvsp[-3].str), (plpgsql_yyvsp[0].loop_body).end_label);
						/* close namespace started in opt_label */
						plpgsql_ns_pop();
					}
#line 2558 "y.tab.c"
    break;

  case 89: /* for_control: lno for_variable K_IN  */
#line 869 "gram.y"
                                        {
						int			tok = plpgsql_yylex();

						/* Simple case: EXECUTE is a dynamic FOR loop */
						if (tok == K_EXECUTE)
						{
							PLpgSQL_stmt_dynfors	*new;
							PLpgSQL_expr			*expr;

							expr = plpgsql_read_expression(K_LOOP, "LOOP");

							new = palloc0(sizeof(PLpgSQL_stmt_dynfors));
							new->cmd_type = PLPGSQL_STMT_DYNFORS;
							new->lineno   = (plpgsql_yyvsp[-2].ival);
							if ((plpgsql_yyvsp[-1].forvariable).rec)
								new->rec = (plpgsql_yyvsp[-1].forvariable).rec;
							else if ((plpgsql_yyvsp[-1].forvariable).row)
								new->row = (plpgsql_yyvsp[-1].forvariable).row;
							else
							{
								plpgsql_error_lineno = (plpgsql_yyvsp[-2].ival);
								plpgsql_yyerror("loop variable of loop over rows must be a record or row variable");
							}
							new->query = expr;

							(plpgsql_yyval.stmt) = (PLpgSQL_stmt *) new;
						}
						else
						{
							PLpgSQL_expr	*expr1;
							bool			 reverse = false;

							/*
							 * We have to distinguish between two
							 * alternatives: FOR var IN a .. b and FOR
							 * var IN query. Unfortunately this is
							 * tricky, since the query in the second
							 * form needn't start with a SELECT
							 * keyword.  We use the ugly hack of
							 * looking for two periods after the first
							 * token. We also check for the REVERSE
							 * keyword, which means it must be an
							 * integer loop.
							 */
							if (tok == K_REVERSE)
								reverse = true;
							else
								plpgsql_push_back_token(tok);

							/*
							 * Read tokens until we see either a ".."
							 * or a LOOP. The text we read may not
							 * necessarily be a well-formed SQL
							 * statement, so we need to invoke
							 * read_sql_construct directly.
							 */
							expr1 = read_sql_construct(K_DOTDOT,
													   K_LOOP,
													   "LOOP",
													   "SELECT ",
													   true,
													   false,
													   &tok);

							if (tok == K_DOTDOT)
							{
								/* Saw "..", so it must be an integer loop */
								PLpgSQL_expr		*expr2;
								PLpgSQL_var			*fvar;
								PLpgSQL_stmt_fori	*new;

								/* First expression is well-formed */
								check_sql_expr(expr1->query);

								expr2 = plpgsql_read_expression(K_LOOP, "LOOP");

								fvar = (PLpgSQL_var *)
									plpgsql_build_variable((plpgsql_yyvsp[-1].forvariable).name,
														   (plpgsql_yyvsp[-1].forvariable).lineno,
														   plpgsql_build_datatype(INT4OID,
																				  -1),
														   true);

								/* put the for-variable into the local block */
								plpgsql_add_initdatums(NULL);

								new = palloc0(sizeof(PLpgSQL_stmt_fori));
								new->cmd_type = PLPGSQL_STMT_FORI;
								new->lineno   = (plpgsql_yyvsp[-2].ival);
								new->var	  = fvar;
								new->reverse  = reverse;
								new->lower	  = expr1;
								new->upper	  = expr2;

								(plpgsql_yyval.stmt) = (PLpgSQL_stmt *) new;
							}
							else
							{
								/*
								 * No "..", so it must be a query loop. We've prefixed an
								 * extra SELECT to the query text, so we need to remove that
								 * before performing syntax checking.
								 */
								char				*tmp_query;
								PLpgSQL_stmt_fors	*new;

								if (reverse)
									plpgsql_yyerror("cannot specify REVERSE in query FOR loop");

								Assert(strncmp(expr1->query, "SELECT ", 7) == 0);
								tmp_query = pstrdup(expr1->query + 7);
								pfree(expr1->query);
								expr1->query = tmp_query;

								check_sql_expr(expr1->query);

								new = palloc0(sizeof(PLpgSQL_stmt_fors));
								new->cmd_type = PLPGSQL_STMT_FORS;
								new->lineno   = (plpgsql_yyvsp[-2].ival);
								if ((plpgsql_yyvsp[-1].forvariable).rec)
									new->rec = (plpgsql_yyvsp[-1].forvariable).rec;
								else if ((plpgsql_yyvsp[-1].forvariable).row)
									new->row = (plpgsql_yyvsp[-1].forvariable).row;
								else
								{
									plpgsql_error_lineno = (plpgsql_yyvsp[-2].ival);
									plpgsql_yyerror("loop variable of loop over rows must be record or row variable");
								}

								new->query = expr1;
								(plpgsql_yyval.stmt) = (PLpgSQL_stmt *) new;
							}
						}
					}
#line 2697 "y.tab.c"
    break;

  case 90: /* for_variable: T_SCALAR  */
#line 1006 "gram.y"
                                        {
						char		*name;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						(plpgsql_yyval.forvariable).name = name;
						(plpgsql_yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(plpgsql_yyval.forvariable).rec = NULL;
						(plpgsql_yyval.forvariable).row = NULL;
					}
#line 2711 "y.tab.c"
    break;

  case 91: /* for_variable: T_WORD  */
#line 1016 "gram.y"
                                        {
						char		*name;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						(plpgsql_yyval.forvariable).name = name;
						(plpgsql_yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(plpgsql_yyval.forvariable).rec = NULL;
						(plpgsql_yyval.forvariable).row = NULL;
					}
#line 2725 "y.tab.c"
    break;

  case 92: /* for_variable: T_RECORD  */
#line 1026 "gram.y"
                                        {
						char		*name;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						(plpgsql_yyval.forvariable).name = name;
						(plpgsql_yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(plpgsql_yyval.forvariable).rec = plpgsql_yylval.rec;
						(plpgsql_yyval.forvariable).row = NULL;
					}
#line 2739 "y.tab.c"
    break;

  case 93: /* for_variable: T_ROW  */
#line 1036 "gram.y"
                                        {
						char		*name;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						(plpgsql_yyval.forvariable).name = name;
						(plpgsql_yyval.forvariable).lineno  = plpgsql_scanner_lineno();
						(plpgsql_yyval.forvariable).row = plpgsql_yylval.row;
						(plpgsql_yyval.forvariable).rec = NULL;
					}
#line 2753 "y.tab.c"
    break;

  case 94: /* stmt_select: K_SELECT lno  */
#line 1048 "gram.y"
                                        {
						(plpgsql_yyval.stmt) = make_select_stmt();
						(plpgsql_yyval.stmt)->lineno = (plpgsql_yyvsp[0].ival);
					}
#line 2762 "y.tab.c"
    break;

  case 95: /* stmt_exit: exit_type lno opt_label opt_exitcond  */
#line 1055 "gram.y"
                                        {
						PLpgSQL_stmt_exit *new;

						new = palloc0(sizeof(PLpgSQL_stmt_exit));
						new->cmd_type = PLPGSQL_STMT_EXIT;
						new->is_exit  = (plpgsql_yyvsp[-3].boolean);
						new->lineno	  = (plpgsql_yyvsp[-2].ival);
						new->label	  = (plpgsql_yyvsp[-1].str);
						new->cond	  = (plpgsql_yyvsp[0].expr);

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2779 "y.tab.c"
    break;

  case 96: /* exit_type: K_EXIT  */
#line 1070 "gram.y"
                                        {
						(plpgsql_yyval.boolean) = true;
					}
#line 2787 "y.tab.c"
    break;

  case 97: /* exit_type: K_CONTINUE  */
#line 1074 "gram.y"
                                        {
						(plpgsql_yyval.boolean) = false;
					}
#line 2795 "y.tab.c"
    break;

  case 98: /* stmt_return: K_RETURN lno  */
#line 1080 "gram.y"
                                        {
						PLpgSQL_stmt_return *new;

						new = palloc0(sizeof(PLpgSQL_stmt_return));
						new->cmd_type = PLPGSQL_STMT_RETURN;
						new->lineno   = (plpgsql_yyvsp[0].ival);
						new->expr	  = NULL;
						new->retvarno = -1;

						if (plpgsql_curr_compile->fn_retset)
						{
							if (plpgsql_yylex() != ';')
								plpgsql_yyerror("RETURN cannot have a parameter in function returning set; use RETURN NEXT");
						}
						else if (plpgsql_curr_compile->out_param_varno >= 0)
						{
							if (plpgsql_yylex() != ';')
								plpgsql_yyerror("RETURN cannot have a parameter in function with OUT parameters");
							new->retvarno = plpgsql_curr_compile->out_param_varno;
						}
						else if (plpgsql_curr_compile->fn_rettype == VOIDOID)
						{
							if (plpgsql_yylex() != ';')
								plpgsql_yyerror("RETURN cannot have a parameter in function returning void");
						}
						else if (plpgsql_curr_compile->fn_retistuple)
						{
							switch (plpgsql_yylex())
							{
								case K_NULL:
									/* we allow this to support RETURN NULL in triggers */
									break;

								case T_ROW:
									new->retvarno = plpgsql_yylval.row->rowno;
									break;

								case T_RECORD:
									new->retvarno = plpgsql_yylval.rec->recno;
									break;

								default:
									plpgsql_yyerror("RETURN must specify a record or row variable in function returning tuple");
									break;
							}
							if (plpgsql_yylex() != ';')
								plpgsql_yyerror("RETURN must specify a record or row variable in function returning tuple");
						}
						else
						{
							/*
							 * Note that a well-formed expression is
							 * _required_ here; anything else is a
							 * compile-time error.
							 */
							new->expr = plpgsql_read_expression(';', ";");
						}

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2860 "y.tab.c"
    break;

  case 99: /* stmt_return_next: K_RETURN_NEXT lno  */
#line 1143 "gram.y"
                                        {
						PLpgSQL_stmt_return_next *new;

						if (!plpgsql_curr_compile->fn_retset)
							plpgsql_yyerror("cannot use RETURN NEXT in a non-SETOF function");

						new = palloc0(sizeof(PLpgSQL_stmt_return_next));
						new->cmd_type	= PLPGSQL_STMT_RETURN_NEXT;
						new->lineno		= (plpgsql_yyvsp[0].ival);
						new->expr = NULL;
						new->retvarno	= -1;

						if (plpgsql_curr_compile->out_param_varno >= 0)
						{
							if (plpgsql_yylex() != ';')
								plpgsql_yyerror("RETURN NEXT cannot have a parameter in function with OUT parameters");
							new->retvarno = plpgsql_curr_compile->out_param_varno;
						}
						else if (plpgsql_curr_compile->fn_retistuple)
						{
							switch (plpgsql_yylex())
							{
								case T_ROW:
									new->retvarno = plpgsql_yylval.row->rowno;
									break;

								case T_RECORD:
									new->retvarno = plpgsql_yylval.rec->recno;
									break;

								default:
									plpgsql_yyerror("RETURN NEXT must specify a record or row variable in function returning tuple");
									break;
							}
							if (plpgsql_yylex() != ';')
								plpgsql_yyerror("RETURN NEXT must specify a record or row variable in function returning tuple");
						}
						else
							new->expr = plpgsql_read_expression(';', ";");

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2907 "y.tab.c"
    break;

  case 100: /* stmt_raise: K_RAISE lno raise_level raise_msg  */
#line 1188 "gram.y"
                                        {
						PLpgSQL_stmt_raise		*new;
						int	tok;

						new = palloc(sizeof(PLpgSQL_stmt_raise));

						new->cmd_type	= PLPGSQL_STMT_RAISE;
						new->lineno		= (plpgsql_yyvsp[-2].ival);
						new->elog_level = (plpgsql_yyvsp[-1].ival);
						new->message	= (plpgsql_yyvsp[0].str);
						new->params		= NIL;

						tok = plpgsql_yylex();

						/*
						 * We expect either a semi-colon, which
						 * indicates no parameters, or a comma that
						 * begins the list of parameter expressions
						 */
						if (tok != ',' && tok != ';')
							plpgsql_yyerror("syntax error");

						if (tok == ',')
						{
							PLpgSQL_expr *expr;
							int term;

							for (;;)
							{
								expr = read_sql_construct(',', ';', ", or ;",
														  "SELECT ",
														  true, true, &term);
								new->params = lappend(new->params, expr);
								if (term == ';')
									break;
							}
						}

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 2952 "y.tab.c"
    break;

  case 101: /* raise_msg: T_STRING  */
#line 1231 "gram.y"
                                        {
						(plpgsql_yyval.str) = plpgsql_get_string_value();
					}
#line 2960 "y.tab.c"
    break;

  case 102: /* raise_level: K_EXCEPTION  */
#line 1237 "gram.y"
                                        {
						(plpgsql_yyval.ival) = ERROR;
					}
#line 2968 "y.tab.c"
    break;

  case 103: /* raise_level: K_WARNING  */
#line 1241 "gram.y"
                                        {
						(plpgsql_yyval.ival) = WARNING;
					}
#line 2976 "y.tab.c"
    break;

  case 104: /* raise_level: K_NOTICE  */
#line 1245 "gram.y"
                                        {
						(plpgsql_yyval.ival) = NOTICE;
					}
#line 2984 "y.tab.c"
    break;

  case 105: /* raise_level: K_INFO  */
#line 1249 "gram.y"
                                        {
						(plpgsql_yyval.ival) = INFO;
					}
#line 2992 "y.tab.c"
    break;

  case 106: /* raise_level: K_LOG  */
#line 1253 "gram.y"
                                        {
						(plpgsql_yyval.ival) = LOG;
					}
#line 3000 "y.tab.c"
    break;

  case 107: /* raise_level: K_DEBUG  */
#line 1257 "gram.y"
                                        {
						(plpgsql_yyval.ival) = DEBUG1;
					}
#line 3008 "y.tab.c"
    break;

  case 108: /* loop_body: proc_sect K_END K_LOOP opt_label ';'  */
#line 1263 "gram.y"
                                        {
						(plpgsql_yyval.loop_body).stmts = (plpgsql_yyvsp[-4].list);
						(plpgsql_yyval.loop_body).end_label = (plpgsql_yyvsp[-1].str);
					}
#line 3017 "y.tab.c"
    break;

  case 109: /* stmt_execsql: execsql_start lno  */
#line 1270 "gram.y"
                                        {
						PLpgSQL_stmt_execsql	*new;

						new = palloc(sizeof(PLpgSQL_stmt_execsql));
						new->cmd_type = PLPGSQL_STMT_EXECSQL;
						new->lineno   = (plpgsql_yyvsp[0].ival);
						new->sqlstmt  = read_sql_stmt((plpgsql_yyvsp[-1].str));

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3032 "y.tab.c"
    break;

  case 110: /* stmt_dynexecute: K_EXECUTE lno  */
#line 1283 "gram.y"
                                        {
						PLpgSQL_stmt_dynexecute *new;
						PLpgSQL_expr *expr;
						int endtoken;

						expr = read_sql_construct(K_INTO, ';', "INTO|;", "SELECT ",
												  true, true, &endtoken);

						new = palloc(sizeof(PLpgSQL_stmt_dynexecute));
						new->cmd_type = PLPGSQL_STMT_DYNEXECUTE;
						new->lineno   = (plpgsql_yyvsp[0].ival);
						new->query    = expr;
						new->rec = NULL;
						new->row = NULL;

						/*
						 * If we saw "INTO", look for a following row
						 * var, record var, or list of scalars.
						 */
						if (endtoken == K_INTO)
						{
							switch (plpgsql_yylex())
							{
								case T_ROW:
									check_assignable((PLpgSQL_datum *) plpgsql_yylval.row);
									new->row = plpgsql_yylval.row;
									break;

								case T_RECORD:
									check_assignable((PLpgSQL_datum *) plpgsql_yylval.row);
									new->rec = plpgsql_yylval.rec;
									break;

								case T_SCALAR:
									new->row = read_into_scalar_list(plpgsql_yytext, plpgsql_yylval.scalar);
									break;

								default:
									plpgsql_error_lineno = (plpgsql_yyvsp[0].ival);
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("syntax error at \"%s\"", plpgsql_yytext),
											 errdetail("Expected record variable, row variable, "
													   "or list of scalar variables.")));
							}
							if (plpgsql_yylex() != ';')
								plpgsql_yyerror("syntax error");
						}

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3088 "y.tab.c"
    break;

  case 111: /* stmt_open: K_OPEN lno cursor_varptr  */
#line 1338 "gram.y"
                                        {
						PLpgSQL_stmt_open *new;
						int				  tok;

						new = palloc0(sizeof(PLpgSQL_stmt_open));
						new->cmd_type = PLPGSQL_STMT_OPEN;
						new->lineno = (plpgsql_yyvsp[-1].ival);
						new->curvar = (plpgsql_yyvsp[0].var)->varno;

						if ((plpgsql_yyvsp[0].var)->cursor_explicit_expr == NULL)
						{
						    tok = plpgsql_yylex();
							if (tok != K_FOR)
							{
								plpgsql_error_lineno = (plpgsql_yyvsp[-1].ival);
								ereport(ERROR,
										(errcode(ERRCODE_SYNTAX_ERROR),
										 errmsg("syntax error at \"%s\"",
												plpgsql_yytext),
										 errdetail("Expected FOR to open a reference cursor.")));
							}

							tok = plpgsql_yylex();
							if (tok == K_EXECUTE)
							{
								new->dynquery = read_sql_stmt("SELECT ");
							}
							else
							{
								plpgsql_push_back_token(tok);
								new->query = read_sql_stmt("");
							}
						}
						else
						{
							if ((plpgsql_yyvsp[0].var)->cursor_explicit_argrow >= 0)
							{
								char   *cp;

								tok = plpgsql_yylex();
								if (tok != '(')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("cursor \"%s\" has arguments",
													(plpgsql_yyvsp[0].var)->refname)));
								}

								/*
								 * Push back the '(', else read_sql_stmt
								 * will complain about unbalanced parens.
								 */
								plpgsql_push_back_token(tok);

								new->argquery = read_sql_stmt("SELECT ");

								/*
								 * Now remove the leading and trailing parens,
								 * because we want "select 1, 2", not
								 * "select (1, 2)".
								 */
								cp = new->argquery->query;

								if (strncmp(cp, "SELECT", 6) != 0)
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									/* internal error */
									elog(ERROR, "expected \"SELECT (\", got \"%s\"",
										 new->argquery->query);
								}
								cp += 6;
								while (*cp == ' ') /* could be more than 1 space here */
									cp++;
								if (*cp != '(')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									/* internal error */
									elog(ERROR, "expected \"SELECT (\", got \"%s\"",
										 new->argquery->query);
								}
								*cp = ' ';

								cp += strlen(cp) - 1;

								if (*cp != ')')
									plpgsql_yyerror("expected \")\"");
								*cp = '\0';
							}
							else
							{
								tok = plpgsql_yylex();
								if (tok == '(')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("cursor \"%s\" has no arguments",
													(plpgsql_yyvsp[0].var)->refname)));
								}

								if (tok != ';')
								{
									plpgsql_error_lineno = plpgsql_scanner_lineno();
									ereport(ERROR,
											(errcode(ERRCODE_SYNTAX_ERROR),
											 errmsg("syntax error at \"%s\"",
													plpgsql_yytext)));
								}
							}
						}

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3207 "y.tab.c"
    break;

  case 112: /* stmt_fetch: K_FETCH lno cursor_variable K_INTO  */
#line 1455 "gram.y"
                                        {
						PLpgSQL_stmt_fetch *new;

						new = (PLpgSQL_stmt_fetch *)make_fetch_stmt();
						new->curvar = (plpgsql_yyvsp[-1].ival);

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
						(plpgsql_yyval.stmt)->lineno = (plpgsql_yyvsp[-2].ival);
					}
#line 3221 "y.tab.c"
    break;

  case 113: /* stmt_close: K_CLOSE lno cursor_variable ';'  */
#line 1467 "gram.y"
                                        {
						PLpgSQL_stmt_close *new;

						new = palloc(sizeof(PLpgSQL_stmt_close));
						new->cmd_type = PLPGSQL_STMT_CLOSE;
						new->lineno = (plpgsql_yyvsp[-2].ival);
						new->curvar = (plpgsql_yyvsp[-1].ival);

						(plpgsql_yyval.stmt) = (PLpgSQL_stmt *)new;
					}
#line 3236 "y.tab.c"
    break;

  case 114: /* stmt_null: K_NULL ';'  */
#line 1480 "gram.y"
                                        {
						/* We do not bother building a node for NULL */
						(plpgsql_yyval.stmt) = NULL;
					}
#line 3245 "y.tab.c"
    break;

  case 115: /* cursor_varptr: T_SCALAR  */
#line 1487 "gram.y"
                                        {
						if (plpgsql_yylval.scalar->dtype != PLPGSQL_DTYPE_VAR)
							plpgsql_yyerror("cursor variable must be a simple variable");

						if (((PLpgSQL_var *) plpgsql_yylval.scalar)->datatype->typoid != REFCURSOROID)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_DATATYPE_MISMATCH),
									 errmsg("\"%s\" must be of type cursor or refcursor",
											((PLpgSQL_var *) plpgsql_yylval.scalar)->refname)));
						}
						(plpgsql_yyval.var) = (PLpgSQL_var *) plpgsql_yylval.scalar;
					}
#line 3264 "y.tab.c"
    break;

  case 116: /* cursor_variable: T_SCALAR  */
#line 1504 "gram.y"
                                        {
						if (plpgsql_yylval.scalar->dtype != PLPGSQL_DTYPE_VAR)
							plpgsql_yyerror("cursor variable must be a simple variable");

						if (((PLpgSQL_var *) plpgsql_yylval.scalar)->datatype->typoid != REFCURSOROID)
						{
							plpgsql_error_lineno = plpgsql_scanner_lineno();
							ereport(ERROR,
									(errcode(ERRCODE_DATATYPE_MISMATCH),
									 errmsg("\"%s\" must be of type refcursor",
											((PLpgSQL_var *) plpgsql_yylval.scalar)->refname)));
						}
						(plpgsql_yyval.ival) = plpgsql_yylval.scalar->dno;
					}
#line 3283 "y.tab.c"
    break;

  case 117: /* execsql_start: T_WORD  */
#line 1521 "gram.y"
                                        { (plpgsql_yyval.str) = pstrdup(plpgsql_yytext); }
#line 3289 "y.tab.c"
    break;

  case 118: /* execsql_start: T_ERROR  */
#line 1523 "gram.y"
                                        { (plpgsql_yyval.str) = pstrdup(plpgsql_yytext); }
#line 3295 "y.tab.c"
    break;

  case 119: /* exception_sect: %empty  */
#line 1527 "gram.y"
                                        { (plpgsql_yyval.exception_block) = NULL; }
#line 3301 "y.tab.c"
    break;

  case 120: /* @2: %empty  */
#line 1529 "gram.y"
                                        {
						/*
						 * We use a mid-rule action to add these
						 * special variables to the namespace before
						 * parsing the WHEN clauses themselves.
						 */
						PLpgSQL_exception_block *new = palloc(sizeof(PLpgSQL_exception_block));
						PLpgSQL_variable *var;

						var = plpgsql_build_variable("sqlstate", (plpgsql_yyvsp[0].ival),
													 plpgsql_build_datatype(TEXTOID, -1),
													 true);
						((PLpgSQL_var *) var)->isconst = true;
						new->sqlstate_varno = var->dno;

						var = plpgsql_build_variable("sqlerrm", (plpgsql_yyvsp[0].ival),
													 plpgsql_build_datatype(TEXTOID, -1),
													 true);
						((PLpgSQL_var *) var)->isconst = true;
						new->sqlerrm_varno = var->dno;

						(plpgsql_yyval.exception_block) = new;
					}
#line 3329 "y.tab.c"
    break;

  case 121: /* exception_sect: K_EXCEPTION lno @2 proc_exceptions  */
#line 1553 "gram.y"
                                        {
						PLpgSQL_exception_block *new = (plpgsql_yyvsp[-1].exception_block);
						new->exc_list = (plpgsql_yyvsp[0].list);

						(plpgsql_yyval.exception_block) = new;
					}
#line 3340 "y.tab.c"
    break;

  case 122: /* proc_exceptions: proc_exceptions proc_exception  */
#line 1562 "gram.y"
                                                {
							(plpgsql_yyval.list) = lappend((plpgsql_yyvsp[-1].list), (plpgsql_yyvsp[0].exception));
						}
#line 3348 "y.tab.c"
    break;

  case 123: /* proc_exceptions: proc_exception  */
#line 1566 "gram.y"
                                                {
							(plpgsql_yyval.list) = list_make1((plpgsql_yyvsp[0].exception));
						}
#line 3356 "y.tab.c"
    break;

  case 124: /* proc_exception: K_WHEN lno proc_conditions K_THEN proc_sect  */
#line 1572 "gram.y"
                                        {
						PLpgSQL_exception *new;

						new = palloc0(sizeof(PLpgSQL_exception));
						new->lineno     = (plpgsql_yyvsp[-3].ival);
						new->conditions = (plpgsql_yyvsp[-2].condition);
						new->action	    = (plpgsql_yyvsp[0].list);

						(plpgsql_yyval.exception) = new;
					}
#line 3371 "y.tab.c"
    break;

  case 125: /* proc_conditions: proc_conditions K_OR opt_lblname  */
#line 1585 "gram.y"
                                                {
							PLpgSQL_condition	*old;

							for (old = (plpgsql_yyvsp[-2].condition); old->next != NULL; old = old->next)
								/* skip */ ;
							old->next = plpgsql_parse_err_condition((plpgsql_yyvsp[0].str));

							(plpgsql_yyval.condition) = (plpgsql_yyvsp[-2].condition);
						}
#line 3385 "y.tab.c"
    break;

  case 126: /* proc_conditions: opt_lblname  */
#line 1595 "gram.y"
                                                {
							(plpgsql_yyval.condition) = plpgsql_parse_err_condition((plpgsql_yyvsp[0].str));
						}
#line 3393 "y.tab.c"
    break;

  case 127: /* expr_until_semi: %empty  */
#line 1601 "gram.y"
                                        { (plpgsql_yyval.expr) = plpgsql_read_expression(';', ";"); }
#line 3399 "y.tab.c"
    break;

  case 128: /* expr_until_rightbracket: %empty  */
#line 1605 "gram.y"
                                        { (plpgsql_yyval.expr) = plpgsql_read_expression(']', "]"); }
#line 3405 "y.tab.c"
    break;

  case 129: /* expr_until_then: %empty  */
#line 1609 "gram.y"
                                        { (plpgsql_yyval.expr) = plpgsql_read_expression(K_THEN, "THEN"); }
#line 3411 "y.tab.c"
    break;

  case 130: /* expr_until_loop: %empty  */
#line 1613 "gram.y"
                                        { (plpgsql_yyval.expr) = plpgsql_read_expression(K_LOOP, "LOOP"); }
#line 3417 "y.tab.c"
    break;

  case 131: /* opt_block_label: %empty  */
#line 1617 "gram.y"
                                        {
						plpgsql_ns_push(NULL);
						(plpgsql_yyval.str) = NULL;
					}
#line 3426 "y.tab.c"
    break;

  case 132: /* opt_block_label: '<' '<' opt_lblname '>' '>'  */
#line 1622 "gram.y"
                                        {
						plpgsql_ns_push((plpgsql_yyvsp[-2].str));
						(plpgsql_yyval.str) = (plpgsql_yyvsp[-2].str);
					}
#line 3435 "y.tab.c"
    break;

  case 133: /* opt_label: %empty  */
#line 1629 "gram.y"
                                        {
						(plpgsql_yyval.str) = NULL;
					}
#line 3443 "y.tab.c"
    break;

  case 134: /* opt_label: T_LABEL  */
#line 1633 "gram.y"
                                        {
						char *label_name;
						plpgsql_convert_ident(plpgsql_yytext, &label_name, 1);
						(plpgsql_yyval.str) = label_name;
					}
#line 3453 "y.tab.c"
    break;

  case 135: /* opt_label: T_WORD  */
#line 1639 "gram.y"
                                        {
						/* just to give a better error than "syntax error" */
						plpgsql_yyerror("no such label");
					}
#line 3462 "y.tab.c"
    break;

  case 136: /* opt_exitcond: ';'  */
#line 1646 "gram.y"
                                        { (plpgsql_yyval.expr) = NULL; }
#line 3468 "y.tab.c"
    break;

  case 137: /* opt_exitcond: K_WHEN expr_until_semi  */
#line 1648 "gram.y"
                                        { (plpgsql_yyval.expr) = (plpgsql_yyvsp[0].expr); }
#line 3474 "y.tab.c"
    break;

  case 138: /* opt_lblname: T_WORD  */
#line 1652 "gram.y"
                                        {
						char	*name;

						plpgsql_convert_ident(plpgsql_yytext, &name, 1);
						(plpgsql_yyval.str) = name;
					}
#line 3485 "y.tab.c"
    break;

  case 139: /* lno: %empty  */
#line 1661 "gram.y"
                                        {
						(plpgsql_yyval.ival) = plpgsql_error_lineno = plpgsql_scanner_lineno();
					}
#line 3493 "y.tab.c"
    break;


#line 3497 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter plpgsql_yychar, and that requires
     that plpgsql_yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of plpgsql_yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     PLPGSQL_YYABORT, PLPGSQL_YYACCEPT, or PLPGSQL_YYERROR immediately after altering plpgsql_yychar or
     if it invokes PLPGSQL_YYBACKUP.  In the case of PLPGSQL_YYABORT or PLPGSQL_YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of PLPGSQL_YYERROR or PLPGSQL_YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  PLPGSQL_YY_SYMBOL_PRINT ("-> $$ =", PLPGSQL_YY_CAST (plpgsql_yysymbol_kind_t, plpgsql_yyr1[plpgsql_yyn]), &plpgsql_yyval, &plpgsql_yyloc);

  PLPGSQL_YYPOPSTACK (plpgsql_yylen);
  plpgsql_yylen = 0;

  *++plpgsql_yyvsp = plpgsql_yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int plpgsql_yylhs = plpgsql_yyr1[plpgsql_yyn] - PLPGSQL_YYNTOKENS;
    const int plpgsql_yyi = plpgsql_yypgoto[plpgsql_yylhs] + *plpgsql_yyssp;
    plpgsql_yystate = (0 <= plpgsql_yyi && plpgsql_yyi <= PLPGSQL_YYLAST && plpgsql_yycheck[plpgsql_yyi] == *plpgsql_yyssp
               ? plpgsql_yytable[plpgsql_yyi]
               : plpgsql_yydefgoto[plpgsql_yylhs]);
  }

  goto plpgsql_yynewstate;


/*--------------------------------------.
| plpgsql_yyerrlab -- here on detecting error.  |
`--------------------------------------*/
plpgsql_yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  plpgsql_yytoken = plpgsql_yychar == PLPGSQL_YYEMPTY ? PLPGSQL_YYSYMBOL_PLPGSQL_YYEMPTY : PLPGSQL_YYTRANSLATE (plpgsql_yychar);
  /* If not already recovering from an error, report this error.  */
  if (!plpgsql_yyerrstatus)
    {
      ++plpgsql_yynerrs;
      plpgsql_yyerror (PLPGSQL_YY_("syntax error"));
    }

  if (plpgsql_yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (plpgsql_yychar <= PLPGSQL_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (plpgsql_yychar == PLPGSQL_YYEOF)
            PLPGSQL_YYABORT;
        }
      else
        {
          plpgsql_yydestruct ("Error: discarding",
                      plpgsql_yytoken, &plpgsql_yylval);
          plpgsql_yychar = PLPGSQL_YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto plpgsql_yyerrlab1;


/*---------------------------------------------------.
| plpgsql_yyerrorlab -- error raised explicitly by PLPGSQL_YYERROR.  |
`---------------------------------------------------*/
plpgsql_yyerrorlab:
  /* Pacify compilers when the user code never invokes PLPGSQL_YYERROR and the
     label plpgsql_yyerrorlab therefore never appears in user code.  */
  if (0)
    PLPGSQL_YYERROR;
  ++plpgsql_yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this PLPGSQL_YYERROR.  */
  PLPGSQL_YYPOPSTACK (plpgsql_yylen);
  plpgsql_yylen = 0;
  PLPGSQL_YY_STACK_PRINT (plpgsql_yyss, plpgsql_yyssp);
  plpgsql_yystate = *plpgsql_yyssp;
  goto plpgsql_yyerrlab1;


/*-------------------------------------------------------------.
| plpgsql_yyerrlab1 -- common code for both syntax error and PLPGSQL_YYERROR.  |
`-------------------------------------------------------------*/
plpgsql_yyerrlab1:
  plpgsql_yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      plpgsql_yyn = plpgsql_yypact[plpgsql_yystate];
      if (!plpgsql_yypact_value_is_default (plpgsql_yyn))
        {
          plpgsql_yyn += PLPGSQL_YYSYMBOL_PLPGSQL_YYerror;
          if (0 <= plpgsql_yyn && plpgsql_yyn <= PLPGSQL_YYLAST && plpgsql_yycheck[plpgsql_yyn] == PLPGSQL_YYSYMBOL_PLPGSQL_YYerror)
            {
              plpgsql_yyn = plpgsql_yytable[plpgsql_yyn];
              if (0 < plpgsql_yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (plpgsql_yyssp == plpgsql_yyss)
        PLPGSQL_YYABORT;


      plpgsql_yydestruct ("Error: popping",
                  PLPGSQL_YY_ACCESSING_SYMBOL (plpgsql_yystate), plpgsql_yyvsp);
      PLPGSQL_YYPOPSTACK (1);
      plpgsql_yystate = *plpgsql_yyssp;
      PLPGSQL_YY_STACK_PRINT (plpgsql_yyss, plpgsql_yyssp);
    }

  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++plpgsql_yyvsp = plpgsql_yylval;
  PLPGSQL_YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  PLPGSQL_YY_SYMBOL_PRINT ("Shifting", PLPGSQL_YY_ACCESSING_SYMBOL (plpgsql_yyn), plpgsql_yyvsp, plpgsql_yylsp);

  plpgsql_yystate = plpgsql_yyn;
  goto plpgsql_yynewstate;


/*-------------------------------------.
| plpgsql_yyacceptlab -- PLPGSQL_YYACCEPT comes here.  |
`-------------------------------------*/
plpgsql_yyacceptlab:
  plpgsql_yyresult = 0;
  goto plpgsql_yyreturnlab;


/*-----------------------------------.
| plpgsql_yyabortlab -- PLPGSQL_YYABORT comes here.  |
`-----------------------------------*/
plpgsql_yyabortlab:
  plpgsql_yyresult = 1;
  goto plpgsql_yyreturnlab;


/*-----------------------------------------------------------.
| plpgsql_yyexhaustedlab -- PLPGSQL_YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
plpgsql_yyexhaustedlab:
  plpgsql_yyerror (PLPGSQL_YY_("memory exhausted"));
  plpgsql_yyresult = 2;
  goto plpgsql_yyreturnlab;


/*----------------------------------------------------------.
| plpgsql_yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
plpgsql_yyreturnlab:
  if (plpgsql_yychar != PLPGSQL_YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      plpgsql_yytoken = PLPGSQL_YYTRANSLATE (plpgsql_yychar);
      plpgsql_yydestruct ("Cleanup: discarding lookahead",
                  plpgsql_yytoken, &plpgsql_yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this PLPGSQL_YYABORT or PLPGSQL_YYACCEPT.  */
  PLPGSQL_YYPOPSTACK (plpgsql_yylen);
  PLPGSQL_YY_STACK_PRINT (plpgsql_yyss, plpgsql_yyssp);
  while (plpgsql_yyssp != plpgsql_yyss)
    {
      plpgsql_yydestruct ("Cleanup: popping",
                  PLPGSQL_YY_ACCESSING_SYMBOL (+*plpgsql_yyssp), plpgsql_yyvsp);
      PLPGSQL_YYPOPSTACK (1);
    }
#ifndef plpgsql_yyoverflow
  if (plpgsql_yyss != plpgsql_yyssa)
    PLPGSQL_YYSTACK_FREE (plpgsql_yyss);
#endif

  return plpgsql_yyresult;
}

#line 1666 "gram.y"



#define MAX_EXPR_PARAMS  1024

/*
 * determine the expression parameter position to use for a plpgsql datum
 *
 * It is important that any given plpgsql datum map to just one parameter.
 * We used to be sloppy and assign a separate parameter for each occurrence
 * of a datum reference, but that fails for situations such as "select DATUM
 * from ... group by DATUM".
 *
 * The params[] array must be of size MAX_EXPR_PARAMS.
 */
static int
assign_expr_param(int dno, int *params, int *nparams)
{
	int		i;

	/* already have an instance of this dno? */
	for (i = 0; i < *nparams; i++)
	{
		if (params[i] == dno)
			return i+1;
	}
	/* check for array overflow */
	if (*nparams >= MAX_EXPR_PARAMS)
	{
		plpgsql_error_lineno = plpgsql_scanner_lineno();
		ereport(ERROR,
				(errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
				 errmsg("too many variables specified in SQL statement")));
	}
	/* add new parameter dno to array */
	params[*nparams] = dno;
	(*nparams)++;
	return *nparams;
}


PLpgSQL_expr *
plpgsql_read_expression(int until, const char *expected)
{
	return read_sql_construct(until, 0, expected, "SELECT ", true, true, NULL);
}

static PLpgSQL_expr *
read_sql_stmt(const char *sqlstart)
{
	return read_sql_construct(';', 0, ";", sqlstart, false, true, NULL);
}

/*
 * Read a SQL construct and build a PLpgSQL_expr for it.
 *
 * until:		token code for expected terminator
 * until2:		token code for alternate terminator (pass 0 if none)
 * expected:	text to use in complaining that terminator was not found
 * sqlstart:	text to prefix to the accumulated SQL text
 * isexpression: whether to say we're reading an "expression" or a "statement"
 * valid_sql:   whether to check the syntax of the expr (prefixed with sqlstart)
 * endtoken:	if not NULL, ending token is stored at *endtoken
 *				(this is only interesting if until2 isn't zero)
 */
static PLpgSQL_expr *
read_sql_construct(int until,
				   int until2,
				   const char *expected,
				   const char *sqlstart,
				   bool isexpression,
				   bool valid_sql,
				   int *endtoken)
{
	int					tok;
	int					lno;
	PLpgSQL_dstring		ds;
	int					parenlevel = 0;
	int					nparams = 0;
	int					params[MAX_EXPR_PARAMS];
	char				buf[32];
	PLpgSQL_expr		*expr;

	lno = plpgsql_scanner_lineno();
	plpgsql_dstring_init(&ds);
	plpgsql_dstring_append(&ds, sqlstart);

	for (;;)
	{
		tok = plpgsql_yylex();
		if (tok == until && parenlevel == 0)
			break;
		if (tok == until2 && parenlevel == 0)
			break;
		if (tok == '(' || tok == '[')
			parenlevel++;
		else if (tok == ')' || tok == ']')
		{
			parenlevel--;
			if (parenlevel < 0)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("mismatched parentheses")));
		}
		/*
		 * End of function definition is an error, and we don't expect to
		 * hit a semicolon either (unless it's the until symbol, in which
		 * case we should have fallen out above).
		 */
		if (tok == 0 || tok == ';')
		{
			plpgsql_error_lineno = lno;
			if (parenlevel != 0)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("mismatched parentheses")));
			if (isexpression)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL expression",
								expected)));
			else
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("missing \"%s\" at end of SQL statement",
								expected)));
		}

		if (plpgsql_SpaceScanned)
			plpgsql_dstring_append(&ds, " ");

		switch (tok)
		{
			case T_SCALAR:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(plpgsql_yylval.scalar->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_ROW:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(plpgsql_yylval.row->rowno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_RECORD:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(plpgsql_yylval.rec->recno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			default:
				plpgsql_dstring_append(&ds, plpgsql_yytext);
				break;
		}
	}

	if (endtoken)
		*endtoken = tok;

	expr = palloc(sizeof(PLpgSQL_expr) + sizeof(int) * nparams - sizeof(int));
	expr->dtype			= PLPGSQL_DTYPE_EXPR;
	expr->query			= pstrdup(plpgsql_dstring_get(&ds));
	expr->plan			= NULL;
	expr->nparams		= nparams;
	while(nparams-- > 0)
		expr->params[nparams] = params[nparams];
	plpgsql_dstring_free(&ds);

	if (valid_sql)
		check_sql_expr(expr->query);

	return expr;
}

static PLpgSQL_type *
read_datatype(int tok)
{
	int					lno;
	PLpgSQL_dstring		ds;
	PLpgSQL_type		*result;
	bool				needspace = false;
	int					parenlevel = 0;

	lno = plpgsql_scanner_lineno();

	/* Often there will be a lookahead token, but if not, get one */
	if (tok == PLPGSQL_YYEMPTY)
		tok = plpgsql_yylex();

	if (tok == T_DTYPE)
	{
		/* lexer found word%TYPE and did its thing already */
		return plpgsql_yylval.dtype;
	}

	plpgsql_dstring_init(&ds);

	while (tok != ';')
	{
		if (tok == 0)
		{
			plpgsql_error_lineno = lno;
			if (parenlevel != 0)
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("mismatched parentheses")));
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("incomplete datatype declaration")));
		}
		/* Possible followers for datatype in a declaration */
		if (tok == K_NOT || tok == K_ASSIGN || tok == K_DEFAULT)
			break;
		/* Possible followers for datatype in a cursor_arg list */
		if ((tok == ',' || tok == ')') && parenlevel == 0)
			break;
		if (tok == '(')
			parenlevel++;
		else if (tok == ')')
			parenlevel--;
		if (needspace)
			plpgsql_dstring_append(&ds, " ");
		needspace = true;
		plpgsql_dstring_append(&ds, plpgsql_yytext);

		tok = plpgsql_yylex();
	}

	plpgsql_push_back_token(tok);

	plpgsql_error_lineno = lno;	/* in case of error in parse_datatype */

	result = plpgsql_parse_datatype(plpgsql_dstring_get(&ds));

	plpgsql_dstring_free(&ds);

	return result;
}

static PLpgSQL_stmt *
make_select_stmt(void)
{
	PLpgSQL_dstring		ds;
	int					nparams = 0;
	int					params[MAX_EXPR_PARAMS];
	char				buf[32];
	PLpgSQL_expr		*expr;
	PLpgSQL_row			*row = NULL;
	PLpgSQL_rec			*rec = NULL;
	int					tok;
	bool				have_into = false;

	plpgsql_dstring_init(&ds);
	plpgsql_dstring_append(&ds, "SELECT ");

	while (1)
	{
		tok = plpgsql_yylex();

		if (tok == ';')
			break;
		if (tok == 0)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("unexpected end of function definition")));
		}
		if (tok == K_INTO)
		{
			if (have_into)
			{
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("INTO specified more than once")));
			}
			tok = plpgsql_yylex();
			switch (tok)
			{
				case T_ROW:
					row = plpgsql_yylval.row;
					have_into = true;
					break;

				case T_RECORD:
					rec = plpgsql_yylval.rec;
					have_into = true;
					break;

				case T_SCALAR:
					row = read_into_scalar_list(plpgsql_yytext, plpgsql_yylval.scalar);
					have_into = true;
					break;

				default:
					/* Treat the INTO as non-special */
					plpgsql_dstring_append(&ds, " INTO ");
					plpgsql_push_back_token(tok);
					break;
			}
			continue;
		}

		if (plpgsql_SpaceScanned)
			plpgsql_dstring_append(&ds, " ");

		switch (tok)
		{
			case T_SCALAR:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(plpgsql_yylval.scalar->dno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_ROW:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(plpgsql_yylval.row->rowno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			case T_RECORD:
				snprintf(buf, sizeof(buf), " $%d ",
						 assign_expr_param(plpgsql_yylval.rec->recno,
										   params, &nparams));
				plpgsql_dstring_append(&ds, buf);
				break;

			default:
				plpgsql_dstring_append(&ds, plpgsql_yytext);
				break;
		}
	}

	expr = palloc(sizeof(PLpgSQL_expr) + sizeof(int) * nparams - sizeof(int));
	expr->dtype			= PLPGSQL_DTYPE_EXPR;
	expr->query			= pstrdup(plpgsql_dstring_get(&ds));
	expr->plan			= NULL;
	expr->nparams		= nparams;
	while(nparams-- > 0)
		expr->params[nparams] = params[nparams];
	plpgsql_dstring_free(&ds);

	check_sql_expr(expr->query);

	if (have_into)
	{
		PLpgSQL_stmt_select *select;

		select = palloc0(sizeof(PLpgSQL_stmt_select));
		select->cmd_type = PLPGSQL_STMT_SELECT;
		select->rec		 = rec;
		select->row		 = row;
		select->query	 = expr;

		return (PLpgSQL_stmt *)select;
	}
	else
	{
		PLpgSQL_stmt_execsql *execsql;

		execsql = palloc(sizeof(PLpgSQL_stmt_execsql));
		execsql->cmd_type = PLPGSQL_STMT_EXECSQL;
		execsql->sqlstmt  = expr;

		return (PLpgSQL_stmt *)execsql;
	}
}


static PLpgSQL_stmt *
make_fetch_stmt(void)
{
	int					tok;
	PLpgSQL_row		   *row = NULL;
	PLpgSQL_rec		   *rec = NULL;
	PLpgSQL_stmt_fetch *fetch;

	/* We have already parsed everything through the INTO keyword */

	tok = plpgsql_yylex();
	switch (tok)
	{
		case T_ROW:
			row = plpgsql_yylval.row;
			break;

		case T_RECORD:
			rec = plpgsql_yylval.rec;
			break;

		case T_SCALAR:
			row = read_into_scalar_list(plpgsql_yytext, plpgsql_yylval.scalar);
			break;

		default:
			plpgsql_yyerror("syntax error");
	}

	tok = plpgsql_yylex();
	if (tok != ';')
		plpgsql_yyerror("syntax error");

	fetch = palloc0(sizeof(PLpgSQL_stmt_select));
	fetch->cmd_type = PLPGSQL_STMT_FETCH;
	fetch->rec		 = rec;
	fetch->row		 = row;

	return (PLpgSQL_stmt *)fetch;
}


static void
check_assignable(PLpgSQL_datum *datum)
{
	switch (datum->dtype)
	{
		case PLPGSQL_DTYPE_VAR:
			if (((PLpgSQL_var *) datum)->isconst)
			{
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_ERROR_IN_ASSIGNMENT),
						 errmsg("\"%s\" is declared CONSTANT",
								((PLpgSQL_var *) datum)->refname)));
			}
			break;
		case PLPGSQL_DTYPE_ROW:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_REC:
			/* always assignable?  What about NEW/OLD? */
			break;
		case PLPGSQL_DTYPE_RECFIELD:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_ARRAYELEM:
			/* always assignable? */
			break;
		case PLPGSQL_DTYPE_TRIGARG:
			plpgsql_yyerror("cannot assign to tg_argv");
			break;
		default:
			elog(ERROR, "unrecognized dtype: %d", datum->dtype);
			break;
	}
}

/*
 * Given the first datum and name in the INTO list, continue to read
 * comma-separated scalar variables until we run out. Then construct
 * and return a fake "row" variable that represents the list of
 * scalars.
 */
static PLpgSQL_row *
read_into_scalar_list(const char *initial_name,
					  PLpgSQL_datum *initial_datum)
{
	int				 nfields;
	char			*fieldnames[1024];
	int				 varnos[1024];
	PLpgSQL_row		*row;
	int				 tok;

	check_assignable(initial_datum);
	fieldnames[0] = pstrdup(initial_name);
	varnos[0]	  = initial_datum->dno;
	nfields		  = 1;

	while ((tok = plpgsql_yylex()) == ',')
	{
		/* Check for array overflow */
		if (nfields >= 1024)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_PROGRAM_LIMIT_EXCEEDED),
					 errmsg("too many INTO variables specified")));
		}

		tok = plpgsql_yylex();
		switch(tok)
		{
			case T_SCALAR:
				check_assignable(plpgsql_yylval.scalar);
				fieldnames[nfields] = pstrdup(plpgsql_yytext);
				varnos[nfields++]	= plpgsql_yylval.scalar->dno;
				break;

			default:
				plpgsql_error_lineno = plpgsql_scanner_lineno();
				ereport(ERROR,
						(errcode(ERRCODE_SYNTAX_ERROR),
						 errmsg("\"%s\" is not a variable",
								plpgsql_yytext)));
		}
	}

	/*
	 * We read an extra, non-comma character from plpgsql_yylex(), so push it
	 * back onto the input stream
	 */
	plpgsql_push_back_token(tok);

	row = palloc(sizeof(PLpgSQL_row));
	row->dtype = PLPGSQL_DTYPE_ROW;
	row->refname = pstrdup("*internal*");
	row->lineno = plpgsql_scanner_lineno();
	row->rowtupdesc = NULL;
	row->nfields = nfields;
	row->fieldnames = palloc(sizeof(char *) * nfields);
	row->varnos = palloc(sizeof(int) * nfields);
	while (--nfields >= 0)
	{
		row->fieldnames[nfields] = fieldnames[nfields];
		row->varnos[nfields] = varnos[nfields];
	}

	plpgsql_adddatum((PLpgSQL_datum *)row);

	return row;
}

/*
 * When the PL/PgSQL parser expects to see a SQL statement, it is very
 * liberal in what it accepts; for example, we often assume an
 * unrecognized keyword is the beginning of a SQL statement. This
 * avoids the need to duplicate parts of the SQL grammar in the
 * PL/PgSQL grammar, but it means we can accept wildly malformed
 * input. To try and catch some of the more obviously invalid input,
 * we run the strings we expect to be SQL statements through the main
 * SQL parser.
 *
 * We only invoke the raw parser (not the analyzer); this doesn't do
 * any database access and does not check any semantic rules, it just
 * checks for basic syntactic correctness. We do this here, rather
 * than after parsing has finished, because a malformed SQL statement
 * may cause the PL/PgSQL parser to become confused about statement
 * borders. So it is best to bail out as early as we can.
 */
static void
check_sql_expr(const char *stmt)
{
	ErrorContextCallback  syntax_errcontext;
	ErrorContextCallback *previous_errcontext;
	MemoryContext oldCxt;

	if (!plpgsql_check_syntax)
		return;

	/*
	 * Setup error traceback support for ereport(). The previous
	 * ereport callback is installed by pl_comp.c, but we don't want
	 * that to be invoked (since it will try to transpose the syntax
	 * error to be relative to the CREATE FUNCTION), so temporarily
	 * remove it from the list of callbacks.
	 */
	Assert(error_context_stack->callback == plpgsql_compile_error_callback);

	previous_errcontext = error_context_stack;
	syntax_errcontext.callback = plpgsql_sql_error_callback;
	syntax_errcontext.arg = (char *) stmt;
	syntax_errcontext.previous = error_context_stack->previous;
	error_context_stack = &syntax_errcontext;

	oldCxt = MemoryContextSwitchTo(compile_tmp_cxt);
	(void) raw_parser(stmt);
	MemoryContextSwitchTo(oldCxt);

	/* Restore former ereport callback */
	error_context_stack = previous_errcontext;
}

static void
plpgsql_sql_error_callback(void *arg)
{
	char *sql_stmt = (char *) arg;

	Assert(plpgsql_error_funcname);

	errcontext("SQL statement in PL/PgSQL function \"%s\" near line %d",
			   plpgsql_error_funcname, plpgsql_error_lineno);
	internalerrquery(sql_stmt);
	internalerrposition(geterrposition());
	errposition(0);
}

static void
check_labels(const char *start_label, const char *end_label)
{
	if (end_label)
	{
		if (!start_label)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" specified for unlabelled block",
							end_label)));
		}

		if (strcmp(start_label, end_label) != 0)
		{
			plpgsql_error_lineno = plpgsql_scanner_lineno();
			ereport(ERROR,
					(errcode(ERRCODE_SYNTAX_ERROR),
					 errmsg("end label \"%s\" differs from block's label \"%s\"",
							end_label, start_label)));
		}
	}
}

#include "pl_scan.c"
