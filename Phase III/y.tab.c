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
#line 1 "parsefile.y"

#include <bits/stdc++.h>
#include "semantics.hpp"

extern FILE *yyin, *tokfile, *parsefile ;
extern int yylineno;
int yylex();
void yyerror(char *s);

#line 81 "y.tab.c"

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
#line 11 "parsefile.y"

	struct variable {
		char* value;
		int type;
	} object;
  struct for_args {
    char* list[100];
    int present;
  } arg_object ;

#line 331 "y.tab.c"

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
#define YYLAST   942

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  189
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

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
       0,    64,    64,    65,    68,    69,    70,    74,    76,    73,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    99,    99,   100,   101,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   114,   114,   115,   116,
     117,   120,   121,   122,   123,   124,   125,   128,   129,   130,
     131,   132,   133,   136,   145,   146,   147,   148,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   163,   164,
     169,   170,   173,   181,   193,   201,   207,   208,   211,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   226,
     227,   228,   229,   240,   243,   245,   247,   251,   252,   253,
     256,   257,   258,   261,   264,   267,   268,   271,   272,   275,
     276,   281,   284,   294,   305,   310,   322,   326,   327,   327,
     327,   332,   332,   337,   342,   352,   353,   358,   363,   368,
     371,   371,   374,   381,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   395,   403,   404,   407,   410,   413,   416,
     419,   422,   425,   428,   431,   436,   439,   442,   445,   448,
     451,   456,   461,   462,   463,   466,   469,   472,   475,   476,
     479,   482,   487,   490,   491,   494,   508,   508,   510,   511,
     516,   520,   521,   520,   533,   534,   533,   548,   557,   556
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
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-263)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-189)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
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
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
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
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -263,  -263,   272,  -263,  -263,  -263,   -45,  -263,  -263,   271,
    -263,  -263,  -263,  -263,   214,  -263,  -263,    21,   260,   112,
    -263,   -46,  -184,   -80,   149,  -263,  -185,  -263,    85,   -31,
      14,   108,  -263,   -20,  -263,  -263,    47,  -263,    73,    84,
       0,   157,   245,    38,  -263,   256,    83,   -72,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -262,   282,   147,
    -263,   391,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
      -6,  -263
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    17,    18,    19,    30,    85,    42,    84,   328,    98,
     164,   358,   213,   214,   147,    20,    21,    43,    44,    72,
      45,    46,   263,   149,   215,   150,   151,   152,   216,    47,
      48,   125,    49,    50,   251,   359,    51,   301,    52,    53,
      54,    55,    56,   128,   184,    57,    58,    80,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   325,    68,    88,
      89,   326,    78,    90,    29,    24,   333,   370,   297,   360,
     122,   254
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
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
};

static const yytype_int16 yycheck[] =
{
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
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    51,    86,    95,    96,    97,
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
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    96,    96,    96,    98,    99,    97,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
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
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     0,     6,
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
#line 74 "parsefile.y"
          {is_func_bool = true; current_pointer++;  curr_scopes[current_pointer]++;}
#line 1864 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 76 "parsefile.y"
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
#line 1879 "y.tab.c"
    break;

  case 9: /* startfn: START OPENCU $@1 body $@2 CLOSECU  */
#line 85 "parsefile.y"
                                      {is_func_bool = false;current_pointer--;
          }
#line 1886 "y.tab.c"
    break;

  case 19: /* body: %empty  */
#line 98 "parsefile.y"
       {}
#line 1892 "y.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 99 "parsefile.y"
                 { current_pointer++;  curr_scopes[current_pointer]++; }
#line 1898 "y.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 99 "parsefile.y"
                                                                                               {current_pointer--; }
#line 1904 "y.tab.c"
    break;

  case 34: /* loop_body: %empty  */
#line 113 "parsefile.y"
       {}
#line 1910 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 114 "parsefile.y"
                 { current_pointer++;  curr_scopes[current_pointer]++; }
#line 1916 "y.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 114 "parsefile.y"
                                                                                                     {current_pointer--; }
#line 1922 "y.tab.c"
    break;

  case 53: /* vectors: OPENSQ check_rhs_exp COMMA check_rhs_exp CLOSESQ  */
#line 136 "parsefile.y"
                                                           {
              if(((yyvsp[-3].object).type == 1 || (yyvsp[-3].object).type == 4 || (yyvsp[-3].object).type == 2) && ((yyvsp[-3].object).type == 1 || (yyvsp[-3].object).type == 4 || (yyvsp[-3].object).type == 2)){
                (yyval.object).type = 10;
              }
              else{
                cout << "Invalid vector in line " << yylineno << endl;
              }}
#line 1934 "y.tab.c"
    break;

  case 54: /* primi_datatype: INT  */
#line 145 "parsefile.y"
                    {insert_type((yyvsp[0].object).value);}
#line 1940 "y.tab.c"
    break;

  case 55: /* primi_datatype: DOUBLE  */
#line 146 "parsefile.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1946 "y.tab.c"
    break;

  case 56: /* primi_datatype: BOOL  */
#line 147 "parsefile.y"
                     {insert_type((yyvsp[0].object).value);}
#line 1952 "y.tab.c"
    break;

  case 57: /* primi_datatype: STRING  */
#line 148 "parsefile.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1958 "y.tab.c"
    break;

  case 58: /* non_pri_datatype: MASS  */
#line 151 "parsefile.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1964 "y.tab.c"
    break;

  case 59: /* non_pri_datatype: TIME  */
#line 152 "parsefile.y"
                       {insert_type((yyvsp[0].object).value);}
#line 1970 "y.tab.c"
    break;

  case 60: /* non_pri_datatype: POSITION  */
#line 153 "parsefile.y"
                           {insert_type((yyvsp[0].object).value);}
#line 1976 "y.tab.c"
    break;

  case 61: /* non_pri_datatype: VELOCITY  */
#line 154 "parsefile.y"
                           {insert_type((yyvsp[0].object).value);}
#line 1982 "y.tab.c"
    break;

  case 62: /* non_pri_datatype: ACC  */
#line 155 "parsefile.y"
                      {insert_type((yyvsp[0].object).value);}
#line 1988 "y.tab.c"
    break;

  case 63: /* non_pri_datatype: ENERGY  */
#line 156 "parsefile.y"
                         {insert_type((yyvsp[0].object).value);}
#line 1994 "y.tab.c"
    break;

  case 64: /* non_pri_datatype: THETA  */
#line 157 "parsefile.y"
                        {insert_type((yyvsp[0].object).value);}
#line 2000 "y.tab.c"
    break;

  case 65: /* non_pri_datatype: E  */
#line 158 "parsefile.y"
                          {insert_type((yyvsp[0].object).value);}
#line 2006 "y.tab.c"
    break;

  case 66: /* non_pri_datatype: DISTANCE  */
#line 159 "parsefile.y"
                           {insert_type((yyvsp[0].object).value);}
#line 2012 "y.tab.c"
    break;

  case 67: /* non_pri_datatype: MOMENTUM  */
#line 160 "parsefile.y"
                           {insert_type((yyvsp[0].object).value);}
#line 2018 "y.tab.c"
    break;

  case 72: /* dimensions: OPENSQ check_rhs_exp CLOSESQ  */
#line 173 "parsefile.y"
                                          {
              if((yyvsp[-1].object).type == 1){
                (yyval.object).type = 10;
              }
              else{
                cout << "Invalid dimension in line " << yylineno << endl;
              }
              }
#line 2031 "y.tab.c"
    break;

  case 73: /* dimensions: OPENSQ check_rhs_exp CLOSESQ dimensions  */
#line 181 "parsefile.y"
                                                    {
              if((yyvsp[-2].object).type == 1){
                (yyval.object).type = 10;
              }
              else{
                cout << "Invalid dimension in line " << yylineno << endl;
              }
           }
#line 2044 "y.tab.c"
    break;

  case 74: /* single_variable_for_exp_stmt: single_variable  */
#line 194 "parsefile.y"
                                {
                                  if(((yyval.object).type = undeclare_check((yyvsp[0].object).value,convert_scope_to_string())) == 0){
                                    cout << "From single_variable_for_exp_stmt Undeclared variable used " << (yyvsp[0].object).value << " at " << yylineno << endl;
                                  }
                                }
#line 2054 "y.tab.c"
    break;

  case 75: /* exp_stmt: single_variable_for_exp_stmt ASSGN check_rhs_exp DOT  */
#line 202 "parsefile.y"
          {if(!type_checking_assign((yyvsp[-3].object).type,(yyvsp[-1].object).type)){
            cout << "From exp_stmt Expression statement types not compatible " << (yyvsp[-3].object).type << ' ' << (yyvsp[-1].object).type << ' ' <<" at " << yylineno << endl;
          }}
#line 2062 "y.tab.c"
    break;

  case 78: /* anything_with_value: single_variable  */
#line 211 "parsefile.y"
                                      {if(((yyval.object).type = undeclare_check((yyvsp[0].object).value,convert_scope_to_string())) == 0){
    cout << "From anything_with_value Undeclared variable used " << (yyvsp[0].object).value << " at " << yylineno<< endl;
  }}
#line 2070 "y.tab.c"
    break;

  case 86: /* anything_with_value: vectors  */
#line 221 "parsefile.y"
                              {(yyval.object).type = 10;}
#line 2076 "y.tab.c"
    break;

  case 87: /* anything_with_value: UNINEG anything_with_value  */
#line 222 "parsefile.y"
                                                 {(yyval.object).type = 4;}
#line 2082 "y.tab.c"
    break;

  case 88: /* anything_with_value: call_stmt_without_dot ARROW pos  */
#line 223 "parsefile.y"
                                                      {if((yyvsp[-2].object).type != 5 && (yyvsp[-2].object).type != 6 && (yyvsp[-2].object).type != 7 && (yyvsp[-2].object).type != 8 && (yyvsp[-2].object).type != 9 && (yyvsp[-2].object).type != 10){
                      cout << "From anything with value call statement return is not a vector" << endl;
                    }}
#line 2090 "y.tab.c"
    break;

  case 92: /* anything_with_value: ID ARROW pos  */
#line 229 "parsefile.y"
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
#line 2106 "y.tab.c"
    break;

  case 93: /* anything_with_value: single_variable UNIOP  */
#line 240 "parsefile.y"
                                            {if(((yyval.object).type = undeclare_check((yyvsp[-1].object).value,convert_scope_to_string())) == 0){
                        cout << "From anything_with_value Undeclared variable used " << (yyvsp[-1].object).value << " at " << yylineno<< endl;
                      }}
#line 2114 "y.tab.c"
    break;

  case 94: /* anything_with_value: SIN OPENCC anything_with_value CLOSECC  */
#line 243 "parsefile.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2121 "y.tab.c"
    break;

  case 95: /* anything_with_value: COS OPENCC anything_with_value CLOSECC  */
#line 245 "parsefile.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2128 "y.tab.c"
    break;

  case 96: /* anything_with_value: TAN OPENCC anything_with_value CLOSECC  */
#line 247 "parsefile.y"
                                                             {(yyval.object).type = 2;
                    if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){cout << "Sin input is out of range" << endl;}}
#line 2135 "y.tab.c"
    break;

  case 100: /* rhs_term: openccs anything_with_value  */
#line 256 "parsefile.y"
                                       {(yyval.object).type = (yyvsp[0].object).type;}
#line 2141 "y.tab.c"
    break;

  case 101: /* rhs_term: openccs anything_with_value closeccs  */
#line 257 "parsefile.y"
                                                {(yyval.object).type = (yyvsp[-1].object).type;}
#line 2147 "y.tab.c"
    break;

  case 102: /* rhs_term: anything_with_value closeccs  */
#line 258 "parsefile.y"
                                        {(yyval.object).type = (yyvsp[-1].object).type;}
#line 2153 "y.tab.c"
    break;

  case 103: /* rhs_exp: rhs_term operations rhs_exp  */
#line 261 "parsefile.y"
                                      {cout << (yyvsp[-2].object).type << ' ' << (yyvsp[-1].object).value << ' '<< (yyvsp[0].object).type << endl;
(yyval.object).type = give_result_type((yyvsp[-2].object).type,(yyvsp[-1].object).value,(yyvsp[0].object).type); 
if((yyval.object).type == -1){cout << "From rhs_exp Invalid operation in rhs side " << (yyvsp[-2].object).type << " " << (yyvsp[-1].object).value << " "  << (yyvsp[0].object).type << " at " << yylineno << endl;}}
#line 2161 "y.tab.c"
    break;

  case 104: /* rhs_exp: anything_with_value operations rhs_exp  */
#line 264 "parsefile.y"
                                                 {cout << (yyvsp[-2].object).type << ' ' << (yyvsp[-1].object).value << ' '<< (yyvsp[0].object).type << endl; 
(yyval.object).type = give_result_type((yyvsp[-2].object).type,(yyvsp[-1].object).value,(yyvsp[0].object).type); 
if((yyval.object).type == -1){cout << "From rhs_exp Invalid operation in rhs side " << (yyvsp[-2].object).type << " " << (yyvsp[-1].object).value << " " << (yyvsp[0].object).type << " at " << yylineno  << endl;}}
#line 2169 "y.tab.c"
    break;

  case 107: /* openccs: openccs OPENCC  */
#line 271 "parsefile.y"
                         {open_brackets = open_brackets + 1;}
#line 2175 "y.tab.c"
    break;

  case 108: /* openccs: OPENCC  */
#line 272 "parsefile.y"
                 {open_brackets = open_brackets + 1;}
#line 2181 "y.tab.c"
    break;

  case 109: /* closeccs: closeccs CLOSECC  */
#line 275 "parsefile.y"
                            {close_brackets = close_brackets + 1;}
#line 2187 "y.tab.c"
    break;

  case 110: /* closeccs: CLOSECC  */
#line 276 "parsefile.y"
                   {close_brackets = close_brackets + 1;}
#line 2193 "y.tab.c"
    break;

  case 112: /* call_stmt_without_dot: ID OPENCU CLOSECU  */
#line 285 "parsefile.y"
                      {
                        char* templist[100];
                        int temp = 0;
                        if(!check_func_args((yyvsp[-2].object).value,templist,temp )){
                          cout << "From call_stmt_without_dot Undeclared function " << (yyvsp[-2].object).value <<" at " << yylineno  << endl;
                        }
                        func_args_list.clear();
                        (yyval.object).type = find_return_type((yyvsp[-2].object).value,templist,temp);
                      }
#line 2207 "y.tab.c"
    break;

  case 113: /* call_stmt_without_dot: ID OPENCU funccallargs CLOSECU  */
#line 295 "parsefile.y"
                      {
                          if(!check_func_args((yyvsp[-3].object).value, (yyvsp[-1].arg_object).list,(yyvsp[-1].arg_object).present)){
                            cout << "From call_stmt_without_dot Undeclared function " << (yyvsp[-3].object).value <<" at " << yylineno  << endl;
                          }
                          func_args_list.clear();
                          (yyval.object).type = find_return_type((yyvsp[-3].object).value,(yyvsp[-1].arg_object).list,(yyvsp[-1].arg_object).present);
                      }
#line 2219 "y.tab.c"
    break;

  case 114: /* funccallargs: check_rhs_exp  */
#line 306 "parsefile.y"
                {
                  (yyval.arg_object).list[0] = &(get_string_type((yyvsp[0].object).type)[0]);
                  (yyval.arg_object).present = 1;
                }
#line 2228 "y.tab.c"
    break;

  case 115: /* funccallargs: check_rhs_exp COMMA funccallargs  */
#line 311 "parsefile.y"
              {
                for(int i=0;i<(yyvsp[0].arg_object).present;i++){
                  (yyval.arg_object).list[i+1] = (yyvsp[0].arg_object).list[i];
                }
                (yyval.arg_object).present = (yyvsp[0].arg_object).present + 1;
                (yyval.arg_object).list[0] = &(get_string_type((yyvsp[-2].object).type)[0]);
              }
#line 2240 "y.tab.c"
    break;

  case 116: /* conditional_stmt_start: OPENSQ check_rhs_exp CLOSESQ OPENCU  */
#line 322 "parsefile.y"
                                                             { current_pointer++;  curr_scopes[current_pointer]++; }
#line 2246 "y.tab.c"
    break;

  case 117: /* conditional_stmt: conditional_stmt_start loop_body CLOSECU  */
#line 326 "parsefile.y"
                                                           {current_pointer--; }
#line 2252 "y.tab.c"
    break;

  case 118: /* $@7: %empty  */
#line 327 "parsefile.y"
                                                           {current_pointer--; }
#line 2258 "y.tab.c"
    break;

  case 119: /* $@8: %empty  */
#line 327 "parsefile.y"
                                                                                                  { current_pointer++;  curr_scopes[current_pointer]++; }
#line 2264 "y.tab.c"
    break;

  case 120: /* conditional_stmt: conditional_stmt_start loop_body CLOSECU $@7 OTHERWISE OPENCU $@8 loop_body CLOSECU  */
#line 327 "parsefile.y"
                                                                                                                                                                             {current_pointer--; }
#line 2270 "y.tab.c"
    break;

  case 121: /* $@9: %empty  */
#line 332 "parsefile.y"
                                                    { current_pointer++;  curr_scopes[current_pointer]++; }
#line 2276 "y.tab.c"
    break;

  case 122: /* loop_stmt: LOOP OPENSQ check_rhs_exp CLOSESQ OPENCU $@9 loop_body CLOSECU  */
#line 332 "parsefile.y"
                                                                                                                              {current_pointer--; }
#line 2282 "y.tab.c"
    break;

  case 123: /* unary_operation_without_dot: single_variable UNIOP  */
#line 337 "parsefile.y"
                                                   {if (((yyval.object).type = undeclare_check((yyvsp[-1].object).value,convert_scope_to_string())) == 0) cout << "undeclaration error at " << yylineno << (yyvsp[-1].object).value << endl;
                              if((yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
                                cout << "From unary_operation_without_dot cant perform operation" << endl;
                              }
                              (yyval.object).type = (yyvsp[-1].object).type;}
#line 2292 "y.tab.c"
    break;

  case 124: /* unary_operation_without_dot: UNINEG check_rhs_exp  */
#line 342 "parsefile.y"
                                                  {
                            (yyval.object).type = 4;
                            if ((yyvsp[0].object).type != 1 && (yyvsp[0].object).type !=2 && (yyvsp[0].object).type != 4){
                              cout << "From unary_operation_without_dot invalid negation operation" << endl;
                            }
                           }
#line 2303 "y.tab.c"
    break;

  case 130: /* $@10: %empty  */
#line 371 "parsefile.y"
                      {if(undeclare_check((yyvsp[0].object).value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        }}
#line 2311 "y.tab.c"
    break;

  case 132: /* ids: single_variable  */
#line 374 "parsefile.y"
                      {if(undeclare_check((yyvsp[0].object).value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        }}
#line 2319 "y.tab.c"
    break;

  case 143: /* stand_id: ID  */
#line 395 "parsefile.y"
              {if(((yyval.object).type = undeclare_check((yyvsp[0].object).value,convert_scope_to_string())) == 0){
                          cout << "From stand_id Undeclared variable used at " << yylineno << (yyvsp[0].object).value << endl;
                        };
                if((yyval.object).type != 11){
                  cout << "From stand_id indentifier is of not mass datatype at " << yylineno << endl; 
                }
              }
#line 2331 "y.tab.c"
    break;

  case 144: /* rel_to_mag: MAG OPENCU stand_id CLOSECU  */
#line 403 "parsefile.y"
                                         {(yyval.object).type = 2;}
#line 2337 "y.tab.c"
    break;

  case 145: /* rel_to_mag: MAG OPENCU vectors CLOSECU  */
#line 404 "parsefile.y"
                                        {(yyval.object).type = 2;}
#line 2343 "y.tab.c"
    break;

  case 146: /* rel_to_pos: OPENCU stand_id CLOSECU SETR OPENCU check_rhs_exp CLOSECU  */
#line 407 "parsefile.y"
                                                                       {if((yyvsp[-1].object).type != 6 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2351 "y.tab.c"
    break;

  case 147: /* rel_to_pos: OPENCU stand_id CLOSECU ADDR OPENCU check_rhs_exp CLOSECU  */
#line 410 "parsefile.y"
                                                                       {if((yyvsp[-1].object).type != 6 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2359 "y.tab.c"
    break;

  case 148: /* rel_to_pos: OPENCU stand_id CLOSECU R_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 413 "parsefile.y"
                                                                          {(yyval.object).type = 6; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_pos invalid statement" << endl;
}}
#line 2367 "y.tab.c"
    break;

  case 149: /* rel_to_pos: OPENCU stand_id CLOSECU GETR  */
#line 416 "parsefile.y"
                                          {(yyval.object).type = 6;}
#line 2373 "y.tab.c"
    break;

  case 150: /* rel_to_vel: OPENCU stand_id CLOSECU SETV OPENCU check_rhs_exp CLOSECU  */
#line 419 "parsefile.y"
                                                                       {if((yyvsp[-1].object).type != 5 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2381 "y.tab.c"
    break;

  case 151: /* rel_to_vel: OPENCU stand_id CLOSECU ADDV OPENCU check_rhs_exp CLOSECU  */
#line 422 "parsefile.y"
                                                                       {if((yyvsp[-1].object).type != 5 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2389 "y.tab.c"
    break;

  case 152: /* rel_to_vel: OPENCU stand_id CLOSECU V_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 425 "parsefile.y"
                                                                          {(yyval.object).type = 5; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_vel invalid statement" << endl;
}}
#line 2397 "y.tab.c"
    break;

  case 153: /* rel_to_vel: OPENCU stand_id CLOSECU GETV  */
#line 428 "parsefile.y"
                                          {(yyval.object).type = 5;}
#line 2403 "y.tab.c"
    break;

  case 154: /* rel_to_momentum: OPENCU stand_id CLOSECU SETP OPENCU check_rhs_exp CLOSECU  */
#line 431 "parsefile.y"
                                                                            {if((yyvsp[-1].object).type != 9 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_momentum invalid statement" << endl;
}}
#line 2411 "y.tab.c"
    break;

  case 155: /* rel_to_acc: OPENCU stand_id CLOSECU SETA OPENCU check_rhs_exp CLOSECU  */
#line 436 "parsefile.y"
                                                                       {if((yyvsp[-1].object).type != 7 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_acc invalid statement" << endl;
}}
#line 2419 "y.tab.c"
    break;

  case 156: /* rel_to_acc: OPENCU stand_id CLOSECU ADDA OPENCU check_rhs_exp CLOSECU  */
#line 439 "parsefile.y"
                                                                       {if((yyvsp[-1].object).type != 7 && (yyvsp[-1].object).type != 10){
  cout << "From rel_to_acc invalid statement" << endl;
}}
#line 2427 "y.tab.c"
    break;

  case 157: /* rel_to_acc: OPENCU stand_id CLOSECU GETA  */
#line 442 "parsefile.y"
                                          {(yyval.object).type = 7;}
#line 2433 "y.tab.c"
    break;

  case 158: /* rel_to_energy: OPENCU stand_id CLOSECU KE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 445 "parsefile.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2441 "y.tab.c"
    break;

  case 159: /* rel_to_energy: OPENCU stand_id CLOSECU PE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 448 "parsefile.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2449 "y.tab.c"
    break;

  case 160: /* rel_to_energy: OPENCU stand_id CLOSECU TE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 451 "parsefile.y"
                                                                             {(yyval.object).type = 13 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_energy invalid statement" << endl;
}}
#line 2457 "y.tab.c"
    break;

  case 161: /* rel_to_angle: OPENCU stand_id CLOSECU ANGLE_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 456 "parsefile.y"
                                                                               {(yyval.object).type = 14 ;if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From rel_to_angle invalid statement" << endl;
}}
#line 2465 "y.tab.c"
    break;

  case 162: /* rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id COMMA ID CLOSECU  */
#line 461 "parsefile.y"
                                                                                   {(yyval.object).type = 13;}
#line 2471 "y.tab.c"
    break;

  case 163: /* rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id CLOSECU  */
#line 462 "parsefile.y"
                                                                          {(yyval.object).type = 13;}
#line 2477 "y.tab.c"
    break;

  case 164: /* rel_to_collision: OPENCU stand_id CLOSECU TIME_TO_COLLIDE OPENCU stand_id CLOSECU  */
#line 463 "parsefile.y"
                                                                                  {(yyval.object).type = 12 ;}
#line 2483 "y.tab.c"
    break;

  case 165: /* miscellaneous: OPENCU stand_id CLOSECU S_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 466 "parsefile.y"
                                                                            {(yyval.object).type = 8; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2491 "y.tab.c"
    break;

  case 166: /* miscellaneous: OPENCU stand_id CLOSECU ROC_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 469 "parsefile.y"
                                                                              {(yyval.object).type = 2; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2499 "y.tab.c"
    break;

  case 167: /* miscellaneous: OPENCU stand_id CLOSECU P_AFTER OPENCU check_rhs_exp CLOSECU  */
#line 472 "parsefile.y"
                                                                            {(yyval.object).type = 9; if((yyvsp[-1].object).type != 12 && (yyvsp[-1].object).type != 1 && (yyvsp[-1].object).type != 2){
  cout << "From miscellaneous invalid statement" << endl;
}}
#line 2507 "y.tab.c"
    break;

  case 168: /* miscellaneous: OPENCU stand_id CLOSECU TIME_TO_R OPENCU term_misc COMMA term_misc CLOSECU  */
#line 475 "parsefile.y"
                                                                                          {(yyval.object).type = 12;}
#line 2513 "y.tab.c"
    break;

  case 169: /* miscellaneous: OPENCU stand_id CLOSECU TIME_TO_V OPENCU term_misc COMMA term_misc CLOSECU  */
#line 476 "parsefile.y"
                                                                                          {(yyval.object).type = 12;}
#line 2519 "y.tab.c"
    break;

  case 170: /* term_misc: check_rhs_exp  */
#line 479 "parsefile.y"
                          {if((yyvsp[0].object).type != 1 && (yyvsp[0].object).type != 2){
  cout << "From term_misc invalid statement" << endl;
}}
#line 2527 "y.tab.c"
    break;

  case 175: /* single_variable_declare: single_variable  */
#line 494 "parsefile.y"
                                          {
                          (yyval.object).type = give_type_index(type);
                          if(is_func_bool){
                          var_records* rec = new var_records;
													rec->name = (yyvsp[0].object).value;
													rec->type = type;
													rec->scope = convert_scope_to_string();
                          fn_var_entry(rec);
                          }
                        else{
                          add('V',(yyvsp[0].object).value,type);
                        }
}
#line 2545 "y.tab.c"
    break;

  case 176: /* $@11: %empty  */
#line 508 "parsefile.y"
                {open_brackets = 0;close_brackets = 0;}
#line 2551 "y.tab.c"
    break;

  case 177: /* check_rhs_exp: $@11 rhs_exp  */
#line 508 "parsefile.y"
                                                                {if(open_brackets != close_brackets){cout << "Incorrect RHS expression at " << yylineno << endl;}open_brackets = 0;close_brackets = 0;(yyval.object).type = (yyvsp[0].object).type;(yyval.object).value = (yyvsp[0].object).value;}
#line 2557 "y.tab.c"
    break;

  case 178: /* expression: single_variable_declare ASSGN check_rhs_exp  */
#line 510 "parsefile.y"
                                                         { if(!type_checking_assign((yyvsp[-2].object).type,(yyvsp[0].object).type)){cout << "Declaration with expression type error " <<  (yyvsp[-2].object).type <<  ' ' << (yyvsp[0].object).type << " at " << yylineno << endl;}}
#line 2563 "y.tab.c"
    break;

  case 180: /* idadd2: ID  */
#line 516 "parsefile.y"
            {is_func_bool = true;
        if(!func_red_var((yyvsp[0].object).value)){cout << "Redeclaration error : Function is redeclared as variable nameat " << yylineno << endl;}}
#line 2570 "y.tab.c"
    break;

  case 181: /* $@12: %empty  */
#line 520 "parsefile.y"
                                                                             {current_pointer++;  curr_scopes[current_pointer]++; }
#line 2576 "y.tab.c"
    break;

  case 182: /* $@13: %empty  */
#line 521 "parsefile.y"
                {   
                  if (valid_func_entry((yyvsp[-8].object).value , par_list)){
                    new_func_entry( (yyvsp[-8].object).value, (yyvsp[-9].object).value, par_list.size(), par_list, var_list);
                    add('F',(yyvsp[-8].object).value,(yyvsp[-9].object).value);
                  }
                  else{
                     cout<< "Function re-def, ERROR!at " << yylineno<<endl;
                  }
                  var_list.clear(); 
                  par_list.clear();
                }
#line 2592 "y.tab.c"
    break;

  case 183: /* function_decl: datatypes idadd2 ASSGN OPENCU parameters CLOSECU DARR OPENCU $@12 body $@13 CLOSECU  */
#line 532 "parsefile.y"
                        {is_func_bool = false;current_pointer--; }
#line 2598 "y.tab.c"
    break;

  case 184: /* $@14: %empty  */
#line 533 "parsefile.y"
                                                                  {current_pointer++;  curr_scopes[current_pointer]++;}
#line 2604 "y.tab.c"
    break;

  case 185: /* $@15: %empty  */
#line 534 "parsefile.y"
                {
                    if (valid_func_entry((yyvsp[-7].object).value , par_list)){
                      new_func_entry( (yyvsp[-7].object).value, (yyvsp[-8].object).value, par_list.size(), par_list, var_list);
                      add('F',(yyvsp[-7].object).value,(yyvsp[-8].object).value);
                    }
                    else{
                      cout<< "Function re-def, ERROR!at " << yylineno<<endl;
                  }
                    var_list.clear(); 
                    par_list.clear();
                }
#line 2620 "y.tab.c"
    break;

  case 186: /* function_decl: datatypes idadd2 ASSGN OPENCU CLOSECU DARR OPENCU $@14 body $@15 CLOSECU  */
#line 545 "parsefile.y"
                        {is_func_bool = false;current_pointer--; }
#line 2626 "y.tab.c"
    break;

  case 187: /* parameters: datatypes ID  */
#line 549 "parsefile.y"
        {
          if(!within_func_parameters_redeclaration((yyvsp[0].object).value)) cout << "Redeclaration of parameters in the functionat " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = (yyvsp[0].object).value;
						rec->type = type;
            par_list.push_back(rec);
        }
#line 2638 "y.tab.c"
    break;

  case 188: /* $@16: %empty  */
#line 557 "parsefile.y"
          {
          if(!within_func_parameters_redeclaration((yyvsp[0].object).value)) cout << "Redeclaration of parameters in the functionat " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = (yyvsp[0].object).value;
						rec->type = type;
            par_list.push_back(rec);
          }
#line 2650 "y.tab.c"
    break;


#line 2654 "y.tab.c"

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

#line 569 "parsefile.y"


void yyerror(char* s){
	printf("Syntax Error : In line number %d\n",yylineno);
	fprintf(parsefile," %s\n",s);
}

int main(int argc ,char * argv[]){
    char inp_file[100],tok[100],parse[100];

    sprintf(inp_file,"inp.phic");

    yyin = fopen(inp_file,"r");

  construct_stack();
	int i = yyparse();

    print_table();
    print_function_table();

	if(i) printf("Failure\n");
	else printf("Success\n");

	return 0;
}
