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
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER_CONSTANT = 258,        /* INTEGER_CONSTANT  */
    STRING_CONSTANT = 259,         /* STRING_CONSTANT  */
    FLOAT_CONSTANT = 260,          /* FLOAT_CONSTANT  */
    TRUE = 261,                    /* TRUE  */
    FALSE = 262,                   /* FALSE  */
    INT = 263,                     /* INT  */
    DOUBLE = 264,                  /* DOUBLE  */
    STRING = 265,                  /* STRING  */
    BOOL = 266,                    /* BOOL  */
    MASS = 267,                    /* MASS  */
    TIME = 268,                    /* TIME  */
    POSITION = 269,                /* POSITION  */
    VELOCITY = 270,                /* VELOCITY  */
    ACC = 271,                     /* ACC  */
    ENERGY = 272,                  /* ENERGY  */
    THETA = 273,                   /* THETA  */
    E = 274,                       /* E  */
    DISTANCE = 275,                /* DISTANCE  */
    MOMENTUM = 276,                /* MOMENTUM  */
    ID = 277,                      /* ID  */
    INPUT = 278,                   /* INPUT  */
    OUTPUT = 279,                  /* OUTPUT  */
    SETR = 280,                    /* SETR  */
    ADDR = 281,                    /* ADDR  */
    SETV = 282,                    /* SETV  */
    ADDV = 283,                    /* ADDV  */
    SETA = 284,                    /* SETA  */
    ADDA = 285,                    /* ADDA  */
    SETP = 286,                    /* SETP  */
    GETR = 287,                    /* GETR  */
    GETA = 288,                    /* GETA  */
    GETV = 289,                    /* GETV  */
    KE_AFTER = 290,                /* KE_AFTER  */
    PE_AFTER = 291,                /* PE_AFTER  */
    TE_AFTER = 292,                /* TE_AFTER  */
    ANGLE_AFTER = 293,             /* ANGLE_AFTER  */
    V_AFTER = 294,                 /* V_AFTER  */
    R_AFTER = 295,                 /* R_AFTER  */
    GET_TRAJ = 296,                /* GET_TRAJ  */
    COLLIDE = 297,                 /* COLLIDE  */
    TIME_TO_COLLIDE = 298,         /* TIME_TO_COLLIDE  */
    ROC_AFTER = 299,               /* ROC_AFTER  */
    P_AFTER = 300,                 /* P_AFTER  */
    S_AFTER = 301,                 /* S_AFTER  */
    TIME_TO_R = 302,               /* TIME_TO_R  */
    TIME_TO_V = 303,               /* TIME_TO_V  */
    LOOP = 304,                    /* LOOP  */
    BREAK = 305,                   /* BREAK  */
    START = 306,                   /* START  */
    SIN = 307,                     /* SIN  */
    COS = 308,                     /* COS  */
    TAN = 309,                     /* TAN  */
    MAG = 310,                     /* MAG  */
    OPENCC = 311,                  /* OPENCC  */
    CLOSECC = 312,                 /* CLOSECC  */
    OPENSQ = 313,                  /* OPENSQ  */
    CLOSESQ = 314,                 /* CLOSESQ  */
    OPENCU = 315,                  /* OPENCU  */
    CLOSECU = 316,                 /* CLOSECU  */
    DOLLAR = 317,                  /* DOLLAR  */
    DOT = 318,                     /* DOT  */
    DOUBLE_QUOTE = 319,            /* DOUBLE_QUOTE  */
    SINGLE_QUOTE = 320,            /* SINGLE_QUOTE  */
    COMMA = 321,                   /* COMMA  */
    COLON = 322,                   /* COLON  */
    ARROW = 323,                   /* ARROW  */
    ADD = 324,                     /* ADD  */
    SUB = 325,                     /* SUB  */
    MUL = 326,                     /* MUL  */
    DIV = 327,                     /* DIV  */
    MOD = 328,                     /* MOD  */
    EXP = 329,                     /* EXP  */
    EQ = 330,                      /* EQ  */
    NEQ = 331,                     /* NEQ  */
    GEQ = 332,                     /* GEQ  */
    LEQ = 333,                     /* LEQ  */
    GT = 334,                      /* GT  */
    LT = 335,                      /* LT  */
    LOGICOP = 336,                 /* LOGICOP  */
    UNIOP = 337,                   /* UNIOP  */
    UNINEG = 338,                  /* UNINEG  */
    ASSGN = 339,                   /* ASSGN  */
    DARR = 340,                    /* DARR  */
    CMT = 341,                     /* CMT  */
    QUESTION = 342,                /* QUESTION  */
    NON_NEGATIVE_INT = 343,        /* NON_NEGATIVE_INT  */
    FIRST = 344,                   /* FIRST  */
    SECOND = 345,                  /* SECOND  */
    OTHERWISE = 346,               /* OTHERWISE  */
    SCOPEOPEN = 347,               /* SCOPEOPEN  */
    SCOPECLOSE = 348               /* SCOPECLOSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INTEGER_CONSTANT 258
#define STRING_CONSTANT 259
#define FLOAT_CONSTANT 260
#define TRUE 261
#define FALSE 262
#define INT 263
#define DOUBLE 264
#define STRING 265
#define BOOL 266
#define MASS 267
#define TIME 268
#define POSITION 269
#define VELOCITY 270
#define ACC 271
#define ENERGY 272
#define THETA 273
#define E 274
#define DISTANCE 275
#define MOMENTUM 276
#define ID 277
#define INPUT 278
#define OUTPUT 279
#define SETR 280
#define ADDR 281
#define SETV 282
#define ADDV 283
#define SETA 284
#define ADDA 285
#define SETP 286
#define GETR 287
#define GETA 288
#define GETV 289
#define KE_AFTER 290
#define PE_AFTER 291
#define TE_AFTER 292
#define ANGLE_AFTER 293
#define V_AFTER 294
#define R_AFTER 295
#define GET_TRAJ 296
#define COLLIDE 297
#define TIME_TO_COLLIDE 298
#define ROC_AFTER 299
#define P_AFTER 300
#define S_AFTER 301
#define TIME_TO_R 302
#define TIME_TO_V 303
#define LOOP 304
#define BREAK 305
#define START 306
#define SIN 307
#define COS 308
#define TAN 309
#define MAG 310
#define OPENCC 311
#define CLOSECC 312
#define OPENSQ 313
#define CLOSESQ 314
#define OPENCU 315
#define CLOSECU 316
#define DOLLAR 317
#define DOT 318
#define DOUBLE_QUOTE 319
#define SINGLE_QUOTE 320
#define COMMA 321
#define COLON 322
#define ARROW 323
#define ADD 324
#define SUB 325
#define MUL 326
#define DIV 327
#define MOD 328
#define EXP 329
#define EQ 330
#define NEQ 331
#define GEQ 332
#define LEQ 333
#define GT 334
#define LT 335
#define LOGICOP 336
#define UNIOP 337
#define UNINEG 338
#define ASSGN 339
#define DARR 340
#define CMT 341
#define QUESTION 342
#define NON_NEGATIVE_INT 343
#define FIRST 344
#define SECOND 345
#define OTHERWISE 346
#define SCOPEOPEN 347
#define SCOPECLOSE 348

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "parse.y"

	struct variable {
		char* value;
		int type;
	} object;
  struct for_args {
    char* list[100];
    int present;
  } arg_object ;

#line 264 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
