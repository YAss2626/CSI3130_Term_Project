/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with PLPGSQL_YY_ or plpgsql_yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 241 "y.tab.h"

};
typedef union PLPGSQL_YYSTYPE PLPGSQL_YYSTYPE;
# define PLPGSQL_YYSTYPE_IS_TRIVIAL 1
# define PLPGSQL_YYSTYPE_IS_DECLARED 1
#endif


extern PLPGSQL_YYSTYPE plpgsql_yylval;


int plpgsql_yyparse (void);


#endif /* !PLPGSQL_YY_PLPGSQL_YY_Y_TAB_H_INCLUDED  */
