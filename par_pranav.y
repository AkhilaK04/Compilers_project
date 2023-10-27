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
%token INTEGER_CONSTANT STRING_CONSTANT FLOAT_CONSTANT TRUE FALSE
%token INT DOUBLE STRING  BOOL
%token MASS TIME POSITION VELOCITY ACC ENERGY THETA E DISTANCE MOMENTUM
%token ID 
%token INPUT OUTPUT
%token SETR ADDR SETV ADDV SETA ADDA SETP
%token KE_AFTER PE_AFTER TE_AFTER ANGLE_AFTER V_AFTER
%token GET_TRAJ COLLIDE TIME_TO_COLLIDE ROC_AFTER
%token P_AFTER S_AFTER TIME_TO
%token LOOP
%token BREAK
%token START
%token SIN COS TAN
%token MAG
%token OPENCC CLOSECC OPENSQ CLOSESQ OPENCU CLOSECU
%token DOLLAR
%token DOT
%token DOUBLE_QUOTE SINGLE_QUOTE
%token COMMA
%token COLON
%token ARROW
%token ADD SUB MUL DIV MOD EXP
%token EQ NEQ GEQ LEQ GT LT EQL
%token LOGICOP UNIOP UNINEG
%token ASSGN
%token DARR
%token MCMT SCMT

%start programStart
%%

/* programStart: startfn
	; */

/* startfn: START OPENCU CLOSECU
    ; */

/* program:
	| SCMT
    | MCMT
	; */

program:
    | std_lib
    ;

std_lib: rel_to_mag
    | rel_to_pos
    ;

rel_to_mag: MAG OPENCC ID CLOSECC
    | MAG OPENCC vectors CLOSECC
    ;

rel_to_pos: OPENCC ID CLOSECC SETR OPENCC ID CLOSECC
    | OPENCC ID CLOSECC ADDR OPENCC ID CLOSECC
    | OPENCC ID CLOSECC R_AFTER OPENCC ID CLOSECC
    ;

vectors: OPENCC constant COMMA constant CLOSECC
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

void yyerror(char* s){
	{fprintf(parsefile,"\ninvalid statement");}
}

int main(int argc ,char * argv[]){

	// yyin = fopen(strcat(argv[1],".clike"),"r");
    
	yyin = fopen("inp_pranav.txt","r");
	tokfile = fopen("pt_seq_tokens_1.txt","w");
	parsefile = fopen("pt_parser_1.parsed","w");

	fprintf(tokfile,"Name: Pericherla Pranav Varma\n");
    fprintf(tokfile,"ID: CS21BTECH11044\n");

	int i = yyparse();

	if(i) printf("Failure\n");
	else printf("Success\n");

	return 0;
}