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
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
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
#line 1 "parse.y"

#include <bits/stdc++.h>
#include "semantics.hpp"

<<<<<<< HEAD
extern FILE *yyin, *tokfile, *parsefile, *outfile ;
extern int yylineno;
int yylex();
void yyerror(char *s);

#line 81 "y.tab.c"
=======
extern FILE *yyin, *tokfile, *parsefile ;
extern int yylineno;
int yylex();
void yyerror(char *s);
bool arr_check=false;
int dim_count = 0;

#line 83 "y.tab.c"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

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
<<<<<<< HEAD
#line 11 "parse.y"
=======
#line 13 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

	struct variable {
		char* value;
		int type;
	} object;
  struct for_args {
    char* list[100];
    int present;
  } arg_object ;

<<<<<<< HEAD
#line 331 "y.tab.c"
=======
#line 333 "y.tab.c"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER_CONSTANT = 3,           /* INTEGER_CONSTANT  */
  YYSYMBOL_STRING_CONSTANT = 4,            /* STRING_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 5,             /* FLOAT_CONSTANT  */
  YYSYMBOL_TRUE = 6,                       /* TRUE  */
  YYSYMBOL_FALSE = 7,                      /* FALSE  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_MASS = 12,                      /* MASS  */
  YYSYMBOL_TIME = 13,                      /* TIME  */
  YYSYMBOL_POSITION = 14,                  /* POSITION  */
  YYSYMBOL_VELOCITY = 15,                  /* VELOCITY  */
  YYSYMBOL_ACC = 16,                       /* ACC  */
  YYSYMBOL_ENERGY = 17,                    /* ENERGY  */
  YYSYMBOL_THETA = 18,                     /* THETA  */
  YYSYMBOL_E = 19,                         /* E  */
  YYSYMBOL_DISTANCE = 20,                  /* DISTANCE  */
  YYSYMBOL_MOMENTUM = 21,                  /* MOMENTUM  */
  YYSYMBOL_ID = 22,                        /* ID  */
  YYSYMBOL_INPUT = 23,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 24,                    /* OUTPUT  */
  YYSYMBOL_SETR = 25,                      /* SETR  */
  YYSYMBOL_ADDR = 26,                      /* ADDR  */
  YYSYMBOL_SETV = 27,                      /* SETV  */
  YYSYMBOL_ADDV = 28,                      /* ADDV  */
  YYSYMBOL_SETA = 29,                      /* SETA  */
  YYSYMBOL_ADDA = 30,                      /* ADDA  */
  YYSYMBOL_SETP = 31,                      /* SETP  */
  YYSYMBOL_GETR = 32,                      /* GETR  */
  YYSYMBOL_GETA = 33,                      /* GETA  */
  YYSYMBOL_GETV = 34,                      /* GETV  */
  YYSYMBOL_KE_AFTER = 35,                  /* KE_AFTER  */
  YYSYMBOL_PE_AFTER = 36,                  /* PE_AFTER  */
  YYSYMBOL_TE_AFTER = 37,                  /* TE_AFTER  */
  YYSYMBOL_ANGLE_AFTER = 38,               /* ANGLE_AFTER  */
  YYSYMBOL_V_AFTER = 39,                   /* V_AFTER  */
  YYSYMBOL_R_AFTER = 40,                   /* R_AFTER  */
  YYSYMBOL_GET_TRAJ = 41,                  /* GET_TRAJ  */
  YYSYMBOL_COLLIDE = 42,                   /* COLLIDE  */
  YYSYMBOL_TIME_TO_COLLIDE = 43,           /* TIME_TO_COLLIDE  */
  YYSYMBOL_ROC_AFTER = 44,                 /* ROC_AFTER  */
  YYSYMBOL_P_AFTER = 45,                   /* P_AFTER  */
  YYSYMBOL_S_AFTER = 46,                   /* S_AFTER  */
  YYSYMBOL_TIME_TO_R = 47,                 /* TIME_TO_R  */
  YYSYMBOL_TIME_TO_V = 48,                 /* TIME_TO_V  */
  YYSYMBOL_LOOP = 49,                      /* LOOP  */
  YYSYMBOL_BREAK = 50,                     /* BREAK  */
  YYSYMBOL_START = 51,                     /* START  */
  YYSYMBOL_SIN = 52,                       /* SIN  */
  YYSYMBOL_COS = 53,                       /* COS  */
  YYSYMBOL_TAN = 54,                       /* TAN  */
  YYSYMBOL_MAG = 55,                       /* MAG  */
  YYSYMBOL_OPENCC = 56,                    /* OPENCC  */
  YYSYMBOL_CLOSECC = 57,                   /* CLOSECC  */
  YYSYMBOL_OPENSQ = 58,                    /* OPENSQ  */
  YYSYMBOL_CLOSESQ = 59,                   /* CLOSESQ  */
  YYSYMBOL_OPENCU = 60,                    /* OPENCU  */
  YYSYMBOL_CLOSECU = 61,                   /* CLOSECU  */
  YYSYMBOL_DOLLAR = 62,                    /* DOLLAR  */
  YYSYMBOL_DOT = 63,                       /* DOT  */
  YYSYMBOL_DOUBLE_QUOTE = 64,              /* DOUBLE_QUOTE  */
  YYSYMBOL_SINGLE_QUOTE = 65,              /* SINGLE_QUOTE  */
  YYSYMBOL_COMMA = 66,                     /* COMMA  */
  YYSYMBOL_COLON = 67,                     /* COLON  */
  YYSYMBOL_ARROW = 68,                     /* ARROW  */
  YYSYMBOL_ADD = 69,                       /* ADD  */
  YYSYMBOL_SUB = 70,                       /* SUB  */
  YYSYMBOL_MUL = 71,                       /* MUL  */
  YYSYMBOL_DIV = 72,                       /* DIV  */
  YYSYMBOL_MOD = 73,                       /* MOD  */
  YYSYMBOL_EXP = 74,                       /* EXP  */
  YYSYMBOL_EQ = 75,                        /* EQ  */
  YYSYMBOL_NEQ = 76,                       /* NEQ  */
  YYSYMBOL_GEQ = 77,                       /* GEQ  */
  YYSYMBOL_LEQ = 78,                       /* LEQ  */
  YYSYMBOL_GT = 79,                        /* GT  */
  YYSYMBOL_LT = 80,                        /* LT  */
  YYSYMBOL_LOGICOP = 81,                   /* LOGICOP  */
  YYSYMBOL_UNIOP = 82,                     /* UNIOP  */
  YYSYMBOL_UNINEG = 83,                    /* UNINEG  */
  YYSYMBOL_ASSGN = 84,                     /* ASSGN  */
  YYSYMBOL_DARR = 85,                      /* DARR  */
  YYSYMBOL_CMT = 86,                       /* CMT  */
  YYSYMBOL_QUESTION = 87,                  /* QUESTION  */
  YYSYMBOL_NON_NEGATIVE_INT = 88,          /* NON_NEGATIVE_INT  */
  YYSYMBOL_FIRST = 89,                     /* FIRST  */
  YYSYMBOL_SECOND = 90,                    /* SECOND  */
  YYSYMBOL_OTHERWISE = 91,                 /* OTHERWISE  */
  YYSYMBOL_SCOPEOPEN = 92,                 /* SCOPEOPEN  */
  YYSYMBOL_SCOPECLOSE = 93,                /* SCOPECLOSE  */
  YYSYMBOL_YYACCEPT = 94,                  /* $accept  */
  YYSYMBOL_code = 95,                      /* code  */
  YYSYMBOL_code_subpart = 96,              /* code_subpart  */
  YYSYMBOL_startfn = 97,                   /* startfn  */
  YYSYMBOL_98_1 = 98,                      /* $@1  */
  YYSYMBOL_99_2 = 99,                      /* $@2  */
  YYSYMBOL_body = 100,                     /* body  */
  YYSYMBOL_101_3 = 101,                    /* $@3  */
  YYSYMBOL_102_4 = 102,                    /* $@4  */
<<<<<<< HEAD
  YYSYMBOL_103_5 = 103,                    /* $@5  */
  YYSYMBOL_104_6 = 104,                    /* $@6  */
  YYSYMBOL_loop_body = 105,                /* loop_body  */
  YYSYMBOL_106_7 = 106,                    /* $@7  */
  YYSYMBOL_107_8 = 107,                    /* $@8  */
  YYSYMBOL_108_9 = 108,                    /* $@9  */
  YYSYMBOL_109_10 = 109,                   /* $@10  */
  YYSYMBOL_110_11 = 110,                   /* $@11  */
  YYSYMBOL_bi_op = 111,                    /* bi_op  */
  YYSYMBOL_relop = 112,                    /* relop  */
  YYSYMBOL_vectors = 113,                  /* vectors  */
  YYSYMBOL_114_12 = 114,                   /* $@12  */
  YYSYMBOL_115_13 = 115,                   /* $@13  */
  YYSYMBOL_116_14 = 116,                   /* $@14  */
  YYSYMBOL_primi_datatype = 117,           /* primi_datatype  */
  YYSYMBOL_non_pri_datatype = 118,         /* non_pri_datatype  */
  YYSYMBOL_datatypes = 119,                /* datatypes  */
  YYSYMBOL_single_variable = 120,          /* single_variable  */
  YYSYMBOL_121_15 = 121,                   /* $@15  */
  YYSYMBOL_dim_con = 122,                  /* dim_con  */
  YYSYMBOL_dimensions = 123,               /* dimensions  */
  YYSYMBOL_124_16 = 124,                   /* $@16  */
  YYSYMBOL_single_variable_for_exp_stmt = 125, /* single_variable_for_exp_stmt  */
  YYSYMBOL_exp_stmt = 126,                 /* exp_stmt  */
  YYSYMBOL_127_17 = 127,                   /* $@17  */
  YYSYMBOL_128_18 = 128,                   /* $@18  */
  YYSYMBOL_pos = 129,                      /* pos  */
  YYSYMBOL_anything_with_value = 130,      /* anything_with_value  */
  YYSYMBOL_131_19 = 131,                   /* $@19  */
  YYSYMBOL_operations = 132,               /* operations  */
  YYSYMBOL_rhs_term = 133,                 /* rhs_term  */
  YYSYMBOL_rhs_exp = 134,                  /* rhs_exp  */
  YYSYMBOL_openccs = 135,                  /* openccs  */
  YYSYMBOL_closeccs = 136,                 /* closeccs  */
  YYSYMBOL_call_stmt_with_dot = 137,       /* call_stmt_with_dot  */
  YYSYMBOL_call_stmt_without_dot = 138,    /* call_stmt_without_dot  */
  YYSYMBOL_139_20 = 139,                   /* $@20  */
  YYSYMBOL_funccallargs = 140,             /* funccallargs  */
  YYSYMBOL_141_21 = 141,                   /* $@21  */
  YYSYMBOL_conditional_stmt_start = 142,   /* conditional_stmt_start  */
  YYSYMBOL_143_22 = 143,                   /* $@22  */
  YYSYMBOL_conditional_stmt = 144,         /* conditional_stmt  */
  YYSYMBOL_145_23 = 145,                   /* $@23  */
  YYSYMBOL_146_24 = 146,                   /* $@24  */
  YYSYMBOL_loop_stmt = 147,                /* loop_stmt  */
  YYSYMBOL_148_25 = 148,                   /* $@25  */
  YYSYMBOL_149_26 = 149,                   /* $@26  */
  YYSYMBOL_unary_operation_without_dot = 150, /* unary_operation_without_dot  */
  YYSYMBOL_151_27 = 151,                   /* $@27  */
  YYSYMBOL_return_stmt = 152,              /* return_stmt  */
  YYSYMBOL_153_28 = 153,                   /* $@28  */
  YYSYMBOL_comments = 154,                 /* comments  */
  YYSYMBOL_output_stmt = 155,              /* output_stmt  */
  YYSYMBOL_156_29 = 156,                   /* $@29  */
  YYSYMBOL_input_stmt = 157,               /* input_stmt  */
  YYSYMBOL_158_30 = 158,                   /* $@30  */
  YYSYMBOL_ids = 159,                      /* ids  */
  YYSYMBOL_160_31 = 160,                   /* $@31  */
  YYSYMBOL_161_32 = 161,                   /* $@32  */
  YYSYMBOL_inbuilt_functions_with_dot = 162, /* inbuilt_functions_with_dot  */
  YYSYMBOL_inbuilt_functions = 163,        /* inbuilt_functions  */
  YYSYMBOL_stand_id = 164,                 /* stand_id  */
  YYSYMBOL_rel_to_mag = 165,               /* rel_to_mag  */
  YYSYMBOL_rel_to_pos = 166,               /* rel_to_pos  */
  YYSYMBOL_rel_to_vel = 167,               /* rel_to_vel  */
  YYSYMBOL_rel_to_momentum = 168,          /* rel_to_momentum  */
  YYSYMBOL_rel_to_acc = 169,               /* rel_to_acc  */
  YYSYMBOL_rel_to_energy = 170,            /* rel_to_energy  */
  YYSYMBOL_rel_to_angle = 171,             /* rel_to_angle  */
  YYSYMBOL_rel_to_collision = 172,         /* rel_to_collision  */
  YYSYMBOL_miscellaneous = 173,            /* miscellaneous  */
  YYSYMBOL_term_misc = 174,                /* term_misc  */
  YYSYMBOL_decl_stmt_with_exp = 175,       /* decl_stmt_with_exp  */
  YYSYMBOL_expressions = 176,              /* expressions  */
  YYSYMBOL_177_33 = 177,                   /* $@33  */
  YYSYMBOL_single_variable_declare = 178,  /* single_variable_declare  */
  YYSYMBOL_check_rhs_exp = 179,            /* check_rhs_exp  */
  YYSYMBOL_180_34 = 180,                   /* $@34  */
  YYSYMBOL_expression = 181,               /* expression  */
  YYSYMBOL_182_35 = 182,                   /* $@35  */
  YYSYMBOL_idadd2 = 183,                   /* idadd2  */
  YYSYMBOL_function_decl = 184,            /* function_decl  */
  YYSYMBOL_185_36 = 185,                   /* $@36  */
  YYSYMBOL_186_37 = 186,                   /* $@37  */
  YYSYMBOL_187_38 = 187,                   /* $@38  */
  YYSYMBOL_188_39 = 188,                   /* $@39  */
  YYSYMBOL_189_40 = 189,                   /* $@40  */
  YYSYMBOL_190_41 = 190,                   /* $@41  */
  YYSYMBOL_191_42 = 191,                   /* $@42  */
  YYSYMBOL_192_43 = 192,                   /* $@43  */
  YYSYMBOL_parameters = 193,               /* parameters  */
  YYSYMBOL_194_44 = 194,                   /* $@44  */
  YYSYMBOL_195_45 = 195,                   /* $@45  */
  YYSYMBOL_196_46 = 196                    /* $@46  */
=======
  YYSYMBOL_loop_body = 103,                /* loop_body  */
  YYSYMBOL_104_5 = 104,                    /* $@5  */
  YYSYMBOL_105_6 = 105,                    /* $@6  */
  YYSYMBOL_bi_op = 106,                    /* bi_op  */
  YYSYMBOL_relop = 107,                    /* relop  */
  YYSYMBOL_vectors = 108,                  /* vectors  */
  YYSYMBOL_primi_datatype = 109,           /* primi_datatype  */
  YYSYMBOL_non_pri_datatype = 110,         /* non_pri_datatype  */
  YYSYMBOL_datatypes = 111,                /* datatypes  */
  YYSYMBOL_single_variable = 112,          /* single_variable  */
  YYSYMBOL_dimensions = 113,               /* dimensions  */
  YYSYMBOL_single_variable_for_exp_stmt = 114, /* single_variable_for_exp_stmt  */
  YYSYMBOL_exp_stmt = 115,                 /* exp_stmt  */
  YYSYMBOL_pos = 116,                      /* pos  */
  YYSYMBOL_anything_with_value = 117,      /* anything_with_value  */
  YYSYMBOL_operations = 118,               /* operations  */
  YYSYMBOL_rhs_term = 119,                 /* rhs_term  */
  YYSYMBOL_rhs_exp = 120,                  /* rhs_exp  */
  YYSYMBOL_openccs = 121,                  /* openccs  */
  YYSYMBOL_closeccs = 122,                 /* closeccs  */
  YYSYMBOL_call_stmt_with_dot = 123,       /* call_stmt_with_dot  */
  YYSYMBOL_call_stmt_without_dot = 124,    /* call_stmt_without_dot  */
  YYSYMBOL_funccallargs = 125,             /* funccallargs  */
  YYSYMBOL_conditional_stmt_start = 126,   /* conditional_stmt_start  */
  YYSYMBOL_conditional_stmt = 127,         /* conditional_stmt  */
  YYSYMBOL_128_7 = 128,                    /* $@7  */
  YYSYMBOL_129_8 = 129,                    /* $@8  */
  YYSYMBOL_loop_stmt = 130,                /* loop_stmt  */
  YYSYMBOL_131_9 = 131,                    /* $@9  */
  YYSYMBOL_unary_operation_without_dot = 132, /* unary_operation_without_dot  */
  YYSYMBOL_return_stmt = 133,              /* return_stmt  */
  YYSYMBOL_comments = 134,                 /* comments  */
  YYSYMBOL_output_stmt = 135,              /* output_stmt  */
  YYSYMBOL_input_stmt = 136,               /* input_stmt  */
  YYSYMBOL_ids = 137,                      /* ids  */
  YYSYMBOL_138_10 = 138,                   /* $@10  */
  YYSYMBOL_inbuilt_functions_with_dot = 139, /* inbuilt_functions_with_dot  */
  YYSYMBOL_inbuilt_functions = 140,        /* inbuilt_functions  */
  YYSYMBOL_stand_id = 141,                 /* stand_id  */
  YYSYMBOL_rel_to_mag = 142,               /* rel_to_mag  */
  YYSYMBOL_rel_to_pos = 143,               /* rel_to_pos  */
  YYSYMBOL_rel_to_vel = 144,               /* rel_to_vel  */
  YYSYMBOL_rel_to_momentum = 145,          /* rel_to_momentum  */
  YYSYMBOL_rel_to_acc = 146,               /* rel_to_acc  */
  YYSYMBOL_rel_to_energy = 147,            /* rel_to_energy  */
  YYSYMBOL_rel_to_angle = 148,             /* rel_to_angle  */
  YYSYMBOL_rel_to_collision = 149,         /* rel_to_collision  */
  YYSYMBOL_miscellaneous = 150,            /* miscellaneous  */
  YYSYMBOL_term_misc = 151,                /* term_misc  */
  YYSYMBOL_decl_stmt_with_exp = 152,       /* decl_stmt_with_exp  */
  YYSYMBOL_expressions = 153,              /* expressions  */
  YYSYMBOL_single_variable_declare = 154,  /* single_variable_declare  */
  YYSYMBOL_check_rhs_exp = 155,            /* check_rhs_exp  */
  YYSYMBOL_156_11 = 156,                   /* $@11  */
  YYSYMBOL_expression = 157,               /* expression  */
  YYSYMBOL_idadd2 = 158,                   /* idadd2  */
  YYSYMBOL_function_decl = 159,            /* function_decl  */
  YYSYMBOL_160_12 = 160,                   /* $@12  */
  YYSYMBOL_161_13 = 161,                   /* $@13  */
  YYSYMBOL_162_14 = 162,                   /* $@14  */
  YYSYMBOL_163_15 = 163,                   /* $@15  */
  YYSYMBOL_parameters = 164,               /* parameters  */
  YYSYMBOL_165_16 = 165                    /* $@16  */
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
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
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
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
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
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
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
<<<<<<< HEAD
#define YYLAST   852
=======
#define YYLAST   942
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
<<<<<<< HEAD
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  220
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  407
=======
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  189
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   348


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
<<<<<<< HEAD
       0,    64,    64,    65,    68,    69,    70,    74,    76,    73,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    99,    99,    99,    99,   100,   101,   104,   105,   106,
     107,   108,   108,   109,   110,   111,   112,   113,   114,   114,
     114,   114,   114,   115,   116,   117,   120,   121,   122,   123,
     124,   125,   128,   129,   130,   131,   132,   133,   136,   136,
     136,   136,   147,   149,   151,   153,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   169,   170,   175,   176,
     176,   179,   181,   190,   190,   202,   210,   210,   210,   217,
     218,   221,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   232,   233,   236,   237,   238,   239,   250,   253,   255,
     257,   261,   262,   263,   266,   267,   268,   271,   275,   279,
     280,   283,   284,   287,   288,   293,   296,   307,   307,   319,
     324,   324,   336,   336,   340,   341,   341,   341,   346,   346,
     346,   351,   359,   359,   369,   369,   370,   375,   380,   380,
     385,   385,   388,   390,   388,   391,   398,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   412,   420,   421,   424,
     427,   430,   433,   436,   439,   442,   445,   448,   453,   456,
     459,   462,   465,   468,   473,   478,   479,   480,   483,   486,
     489,   492,   493,   496,   499,   504,   507,   507,   508,   511,
     525,   525,   527,   527,   528,   533,   539,   539,   539,   540,
     541,   539,   554,   554,   555,   554,   570,   570,   579,   586,
     578
=======
       0,    67,    67,    68,    71,    72,    73,    77,    79,    76,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   102,   102,   103,   104,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   117,   117,   118,   119,
     120,   123,   124,   125,   126,   127,   128,   131,   132,   133,
     134,   135,   136,   139,   148,   149,   150,   151,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   166,   167,
     172,   173,   177,   186,   199,   207,   213,   214,   217,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   232,
     233,   234,   235,   246,   249,   251,   253,   257,   258,   259,
     262,   263,   264,   267,   270,   273,   274,   277,   278,   281,
     282,   287,   290,   300,   311,   316,   328,   332,   333,   333,
     333,   338,   338,   343,   348,   358,   359,   364,   369,   374,
     377,   377,   380,   387,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   401,   409,   410,   413,   416,   419,   422,
     425,   428,   431,   434,   437,   442,   445,   448,   451,   454,
     457,   462,   467,   468,   469,   472,   475,   478,   481,   482,
     485,   488,   493,   496,   497,   500,   518,   518,   520,   521,
     526,   530,   531,   530,   543,   544,   543,   558,   567,   566
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER_CONSTANT",
  "STRING_CONSTANT", "FLOAT_CONSTANT", "TRUE", "FALSE", "INT", "DOUBLE",
  "STRING", "BOOL", "MASS", "TIME", "POSITION", "VELOCITY", "ACC",
  "ENERGY", "THETA", "E", "DISTANCE", "MOMENTUM", "ID", "INPUT", "OUTPUT",
  "SETR", "ADDR", "SETV", "ADDV", "SETA", "ADDA", "SETP", "GETR", "GETA",
  "GETV", "KE_AFTER", "PE_AFTER", "TE_AFTER", "ANGLE_AFTER", "V_AFTER",
  "R_AFTER", "GET_TRAJ", "COLLIDE", "TIME_TO_COLLIDE", "ROC_AFTER",
  "P_AFTER", "S_AFTER", "TIME_TO_R", "TIME_TO_V", "LOOP", "BREAK", "START",
  "SIN", "COS", "TAN", "MAG", "OPENCC", "CLOSECC", "OPENSQ", "CLOSESQ",
  "OPENCU", "CLOSECU", "DOLLAR", "DOT", "DOUBLE_QUOTE", "SINGLE_QUOTE",
  "COMMA", "COLON", "ARROW", "ADD", "SUB", "MUL", "DIV", "MOD", "EXP",
  "EQ", "NEQ", "GEQ", "LEQ", "GT", "LT", "LOGICOP", "UNIOP", "UNINEG",
  "ASSGN", "DARR", "CMT", "QUESTION", "NON_NEGATIVE_INT", "FIRST",
  "SECOND", "OTHERWISE", "SCOPEOPEN", "SCOPECLOSE", "$accept", "code",
<<<<<<< HEAD
  "code_subpart", "startfn", "$@1", "$@2", "body", "$@3", "$@4", "$@5",
  "$@6", "loop_body", "$@7", "$@8", "$@9", "$@10", "$@11", "bi_op",
  "relop", "vectors", "$@12", "$@13", "$@14", "primi_datatype",
  "non_pri_datatype", "datatypes", "single_variable", "$@15", "dim_con",
  "dimensions", "$@16", "single_variable_for_exp_stmt", "exp_stmt", "$@17",
  "$@18", "pos", "anything_with_value", "$@19", "operations", "rhs_term",
  "rhs_exp", "openccs", "closeccs", "call_stmt_with_dot",
  "call_stmt_without_dot", "$@20", "funccallargs", "$@21",
  "conditional_stmt_start", "$@22", "conditional_stmt", "$@23", "$@24",
  "loop_stmt", "$@25", "$@26", "unary_operation_without_dot", "$@27",
  "return_stmt", "$@28", "comments", "output_stmt", "$@29", "input_stmt",
  "$@30", "ids", "$@31", "$@32", "inbuilt_functions_with_dot",
  "inbuilt_functions", "stand_id", "rel_to_mag", "rel_to_pos",
  "rel_to_vel", "rel_to_momentum", "rel_to_acc", "rel_to_energy",
  "rel_to_angle", "rel_to_collision", "miscellaneous", "term_misc",
  "decl_stmt_with_exp", "expressions", "$@33", "single_variable_declare",
  "check_rhs_exp", "$@34", "expression", "$@35", "idadd2", "function_decl",
  "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42", "$@43",
  "parameters", "$@44", "$@45", "$@46", YY_NULLPTR
=======
  "code_subpart", "startfn", "$@1", "$@2", "body", "$@3", "$@4",
  "loop_body", "$@5", "$@6", "bi_op", "relop", "vectors", "primi_datatype",
  "non_pri_datatype", "datatypes", "single_variable", "dimensions",
  "single_variable_for_exp_stmt", "exp_stmt", "pos", "anything_with_value",
  "operations", "rhs_term", "rhs_exp", "openccs", "closeccs",
  "call_stmt_with_dot", "call_stmt_without_dot", "funccallargs",
  "conditional_stmt_start", "conditional_stmt", "$@7", "$@8", "loop_stmt",
  "$@9", "unary_operation_without_dot", "return_stmt", "comments",
  "output_stmt", "input_stmt", "ids", "$@10", "inbuilt_functions_with_dot",
  "inbuilt_functions", "stand_id", "rel_to_mag", "rel_to_pos",
  "rel_to_vel", "rel_to_momentum", "rel_to_acc", "rel_to_energy",
  "rel_to_angle", "rel_to_collision", "miscellaneous", "term_misc",
  "decl_stmt_with_exp", "expressions", "single_variable_declare",
  "check_rhs_exp", "$@11", "expression", "idadd2", "function_decl", "$@12",
  "$@13", "$@14", "$@15", "parameters", "$@16", YY_NULLPTR
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

<<<<<<< HEAD
#define YYPACT_NINF (-259)
=======
#define YYPACT_NINF (-263)
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

<<<<<<< HEAD
#define YYTABLE_NINF (-219)
=======
#define YYTABLE_NINF (-189)
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
     766,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,   -37,  -259,   496,  -259,  -259,
    -259,  -259,     6,  -259,  -259,  -259,  -259,  -259,  -259,   -51,
     681,   -25,   -29,   -31,   -30,   -19,   -20,  -259,    19,  -259,
     -18,  -259,  -259,    26,   -26,   -35,   681,   681,   -12,   664,
     681,   681,     5,   681,   681,   681,   681,   681,    48,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   681,     2,
      53,    57,  -259,  -259,  -259,   -14,  -259,  -259,    55,  -259,
    -259,  -259,    58,    56,    63,  -259,    59,    39,    60,  -259,
    -259,  -259,  -259,  -259,    62,  -259,    66,   664,   664,   664,
     664,    67,   664,   664,   664,   664,   664,   664,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,    44,   810,
    -259,  -259,  -259,  -259,  -259,    26,  -259,  -259,  -259,    71,
      72,    65,   388,   763,  -259,    73,  -259,  -259,  -259,  -259,
    -259,  -259,   664,    77,    51,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,    84,   123,    85,    86,
      82,    90,    91,    92,    93,    98,  -259,  -259,  -259,   102,
    -259,  -259,  -259,  -259,  -259,   -38,   113,   115,   117,  -259,
    -259,  -259,   107,    95,   587,   383,  -259,   557,   111,   112,
     121,   126,   127,   131,   132,   133,   134,  -259,  -259,  -259,
     135,   136,   137,   138,   140,   141,   142,   145,   149,   151,
     152,   153,   154,  -259,   681,  -259,    26,   155,  -259,  -259,
     124,   664,  -259,   150,  -259,  -259,  -259,   159,   157,  -259,
    -259,   160,   158,  -259,   -75,   518,   518,   518,   518,   -75,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,   388,   164,   388,
    -259,   168,   -75,   -75,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,    19,    19,  -259,
    -259,  -259,   161,   161,    96,  -259,  -259,  -259,   664,   177,
    -259,  -259,  -259,   176,   162,  -259,    57,  -259,  -259,  -259,
    -259,  -259,  -259,   187,   188,   189,  -259,  -259,  -259,  -259,
    -259,   164,  -259,  -259,   190,   191,   192,   193,   195,   196,
     197,   198,   202,   203,   204,   206,   207,   -40,   208,   209,
     211,   213,  -259,   184,  -259,   210,  -259,  -259,   180,  -259,
     681,  -259,   215,  -259,  -259,    26,   664,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,   268,  -259,  -259,  -259,  -259,
     161,   161,   230,  -259,   664,  -259,   810,  -259,  -259,   231,
     234,   233,   247,   259,  -259,   260,   261,   264,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,   681,  -259,  -259,  -259,   681,
    -259,  -259,   681,  -259,  -259,   265,  -259
=======
     799,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,   -38,  -263,   550,  -263,  -263,
    -263,  -263,    -7,  -263,  -263,  -263,  -263,  -263,  -263,   -65,
     746,   -33,   -32,   -28,   -27,   -23,   -19,  -263,    20,  -263,
     -18,  -263,  -263,    22,   -36,   -37,   746,   746,   -13,   693,
     746,   746,   -12,   746,   746,   746,   746,   746,   -11,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,   746,   843,
    -263,    -4,  -263,    22,  -263,  -263,   -15,     5,   533,  -263,
      30,  -263,  -263,     3,    23,    34,   -10,  -263,    35,    13,
      37,  -263,  -263,  -263,  -263,  -263,    48,  -263,    49,   693,
     693,   693,   693,    53,   693,   693,   693,   693,   693,   693,
    -263,  -263,   746,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
      33,    97,    59,    62,  -263,    64,    57,    63,    65,    66,
      68,  -263,    69,    70,    74,  -263,  -263,  -263,  -263,  -263,
     -44,    79,    80,    81,  -263,   640,  -263,    72,    56,   817,
     323,  -263,   573,    76,    77,   880,  -263,   746,  -263,  -263,
    -263,    22,    78,   693,    82,    67,  -263,  -263,  -263,  -263,
     693,  -263,  -263,  -263,  -263,  -263,  -263,  -263,   100,    91,
      86,   -10,  -263,  -263,    96,  -263,  -263,   104,    99,  -263,
    -263,  -263,   -56,   640,   640,   640,  -263,   -56,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,   533,   110,   533,  -263,   111,
     -56,   -56,   109,   116,   127,   134,   135,   136,   137,  -263,
    -263,  -263,   138,   139,   140,   141,   142,   143,   145,   151,
     152,   153,   154,   158,   160,   128,  -263,  -263,  -263,  -263,
     693,   131,  -263,  -263,   159,   163,  -263,  -263,    22,  -263,
    -263,  -263,  -263,  -263,   167,   169,   170,  -263,  -263,  -263,
    -263,   110,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,    20,    20,  -263,
    -263,  -263,   146,   146,  -263,   144,   172,   746,   921,  -263,
    -263,   693,   175,  -263,  -263,  -263,   177,   178,   179,   180,
     181,   183,   184,   185,   187,   188,   190,   192,   199,   -41,
     206,   207,   208,   210,  -263,   209,  -263,   213,   211,  -263,
    -263,  -263,  -263,   746,   212,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
     252,  -263,  -263,  -263,  -263,   146,   146,   746,   219,   693,
     221,  -263,  -263,   222,   223,   224,  -263,   746,   225,  -263,
     226,  -263,  -263,  -263,  -263,  -263,  -263
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
<<<<<<< HEAD
       0,    62,    63,    65,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,   147,     0,     2,     5,
      76,    77,     0,     4,     6,     7,     1,     3,   205,     0,
      19,     0,    78,     0,     0,     0,     0,   132,     0,   142,
     144,    20,     8,     0,    85,     0,    19,    19,     0,    37,
      19,    19,     0,    19,    19,    19,    19,    19,     0,   157,
     159,   158,   164,   160,   161,   162,   163,   165,    19,   206,
     127,     0,   150,   148,   138,     0,   200,   166,     0,   200,
     146,   200,     0,     0,    78,   199,     0,   204,   198,   141,
      86,    10,    11,   125,     0,    38,     0,    37,    37,    37,
      37,     0,    37,    37,    37,    37,    37,    37,    12,    13,
      14,    15,    16,    17,    18,    25,   156,    26,     0,     0,
     126,   200,    81,   200,    80,     0,   200,   200,    58,     0,
       0,     0,     0,     0,   143,     0,    21,     9,   195,   202,
     196,   200,    37,     0,   134,    27,    28,    29,    30,    31,
      33,    34,    35,    36,    43,    44,     0,     0,     0,     0,
     129,     0,   152,     0,     0,     0,   200,   168,   167,     0,
      93,    95,    94,    96,    97,    78,     0,     0,     0,   122,
     100,    92,    99,    91,   120,   119,   201,     0,    98,   104,
       0,     0,     0,     0,     0,     0,     0,   172,   180,   176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,    19,   200,     0,     0,    45,    39,
       0,    37,   212,   216,   207,   128,   130,    82,     0,   151,
     149,     0,     0,   133,     0,     0,     0,     0,     0,     0,
     107,   124,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    56,    55,    57,   112,   111,   113,     0,   116,     0,
     121,   114,     0,     0,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,     0,     0,   200,
     200,   200,   200,   200,     0,   203,   197,    87,    37,     0,
      32,   213,   217,     0,     0,   200,     0,   153,   139,    59,
      89,    90,   106,     0,     0,     0,   101,   105,   118,   123,
     117,   115,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,   193,     0,    22,    88,     0,   136,
      19,   219,     0,   131,    84,     0,    37,   200,   108,   109,
     110,   169,   170,   173,   174,   178,   179,   177,   181,   182,
     183,   184,   175,   171,   186,     0,   187,   189,   190,   188,
     200,   200,     0,    40,    37,   214,     0,   208,   154,     0,
       0,     0,     0,     0,    23,     0,     0,     0,   220,   209,
     140,    60,   185,   191,   192,    19,    41,   137,   215,    19,
      61,    24,    19,   210,    42,     0,   211
=======
       0,    54,    55,    57,    56,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,   127,     0,     2,     5,
      68,    69,     0,     4,     6,     7,     1,     3,   180,     0,
      19,     0,    70,     0,     0,     0,     0,   176,     0,   176,
     176,    20,     8,     0,    74,     0,    19,    19,     0,    34,
      19,    19,     0,    19,    19,    19,    19,    19,     0,   134,
     136,   135,   141,   137,   138,   139,   140,   142,    19,     0,
     176,   176,    71,     0,   176,   176,     0,     0,     0,   143,
       0,   124,   126,     0,     0,     0,    70,   175,     0,   179,
     174,   123,   176,    10,    11,   111,     0,    35,     0,    34,
      34,    34,    34,     0,    34,    34,    34,    34,    34,    34,
      12,    13,    19,    15,    16,    17,    18,    23,   133,    24,
       0,     0,     0,     0,   112,     0,   114,   130,     0,     0,
       0,   176,     0,     0,     0,    80,    82,    81,    83,    84,
      70,     0,     0,     0,   108,     0,    79,    86,    78,   106,
     105,   177,     0,    85,    90,     0,   125,    19,     9,   172,
     176,     0,     0,    34,     0,   117,    25,    26,    27,    28,
      34,    30,    31,    32,    33,    38,    39,    14,     0,   187,
       0,    72,   113,   176,     0,   129,   128,     0,     0,   145,
     144,   116,     0,     0,     0,     0,    87,     0,    93,   110,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    51,
      50,    52,    98,    97,    99,     0,   102,     0,   107,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     157,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   178,   173,    75,    40,
      34,     0,    29,   184,     0,     0,    73,   115,     0,   121,
     176,    76,    77,    92,     0,     0,     0,    91,   104,   109,
     103,   101,    88,    89,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,     0,     0,   176,
     176,   176,   176,   176,    21,     0,     0,    19,     0,   181,
     131,    34,     0,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,     0,   170,     0,     0,    36,
     119,   185,   189,    19,     0,    53,   146,   147,   150,   151,
     155,   156,   154,   158,   159,   160,   161,   152,   148,   163,
       0,   164,   166,   167,   165,   176,   176,    19,     0,    34,
       0,   182,   122,     0,     0,     0,    22,    19,     0,   186,
       0,   162,   168,   169,    37,   120,   183
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -259,  -259,   278,  -259,  -259,  -259,   -44,  -259,  -259,  -259,
    -259,   262,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   252,
    -259,  -259,  -259,  -259,  -259,     0,     3,  -259,  -259,    32,
    -259,  -259,   -45,  -259,  -259,  -220,   -97,  -259,   146,  -259,
    -225,  -259,    75,   -33,   -85,  -259,    37,  -259,  -259,  -259,
     -22,  -259,  -259,   -11,  -259,  -259,    61,  -259,   129,  -259,
       1,   181,  -259,   200,  -259,    -8,  -259,  -259,   212,   -53,
     -70,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -258,   281,   118,  -259,  -259,   324,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   -43,
    -259,  -259,  -259
=======
    -263,  -263,   272,  -263,  -263,  -263,   -45,  -263,  -263,   271,
    -263,  -263,  -263,  -263,   214,  -263,  -263,    21,   260,   112,
    -263,   -46,  -184,   -80,   149,  -263,  -185,  -263,    85,   -31,
      14,   108,  -263,   -20,  -263,  -263,    47,  -263,    73,    84,
       0,   157,   245,    38,  -263,   256,    83,   -72,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -262,   282,   147,
    -263,   391,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
      -6,  -263
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
<<<<<<< HEAD
       0,    17,    18,    19,    30,    83,    42,    82,   214,   372,
     395,    96,   221,   143,   288,   385,   402,   255,   256,   182,
     166,   347,   400,    20,    21,    43,    44,    71,   123,   124,
     296,    45,    46,   141,   337,   302,   184,   238,   257,   185,
     186,   187,   258,    47,    48,   121,   159,   295,    49,    76,
      50,   220,   374,    51,   127,   346,    52,    79,    53,    81,
      54,    55,   126,    56,   125,   163,   228,   345,    57,    58,
      78,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     333,    68,    86,   216,    87,   334,   132,    88,   215,    29,
      24,   119,   294,   389,   399,   405,   291,   340,   387,   158,
     292,   293,   376
=======
       0,    17,    18,    19,    30,    85,    42,    84,   328,    98,
     164,   358,   213,   214,   147,    20,    21,    43,    44,    72,
      45,    46,   263,   149,   215,   150,   151,   152,   216,    47,
      48,   125,    49,    50,   251,   359,    51,   301,    52,    53,
      54,    55,    56,   128,   184,    57,    58,    80,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   325,    68,    88,
      89,   326,    78,    90,    29,    24,   333,   370,   297,   360,
     122,   254
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
<<<<<<< HEAD
      22,    23,    91,    92,    97,   130,   108,   109,    77,   111,
     112,   113,   114,   115,   300,   301,    98,    22,    23,   307,
     -79,   364,    70,    25,   117,   335,   365,    99,    28,   -79,
     234,    70,   308,    31,   310,    69,    72,    73,   100,    74,
      75,    77,   312,   313,   128,    80,    85,   188,    84,    90,
     103,    93,    97,    97,    97,    97,    89,    97,    97,    97,
      97,    97,    97,   118,    98,    98,    98,    98,   110,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,   189,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     261,   100,   100,   100,   100,   100,   100,    97,   103,   103,
     103,   103,   188,   103,   103,   103,   103,   103,   103,    98,
     101,   116,   382,   383,   120,   122,   133,   137,   136,   157,
      99,   -79,   138,   139,   169,   142,   140,   144,   162,   156,
     149,   100,   167,   168,   189,   183,   213,   219,   303,   304,
     305,   306,  -135,   103,   222,   223,   224,   225,   226,   227,
     188,   188,   188,   188,  -155,   229,   230,   231,   101,   101,
     101,   101,   233,   101,   101,   101,   101,   101,   101,   235,
     284,   236,   188,   237,   188,   239,    97,   240,   102,   262,
     263,   264,   189,   189,   189,   189,   265,   266,    98,   336,
     183,   267,   268,   269,   270,   271,   272,   273,   274,    99,
     275,   276,   277,   101,   189,   278,   189,   327,   328,   279,
     100,   280,   281,   282,   283,   289,  -218,   -83,   287,    85,
     298,   309,   103,   297,   299,   241,   102,   102,   102,   102,
     104,   102,   102,   102,   102,   102,   102,   339,   183,   183,
     183,   183,   341,    97,   348,   349,   350,   342,   332,   105,
     370,   351,   352,   353,   354,    98,   355,   356,   357,   358,
     183,   106,   183,   359,   360,   361,    99,   362,   363,   366,
     367,   102,   368,   373,   369,   377,   371,   100,   104,   104,
     104,   104,   101,   104,   104,   104,   104,   104,   104,   103,
     381,   384,   390,   391,   392,    27,   375,   105,   105,   105,
     105,    97,   105,   105,   105,   105,   105,   105,   393,   106,
     106,   106,   106,    98,   106,   106,   106,   106,   106,   106,
     394,   396,   397,   104,    99,   398,   406,   129,   344,    97,
     107,   259,   343,   388,   286,   100,   311,   378,     0,     0,
       0,    98,   105,     0,     0,     0,     0,   103,   162,   101,
     102,   401,    99,     0,   106,   403,     0,     0,   404,   145,
     146,   147,   148,   100,   150,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,   103,   157,     0,   107,   107,
     107,   107,     0,   107,   107,   107,   107,   107,   107,     0,
       0,   170,   171,   172,   173,   174,     0,     0,     0,     0,
     131,     0,   104,   134,   218,   135,     0,   101,     0,     0,
     175,     0,     0,     0,     0,     0,     0,   102,     0,     0,
       0,   105,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,   101,     0,     0,     0,     0,
     176,   177,   178,    36,   179,   160,   128,   161,    38,     0,
     164,   165,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   217,     0,     0,     0,   104,
       0,   180,     0,     0,     0,   102,   181,     0,     0,     0,
       0,     0,     0,   290,     0,     0,     0,     0,   105,     0,
     232,     0,     0,     0,     0,     0,    26,     0,     0,     0,
     106,     0,   107,   102,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
       0,   170,   171,   172,   173,   174,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   285,
     175,     0,     0,     0,     0,     0,   105,    15,     0,     0,
     338,     0,     0,     0,     0,   104,     0,     0,   106,     0,
     170,   171,   172,   173,   174,     0,     0,     0,     0,   107,
     176,   177,   178,    36,   105,     0,   128,     0,    38,   175,
       0,     0,    16,     0,     0,     0,   106,     0,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   180,     0,   329,   330,   331,   181,     0,   379,   176,
     177,   178,    36,   260,     0,   128,     0,    38,     0,   160,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,   386,     0,     0,     0,
     180,     0,     0,     0,   241,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
       0,   380,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    32,    33,    34,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,    35,    94,     0,     0,     0,     0,    36,
       0,     0,    37,     0,    38,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,     0,    36,     0,     0,    37,
       0,    38,     0,     0,     0,     0,     0,    39,     0,    40,
      16,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    40,    16,     0,     0,
       0,     0,     0,    41,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,     0,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,    15,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16
=======
      23,    93,    94,    99,   133,   110,   111,    79,   113,   114,
     115,   116,   117,   267,    70,    28,    71,    23,   100,    31,
     349,    22,    25,   119,   192,   350,    70,    69,    71,   101,
     268,   327,   270,   261,   262,    75,   272,   273,    22,    73,
      74,    76,    79,   131,    86,    82,    91,    92,    70,   105,
      95,   112,   118,    99,    99,    99,    99,   124,    99,    99,
      99,    99,    99,    99,   134,   196,   156,   177,   100,   100,
     100,   100,   219,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   157,   101,   101,   101,   101,   101,   101,
     121,   155,   153,   364,   365,   158,   102,   160,   159,   105,
     105,   105,   105,   161,   105,   105,   105,   105,   105,   105,
     165,   163,   245,   264,   265,   266,   170,    99,   178,   179,
     180,   181,   103,   183,    99,   182,  -132,   187,   185,   186,
     189,   190,   100,   104,   191,   193,   194,   195,   198,   100,
     197,   248,   250,   101,   220,   221,   102,   102,   102,   102,
     101,   102,   102,   102,   102,   102,   102,  -188,  -118,   153,
     253,   154,   258,   105,   259,   260,   153,   269,   199,   274,
     105,   255,   103,   103,   103,   103,   275,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   104,   276,   104,   104,
     104,   104,   104,   104,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,    99,   287,   106,   153,   153,   153,
     102,   288,   289,   290,   291,   319,   320,   102,   292,   100,
     293,   294,   296,   299,   303,   298,   304,   305,   154,   153,
     101,   153,   330,   324,   335,   154,   103,   329,   336,   337,
     338,   339,   340,   103,   341,   342,   343,   104,   344,   345,
     105,   346,   331,   347,   104,    99,   106,   106,   106,   106,
     348,   106,   106,   106,   106,   106,   106,   351,   352,   353,
     100,   354,   357,   362,   363,   355,   154,   154,   154,   356,
     367,   101,   369,   371,   372,   373,   375,   376,   361,    27,
     132,   257,   332,   256,   107,     0,   300,   102,   154,   217,
     154,   105,     0,    87,   271,   108,     0,     0,   247,     0,
       0,     0,   366,    99,     0,     0,     0,     0,     0,   121,
     106,     0,   374,   103,     0,     0,     0,   106,   100,     0,
       0,   109,     0,   127,   104,     0,     0,     0,   148,   101,
       0,     0,     0,     0,   107,   107,   107,   107,   102,   107,
     107,   107,   107,   107,   107,   108,   108,   108,   108,   105,
     108,   108,   108,   108,   108,   108,     0,     0,     0,     0,
     166,   167,   168,   169,   103,   171,   172,   173,   174,   175,
     176,   109,   109,   109,   109,   104,   109,   109,   109,   109,
     109,   109,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   148,   102,   106,   107,     0,
       0,     0,   148,     0,     0,   107,     0,     0,     0,   108,
       0,    87,     0,     0,     0,     0,   108,     0,    77,     0,
      81,    83,   103,     0,   249,     0,     0,     0,     0,     0,
       0,   252,     0,   104,     0,   109,     0,     0,     0,     0,
       0,     0,   109,   148,   148,   148,     0,     0,   106,     0,
       0,   123,   126,     0,     0,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,   148,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,     0,   127,     0,
       0,   295,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,   135,   136,   137,   138,
     139,     0,     0,     0,     0,     0,   107,     0,     0,     0,
      26,   246,     0,     0,     0,   140,     0,   108,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,   334,     0,   126,     0,   135,   136,   137,   138,
     139,     0,     0,   109,     0,   141,   142,   143,    36,   144,
       0,   131,     0,    38,     0,   140,     0,     0,     0,     0,
       0,    15,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,   145,     0,     0,     0,
       0,   146,     0,     0,     0,   141,   142,   143,    36,   218,
     368,   131,     0,    38,     0,     0,    16,     0,     0,     0,
       0,   109,     0,   135,   136,   137,   138,   139,     0,     0,
       0,   302,     0,     0,     0,     0,   145,     0,     0,     0,
       0,   146,   140,     0,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,     0,     0,
     321,   322,   323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,   142,   143,    36,     0,     0,   131,     0,
      38,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    32,    33,    34,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    96,     0,     0,     0,     0,    36,     0,
       0,    37,     0,    38,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    32,    33,
      34,     0,     0,     0,     0,     0,    39,     0,    40,    16,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,     0,
       0,    36,     0,     0,    37,     0,    38,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,    40,    16,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
       0,     0,     0,     0,   120,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,   238,   239,   240,   241,   242,   243,   244,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
       0,     0,    46,    47,    49,    75,    50,    51,    22,    53,
      54,    55,    56,    57,    89,    90,    49,    17,    17,   239,
      58,    61,    60,    60,    68,   283,    66,    49,    22,    58,
      68,    60,   257,    84,   259,    60,    67,    67,    49,    58,
      60,    22,   262,   263,    58,    63,    43,   132,    22,    84,
      49,    63,    97,    98,    99,   100,    82,   102,   103,   104,
     105,   106,   107,    61,    97,    98,    99,   100,    63,   102,
     103,   104,   105,   106,   107,    97,    98,    99,   100,   132,
     102,   103,   104,   105,   106,   107,    97,    98,    99,   100,
     187,   102,   103,   104,   105,   106,   107,   142,    97,    98,
      99,   100,   187,   102,   103,   104,   105,   106,   107,   142,
      49,    63,   370,   371,    61,    58,    61,    61,    60,   119,
     142,    58,    63,    84,    59,    63,    66,    61,   125,    85,
      63,   142,    61,    61,   187,   132,    63,    60,   235,   236,
     237,   238,    91,   142,    60,    22,    61,    61,    66,    59,
     235,   236,   237,   238,    63,    63,    63,    59,    97,    98,
      99,   100,    60,   102,   103,   104,   105,   106,   107,    56,
     214,    56,   257,    56,   259,    68,   221,    82,    49,    68,
      68,    60,   235,   236,   237,   238,    60,    60,   221,    93,
     187,    60,    60,    60,    60,    60,    60,    60,    60,   221,
      60,    60,    60,   142,   257,    60,   259,   277,   278,    60,
     221,    60,    60,    60,    60,    91,    66,    58,    63,   216,
      60,    57,   221,    66,    66,    57,    97,    98,    99,   100,
      49,   102,   103,   104,   105,   106,   107,    60,   235,   236,
     237,   238,    66,   288,    57,    57,    57,    85,    87,    49,
      66,    61,    61,    61,    61,   288,    61,    61,    61,    61,
     257,    49,   259,    61,    61,    61,   288,    61,    61,    61,
      61,   142,    61,    93,    61,    60,    66,   288,    97,    98,
      99,   100,   221,   102,   103,   104,   105,   106,   107,   288,
      22,    61,    61,    59,    61,    17,   340,    97,    98,    99,
     100,   346,   102,   103,   104,   105,   106,   107,    61,    97,
      98,    99,   100,   346,   102,   103,   104,   105,   106,   107,
      61,    61,    61,   142,   346,    61,    61,    75,   296,   374,
      49,   185,   295,   376,   216,   346,   261,   345,    -1,    -1,
      -1,   374,   142,    -1,    -1,    -1,    -1,   346,   345,   288,
     221,   395,   374,    -1,   142,   399,    -1,    -1,   402,    97,
      98,    99,   100,   374,   102,   103,   104,   105,   106,   107,
      -1,    -1,    -1,    -1,    -1,   374,   376,    -1,    97,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,   107,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      76,    -1,   221,    79,   142,    81,    -1,   346,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,   288,    -1,    -1,
      -1,   221,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,    -1,   374,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,   121,    58,   123,    60,    -1,
     126,   127,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   141,    -1,    -1,    -1,   288,
      -1,    83,    -1,    -1,    -1,   346,    88,    -1,    -1,    -1,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,   288,    -1,
     166,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,
     288,    -1,   221,   374,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
      22,    -1,    -1,    -1,    -1,    -1,   346,    51,    -1,    -1,
     288,    -1,    -1,    -1,    -1,   374,    -1,    -1,   346,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,   288,
      52,    53,    54,    55,   374,    -1,    58,    -1,    60,    22,
      -1,    -1,    86,    -1,    -1,    -1,   374,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,    83,    -1,   279,   280,   281,    88,    -1,   346,    52,
      53,    54,    55,    56,    -1,    58,    -1,    60,    -1,   295,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    57,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   374,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,   347,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,
      86,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    92,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    51,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86
=======
       0,    46,    47,    49,    76,    50,    51,    22,    53,    54,
      55,    56,    57,   197,    58,    22,    60,    17,    49,    84,
      61,     0,    60,    68,    68,    66,    58,    60,    60,    49,
     215,   293,   217,    89,    90,    58,   220,   221,    17,    67,
      67,    60,    22,    58,    22,    63,    82,    84,    58,    49,
      63,    63,    63,    99,   100,   101,   102,    61,   104,   105,
     106,   107,   108,   109,    59,   145,    63,   112,    99,   100,
     101,   102,   152,   104,   105,   106,   107,   108,   109,    99,
     100,   101,   102,    60,   104,   105,   106,   107,   108,   109,
      69,    61,    78,   355,   356,    61,    49,    84,    63,    99,
     100,   101,   102,    66,   104,   105,   106,   107,   108,   109,
      61,    63,   157,   193,   194,   195,    63,   163,    85,    22,
      61,    59,    49,    66,   170,    61,    63,    59,    63,    63,
      61,    61,   163,    49,    60,    56,    56,    56,    82,   170,
      68,    63,    60,   163,    68,    68,    99,   100,   101,   102,
     170,   104,   105,   106,   107,   108,   109,    66,    91,   145,
      60,    78,    66,   163,    60,    66,   152,    57,    57,    60,
     170,    85,    99,   100,   101,   102,    60,   104,   105,   106,
     107,   108,   109,    99,   100,   101,   102,    60,   104,   105,
     106,   107,   108,   109,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,   250,    60,    49,   193,   194,   195,
     163,    60,    60,    60,    60,   287,   288,   170,    60,   250,
      60,    93,    91,    60,    57,    66,    57,    57,   145,   215,
     250,   217,    60,    87,    59,   152,   163,    93,    61,    61,
      61,    61,    61,   170,    61,    61,    61,   163,    61,    61,
     250,    61,   297,    61,   170,   301,    99,   100,   101,   102,
      61,   104,   105,   106,   107,   108,   109,    61,    61,    61,
     301,    61,    61,    61,    22,    66,   193,   194,   195,    66,
      61,   301,    61,    61,    61,    61,    61,    61,   333,    17,
      76,   183,   298,   181,    49,    -1,   258,   250,   215,   150,
     217,   301,    -1,    43,   219,    49,    -1,    -1,   161,    -1,
      -1,    -1,   357,   359,    -1,    -1,    -1,    -1,    -1,   298,
     163,    -1,   367,   250,    -1,    -1,    -1,   170,   359,    -1,
      -1,    49,    -1,    73,   250,    -1,    -1,    -1,    78,   359,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   301,   104,
     105,   106,   107,   108,   109,    99,   100,   101,   102,   359,
     104,   105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   301,   104,   105,   106,   107,   108,
     109,    99,   100,   101,   102,   301,   104,   105,   106,   107,
     108,   109,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   145,   359,   250,   163,    -1,
      -1,    -1,   152,    -1,    -1,   170,    -1,    -1,    -1,   163,
      -1,   161,    -1,    -1,    -1,    -1,   170,    -1,    37,    -1,
      39,    40,   359,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,   359,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   193,   194,   195,    -1,    -1,   301,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,   217,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,   258,    -1,
      -1,   250,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,    -1,
       0,   160,    -1,    -1,    -1,    22,    -1,   301,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   301,    -1,   183,    -1,     3,     4,     5,     6,
       7,    -1,    -1,   301,    -1,    52,    53,    54,    55,    56,
      -1,    58,    -1,    60,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   359,    83,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    52,    53,    54,    55,    56,
     359,    58,    -1,    60,    -1,    -1,    86,    -1,    -1,    -1,
      -1,   359,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    88,    22,    -1,    -1,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,    -1,    -1,
     289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    -1,    -1,    58,    -1,
      60,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    -1,    60,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    -1,    60,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    61,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    51,    86,    95,    96,    97,
<<<<<<< HEAD
     117,   118,   119,   154,   184,    60,     0,    96,    22,   183,
      98,    84,    22,    23,    24,    49,    55,    58,    60,    83,
      85,    92,   100,   119,   120,   125,   126,   137,   138,   142,
     144,   147,   150,   152,   154,   155,   157,   162,   163,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   175,    60,
      60,   121,    67,    67,    58,    60,   143,    22,   164,   151,
      63,   153,   101,    99,    22,   120,   176,   178,   181,    82,
      84,   100,   100,    63,    50,    92,   105,   126,   137,   144,
     147,   150,   152,   154,   155,   157,   162,   175,   100,   100,
      63,   100,   100,   100,   100,   100,    63,   100,    61,   185,
      61,   139,    58,   122,   123,   158,   156,   148,    58,   113,
     164,   179,   180,    61,   179,   179,    60,    61,    63,    84,
      66,   127,    63,   107,    61,   105,   105,   105,   105,    63,
     105,   105,   105,   105,   105,   105,    85,   119,   193,   140,
     179,   179,   120,   159,   179,   179,   114,    61,    61,    59,
       3,     4,     5,     6,     7,    22,    52,    53,    54,    56,
      83,    88,   113,   120,   130,   133,   134,   135,   138,   163,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    42,    43,    44,    45,
      46,    47,    48,    63,   102,   182,   177,   179,   105,    60,
     145,   106,    60,    22,    61,    61,    66,    59,   160,    63,
      63,    59,   179,    60,    68,    56,    56,    56,   131,    68,
      82,    57,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   111,   112,   132,   136,   132,
      56,   130,    68,    68,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,   100,   179,   176,    63,   108,    91,
     105,   190,   194,   195,   186,   141,   124,    66,    60,    66,
      89,    90,   129,   130,   130,   130,   130,   129,   134,    57,
     134,   136,   129,   129,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   164,   164,   179,
     179,   179,    87,   174,   179,   174,    93,   128,   105,    60,
     191,    66,    85,   140,   123,   161,   149,   115,    57,    57,
      57,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    66,    61,    61,    61,    61,
      66,    66,   103,    93,   146,   100,   196,    60,   159,   105,
     179,    22,   174,   174,    61,   109,   105,   192,   193,   187,
      61,    59,    61,    61,    61,   104,    61,    61,    61,   188,
     116,   100,   110,   100,   100,   189,    61
=======
     109,   110,   111,   134,   159,    60,     0,    96,    22,   158,
      98,    84,    22,    23,    24,    49,    55,    58,    60,    83,
      85,    92,   100,   111,   112,   114,   115,   123,   124,   126,
     127,   130,   132,   133,   134,   135,   136,   139,   140,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   152,    60,
      58,    60,   113,    67,    67,    58,    60,   155,   156,    22,
     141,   155,    63,   155,   101,    99,    22,   112,   153,   154,
     157,    82,    84,   100,   100,    63,    50,    92,   103,   115,
     123,   127,   130,   132,   133,   134,   135,   136,   139,   152,
     100,   100,    63,   100,   100,   100,   100,   100,    63,   100,
      61,   111,   164,   155,    61,   125,   155,   112,   137,   155,
     155,    58,   108,   141,    59,     3,     4,     5,     6,     7,
      22,    52,    53,    54,    56,    83,    88,   108,   112,   117,
     119,   120,   121,   124,   140,    61,    63,    60,    61,    63,
      84,    66,   155,    63,   104,    61,   103,   103,   103,   103,
      63,   103,   103,   103,   103,   103,   103,   100,    85,    22,
      61,    59,    61,    66,   138,    63,    63,    59,   155,    61,
      61,    60,    68,    56,    56,    56,   117,    68,    82,    57,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   106,   107,   118,   122,   118,    56,   117,
      68,    68,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    42,    43,
      44,    45,    46,    47,    48,   100,   155,   153,    63,   103,
      60,   128,   103,    60,   165,    85,   113,   125,    66,    60,
      66,    89,    90,   116,   117,   117,   117,   116,   120,    57,
     120,   122,   116,   116,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    93,   103,    91,   162,    66,    60,
     137,   131,   155,    57,    57,    57,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   141,
     141,   155,   155,   155,    87,   151,   155,   151,   102,    93,
      60,   100,   164,   160,   103,    59,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      66,    61,    61,    61,    61,    66,    66,    61,   105,   129,
     163,   100,    61,    22,   151,   151,   100,    61,   103,    61,
     161,    61,    61,    61,   100,    61,    61
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    96,    96,    96,    98,    99,    97,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
<<<<<<< HEAD
     101,   102,   103,   104,   100,   100,   100,   105,   105,   105,
     105,   106,   105,   105,   105,   105,   105,   105,   107,   108,
     109,   110,   105,   105,   105,   105,   111,   111,   111,   111,
     111,   111,   112,   112,   112,   112,   112,   112,   114,   115,
     116,   113,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   119,   119,   120,   121,
     120,   122,   123,   124,   123,   125,   127,   128,   126,   129,
     129,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     131,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   132,   132,   132,   133,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   136,   137,   138,   139,   138,   140,
     141,   140,   143,   142,   144,   145,   146,   144,   148,   149,
     147,   150,   151,   150,   153,   152,   152,   154,   156,   155,
     158,   157,   160,   161,   159,   159,   162,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   164,   165,   165,   166,
     166,   166,   166,   167,   167,   167,   167,   168,   169,   169,
     169,   170,   170,   170,   171,   172,   172,   172,   173,   173,
     173,   173,   173,   174,   174,   175,   177,   176,   176,   178,
     180,   179,   182,   181,   181,   183,   185,   186,   187,   188,
     189,   184,   190,   191,   192,   184,   194,   193,   195,   196,
     193
=======
     101,   102,   100,   100,   100,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   105,   103,   103,   103,
     103,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   108,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   114,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   118,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   124,   124,   125,   125,   126,   127,   128,   129,
     127,   131,   130,   132,   132,   133,   133,   134,   135,   136,
     138,   137,   137,   139,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   141,   142,   142,   143,   143,   143,   143,
     144,   144,   144,   144,   145,   146,   146,   146,   147,   147,
     147,   148,   149,   149,   149,   150,   150,   150,   150,   150,
     151,   151,   152,   153,   153,   154,   156,   155,   157,   157,
     158,   160,   161,   159,   162,   163,   159,   164,   165,   164
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     0,     6,
<<<<<<< HEAD
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       0,     0,     0,     0,    10,     2,     2,     2,     2,     2,
       2,     0,     4,     2,     2,     2,     2,     0,     0,     0,
       0,     0,    10,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       0,     8,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     3,     0,     5,     1,     0,     0,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     3,     3,     1,     3,     3,     2,     4,     4,
       4,     1,     1,     1,     2,     3,     2,     3,     3,     1,
       1,     2,     1,     2,     1,     2,     3,     0,     5,     1,
       0,     4,     0,     5,     3,     0,     0,     9,     0,     0,
       9,     2,     0,     3,     0,     4,     2,     1,     0,     5,
       0,     5,     0,     0,     5,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     7,
       7,     7,     4,     7,     7,     7,     4,     7,     7,     7,
       4,     7,     7,     7,     7,     9,     7,     7,     7,     7,
       7,     9,     9,     1,     1,     3,     0,     4,     1,     1,
       0,     2,     0,     4,     1,     1,     0,     0,     0,     0,
       0,    15,     0,     0,     0,    12,     0,     3,     0,     0,
       6
=======
       2,     2,     2,     2,     3,     2,     2,     2,     2,     0,
       0,     0,     8,     2,     2,     2,     2,     2,     2,     3,
       2,     2,     2,     2,     0,     0,     0,     8,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       1,     3,     3,     2,     4,     4,     4,     1,     1,     1,
       2,     3,     2,     3,     3,     1,     1,     2,     1,     2,
       1,     2,     3,     4,     1,     3,     4,     3,     0,     0,
       9,     0,     8,     2,     2,     3,     2,     1,     4,     4,
       0,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     7,     7,     7,     4,
       7,     7,     7,     4,     7,     7,     7,     4,     7,     7,
       7,     7,     9,     7,     7,     7,     7,     7,     9,     9,
       1,     1,     3,     3,     1,     1,     0,     2,     3,     1,
       1,     0,     0,    12,     0,     0,    11,     2,     0,     5
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
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
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
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
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* $@1: %empty  */
<<<<<<< HEAD
#line 74 "parse.y"
          {is_func_bool = true; current_pointer++;  curr_scopes[current_pointer]++;}
#line 1908 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 76 "parse.y"
=======
#line 77 "parse.y"
          {is_func_bool = true; current_pointer++;  curr_scopes[current_pointer]++;}
#line 1866 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 79 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
          {
            if (valid_func_entry((yyvsp[-3].object).value , par_list)){
              new_func_entry( (yyvsp[-3].object).value, "null", par_list.size(), par_list, var_list);
              add('F',(yyvsp[-3].object).value,"null");
            }
            else{
              cout<< "From startfn Function re-def, ERROR! at " << yylineno <<endl;
            }
            var_list.clear(); 
            par_list.clear();}
<<<<<<< HEAD
#line 1923 "y.tab.c"
    break;

  case 9: /* startfn: START OPENCU $@1 body $@2 CLOSECU  */
#line 85 "parse.y"
                                      {is_func_bool = false;current_pointer--;
          }
#line 1930 "y.tab.c"
    break;

  case 14: /* body: unary_operation_without_dot DOT  */
#line 93 "parse.y"
                                       {fprintf(outfile, ";");}
#line 1936 "y.tab.c"
    break;

  case 19: /* body: %empty  */
#line 98 "parse.y"
       {}
#line 1942 "y.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 99 "parse.y"
                 { current_pointer++;  curr_scopes[current_pointer]++; }
#line 1948 "y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 99 "parse.y"
                                                                               {fprintf(outfile, "{");}
#line 1954 "y.tab.c"
    break;

  case 22: /* $@5: %empty  */
#line 99 "parse.y"
                                                                                                                        {current_pointer--; }
#line 1960 "y.tab.c"
    break;

  case 23: /* $@6: %empty  */
#line 99 "parse.y"
                                                                                                                                                     {fprintf(outfile, "}");}
#line 1966 "y.tab.c"
    break;

  case 31: /* $@7: %empty  */
#line 108 "parse.y"
                                       {fprintf(outfile, ";");}
#line 1972 "y.tab.c"
    break;

  case 37: /* loop_body: %empty  */
#line 113 "parse.y"
       {}
#line 1978 "y.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 114 "parse.y"
                 { current_pointer++;  curr_scopes[current_pointer]++; }
#line 1984 "y.tab.c"
    break;

  case 39: /* $@9: %empty  */
#line 114 "parse.y"
                                                                                {fprintf(outfile, "{");}
#line 1990 "y.tab.c"
    break;

  case 40: /* $@10: %empty  */
#line 114 "parse.y"
                                                                                                                              {current_pointer--; }
#line 1996 "y.tab.c"
    break;

  case 41: /* $@11: %empty  */
#line 114 "parse.y"
                                                                                                                                                            {fprintf(outfile, "}");}
#line 2002 "y.tab.c"
    break;

  case 45: /* loop_body: BREAK DOT loop_body  */
#line 117 "parse.y"
                           {fprintf(outfile, "break; %s", (yyvsp[0].object));}
#line 2008 "y.tab.c"
    break;

  case 46: /* bi_op: ADD  */
#line 120 "parse.y"
            {fprintf(outfile, "+");}
#line 2014 "y.tab.c"
    break;

  case 47: /* bi_op: SUB  */
#line 121 "parse.y"
            {fprintf(outfile, "-");}
#line 2020 "y.tab.c"
    break;

  case 48: /* bi_op: MUL  */
#line 122 "parse.y"
            {fprintf(outfile, "*");}
#line 2026 "y.tab.c"
    break;

  case 49: /* bi_op: DIV  */
#line 123 "parse.y"
            {fprintf(outfile, "/");}
#line 2032 "y.tab.c"
    break;

  case 52: /* relop: EQ  */
#line 128 "parse.y"
           {fprintf(outfile, "==");}
#line 2038 "y.tab.c"
    break;

  case 53: /* relop: NEQ  */
#line 129 "parse.y"
            {fprintf(outfile, "!=");}
#line 2044 "y.tab.c"
    break;

  case 54: /* relop: GEQ  */
#line 130 "parse.y"
            {fprintf(outfile, ">=");}
#line 2050 "y.tab.c"
    break;

  case 55: /* relop: GT  */
#line 131 "parse.y"
           {fprintf(outfile, ">");}
#line 2056 "y.tab.c"
    break;

  case 56: /* relop: LEQ  */
#line 132 "parse.y"
            {fprintf(outfile, "<=");}
#line 2062 "y.tab.c"
    break;

  case 57: /* relop: LT  */
#line 133 "parse.y"
           {fprintf(outfile, "<");}
#line 2068 "y.tab.c"
    break;

  case 58: /* $@12: %empty  */
#line 136 "parse.y"
                 {fprintf(outfile, "{");}
#line 2074 "y.tab.c"
    break;

  case 59: /* $@13: %empty  */
#line 136 "parse.y"
                                                              {fprintf(outfile, ",");}
#line 2080 "y.tab.c"
    break;

  case 60: /* $@14: %empty  */
#line 136 "parse.y"
                                                                                                             {fprintf(outfile, "}");}
#line 2086 "y.tab.c"
    break;

  case 61: /* vectors: OPENSQ $@12 check_rhs_exp COMMA $@13 check_rhs_exp CLOSESQ $@14  */
#line 136 "parse.y"
                                                                                                                                      {
              if(((yyvsp[-5].object).type == 1 || (yyvsp[-5].object).type == 4 || (yyvsp[-5].object).type == 2) && ((yyvsp[-5].object).type == 1 || (yyvsp[-5].object).type == 4 || (yyvsp[-5].object).type == 2)){
=======
#line 1881 "y.tab.c"
    break;

  case 9: /* startfn: START OPENCU $@1 body $@2 CLOSECU  */
#line 88 "parse.y"
                                      {is_func_bool = false;current_pointer--;
          }
#line 1888 "y.tab.c"
    break;

  case 19: /* body: %empty  */
#line 101 "parse.y"
       {}
#line 1894 "y.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 102 "parse.y"
                 { current_pointer++;  curr_scopes[current_pointer]++; }
#line 1900 "y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 102 "parse.y"
                                                                                               {current_pointer--; }
#line 1906 "y.tab.c"
    break;

  case 34: /* loop_body: %empty  */
#line 116 "parse.y"
       {}
#line 1912 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 117 "parse.y"
                 { current_pointer++;  curr_scopes[current_pointer]++; }
#line 1918 "y.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 117 "parse.y"
                                                                                                     {current_pointer--; }
#line 1924 "y.tab.c"
    break;

  case 53: /* vectors: OPENSQ check_rhs_exp COMMA check_rhs_exp CLOSESQ  */
#line 139 "parse.y"
                                                           {
              if(((yyvsp[-3].object).type == 1 || (yyvsp[-3].object).type == 4 || (yyvsp[-3].object).type == 2) && ((yyvsp[-3].object).type == 1 || (yyvsp[-3].object).type == 4 || (yyvsp[-3].object).type == 2)){
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                (yyval.object).type = 10;
              }
              else{
                cout << "Invalid vector in line " << yylineno << endl;
<<<<<<< HEAD
              }
              
              }
#line 2100 "y.tab.c"
    break;

  case 62: /* primi_datatype: INT  */
#line 147 "parse.y"
                    {insert_type((yyvsp[0].object).value);
                  fprintf(outfile, "int");}
#line 2107 "y.tab.c"
    break;

  case 63: /* primi_datatype: DOUBLE  */
#line 149 "parse.y"
                       {insert_type((yyvsp[0].object).value);
               fprintf(outfile, "double");}
#line 2114 "y.tab.c"
    break;

  case 64: /* primi_datatype: BOOL  */
#line 151 "parse.y"
                     {insert_type((yyvsp[0].object).value);
              fprintf(outfile, "bool");}
#line 2121 "y.tab.c"
    break;

  case 65: /* primi_datatype: STRING  */
#line 153 "parse.y"
                       {insert_type((yyvsp[0].object).value);
              fprintf(outfile, "string");}
#line 2128 "y.tab.c"
    break;

  case 66: /* non_pri_datatype: MASS  */
#line 157 "parse.y"
                       {insert_type((yyvsp[0].object).value); fprintf(outfile, "mass");}
#line 2134 "y.tab.c"
    break;

  case 67: /* non_pri_datatype: TIME  */
#line 158 "parse.y"
                       {insert_type((yyvsp[0].object).value); fprintf(outfile, "double");}
#line 2140 "y.tab.c"
    break;

  case 68: /* non_pri_datatype: POSITION  */
#line 159 "parse.y"
                           {insert_type((yyvsp[0].object).value); fprintf(outfile, "pair<double,double>");}
#line 2146 "y.tab.c"
    break;

  case 69: /* non_pri_datatype: VELOCITY  */
#line 160 "parse.y"
                           {insert_type((yyvsp[0].object).value); fprintf(outfile, "pair<double,double>");}
#line 2152 "y.tab.c"
    break;

  case 70: /* non_pri_datatype: ACC  */
#line 161 "parse.y"
                      {insert_type((yyvsp[0].object).value); fprintf(outfile, "pair<double,double>");}
#line 2158 "y.tab.c"
    break;

  case 71: /* non_pri_datatype: ENERGY  */
#line 162 "parse.y"
                         {insert_type((yyvsp[0].object).value); fprintf(outfile, "double");}
#line 2164 "y.tab.c"
    break;

  case 72: /* non_pri_datatype: THETA  */
#line 163 "parse.y"
                        {insert_type((yyvsp[0].object).value); fprintf(outfile, "double");}
#line 2170 "y.tab.c"
    break;

  case 73: /* non_pri_datatype: E  */
#line 164 "parse.y"
                          {insert_type((yyvsp[0].object).value); fprintf(outfile, "double");}
#line 2176 "y.tab.c"
    break;

  case 74: /* non_pri_datatype: DISTANCE  */
#line 165 "parse.y"
                           {insert_type((yyvsp[0].object).value); fprintf(outfile, "double");}
#line 2182 "y.tab.c"
    break;

  case 75: /* non_pri_datatype: MOMENTUM  */
#line 166 "parse.y"
                           {insert_type((yyvsp[0].object).value); fprintf(outfile, "double");}
#line 2188 "y.tab.c"
    break;

  case 78: /* single_variable: ID  */
#line 175 "parse.y"
                     { fprintf(outfile,"%s", (yyvsp[0].object));}
#line 2194 "y.tab.c"
    break;

  case 79: /* $@15: %empty  */
#line 176 "parse.y"
                     { fprintf(outfile,"%s", (yyvsp[0].object));}
#line 2200 "y.tab.c"
    break;

  case 81: /* dim_con: OPENSQ  */
#line 179 "parse.y"
                 {fprintf(outfile, "[");}
#line 2206 "y.tab.c"
    break;

  case 82: /* dimensions: dim_con check_rhs_exp CLOSESQ  */
#line 181 "parse.y"
                                           {
              fprintf(outfile, "]");
              if((yyvsp[-1].object).type == 1){
                (yyval.object).type = 10;
=======
              }}
#line 1936 "y.tab.c"
    break;

  case 54: /* primi_datatype: INT  */
#line 148 "parse.y"
                    {insert_type((yyvsp[0].object).value);}
#line 1942 "y.tab.c"
    break;

  case 55: /* primi_datatype: DOUBLE  */
#line 149 "parse.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1948 "y.tab.c"
    break;

  case 56: /* primi_datatype: BOOL  */
#line 150 "parse.y"
                     {insert_type((yyvsp[0].object).value);}
#line 1954 "y.tab.c"
    break;

  case 57: /* primi_datatype: STRING  */
#line 151 "parse.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1960 "y.tab.c"
    break;

  case 58: /* non_pri_datatype: MASS  */
#line 154 "parse.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1966 "y.tab.c"
    break;

  case 59: /* non_pri_datatype: TIME  */
#line 155 "parse.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1972 "y.tab.c"
    break;

  case 60: /* non_pri_datatype: POSITION  */
#line 156 "parse.y"
                           {insert_type((yyvsp[0].object).value);}
#line 1978 "y.tab.c"
    break;

  case 61: /* non_pri_datatype: VELOCITY  */
#line 157 "parse.y"
                           {insert_type((yyvsp[0].object).value);}
#line 1984 "y.tab.c"
    break;

  case 62: /* non_pri_datatype: ACC  */
#line 158 "parse.y"
                      {insert_type((yyvsp[0].object).value);}
#line 1990 "y.tab.c"
    break;

  case 63: /* non_pri_datatype: ENERGY  */
#line 159 "parse.y"
                         {insert_type((yyvsp[0].object).value);}
#line 1996 "y.tab.c"
    break;

  case 64: /* non_pri_datatype: THETA  */
#line 160 "parse.y"
                        {insert_type((yyvsp[0].object).value);}
#line 2002 "y.tab.c"
    break;

  case 65: /* non_pri_datatype: E  */
#line 161 "parse.y"
                          {insert_type((yyvsp[0].object).value);}
#line 2008 "y.tab.c"
    break;

  case 66: /* non_pri_datatype: DISTANCE  */
#line 162 "parse.y"
                           {insert_type((yyvsp[0].object).value);}
#line 2014 "y.tab.c"
    break;

  case 67: /* non_pri_datatype: MOMENTUM  */
#line 163 "parse.y"
                           {insert_type((yyvsp[0].object).value);}
#line 2020 "y.tab.c"
    break;

  case 70: /* single_variable: ID  */
#line 172 "parse.y"
                     {arr_check = false;}
#line 2026 "y.tab.c"
    break;

  case 71: /* single_variable: ID dimensions  */
#line 173 "parse.y"
                                {arr_check = true;}
#line 2032 "y.tab.c"
    break;

  case 72: /* dimensions: OPENSQ check_rhs_exp CLOSESQ  */
#line 177 "parse.y"
                                           {
              if((yyvsp[-1].object).type == 1){
                (yyval.object).type = 10;
                dim_count++;
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
              }
              else{
                cout << "Invalid dimension in line " << yylineno << endl;
              }
              }
<<<<<<< HEAD
#line 2220 "y.tab.c"
    break;

  case 83: /* $@16: %empty  */
#line 190 "parse.y"
                                           {fprintf(outfile, "]");}
#line 2226 "y.tab.c"
    break;

  case 84: /* dimensions: dim_con check_rhs_exp CLOSESQ $@16 dimensions  */
#line 190 "parse.y"
                                                                              {
              if((yyvsp[-3].object).type == 1){
                (yyval.object).type = 10;
=======
#line 2046 "y.tab.c"
    break;

  case 73: /* dimensions: OPENSQ check_rhs_exp CLOSESQ dimensions  */
#line 186 "parse.y"
                                                    {
              if((yyvsp[-2].object).type == 1){
                (yyval.object).type = 10;
                dim_count++;
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
              }
              else{
                cout << "Invalid dimension in line " << yylineno << endl;
              }
           }
<<<<<<< HEAD
#line 2239 "y.tab.c"
    break;

  case 85: /* single_variable_for_exp_stmt: single_variable  */
#line 203 "parse.y"
=======
#line 2060 "y.tab.c"
    break;

  case 74: /* single_variable_for_exp_stmt: single_variable  */
#line 200 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                                {
                                  if(((yyval.object).type = undeclare_check((yyvsp[0].object).value,convert_scope_to_string())) == 0){
                                    cout << "From single_variable_for_exp_stmt Undeclared variable used " << (yyvsp[0].object).value << " at " << yylineno << endl;
                                  }
                                }
<<<<<<< HEAD
#line 2249 "y.tab.c"
    break;

  case 86: /* $@17: %empty  */
#line 210 "parse.y"
                                              { fprintf(outfile, "=");}
#line 2255 "y.tab.c"
    break;

  case 87: /* $@18: %empty  */
#line 210 "parse.y"
                                                                                          {fprintf(outfile, ";");}
#line 2261 "y.tab.c"
    break;

  case 88: /* exp_stmt: single_variable_for_exp_stmt ASSGN $@17 check_rhs_exp DOT $@18  */
#line 211 "parse.y"
          {if(!type_checking_assign((yyvsp[-5].object).type,(yyvsp[-2].object).type)){
            cout << "From exp_stmt Expression statement types not compatible " << (yyvsp[-5].object).type << ' ' << (yyvsp[-2].object).type << ' ' <<" at " << yylineno << endl;
          }
          }
#line 2270 "y.tab.c"
    break;

  case 91: /* anything_with_value: single_variable  */
#line 221 "parse.y"
                                      {if(((yyval.object).type = undeclare_check((yyvsp[0].object).value,convert_scope_to_string())) == 0){
    cout << "From anything_with_value Undeclared variable used " << (yyvsp[0].object).value << " at " << yylineno<< endl;
  }}
#line 2278 "y.tab.c"
    break;

  case 92: /* anything_with_value: NON_NEGATIVE_INT  */
#line 224 "parse.y"
                                       {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2284 "y.tab.c"
    break;

  case 93: /* anything_with_value: INTEGER_CONSTANT  */
#line 225 "parse.y"
                                       {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2290 "y.tab.c"
    break;

  case 94: /* anything_with_value: FLOAT_CONSTANT  */
#line 226 "parse.y"
                                     {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2296 "y.tab.c"
    break;

  case 95: /* anything_with_value: STRING_CONSTANT  */
#line 227 "parse.y"
                                      {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2302 "y.tab.c"
    break;

  case 96: /* anything_with_value: TRUE  */
#line 228 "parse.y"
                           {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2308 "y.tab.c"
    break;

  case 97: /* anything_with_value: FALSE  */
#line 229 "parse.y"
                            {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2314 "y.tab.c"
    break;

  case 99: /* anything_with_value: vectors  */
#line 231 "parse.y"
                              {(yyval.object).type = 10;}
#line 2320 "y.tab.c"
    break;

  case 100: /* $@19: %empty  */
#line 232 "parse.y"
                             {fprintf(outfile, "!");}
#line 2326 "y.tab.c"
    break;

  case 101: /* anything_with_value: UNINEG $@19 anything_with_value  */
#line 232 "parse.y"
                                                                         {(yyval.object).type = 4;}
#line 2332 "y.tab.c"
    break;

  case 102: /* anything_with_value: call_stmt_without_dot ARROW pos  */
#line 233 "parse.y"
                                                      {if((yyvsp[-2].object).type != 5 && (yyvsp[-2].object).type != 6 && (yyvsp[-2].object).type != 7 && (yyvsp[-2].object).type != 8 && (yyvsp[-2].object).type != 9 && (yyvsp[-2].object).type != 10){
                      cout << "From anything with value call statement return is not a vector" << endl;
                    }}
#line 2340 "y.tab.c"
    break;

  case 106: /* anything_with_value: ID ARROW pos  */
#line 239 "parse.y"
=======
#line 2070 "y.tab.c"
    break;

  case 75: /* exp_stmt: single_variable_for_exp_stmt ASSGN check_rhs_exp DOT  */
#line 208 "parse.y"
          {if(!type_checking_assign((yyvsp[-3].object).type,(yyvsp[-1].object).type)){
            cout << "From exp_stmt Expression statement types not compatible " << (yyvsp[-3].object).type << ' ' << (yyvsp[-1].object).type << ' ' <<" at " << yylineno << endl;
          }}
#line 2078 "y.tab.c"
    break;

  case 78: /* anything_with_value: single_variable  */
#line 217 "parse.y"
                                      {if(((yyval.object).type = undeclare_check((yyvsp[0].object).value,convert_scope_to_string())) == 0){
    cout << "From anything_with_value Undeclared variable used " << (yyvsp[0].object).value << " at " << yylineno<< endl;
  }}
#line 2086 "y.tab.c"
    break;

  case 86: /* anything_with_value: vectors  */
#line 227 "parse.y"
                              {(yyval.object).type = 10;}
#line 2092 "y.tab.c"
    break;

  case 87: /* anything_with_value: UNINEG anything_with_value  */
#line 228 "parse.y"
                                                 {(yyval.object).type = 4;}
#line 2098 "y.tab.c"
    break;

  case 88: /* anything_with_value: call_stmt_without_dot ARROW pos  */
#line 229 "parse.y"
                                                      {if((yyvsp[-2].object).type != 5 && (yyvsp[-2].object).type != 6 && (yyvsp[-2].object).type != 7 && (yyvsp[-2].object).type != 8 && (yyvsp[-2].object).type != 9 && (yyvsp[-2].object).type != 10){
                      cout << "From anything with value call statement return is not a vector" << endl;
                    }}
#line 2106 "y.tab.c"
    break;

  case 92: /* anything_with_value: ID ARROW pos  */
#line 235 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                                   {
                      if(((yyval.object).type = undeclare_check((yyvsp[-2].object).value,convert_scope_to_string())) == 0){
                        cout << "From anything_with_value Undeclared variable used " << (yyvsp[-2].object).value << " at " << yylineno<< endl;
                      }
                      if((yyval.object).type == 5 || (yyval.object).type == 6 || (yyval.object).type == 7 || (yyval.object).type == 8 || (yyval.object).type == 9 || (yyval.object).type == 10){

                      }
                      else{
                        cout << "From anything_with_value " << (yyvsp[-2].object).value << " is not a vector to access first or second" << endl;
                      }
                    }
<<<<<<< HEAD
#line 2356 "y.tab.c"
    break;

  case 107: /* anything_with_value: single_variable UNIOP  */
#line 250 "parse.y"
                                            {if(((yyval.object).type = undeclare_check((yyvsp[-1].object).value,convert_scope_to_string())) == 0){
                        cout << "From anything_with_value Undeclared variable used " << (yyvsp[-1].object).value << " at " << yylineno<< endl;
                      }}
#line 2364 "y.tab.c"
    break;

  case 108: /* anything_with_value: SIN OPENCC anything_with_value CLOSECC  */
#line 253 "parse.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2371 "y.tab.c"
    break;

  case 109: /* anything_with_value: COS OPENCC anything_with_value CLOSECC  */
#line 255 "parse.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2378 "y.tab.c"
    break;

  case 110: /* anything_with_value: TAN OPENCC anything_with_value CLOSECC  */
#line 257 "parse.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2385 "y.tab.c"
    break;

  case 112: /* operations: LOGICOP  */
#line 262 "parse.y"
                     {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2391 "y.tab.c"
    break;

  case 114: /* rhs_term: openccs anything_with_value  */
#line 266 "parse.y"
                                       {(yyval.object).type = (yyvsp[0].object).type;}
#line 2397 "y.tab.c"
    break;

  case 115: /* rhs_term: openccs anything_with_value closeccs  */
#line 267 "parse.y"
                                                {(yyval.object).type = (yyvsp[-1].object).type;}
#line 2403 "y.tab.c"
    break;

  case 116: /* rhs_term: anything_with_value closeccs  */
#line 268 "parse.y"
                                        {(yyval.object).type = (yyvsp[-1].object).type;}
#line 2409 "y.tab.c"
    break;

  case 117: /* rhs_exp: rhs_term operations rhs_exp  */
#line 272 "parse.y"
          {cout << (yyvsp[-2].object).type << ' ' << (yyvsp[-1].object).value << ' '<< (yyvsp[0].object).type << endl;
            (yyval.object).type = give_result_type((yyvsp[-2].object).type,(yyvsp[-1].object).value,(yyvsp[0].object).type); 
            if((yyval.object).type == -1){cout << "From rhs_exp Invalid operation in rhs side " << (yyvsp[-2].object).type << " " << (yyvsp[-1].object).value << " "  << (yyvsp[0].object).type << " at " << yylineno << endl;}}
#line 2417 "y.tab.c"
    break;

  case 118: /* rhs_exp: anything_with_value operations rhs_exp  */
#line 276 "parse.y"
        {cout << (yyvsp[-2].object).type << ' ' << (yyvsp[-1].object).value << ' '<< (yyvsp[0].object).type << endl; 
          (yyval.object).type = give_result_type((yyvsp[-2].object).type,(yyvsp[-1].object).value,(yyvsp[0].object).type); 
          if((yyval.object).type == -1){cout << "From rhs_exp Invalid operation in rhs side " << (yyvsp[-2].object).type << " " << (yyvsp[-1].object).value << " " << (yyvsp[0].object).type << " at " << yylineno  << endl;}}
#line 2425 "y.tab.c"
    break;

  case 121: /* openccs: openccs OPENCC  */
#line 283 "parse.y"
                         {open_brackets = open_brackets + 1; fprintf(outfile, "(");}
#line 2431 "y.tab.c"
    break;

  case 122: /* openccs: OPENCC  */
#line 284 "parse.y"
                 {open_brackets = open_brackets + 1; fprintf(outfile, "(");}
#line 2437 "y.tab.c"
    break;

  case 123: /* closeccs: closeccs CLOSECC  */
#line 287 "parse.y"
                            {close_brackets = close_brackets + 1; fprintf(outfile, ")");}
#line 2443 "y.tab.c"
    break;

  case 124: /* closeccs: CLOSECC  */
#line 288 "parse.y"
                   {close_brackets = close_brackets + 1; fprintf(outfile, ")");}
#line 2449 "y.tab.c"
    break;

  case 125: /* call_stmt_with_dot: call_stmt_without_dot DOT  */
#line 293 "parse.y"
                                               {fprintf(outfile, ";");}
#line 2455 "y.tab.c"
    break;

  case 126: /* call_stmt_without_dot: ID OPENCU CLOSECU  */
#line 297 "parse.y"
=======
#line 2122 "y.tab.c"
    break;

  case 93: /* anything_with_value: single_variable UNIOP  */
#line 246 "parse.y"
                                            {if(((yyval.object).type = undeclare_check((yyvsp[-1].object).value,convert_scope_to_string())) == 0){
                        cout << "From anything_with_value Undeclared variable used " << (yyvsp[-1].object).value << " at " << yylineno<< endl;
                      }}
#line 2130 "y.tab.c"
    break;

  case 94: /* anything_with_value: SIN OPENCC anything_with_value CLOSECC  */
#line 249 "parse.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2137 "y.tab.c"
    break;

  case 95: /* anything_with_value: COS OPENCC anything_with_value CLOSECC  */
#line 251 "parse.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2144 "y.tab.c"
    break;

  case 96: /* anything_with_value: TAN OPENCC anything_with_value CLOSECC  */
#line 253 "parse.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2151 "y.tab.c"
    break;

  case 100: /* rhs_term: openccs anything_with_value  */
#line 262 "parse.y"
                                       {(yyval.object).type = (yyvsp[0].object).type;}
#line 2157 "y.tab.c"
    break;

  case 101: /* rhs_term: openccs anything_with_value closeccs  */
#line 263 "parse.y"
                                                {(yyval.object).type = (yyvsp[-1].object).type;}
#line 2163 "y.tab.c"
    break;

  case 102: /* rhs_term: anything_with_value closeccs  */
#line 264 "parse.y"
                                        {(yyval.object).type = (yyvsp[-1].object).type;}
#line 2169 "y.tab.c"
    break;

  case 103: /* rhs_exp: rhs_term operations rhs_exp  */
#line 267 "parse.y"
                                      {cout << (yyvsp[-2].object).type << ' ' << (yyvsp[-1].object).value << ' '<< (yyvsp[0].object).type << endl;
(yyval.object).type = give_result_type((yyvsp[-2].object).type,(yyvsp[-1].object).value,(yyvsp[0].object).type); 
if((yyval.object).type == -1){cout << "From rhs_exp Invalid operation in rhs side " << (yyvsp[-2].object).type << " " << (yyvsp[-1].object).value << " "  << (yyvsp[0].object).type << " at " << yylineno << endl;}}
#line 2177 "y.tab.c"
    break;

  case 104: /* rhs_exp: anything_with_value operations rhs_exp  */
#line 270 "parse.y"
                                                 {cout << (yyvsp[-2].object).type << ' ' << (yyvsp[-1].object).value << ' '<< (yyvsp[0].object).type << endl; 
(yyval.object).type = give_result_type((yyvsp[-2].object).type,(yyvsp[-1].object).value,(yyvsp[0].object).type); 
if((yyval.object).type == -1){cout << "From rhs_exp Invalid operation in rhs side " << (yyvsp[-2].object).type << " " << (yyvsp[-1].object).value << " " << (yyvsp[0].object).type << " at " << yylineno  << endl;}}
#line 2185 "y.tab.c"
    break;

  case 107: /* openccs: openccs OPENCC  */
#line 277 "parse.y"
                         {open_brackets = open_brackets + 1;}
#line 2191 "y.tab.c"
    break;

  case 108: /* openccs: OPENCC  */
#line 278 "parse.y"
                 {open_brackets = open_brackets + 1;}
#line 2197 "y.tab.c"
    break;

  case 109: /* closeccs: closeccs CLOSECC  */
#line 281 "parse.y"
                            {close_brackets = close_brackets + 1;}
#line 2203 "y.tab.c"
    break;

  case 110: /* closeccs: CLOSECC  */
#line 282 "parse.y"
                   {close_brackets = close_brackets + 1;}
#line 2209 "y.tab.c"
    break;

  case 112: /* call_stmt_without_dot: ID OPENCU CLOSECU  */
#line 291 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                      {
                        char* templist[100];
                        int temp = 0;
                        if(!check_func_args((yyvsp[-2].object).value,templist,temp )){
                          cout << "From call_stmt_without_dot Undeclared function " << (yyvsp[-2].object).value <<" at " << yylineno  << endl;
                        }
                        func_args_list.clear();
                        (yyval.object).type = find_return_type((yyvsp[-2].object).value,templist,temp);
<<<<<<< HEAD
                        fprintf(outfile, "%s()", (yyvsp[-2].object));
                      }
#line 2470 "y.tab.c"
    break;

  case 127: /* $@20: %empty  */
#line 307 "parse.y"
                                       {fprintf(outfile, "%s(",(yyvsp[-1].object));}
#line 2476 "y.tab.c"
    break;

  case 128: /* call_stmt_without_dot: ID OPENCU $@20 funccallargs CLOSECU  */
#line 308 "parse.y"
                      {
                          if(!check_func_args((yyvsp[-4].object).value, (yyvsp[-1].arg_object).list,(yyvsp[-1].arg_object).present)){
                            cout << "From call_stmt_without_dot Undeclared function " << (yyvsp[-4].object).value <<" at " << yylineno  << endl;
                          }
                          func_args_list.clear();
                          (yyval.object).type = find_return_type((yyvsp[-4].object).value,(yyvsp[-1].arg_object).list,(yyvsp[-1].arg_object).present);
                          fprintf(outfile, ")");
                      }
#line 2489 "y.tab.c"
    break;

  case 129: /* funccallargs: check_rhs_exp  */
#line 320 "parse.y"
=======
                      }
#line 2223 "y.tab.c"
    break;

  case 113: /* call_stmt_without_dot: ID OPENCU funccallargs CLOSECU  */
#line 301 "parse.y"
                      {
                          if(!check_func_args((yyvsp[-3].object).value, (yyvsp[-1].arg_object).list,(yyvsp[-1].arg_object).present)){
                            cout << "From call_stmt_without_dot Undeclared function " << (yyvsp[-3].object).value <<" at " << yylineno  << endl;
                          }
                          func_args_list.clear();
                          (yyval.object).type = find_return_type((yyvsp[-3].object).value,(yyvsp[-1].arg_object).list,(yyvsp[-1].arg_object).present);
                      }
#line 2235 "y.tab.c"
    break;

  case 114: /* funccallargs: check_rhs_exp  */
#line 312 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                {
                  (yyval.arg_object).list[0] = &(get_string_type((yyvsp[0].object).type)[0]);
                  (yyval.arg_object).present = 1;
                }
<<<<<<< HEAD
#line 2498 "y.tab.c"
    break;

  case 130: /* $@21: %empty  */
#line 324 "parse.y"
                                   {fprintf(outfile, ",");}
#line 2504 "y.tab.c"
    break;

  case 131: /* funccallargs: check_rhs_exp COMMA $@21 funccallargs  */
#line 325 "parse.y"
=======
#line 2244 "y.tab.c"
    break;

  case 115: /* funccallargs: check_rhs_exp COMMA funccallargs  */
#line 317 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
              {
                for(int i=0;i<(yyvsp[0].arg_object).present;i++){
                  (yyval.arg_object).list[i+1] = (yyvsp[0].arg_object).list[i];
                }
                (yyval.arg_object).present = (yyvsp[0].arg_object).present + 1;
<<<<<<< HEAD
                (yyval.arg_object).list[0] = &(get_string_type((yyvsp[-3].object).type)[0]);
              }
#line 2516 "y.tab.c"
    break;

  case 132: /* $@22: %empty  */
#line 336 "parse.y"
                                {fprintf(outfile, "if(");}
#line 2522 "y.tab.c"
    break;

  case 133: /* conditional_stmt_start: OPENSQ $@22 check_rhs_exp CLOSESQ OPENCU  */
#line 336 "parse.y"
                                                                                        { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "){");}
#line 2528 "y.tab.c"
    break;

  case 134: /* conditional_stmt: conditional_stmt_start loop_body CLOSECU  */
#line 340 "parse.y"
                                                           {current_pointer--; fprintf(outfile, "\n}\n");}
#line 2534 "y.tab.c"
    break;

  case 135: /* $@23: %empty  */
#line 341 "parse.y"
                                                           {current_pointer--; }
#line 2540 "y.tab.c"
    break;

  case 136: /* $@24: %empty  */
#line 341 "parse.y"
                                                                                                  { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "} else {");}
#line 2546 "y.tab.c"
    break;

  case 137: /* conditional_stmt: conditional_stmt_start loop_body CLOSECU $@23 OTHERWISE OPENCU $@24 loop_body CLOSECU  */
#line 341 "parse.y"
                                                                                                                                                                                                          {current_pointer--; fprintf(outfile, "}");}
#line 2552 "y.tab.c"
    break;

  case 138: /* $@25: %empty  */
#line 346 "parse.y"
                       {fprintf(outfile, "while(");}
#line 2558 "y.tab.c"
    break;

  case 139: /* $@26: %empty  */
#line 346 "parse.y"
                                                                                  { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "){");}
#line 2564 "y.tab.c"
    break;

  case 140: /* loop_stmt: LOOP OPENSQ $@25 check_rhs_exp CLOSESQ OPENCU $@26 loop_body CLOSECU  */
#line 346 "parse.y"
                                                                                                                                                                                   {current_pointer--; fprintf(outfile, "}");}
#line 2570 "y.tab.c"
    break;

  case 141: /* unary_operation_without_dot: single_variable UNIOP  */
#line 351 "parse.y"
                                                   {
                              fprintf(outfile, "%s", (yyvsp[0].object));
                              if (((yyval.object).type = undeclare_check((yyvsp[-1].object).value,convert_scope_to_string())) == 0) cout << "undeclaration error at " << yylineno << (yyvsp[-1].object).value << endl;
                              if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
                                cout << "From unary_operation_without_dot cant perform operation" << endl;
                              }
                              (yyval.object).type = (yyvsp[-1].object).type;
                              }
#line 2583 "y.tab.c"
    break;

  case 142: /* $@27: %empty  */
#line 359 "parse.y"
                                    {fprintf(outfile, " !");}
#line 2589 "y.tab.c"
    break;

  case 143: /* unary_operation_without_dot: UNINEG $@27 check_rhs_exp  */
#line 359 "parse.y"
                                                                            {
=======
                (yyval.arg_object).list[0] = &(get_string_type((yyvsp[-2].object).type)[0]);
              }
#line 2256 "y.tab.c"
    break;

  case 116: /* conditional_stmt_start: OPENSQ check_rhs_exp CLOSESQ OPENCU  */
#line 328 "parse.y"
                                                             { current_pointer++;  curr_scopes[current_pointer]++; }
#line 2262 "y.tab.c"
    break;

  case 117: /* conditional_stmt: conditional_stmt_start loop_body CLOSECU  */
#line 332 "parse.y"
                                                           {current_pointer--; }
#line 2268 "y.tab.c"
    break;

  case 118: /* $@7: %empty  */
#line 333 "parse.y"
                                                           {current_pointer--; }
#line 2274 "y.tab.c"
    break;

  case 119: /* $@8: %empty  */
#line 333 "parse.y"
                                                                                                  { current_pointer++;  curr_scopes[current_pointer]++; }
#line 2280 "y.tab.c"
    break;

  case 120: /* conditional_stmt: conditional_stmt_start loop_body CLOSECU $@7 OTHERWISE OPENCU $@8 loop_body CLOSECU  */
#line 333 "parse.y"
                                                                                                                                                                             {current_pointer--; }
#line 2286 "y.tab.c"
    break;

  case 121: /* $@9: %empty  */
#line 338 "parse.y"
                                                    { current_pointer++;  curr_scopes[current_pointer]++; }
#line 2292 "y.tab.c"
    break;

  case 122: /* loop_stmt: LOOP OPENSQ check_rhs_exp CLOSESQ OPENCU $@9 loop_body CLOSECU  */
#line 338 "parse.y"
                                                                                                                              {current_pointer--; }
#line 2298 "y.tab.c"
    break;

  case 123: /* unary_operation_without_dot: single_variable UNIOP  */
#line 343 "parse.y"
                                                   {if (((yyval.object).type = undeclare_check((yyvsp[-1].object).value,convert_scope_to_string())) == 0) cout << "undeclaration error at " << yylineno << (yyvsp[-1].object).value << endl;
                              if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
                                cout << "From unary_operation_without_dot cant perform operation" << endl;
                              }
                              (yyval.object).type = (yyvsp[-1].object).type;}
#line 2308 "y.tab.c"
    break;

  case 124: /* unary_operation_without_dot: UNINEG check_rhs_exp  */
#line 348 "parse.y"
                                                  {
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                            (yyval.object).type = 4;
                            if ((yyvsp[0].object).type != 1 && (yyvsp[0].object).type !=2 && (yyvsp[0].object).type != 4){
                              cout << "From unary_operation_without_dot invalid negation operation" << endl;
                            }
                           }
<<<<<<< HEAD
#line 2600 "y.tab.c"
    break;

  case 144: /* $@28: %empty  */
#line 369 "parse.y"
                  {fprintf(outfile, "return ");}
#line 2606 "y.tab.c"
    break;

  case 145: /* return_stmt: DARR $@28 check_rhs_exp DOT  */
#line 369 "parse.y"
                                                                    {fprintf(outfile, ";");}
#line 2612 "y.tab.c"
    break;

  case 146: /* return_stmt: DARR DOT  */
#line 370 "parse.y"
                      {fprintf(outfile, "return ;");}
#line 2618 "y.tab.c"
    break;

  case 147: /* comments: CMT  */
#line 375 "parse.y"
               {fprintf(outfile, "%s", (yyvsp[0].object));}
#line 2624 "y.tab.c"
    break;

  case 148: /* $@29: %empty  */
#line 380 "parse.y"
                           {fprintf(outfile, " cout << ");}
#line 2630 "y.tab.c"
    break;

  case 149: /* output_stmt: OUTPUT COLON $@29 check_rhs_exp DOT  */
#line 380 "parse.y"
                                                                              {fprintf(outfile, ";");}
#line 2636 "y.tab.c"
    break;

  case 150: /* $@30: %empty  */
#line 385 "parse.y"
                         {fprintf(outfile, "cin >>  ");}
#line 2642 "y.tab.c"
    break;

  case 151: /* input_stmt: INPUT COLON $@30 ids DOT  */
#line 385 "parse.y"
                                                                 {fprintf(outfile, ";");}
#line 2648 "y.tab.c"
    break;

  case 152: /* $@31: %empty  */
#line 388 "parse.y"
                      {if(undeclare_check((yyvsp[0].object).value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        }}
#line 2656 "y.tab.c"
    break;

  case 153: /* $@32: %empty  */
#line 390 "parse.y"
                                {fprintf(outfile, ",");}
#line 2662 "y.tab.c"
    break;

  case 155: /* ids: single_variable  */
#line 391 "parse.y"
                      {if(undeclare_check((yyvsp[0].object).value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        }}
#line 2670 "y.tab.c"
    break;

  case 156: /* inbuilt_functions_with_dot: inbuilt_functions DOT  */
#line 398 "parse.y"
                                                   {fprintf(outfile, ";");}
#line 2676 "y.tab.c"
    break;

  case 166: /* stand_id: ID  */
#line 412 "parse.y"
=======
#line 2319 "y.tab.c"
    break;

  case 130: /* $@10: %empty  */
#line 377 "parse.y"
                      {if(undeclare_check((yyvsp[0].object).value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        }}
#line 2327 "y.tab.c"
    break;

  case 132: /* ids: single_variable  */
#line 380 "parse.y"
                      {if(undeclare_check((yyvsp[0].object).value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        }}
#line 2335 "y.tab.c"
    break;

  case 143: /* stand_id: ID  */
#line 401 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
              {if(((yyval.object).type = undeclare_check((yyvsp[0].object).value,convert_scope_to_string())) == 0){
                          cout << "From stand_id Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        };
                if((yyval.object).type != 11){
                  cout << "From stand_id indentifier is of not mass datatype at " << yylineno << endl; 
                }
              }
<<<<<<< HEAD
#line 2688 "y.tab.c"
    break;

  case 167: /* rel_to_mag: MAG OPENCU stand_id CLOSECU  */
#line 420 "parse.y"
                                         {(yyval.object).type = 2;}
#line 2694 "y.tab.c"
    break;

  case 168: /* rel_to_mag: MAG OPENCU vectors CLOSECU  */
#line 421 "parse.y"
                                        {(yyval.object).type = 2;}
#line 2700 "y.tab.c"
    break;

  case 169: /* rel_to_pos: OPENCU stand_id CLOSECU SETR OPENCU check_rhs_exp CLOSECU  */
#line 424 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 6 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2708 "y.tab.c"
    break;

  case 170: /* rel_to_pos: OPENCU stand_id CLOSECU ADDR OPENCU check_rhs_exp CLOSECU  */
#line 427 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 6 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2716 "y.tab.c"
    break;

  case 171: /* rel_to_pos: OPENCU stand_id CLOSECU R_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 430 "parse.y"
                                                                          {(yyval.object).type = 6; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2724 "y.tab.c"
    break;

  case 172: /* rel_to_pos: OPENCU stand_id CLOSECU GETR  */
#line 433 "parse.y"
                                          {(yyval.object).type = 6;}
#line 2730 "y.tab.c"
    break;

  case 173: /* rel_to_vel: OPENCU stand_id CLOSECU SETV OPENCU check_rhs_exp CLOSECU  */
#line 436 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 5 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2738 "y.tab.c"
    break;

  case 174: /* rel_to_vel: OPENCU stand_id CLOSECU ADDV OPENCU check_rhs_exp CLOSECU  */
#line 439 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 5 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2746 "y.tab.c"
    break;

  case 175: /* rel_to_vel: OPENCU stand_id CLOSECU V_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 442 "parse.y"
                                                                          {(yyval.object).type = 5; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2754 "y.tab.c"
    break;

  case 176: /* rel_to_vel: OPENCU stand_id CLOSECU GETV  */
#line 445 "parse.y"
                                          {(yyval.object).type = 5;}
#line 2760 "y.tab.c"
    break;

  case 177: /* rel_to_momentum: OPENCU stand_id CLOSECU SETP OPENCU check_rhs_exp CLOSECU  */
#line 448 "parse.y"
                                                                            {if((yyvsp[-1].object).type != 9 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_momentum invalid statement" << endl;
}}
#line 2768 "y.tab.c"
    break;

  case 178: /* rel_to_acc: OPENCU stand_id CLOSECU SETA OPENCU check_rhs_exp CLOSECU  */
#line 453 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 7 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_acc invalid statement" << endl;
}}
#line 2776 "y.tab.c"
    break;

  case 179: /* rel_to_acc: OPENCU stand_id CLOSECU ADDA OPENCU check_rhs_exp CLOSECU  */
#line 456 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 7 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_acc invalid statement" << endl;
}}
#line 2784 "y.tab.c"
    break;

  case 180: /* rel_to_acc: OPENCU stand_id CLOSECU GETA  */
#line 459 "parse.y"
                                          {(yyval.object).type = 7;}
#line 2790 "y.tab.c"
    break;

  case 181: /* rel_to_energy: OPENCU stand_id CLOSECU KE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 462 "parse.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2798 "y.tab.c"
    break;

  case 182: /* rel_to_energy: OPENCU stand_id CLOSECU PE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 465 "parse.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2806 "y.tab.c"
    break;

  case 183: /* rel_to_energy: OPENCU stand_id CLOSECU TE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 468 "parse.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2814 "y.tab.c"
    break;

  case 184: /* rel_to_angle: OPENCU stand_id CLOSECU ANGLE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 473 "parse.y"
                                                                               {(yyval.object).type = 14 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_angle invalid statement" << endl;
}}
#line 2822 "y.tab.c"
    break;

  case 185: /* rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id COMMA ID CLOSECU  */
#line 478 "parse.y"
                                                                                   {(yyval.object).type = 13;}
#line 2828 "y.tab.c"
    break;

  case 186: /* rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id CLOSECU  */
#line 479 "parse.y"
                                                                          {(yyval.object).type = 13;}
#line 2834 "y.tab.c"
    break;

  case 187: /* rel_to_collision: OPENCU stand_id CLOSECU TIME_TO_COLLIDE OPENCU stand_id CLOSECU  */
#line 480 "parse.y"
                                                                                  {(yyval.object).type = 12 ;}
#line 2840 "y.tab.c"
    break;

  case 188: /* miscellaneous: OPENCU stand_id CLOSECU S_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 483 "parse.y"
                                                                            {(yyval.object).type = 8; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2848 "y.tab.c"
    break;

  case 189: /* miscellaneous: OPENCU stand_id CLOSECU ROC_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 486 "parse.y"
                                                                              {(yyval.object).type = 2; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2856 "y.tab.c"
    break;

  case 190: /* miscellaneous: OPENCU stand_id CLOSECU P_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 489 "parse.y"
                                                                            {(yyval.object).type = 9; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2864 "y.tab.c"
    break;

  case 191: /* miscellaneous: OPENCU stand_id CLOSECU TIME_TO_R OPENCU term_misc COMMA term_misc CLOSECU  */
#line 492 "parse.y"
                                                                                          {(yyval.object).type = 12;}
#line 2870 "y.tab.c"
    break;

  case 192: /* miscellaneous: OPENCU stand_id CLOSECU TIME_TO_V OPENCU term_misc COMMA term_misc CLOSECU  */
#line 493 "parse.y"
                                                                                          {(yyval.object).type = 12;}
#line 2876 "y.tab.c"
    break;

  case 193: /* term_misc: check_rhs_exp  */
#line 496 "parse.y"
                          {if((yyvsp[0].object).type != 1 && (yyvsp[0].object).type != 2){
  cout << "From term_misc invalid statement" << endl;
}}
#line 2884 "y.tab.c"
    break;

  case 195: /* decl_stmt_with_exp: datatypes expressions DOT  */
#line 504 "parse.y"
                                               {fprintf(outfile,";");}
#line 2890 "y.tab.c"
    break;

  case 196: /* $@33: %empty  */
#line 507 "parse.y"
                               {fprintf(outfile,",");}
#line 2896 "y.tab.c"
    break;

  case 199: /* single_variable_declare: single_variable  */
#line 511 "parse.y"
=======
#line 2347 "y.tab.c"
    break;

  case 144: /* rel_to_mag: MAG OPENCU stand_id CLOSECU  */
#line 409 "parse.y"
                                         {(yyval.object).type = 2;}
#line 2353 "y.tab.c"
    break;

  case 145: /* rel_to_mag: MAG OPENCU vectors CLOSECU  */
#line 410 "parse.y"
                                        {(yyval.object).type = 2;}
#line 2359 "y.tab.c"
    break;

  case 146: /* rel_to_pos: OPENCU stand_id CLOSECU SETR OPENCU check_rhs_exp CLOSECU  */
#line 413 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 6 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2367 "y.tab.c"
    break;

  case 147: /* rel_to_pos: OPENCU stand_id CLOSECU ADDR OPENCU check_rhs_exp CLOSECU  */
#line 416 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 6 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2375 "y.tab.c"
    break;

  case 148: /* rel_to_pos: OPENCU stand_id CLOSECU R_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 419 "parse.y"
                                                                          {(yyval.object).type = 6; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2383 "y.tab.c"
    break;

  case 149: /* rel_to_pos: OPENCU stand_id CLOSECU GETR  */
#line 422 "parse.y"
                                          {(yyval.object).type = 6;}
#line 2389 "y.tab.c"
    break;

  case 150: /* rel_to_vel: OPENCU stand_id CLOSECU SETV OPENCU check_rhs_exp CLOSECU  */
#line 425 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 5 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2397 "y.tab.c"
    break;

  case 151: /* rel_to_vel: OPENCU stand_id CLOSECU ADDV OPENCU check_rhs_exp CLOSECU  */
#line 428 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 5 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2405 "y.tab.c"
    break;

  case 152: /* rel_to_vel: OPENCU stand_id CLOSECU V_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 431 "parse.y"
                                                                          {(yyval.object).type = 5; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2413 "y.tab.c"
    break;

  case 153: /* rel_to_vel: OPENCU stand_id CLOSECU GETV  */
#line 434 "parse.y"
                                          {(yyval.object).type = 5;}
#line 2419 "y.tab.c"
    break;

  case 154: /* rel_to_momentum: OPENCU stand_id CLOSECU SETP OPENCU check_rhs_exp CLOSECU  */
#line 437 "parse.y"
                                                                            {if((yyvsp[-1].object).type != 9 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_momentum invalid statement" << endl;
}}
#line 2427 "y.tab.c"
    break;

  case 155: /* rel_to_acc: OPENCU stand_id CLOSECU SETA OPENCU check_rhs_exp CLOSECU  */
#line 442 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 7 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_acc invalid statement" << endl;
}}
#line 2435 "y.tab.c"
    break;

  case 156: /* rel_to_acc: OPENCU stand_id CLOSECU ADDA OPENCU check_rhs_exp CLOSECU  */
#line 445 "parse.y"
                                                                       {if((yyvsp[-1].object).type != 7 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_acc invalid statement" << endl;
}}
#line 2443 "y.tab.c"
    break;

  case 157: /* rel_to_acc: OPENCU stand_id CLOSECU GETA  */
#line 448 "parse.y"
                                          {(yyval.object).type = 7;}
#line 2449 "y.tab.c"
    break;

  case 158: /* rel_to_energy: OPENCU stand_id CLOSECU KE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 451 "parse.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2457 "y.tab.c"
    break;

  case 159: /* rel_to_energy: OPENCU stand_id CLOSECU PE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 454 "parse.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2465 "y.tab.c"
    break;

  case 160: /* rel_to_energy: OPENCU stand_id CLOSECU TE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 457 "parse.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2473 "y.tab.c"
    break;

  case 161: /* rel_to_angle: OPENCU stand_id CLOSECU ANGLE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 462 "parse.y"
                                                                               {(yyval.object).type = 14 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_angle invalid statement" << endl;
}}
#line 2481 "y.tab.c"
    break;

  case 162: /* rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id COMMA ID CLOSECU  */
#line 467 "parse.y"
                                                                                   {(yyval.object).type = 13;}
#line 2487 "y.tab.c"
    break;

  case 163: /* rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id CLOSECU  */
#line 468 "parse.y"
                                                                          {(yyval.object).type = 13;}
#line 2493 "y.tab.c"
    break;

  case 164: /* rel_to_collision: OPENCU stand_id CLOSECU TIME_TO_COLLIDE OPENCU stand_id CLOSECU  */
#line 469 "parse.y"
                                                                                  {(yyval.object).type = 12 ;}
#line 2499 "y.tab.c"
    break;

  case 165: /* miscellaneous: OPENCU stand_id CLOSECU S_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 472 "parse.y"
                                                                            {(yyval.object).type = 8; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2507 "y.tab.c"
    break;

  case 166: /* miscellaneous: OPENCU stand_id CLOSECU ROC_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 475 "parse.y"
                                                                              {(yyval.object).type = 2; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2515 "y.tab.c"
    break;

  case 167: /* miscellaneous: OPENCU stand_id CLOSECU P_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 478 "parse.y"
                                                                            {(yyval.object).type = 9; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2523 "y.tab.c"
    break;

  case 168: /* miscellaneous: OPENCU stand_id CLOSECU TIME_TO_R OPENCU term_misc COMMA term_misc CLOSECU  */
#line 481 "parse.y"
                                                                                          {(yyval.object).type = 12;}
#line 2529 "y.tab.c"
    break;

  case 169: /* miscellaneous: OPENCU stand_id CLOSECU TIME_TO_V OPENCU term_misc COMMA term_misc CLOSECU  */
#line 482 "parse.y"
                                                                                          {(yyval.object).type = 12;}
#line 2535 "y.tab.c"
    break;

  case 170: /* term_misc: check_rhs_exp  */
#line 485 "parse.y"
                          {if((yyvsp[0].object).type != 1 && (yyvsp[0].object).type != 2){
  cout << "From term_misc invalid statement" << endl;
}}
#line 2543 "y.tab.c"
    break;

  case 175: /* single_variable_declare: single_variable  */
#line 500 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                                          {
                          (yyval.object).type = give_type_index(type);
                          if(is_func_bool){
                          var_records* rec = new var_records;
													rec->name = (yyvsp[0].object).value;
													rec->type = type;
													rec->scope = convert_scope_to_string();
<<<<<<< HEAD
=======
                          if(arr_check) rec->arr_type = "Array";
                          else rec->arr_type = "Simple";
                          rec->dim_countt = dim_count;
                          dim_count = 0;
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                          fn_var_entry(rec);
                          }
                        else{
                          add('V',(yyvsp[0].object).value,type);
                        }
}
<<<<<<< HEAD
#line 2914 "y.tab.c"
    break;

  case 200: /* $@34: %empty  */
#line 525 "parse.y"
                {open_brackets = 0;close_brackets = 0;}
#line 2920 "y.tab.c"
    break;

  case 201: /* check_rhs_exp: $@34 rhs_exp  */
#line 525 "parse.y"
                                                                {if(open_brackets != close_brackets){cout << "Incorrect RHS expression at " << yylineno << endl;}open_brackets = 0;close_brackets = 0;(yyval.object).type = (yyvsp[0].object).type;(yyval.object).value = (yyvsp[0].object).value;}
#line 2926 "y.tab.c"
    break;

  case 202: /* $@35: %empty  */
#line 527 "parse.y"
                                           {fprintf(outfile, "=");}
#line 2932 "y.tab.c"
    break;

  case 203: /* expression: single_variable_declare ASSGN $@35 check_rhs_exp  */
#line 527 "parse.y"
                                                                                  { if(!type_checking_assign((yyvsp[-3].object).type,(yyvsp[0].object).type)){cout << "Declaration with expression type error " <<  (yyvsp[-3].object).type <<  ' ' << (yyvsp[0].object).type << " at " << yylineno << endl;}}
#line 2938 "y.tab.c"
    break;

  case 205: /* idadd2: ID  */
#line 533 "parse.y"
            {is_func_bool = true;
        if(!func_red_var((yyvsp[0].object).value)){cout << "Redeclaration error : Function is redeclared as variable nameat " << yylineno << endl;}
        fprintf(outfile,"%s", (yyvsp[0].object));
        }
#line 2947 "y.tab.c"
    break;

  case 206: /* $@36: %empty  */
#line 539 "parse.y"
                                              {fprintf(outfile,"(");}
#line 2953 "y.tab.c"
    break;

  case 207: /* $@37: %empty  */
#line 539 "parse.y"
                                                                                         {fprintf(outfile,")");}
#line 2959 "y.tab.c"
    break;

  case 208: /* $@38: %empty  */
#line 539 "parse.y"
                                                                                                                             {fprintf(outfile,"{");}
#line 2965 "y.tab.c"
    break;

  case 209: /* $@39: %empty  */
#line 540 "parse.y"
{current_pointer++;  curr_scopes[current_pointer]++; }
#line 2971 "y.tab.c"
    break;

  case 210: /* $@40: %empty  */
#line 541 "parse.y"
                {   
                  if (valid_func_entry((yyvsp[-11].object).value , par_list)){
                    new_func_entry( (yyvsp[-11].object).value, (yyvsp[-12].object).value, par_list.size(), par_list, var_list);
                    add('F',(yyvsp[-11].object).value,(yyvsp[-12].object).value);
=======
#line 2565 "y.tab.c"
    break;

  case 176: /* $@11: %empty  */
#line 518 "parse.y"
                {open_brackets = 0;close_brackets = 0;}
#line 2571 "y.tab.c"
    break;

  case 177: /* check_rhs_exp: $@11 rhs_exp  */
#line 518 "parse.y"
                                                                {if(open_brackets != close_brackets){cout << "Incorrect RHS expression at " << yylineno << endl;}open_brackets = 0;close_brackets = 0;(yyval.object).type = (yyvsp[0].object).type;(yyval.object).value = (yyvsp[0].object).value;}
#line 2577 "y.tab.c"
    break;

  case 178: /* expression: single_variable_declare ASSGN check_rhs_exp  */
#line 520 "parse.y"
                                                         { if(!type_checking_assign((yyvsp[-2].object).type,(yyvsp[0].object).type)){cout << "Declaration with expression type error " <<  (yyvsp[-2].object).type <<  ' ' << (yyvsp[0].object).type << " at " << yylineno << endl;}}
#line 2583 "y.tab.c"
    break;

  case 180: /* idadd2: ID  */
#line 526 "parse.y"
            {is_func_bool = true;
        if(!func_red_var((yyvsp[0].object).value)){cout << "Redeclaration error : Function is redeclared as variable nameat " << yylineno << endl;}}
#line 2590 "y.tab.c"
    break;

  case 181: /* $@12: %empty  */
#line 530 "parse.y"
                                                                             {current_pointer++;  curr_scopes[current_pointer]++; }
#line 2596 "y.tab.c"
    break;

  case 182: /* $@13: %empty  */
#line 531 "parse.y"
                {   
                  if (valid_func_entry((yyvsp[-8].object).value , par_list)){
                    new_func_entry( (yyvsp[-8].object).value, (yyvsp[-9].object).value, par_list.size(), par_list, var_list);
                    add('F',(yyvsp[-8].object).value,(yyvsp[-9].object).value);
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                  }
                  else{
                     cout<< "Function re-def, ERROR!at " << yylineno<<endl;
                  }
                  var_list.clear(); 
                  par_list.clear();
                }
<<<<<<< HEAD
#line 2987 "y.tab.c"
    break;

  case 211: /* function_decl: datatypes idadd2 ASSGN OPENCU $@36 parameters CLOSECU $@37 DARR OPENCU $@38 $@39 body $@40 CLOSECU  */
#line 552 "parse.y"
                        {is_func_bool = false;current_pointer--; fprintf(outfile,"}"); }
#line 2993 "y.tab.c"
    break;

  case 212: /* $@41: %empty  */
#line 554 "parse.y"
                                                                  {fprintf(outfile,"(){");}
#line 2999 "y.tab.c"
    break;

  case 213: /* $@42: %empty  */
#line 554 "parse.y"
                                                                                            {current_pointer++;  curr_scopes[current_pointer]++;}
#line 3005 "y.tab.c"
    break;

  case 214: /* $@43: %empty  */
#line 555 "parse.y"
                {
                    if (valid_func_entry((yyvsp[-8].object).value , par_list)){
                      new_func_entry( (yyvsp[-8].object).value, (yyvsp[-9].object).value, par_list.size(), par_list, var_list);
                      add('F',(yyvsp[-8].object).value,(yyvsp[-9].object).value);
=======
#line 2612 "y.tab.c"
    break;

  case 183: /* function_decl: datatypes idadd2 ASSGN OPENCU parameters CLOSECU DARR OPENCU $@12 body $@13 CLOSECU  */
#line 542 "parse.y"
                        {is_func_bool = false;current_pointer--; }
#line 2618 "y.tab.c"
    break;

  case 184: /* $@14: %empty  */
#line 543 "parse.y"
                                                                  {current_pointer++;  curr_scopes[current_pointer]++;}
#line 2624 "y.tab.c"
    break;

  case 185: /* $@15: %empty  */
#line 544 "parse.y"
                {
                    if (valid_func_entry((yyvsp[-7].object).value , par_list)){
                      new_func_entry( (yyvsp[-7].object).value, (yyvsp[-8].object).value, par_list.size(), par_list, var_list);
                      add('F',(yyvsp[-7].object).value,(yyvsp[-8].object).value);
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
                    }
                    else{
                      cout<< "Function re-def, ERROR!at " << yylineno<<endl;
                  }
                    var_list.clear(); 
                    par_list.clear();
                }
<<<<<<< HEAD
#line 3021 "y.tab.c"
    break;

  case 215: /* function_decl: datatypes idadd2 ASSGN OPENCU CLOSECU DARR OPENCU $@41 $@42 body $@43 CLOSECU  */
#line 566 "parse.y"
                        {is_func_bool = false;current_pointer--; 
                fprintf(outfile,"}");}
#line 3028 "y.tab.c"
    break;

  case 216: /* $@44: %empty  */
#line 570 "parse.y"
                         {fprintf(outfile,"%s", (yyvsp[0].object));}
#line 3034 "y.tab.c"
    break;

  case 217: /* parameters: datatypes ID $@44  */
#line 571 "parse.y"
        {
          if(!within_func_parameters_redeclaration((yyvsp[-1].object).value)) cout << "Redeclaration of parameters in the functionat " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = (yyvsp[-1].object).value;
						rec->type = type;
            par_list.push_back(rec);
        }
#line 3046 "y.tab.c"
    break;

  case 218: /* $@45: %empty  */
#line 579 "parse.y"
=======
#line 2640 "y.tab.c"
    break;

  case 186: /* function_decl: datatypes idadd2 ASSGN OPENCU CLOSECU DARR OPENCU $@14 body $@15 CLOSECU  */
#line 555 "parse.y"
                        {is_func_bool = false;current_pointer--; }
#line 2646 "y.tab.c"
    break;

  case 187: /* parameters: datatypes ID  */
#line 559 "parse.y"
        {
          if(!within_func_parameters_redeclaration((yyvsp[0].object).value)) cout << "Redeclaration of parameters in the functionat " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = (yyvsp[0].object).value;
						rec->type = type;
            par_list.push_back(rec);
        }
#line 2658 "y.tab.c"
    break;

  case 188: /* $@16: %empty  */
#line 567 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
          {
          if(!within_func_parameters_redeclaration((yyvsp[0].object).value)) cout << "Redeclaration of parameters in the functionat " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = (yyvsp[0].object).value;
						rec->type = type;
            par_list.push_back(rec);
          }
<<<<<<< HEAD
#line 3058 "y.tab.c"
    break;

  case 219: /* $@46: %empty  */
#line 586 "parse.y"
                {fprintf(outfile,"%s,",(yyvsp[-2].object));}
#line 3064 "y.tab.c"
    break;


#line 3068 "y.tab.c"
=======
#line 2670 "y.tab.c"
    break;


#line 2674 "y.tab.c"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

<<<<<<< HEAD
#line 591 "parse.y"
=======
#line 579 "parse.y"
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741


void yyerror(char* s){
	printf("Syntax Error : In line number %d\n",yylineno);
	fprintf(parsefile," %s\n",s);
}

int main(int argc ,char * argv[]){
<<<<<<< HEAD
    char inp_file[100],tok[100],parse[100],out_file[100];

    sprintf(inp_file,"inp.phic");
    sprintf(out_file,"outc.cpp");

    yyin = fopen(inp_file,"r");

  outfile = fopen(out_file,"w");
    fprintf(outfile,"#include <bits/stdc++.h> \nusing namespace std;\n\n");


=======
    char inp_file[100],tok[100],parse[100];

    sprintf(inp_file,"inp.phic");

    yyin = fopen(inp_file,"r");

>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
  construct_stack();
	int i = yyparse();

    print_table();
    print_function_table();

<<<<<<< HEAD

=======
>>>>>>> e5e67e992621007fb70519ea2ef45fd336629741
	if(i) printf("Failure\n");
	else printf("Success\n");

	return 0;
}
