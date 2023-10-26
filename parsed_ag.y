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
%token INT
%token DOUBLE
%token STRING
%token BOOL
%token MASS
%token TIME
%token POSITION
%token VELOCITY
%token ACC
%token ENERGY
%token THETA
%token E
%token DISTANCE
%token MOMENTUM
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
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token EXP
%token EQ
%token NEQ
%token GEQ
%token LEQ
%token GT
%token LT
%token LOGICOP
%token UNIOP
%token UNINEG
%token ASSGN
%token DARR
%token LINE
%token SLASHN


%start program
%%

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

program:
	| cmt_stmt
	;

cmt_body: cmt_body LINE
    | LINE
    ;

cmt_stmt: DOLLAR LINE SLASHN
    | DOLLAR cmt_body DOLLAR
    ;

ids: ID
   | ID COMMA ids
   ;

call_stmt_without_dots: call_stmt_without_dot
                      | call_stmt_without_dot COMMA call_stmt_without_dots
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
               | binary_operation
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

body: decl_stmt body
         | exp_stmt body
         | call_stmt body
         | conditional_stmt body
         | loop_stmt body
         | unary_operation_without_dot DOT body
         | return_stmt body
         | {}
         ;

loop_body: decl_stmt loop_body
         | exp_stmt loop_body
         | call_stmt loop_body
         | conditional_stmt loop_body
         | loop_conditional loop_body
         | loop_stmt loop_body
         | unary_operation_without_dot DOT loop_body
         | return_stmt loop_body
         | {}
         ;

loop_stmt: loop LT predicate GT OPENCU loop_body CLOSECU
         ; 

break_body: decl_stmt body
         | exp_stmt body
         | call_stmt body
         | conditional_stmt body
         | loop_stmt body
         | BREAK DOT body
         | unary_operation_without_dot DOT body
         | return_stmt body
         | {}-
         ;

loop_conditional: LT predicate GT OPENCU break_body CLOSECU
                | LT predicate GT OPENCU break_body CLOSECU OPENCU break_body CLOSECU

conditional_stmt: LT predicate GT OPENCU body CLOSECU
                | LT predicate GT OPENCU body CLOSECU OPENCU body CLOSECU
                ;

return_val: ID
          | constant_for_bo
          | call_stmt_without_dot
          | {}
          | DOUBLE_QUOTE STRING_CONSTANT DOUBLE_QUOTE
          | TRUE
          | FALSE
          | predicate
          ;

return_stmt: ARROW return_val DOT
           ;

parameters: DATATYPE ID
          | DATATYPE ID COMMA parameters
          ;

function_decl: DATATYPE ID ASSGN OPENCC parameters CLOSECC ARROW OPENCU body CLOSECU
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
