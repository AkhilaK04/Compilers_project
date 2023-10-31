%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
extern FILE *yyin, *tokfile, *parsefile;
extern int yylineno;
int yylex();
void yyerror(char *s);
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
%token QUESTION
%token NON_NEGATIVE_INT

%start code
%%

code: code_subpart
    | code_subpart code
	;

code_subpart: comments
            | startfn
            | function_decl
            ;

startfn : START OPENCU body CLOSECU
        ;

body : 
        /* decl_stmt body */
     exp_stmt body
     | call_stmt_with_dot body
     | conditional_stmt body
     | loop_stmt body
     | unary_operation_without_dot DOT body
     | return_stmt body
     | comments body
     | output_stmt body
     | input_stmt body
     | {}
     /* | inbuilt_functions body */
     | decl_stmt_with_exp body
     ;

bi_op : ADD
      | SUB
      | MUL
      | DIV
      | MOD
      | EXP
      ;

relop : EQ
      | NEQ
      | GEQ
      | GT
      | LEQ
      | LT
      ;
/* 
vectors : OPENCC rhs_exp COMMA rhs_exp CLOSECC
        ; */

primi_datatype: INT
              | DOUBLE
              | BOOL
              | STRING
              ;
            
non_pri_datatype: MASS
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
            
datatypes : primi_datatype
          | non_pri_datatype
          ; 

/* DECLARATION STATEMENT */

/* decl_stmt : datatypes variables DOT
          ;

variables : single_variable COMMA variables
          | single_variable
          ;   */

single_variable : ID
                | ID dimensions 
                ;

dimensions : OPENSQ rhs_exp CLOSESQ
           | OPENSQ rhs_exp CLOSESQ dimensions
           ;

/* EXPRESSION STATEMENT */

exp_stmt : single_variable ASSGN rhs_exp DOT
         /* | ID OPENSQ rhs_exp CLOSESQ ASSGN rhs_exp DOT    */
         ;

anything_with_value : single_variable
                    | NON_NEGATIVE_INT
                    | INTEGER_CONSTANT
                    | FLOAT_CONSTANT
                    | STRING_CONSTANT
                    | TRUE
                    | FALSE
                    | call_stmt_without_dot
                    ;
        
operations : bi_op
           | LOGICOP
           | relop
           ;

rhs_term : OPENCC anything_with_value
         | anything_with_value CLOSECC

rhs_exp : rhs_term operations rhs_exp
        | anything_with_value operations rhs_exp
        | rhs_term
        | anything_with_value
        ;

/* CALL STATEMENT WITH DOT */

call_stmt_with_dot : call_stmt_without_dot DOT
                   ;

call_stmt_without_dot : ID OPENCU CLOSECU
	                  | ID OPENCU funccallargs CLOSECU
	                  ;

funccallargs : rhs_exp
             | rhs_exp COMMA funccallargs
             ;

/* CONDITIONAL STATEMENT  */


conditional_stmt: OPENSQ rhs_exp CLOSESQ OPENCU body CLOSECU
                | OPENSQ rhs_exp CLOSESQ OPENCU body CLOSECU OPENCU body CLOSECU
                ;

/* LOOP STATEMENT */
      
loop_stmt: LOOP OPENSQ rhs_exp CLOSESQ OPENCU body CLOSECU
         ; 

/* UNIRARY OPERATION WITHOUT DOT */
     
unary_operation_without_dot: single_variable UNIOP
                           | UNINEG rhs_exp
                           ;

/* RETURN STATEMENT */
    
return_stmt: ARROW rhs_exp DOT
           ;

/* COMMENT STATEMENT */

comments : SCMT
         | MCMT
         ;

/* OUTPUT STATEMENT */
     
output_stmt : OUTPUT COLON rhs_exp DOT
            ;

/* INPUT STATEMENT */
     
input_stmt : INPUT COLON ids DOT
           ;

ids : single_variable COMMA ids
    | single_variable
    ;

/* INBUILT STATEMENT */
/*      
inbuilt_functions : 
                  ; */

/* DECLARATION OR DECLARATION WITH INITIALIZATION STATEMENT */
     
decl_stmt_with_exp : datatypes expressions DOT
                   ;

expressions : expression COMMA expressions
            | expression
            ;

expression : single_variable ASSGN rhs_exp
           | single_variable
           ;

/* FUNCTION DECLARATION */

function_decl : datatypes ID ASSGN OPENCU parameters CLOSECU ARROW OPENCU body CLOSECU
              ;

parameters: datatypes ID
          | datatypes ID COMMA parameters
          ;

/*  */



/* std_lib: rel_to_mag
    | rel_to_pos
    | rel_to_energy
    | rel_to_angle
    | rel_to_collision
    | miscellaneous
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

rel_to_collision: OPENCC ID CLOSECC COLLIDE OPENCC ID COMMA E CLOSECC
                | OPENCC ID CLOSECC COLLIDE OPENCC ID CLOSECC
                | OPENCC ID CLOSECC TIME_TO_COLLIDE OPENCC CLOSECC ID CLOSECC
                ;

miscellaneous: OPENCC ID CLOSECC S_AFTER OPENCC CLOSECC ID CLOSECC
             | OPENCC ID CLOSECC ROC_AFTER OPENCC CLOSECC ID CLOSECC
             | OPENCC ID CLOSECC P_AFTER OPENCC CLOSECC ID CLOSECC
             | OPENCC ID CLOSECC TIME_TO OPENCC CLOSECC ID CLOSECC
              ; */

%%

void yyerror(char* s){
	printf("Syntax Error : In line number %d\n",yylineno);
	fprintf(parsefile," %s\n",s);
}

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
