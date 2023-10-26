%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
extern FILE *yyin, *tokfile, *parsefile;
extern int yylineno;
int yylex();
void yyerror();
%}

/* %union {
    int val;
    char* sval;
} */

%token INTEGER_CONSTANT
%token STRING_CONSTANT
%token FLOAT_CONSTANT
%token ID 
%token PRIMI_DATATYPE
%token NON_PRI_DATATYPE
%token INPUT
%token OUTPUT
%token TRUE
%token FALSE
%token SETR
%token ADDR
%token SETV
%token ADDV
%token SETA
%token ADDA
%token KE_AFTER
%token PE_AFTER
%token TE_AFTER
%token ANGLE_AFTER
%token GET_TRAJ
%token COLLIDE
%token TIME_TO_COLLIDE
%token ROC_AFTER
%token P_AFTER
%token S_AFTER
%token TIME_TO
%token LOOP
%token BREAK
%token START
%token SIN 
%token COS 
%token TAN 
%token MAG
%token SETP
%token V_AFTER
%token OPENCC
%token CLOSECC
%token OPENSQ
%token CLOSESQ
%token OPENCU
%token CLOSECU
%token DOLLAR
%token DOT
%token PUNCTUATION
%token ARROW
%token BIOP
%token RELOP
%token LOGICOP
%token UNIOP
%token ASSGN
%token DARR
%token LINE
%token SLASHN


%start program
%%

program:
	| cmt_stmt
	;

cmt_body: cmt_body LINE
    | LINE
    ;

cmt_stmt: DOLLAR LINE SLASHN
    | DOLLAR cmt_body DOLLAR
    ;

/* print_statement
    : OUTPUT COLON STRING_CONSTANT 

loops 
    : 

conditional_statement
    : 
    ;
    ; */
%%

int main(int argc ,char * argv[]){

	// yyin = fopen(strcat(argv[1],".clike"),"r");
    
	yyin = fopen("inp.txt","r");
	tokfile = fopen("pt_seq_tokens_1.txt","w");
	parsefile = fopen("pt_parser_1.parsed","w");

	fprintf(tokfile,"Name: Pericherla Pranav Varma\n");
    fprintf(tokfile,"ID: CS21BTECH11044\n");

	int i = yyparse();

	if(i) printf("Failure\n");
	else printf("Success\n");

	return 0;
}