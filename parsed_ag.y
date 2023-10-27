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
%token KE_AFTER PE_AFTER TE_AFTER ANGLE_AFTER V_AFTER R_AFTER
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

%start program
%%


programStart:
	| comments
    | program startfn
	;

startfn: START OPENCU body CLOSECU
    ;

program:
    | comments
    | program function_decl
    ;

BI_OP : ADD
      | SUB
      | MUL
      | DIV
      | MOD
      | EXP
      ;

RELOP: EQ
     | NEQ
     | GEQ
     | GT
     | LEQ
     | LT
     ;

PRIMI_DATATYPE: INT
              | DOUBLE
              | BOOL
              | STRING
              ;
            
NON_PRI_DATATYPE: MASS
                | TIME
                | POSITION
                | VELOCITY
                | ACC
                | ENERGY
                | THETA
                | E      
                | DISTANCE
                | MOMENTUM
                ;
            
DATATYPE: PRIMI_DATATYPE
        | NON_PRI_DATATYPE
        ; 

comments: SCMT
    | MCMT
    ;

ids: ID
   | ID COMMA ids
   ;

operand: ID
	| INTEGER_CONSTANT
	| STRING_CONSTANT
    | FLOAT_CONSTANT
    | TRUE
    | FALSE
	;

funccallargs: operand
	| operand COMMA funccallargs
	;

funccall: ID OPENCC CLOSECC
	| ID OPENCC funccallargs CLOSECC
	;

call_stmt_without_dot: funccall
    ;

call_stmt_with_dot: call_stmt_without_dot DOT
    ;

constant: INTEGER_CONSTANT
        | STRING_CONSTANT
        | FLOAT_CONSTANT
        ;
constant_for_bo: INTEGER_CONSTANT
               | FLOAT_CONSTANT
               ;

input_stmt: INPUT COLON ids DOT
          ;

STR: DOUBLE_QUOTE STRING_CONSTANT DOUBLE_QUOTE 
   | ID
   | call_stmt_without_dot
   ;

for_out: STR
       | STR ADD for_out
       ;

output_stmt: OUTPUT COLON for_out DOT
           ;

unary_operation_without_dot: ID UNIOP
                           | UNINEG ID
                           ;

binary_operands: ID
               | constant_for_bo
               /* | binary_operation */
               | call_stmt_without_dot
               ;

binary_operation: OPENCC binary_operation CLOSECC 
                | binary_operands BI_OP binary_operands
                ;

vectors: OPENCC constant COMMA constant CLOSECC
       ;

rhs_exp: constant
       | ID
       | TRUE
       | FALSE
       | call_stmt_without_dot
       | unary_operation_without_dot
       | binary_operation
       | vectors
       ;

exp_stmt: ID ASSGN rhs_exp DOT
        ;

body:    decl_stmt body
         | exp_stmt body
         | call_stmt_with_dot body
         | conditional_stmt body
         | loop_stmt body
         | unary_operation_without_dot DOT body
         | return_stmt body
         | comments body
         | output_stmt body
         | input_stmt body
         | {}
         ;

break_body: decl_stmt break_body
         | exp_stmt break_body
         | call_stmt_with_dot break_body
         | conditional_stmt break_body
         | loop_stmt break_body
         | BREAK DOT break_body
         | unary_operation_without_dot DOT break_body
         | return_stmt break_body
         | comments break_body
         | output_stmt break_body
         | input_stmt break_body
         | {}
         ;

loop_body: decl_stmt loop_body
         | exp_stmt loop_body
         | call_stmt_with_dot loop_body
         /* | conditional_stmt loop_body */
         | loop_conditional loop_body
         | loop_stmt loop_body
         | unary_operation_without_dot DOT loop_body
         | return_stmt loop_body
         | comments loop_body
         | output_stmt loop_body
         | input_stmt loop_body
         | {}
         ;

loop_conditional: LT predicate GT OPENCU break_body CLOSECU
                | LT predicate GT OPENCU break_body CLOSECU OPENCU break_body CLOSECU
                ;

conditional_stmt: LT predicate GT OPENCU body CLOSECU
                | LT predicate GT OPENCU body CLOSECU OPENCU body CLOSECU
                ;

loop_stmt: LOOP LT predicate GT OPENCU loop_body CLOSECU
         ; 

return_val: ID
          | constant_for_bo
          | call_stmt_without_dot
          | DOUBLE_QUOTE STRING_CONSTANT DOUBLE_QUOTE
          | TRUE
          | FALSE
          | predicate
          | {}
          ;

return_stmt: ARROW return_val DOT
           ;

parameters: DATATYPE ID
          | DATATYPE ID COMMA parameters
          ;

function_decl: DATATYPE ID ASSGN OPENCC parameters CLOSECC ARROW OPENCU body CLOSECU
             ;

std_lib: rel_to_mag
    | rel_to_pos
    | rel_to_energy
    | rel_to_angle
    ;

rel_to_mag: MAG OPENCC ID CLOSECC
    | MAG OPENCC vectors CLOSECC
    ;

rel_to_pos: OPENCC ID CLOSECC SETR OPENCC ID CLOSECC
    | OPENCC ID CLOSECC ADDR OPENCC ID CLOSECC
    | OPENCC ID CLOSECC R_AFTER OPENCC ID CLOSECC
    ;

rel_to_energy: OPENCC ID CLOSECC KE_AFTER OPENCC ID CLOSECC
             | OPENCC ID CLOSECC PE_AFTER OPENCC ID CLOSECC
             | OPENCC ID CLOSECC TE_AFTER OPENCC ID CLOSECC
             ;

rel_to_angle: OPENCC ID CLOSECC ANGLE_AFTER OPENCC ID CLOSECC
            ;

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
