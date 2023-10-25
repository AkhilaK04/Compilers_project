%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
extern FILE *yyin, *tokfile, *parsefile;
extern int yylineno;
int yylex();
void yyerror();
%}

%union {
    int val;
    char* sval;
}

%token <sval> INTEGER_CONSTANT
%token <sval> STRING_CONSTANT
%token <sval> FLOAT_CONSTANT
%token <sval> ID 
%token <sval> PRIMI_DATATYPE
%token <sval> NON_PRI_DATATYPE
%token <sval> INPUT
%token <sval> OUTPUT
%token <sval> TRUE
%token <sval> FALSE
%token <sval> SETR
%token <sval> ADDR
%token <sval> SETV
%token <sval> ADDV
%token <sval> SETA
%token <sval> ADDA
%token <sval> KE_AFTER
%token <sval> PE_AFTER
%token <sval> TE_AFTER
%token <sval> ANGLE_AFTER
%token <sval> GET_TRAJ
%token <sval> COLLIDE
%token <sval> TIME_TO_COLLIDE
%token <sval> ROC_AFTER
%token <sval> P_AFTER
%token <sval> S_AFTER
%token <sval> TIME_TO
%token <sval> LOOP
%token <sval> BREAK
%token <sval> START
%token <sval> SIN 
%token <sval> COS 
%token <sval> TAN 
%token <sval> MAG
%token <sval> SETP
%token <sval> V_AFTER
%token <sval> OPENCC
%token <sval> CLOSECC
%token <sval> OPENSQ
%token <sval> CLOSESQ
%token <sval> OPENCU
%token <sval> CLOSECU
%token <sval> DOLLAR
%token <sval> DOT
%token <sval> PUNCTUATION
%token <sval> ARROW
%token <sval> BIOP
%token <sval> RELOP
%token <sval> LOGICOP
%token <sval> UNIOP
%token <sval> ASSGN
%token <sval> DARR


%start program

program 
    : START { }
    ;

print_statement
    : OUTPUT COLON STRING_CONSTANT 

loops 
    : 

conditional_statement
    : 