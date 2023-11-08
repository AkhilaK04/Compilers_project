#ifndef YY_parse_h_included
#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 11 "new.y"
typedef union {
  char * string;
} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype
#ifndef YY_USE_CLASS
#define YYSTYPE yy_parse_stype
#endif

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	INTEGER_CONSTANT	258
#define	STRING_CONSTANT	259
#define	FLOAT_CONSTANT	260
#define	TRUE	261
#define	FALSE	262
#define	INT	263
#define	DOUBLE	264
#define	STRING	265
#define	BOOL	266
#define	MASS	267
#define	TIME	268
#define	POSITION	269
#define	VELOCITY	270
#define	ACC	271
#define	ENERGY	272
#define	THETA	273
#define	E	274
#define	DISTANCE	275
#define	MOMENTUM	276
#define	ID	277
#define	INPUT	278
#define	OUTPUT	279
#define	SETR	280
#define	ADDR	281
#define	SETV	282
#define	ADDV	283
#define	SETA	284
#define	ADDA	285
#define	SETP	286
#define	GETR	287
#define	GETA	288
#define	GETV	289
#define	KE_AFTER	290
#define	PE_AFTER	291
#define	TE_AFTER	292
#define	ANGLE_AFTER	293
#define	V_AFTER	294
#define	R_AFTER	295
#define	GET_TRAJ	296
#define	COLLIDE	297
#define	TIME_TO_COLLIDE	298
#define	ROC_AFTER	299
#define	P_AFTER	300
#define	S_AFTER	301
#define	TIME_TO_R	302
#define	TIME_TO_V	303
#define	LOOP	304
#define	BREAK	305
#define	START	306
#define	SIN	307
#define	COS	308
#define	TAN	309
#define	MAG	310
#define	OPENCC	311
#define	CLOSECC	312
#define	OPENSQ	313
#define	CLOSESQ	314
#define	OPENCU	315
#define	CLOSECU	316
#define	DOLLAR	317
#define	DOT	318
#define	DOUBLE_QUOTE	319
#define	SINGLE_QUOTE	320
#define	COMMA	321
#define	COLON	322
#define	ARROW	323
#define	ADD	324
#define	SUB	325
#define	MUL	326
#define	DIV	327
#define	MOD	328
#define	EXP	329
#define	EQ	330
#define	NEQ	331
#define	GEQ	332
#define	LEQ	333
#define	GT	334
#define	LT	335
#define	LOGICOP	336
#define	UNIOP	337
#define	UNINEG	338
#define	ASSGN	339
#define	DARR	340
#define	CMT	341
#define	QUESTION	342
#define	NON_NEGATIVE_INT	343
#define	FIRST	344
#define	SECOND	345
#define	OTHERWISE	346
#define	SCOPEOPEN	347
#define	SCOPECLOSE	348


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int INTEGER_CONSTANT;
static const int STRING_CONSTANT;
static const int FLOAT_CONSTANT;
static const int TRUE;
static const int FALSE;
static const int INT;
static const int DOUBLE;
static const int STRING;
static const int BOOL;
static const int MASS;
static const int TIME;
static const int POSITION;
static const int VELOCITY;
static const int ACC;
static const int ENERGY;
static const int THETA;
static const int E;
static const int DISTANCE;
static const int MOMENTUM;
static const int ID;
static const int INPUT;
static const int OUTPUT;
static const int SETR;
static const int ADDR;
static const int SETV;
static const int ADDV;
static const int SETA;
static const int ADDA;
static const int SETP;
static const int GETR;
static const int GETA;
static const int GETV;
static const int KE_AFTER;
static const int PE_AFTER;
static const int TE_AFTER;
static const int ANGLE_AFTER;
static const int V_AFTER;
static const int R_AFTER;
static const int GET_TRAJ;
static const int COLLIDE;
static const int TIME_TO_COLLIDE;
static const int ROC_AFTER;
static const int P_AFTER;
static const int S_AFTER;
static const int TIME_TO_R;
static const int TIME_TO_V;
static const int LOOP;
static const int BREAK;
static const int START;
static const int SIN;
static const int COS;
static const int TAN;
static const int MAG;
static const int OPENCC;
static const int CLOSECC;
static const int OPENSQ;
static const int CLOSESQ;
static const int OPENCU;
static const int CLOSECU;
static const int DOLLAR;
static const int DOT;
static const int DOUBLE_QUOTE;
static const int SINGLE_QUOTE;
static const int COMMA;
static const int COLON;
static const int ARROW;
static const int ADD;
static const int SUB;
static const int MUL;
static const int DIV;
static const int MOD;
static const int EXP;
static const int EQ;
static const int NEQ;
static const int GEQ;
static const int LEQ;
static const int GT;
static const int LT;
static const int LOGICOP;
static const int UNIOP;
static const int UNINEG;
static const int ASSGN;
static const int DARR;
static const int CMT;
static const int QUESTION;
static const int NON_NEGATIVE_INT;
static const int FIRST;
static const int SECOND;
static const int OTHERWISE;
static const int SCOPEOPEN;
static const int SCOPECLOSE;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,INTEGER_CONSTANT=258
	,STRING_CONSTANT=259
	,FLOAT_CONSTANT=260
	,TRUE=261
	,FALSE=262
	,INT=263
	,DOUBLE=264
	,STRING=265
	,BOOL=266
	,MASS=267
	,TIME=268
	,POSITION=269
	,VELOCITY=270
	,ACC=271
	,ENERGY=272
	,THETA=273
	,E=274
	,DISTANCE=275
	,MOMENTUM=276
	,ID=277
	,INPUT=278
	,OUTPUT=279
	,SETR=280
	,ADDR=281
	,SETV=282
	,ADDV=283
	,SETA=284
	,ADDA=285
	,SETP=286
	,GETR=287
	,GETA=288
	,GETV=289
	,KE_AFTER=290
	,PE_AFTER=291
	,TE_AFTER=292
	,ANGLE_AFTER=293
	,V_AFTER=294
	,R_AFTER=295
	,GET_TRAJ=296
	,COLLIDE=297
	,TIME_TO_COLLIDE=298
	,ROC_AFTER=299
	,P_AFTER=300
	,S_AFTER=301
	,TIME_TO_R=302
	,TIME_TO_V=303
	,LOOP=304
	,BREAK=305
	,START=306
	,SIN=307
	,COS=308
	,TAN=309
	,MAG=310
	,OPENCC=311
	,CLOSECC=312
	,OPENSQ=313
	,CLOSESQ=314
	,OPENCU=315
	,CLOSECU=316
	,DOLLAR=317
	,DOT=318
	,DOUBLE_QUOTE=319
	,SINGLE_QUOTE=320
	,COMMA=321
	,COLON=322
	,ARROW=323
	,ADD=324
	,SUB=325
	,MUL=326
	,DIV=327
	,MOD=328
	,EXP=329
	,EQ=330
	,NEQ=331
	,GEQ=332
	,LEQ=333
	,GT=334
	,LT=335
	,LOGICOP=336
	,UNIOP=337
	,UNINEG=338
	,ASSGN=339
	,DARR=340
	,CMT=341
	,QUESTION=342
	,NON_NEGATIVE_INT=343
	,FIRST=344
	,SECOND=345
	,OTHERWISE=346
	,SCOPEOPEN=347
	,SCOPECLOSE=348


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
