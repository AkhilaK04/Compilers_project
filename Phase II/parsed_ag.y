%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
extern FILE *yyin, *tokfile, *parsefile ;
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
%token SETR ADDR SETV ADDV SETA ADDA SETP GETR GETA GETV
%token KE_AFTER PE_AFTER TE_AFTER ANGLE_AFTER V_AFTER R_AFTER
%token GET_TRAJ COLLIDE TIME_TO_COLLIDE ROC_AFTER
%token P_AFTER S_AFTER TIME_TO_R TIME_TO_V
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
%token EQ NEQ GEQ LEQ GT LT
%token LOGICOP UNIOP UNINEG
%token ASSGN
%token DARR
%token CMT
%token QUESTION
%token NON_NEGATIVE_INT
%token FIRST
%token SECOND
%token OTHERWISE
%token SCOPEOPEN
%token SCOPECLOSE

%start code
%%

code: code_subpart
    | code_subpart code
	;

code_subpart: comments {fprintf(parsefile," : comment");}
            | startfn 
            | function_decl 
            ;

startfn : START OPENCU {fprintf(parsefile," : main function");} body CLOSECU
        ;

body : exp_stmt {fprintf(parsefile," : expression statement");} body
     | call_stmt_with_dot {fprintf(parsefile," : call statement");} body
     | conditional_stmt {fprintf(parsefile," : conditional statement");} body
     | loop_stmt {fprintf(parsefile," : loop statement");} body
     | unary_operation_without_dot DOT {fprintf(parsefile," : call statement");} body
     | return_stmt {fprintf(parsefile," : return statement");} body
     | comments {fprintf(parsefile," : comment ");} body
     | output_stmt {fprintf(parsefile," : output statement");} body
     | input_stmt {fprintf(parsefile," : input statement");} body
     | {}
     | SCOPEOPEN OPENCU {fprintf(parsefile," : opening of new scope");} body SCOPECLOSE CLOSECU {fprintf(parsefile," : ending of new scope");} body 
     | inbuilt_functions_with_dot {fprintf(parsefile," : standard-library");} body
     | decl_stmt_with_exp {fprintf(parsefile," : declaration statement");} body 
     ;

loop_body : exp_stmt {fprintf(parsefile," : expression statement");} loop_body
     | call_stmt_with_dot {fprintf(parsefile," : call statement");} loop_body
     | conditional_stmt {fprintf(parsefile," : conditional statement");} loop_body
     | loop_stmt {fprintf(parsefile," : loop statement");} loop_body
     | unary_operation_without_dot DOT {fprintf(parsefile," : call statement");} loop_body
     | return_stmt {fprintf(parsefile," : return statement");} loop_body
     | comments {fprintf(parsefile," : comment statement");} loop_body
     | output_stmt {fprintf(parsefile," : output statement");} loop_body
     | input_stmt {fprintf(parsefile," : input statement");} loop_body
     | {}
     | SCOPEOPEN OPENCU {fprintf(parsefile," : opening of new scope");} loop_body SCOPECLOSE CLOSECU {fprintf(parsefile," : ending of new scope");} body 
     | inbuilt_functions_with_dot {fprintf(parsefile," : standard-library");} loop_body
     | decl_stmt_with_exp {fprintf(parsefile," : declaration statement");} loop_body 
     | BREAK DOT {fprintf(parsefile," : break statement");} loop_body
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

vectors : OPENSQ rhs_exp COMMA rhs_exp CLOSESQ
        ;

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

/* DECLARATION STATEMENT needed things */


single_variable : ID
                | ID dimensions 
                ;

dimensions : OPENSQ rhs_exp CLOSESQ
           | OPENSQ rhs_exp CLOSESQ dimensions
           ;

/* EXPRESSION STATEMENT */

exp_stmt : single_variable ASSGN rhs_exp DOT
         ;

pos : FIRST
    | SECOND
    ;

anything_with_value : single_variable
                    | NON_NEGATIVE_INT
                    | INTEGER_CONSTANT
                    | FLOAT_CONSTANT
                    | STRING_CONSTANT
                    | TRUE
                    | FALSE
                    | call_stmt_without_dot
                    | vectors
                    | UNINEG anything_with_value
                    | call_stmt_without_dot ARROW pos
                    | inbuilt_functions ARROW pos
                    | inbuilt_functions
                    | vectors ARROW pos
                    | ID ARROW pos
                    | SIN OPENCC anything_with_value CLOSECC
                    | COS OPENCC anything_with_value CLOSECC
                    | TAN OPENCC anything_with_value CLOSECC
                    ;
        
operations : bi_op
           | LOGICOP
           | relop
           ;

rhs_term : openccs anything_with_value
         | anything_with_value closeccs

rhs_exp : rhs_term operations rhs_exp
        | anything_with_value operations rhs_exp
        | rhs_term
        | anything_with_value
        ;

openccs : openccs OPENCC
        | OPENCC
        ;

closeccs : closeccs CLOSECC
         | CLOSECC
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


conditional_stmt: OPENSQ rhs_exp CLOSESQ OPENCU loop_body CLOSECU
                | OPENSQ rhs_exp CLOSESQ OPENCU loop_body CLOSECU OTHERWISE OPENCU loop_body CLOSECU
                | OPENSQ single_variable UNIOP CLOSESQ OPENCU loop_body CLOSECU
                | OPENSQ single_variable UNIOP CLOSESQ OPENCU loop_body CLOSECU OTHERWISE OPENCU loop_body CLOSECU
                ;

/* LOOP STATEMENT */
      
loop_stmt: LOOP OPENSQ rhs_exp CLOSESQ OPENCU loop_body CLOSECU
         | LOOP OPENSQ single_variable UNIOP CLOSESQ OPENCU loop_body CLOSECU
         ; 

/* UNIRARY OPERATION WITHOUT DOT */
     
unary_operation_without_dot: single_variable UNIOP
                           | UNINEG rhs_exp
                           ;

/* RETURN STATEMENT */
    
return_stmt: DARR rhs_exp DOT
           | DARR DOT
           ;

/* COMMENT STATEMENT */

comments : CMT
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

inbuilt_functions_with_dot : inbuilt_functions DOT
                           ;
     
inbuilt_functions : rel_to_mag
                  | rel_to_vel  
                  | rel_to_pos
                  | rel_to_acc
                  | rel_to_energy
                  | rel_to_angle
                  | rel_to_collision
                  | rel_to_momentum
                  | miscellaneous 
                  ;

rel_to_mag : MAG OPENCU ID CLOSECU
           | MAG OPENCU vectors CLOSECU
           ;

rel_to_pos : OPENCU ID CLOSECU SETR OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU ADDR OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU R_AFTER OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU GETR
           ;

rel_to_vel : OPENCU ID CLOSECU SETV OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU ADDV OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU V_AFTER OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU GETV
           ; 

rel_to_momentum : OPENCU ID CLOSECU SETP OPENCU rhs_exp CLOSECU
                ;

rel_to_acc : OPENCU ID CLOSECU SETA OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU ADDA OPENCU rhs_exp CLOSECU
           | OPENCU ID CLOSECU GETA
           ;

rel_to_energy: OPENCU ID CLOSECU KE_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU ID CLOSECU PE_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU ID CLOSECU TE_AFTER OPENCU rhs_exp CLOSECU
             ;

rel_to_angle: OPENCU ID CLOSECU ANGLE_AFTER OPENCU rhs_exp CLOSECU
            ;

rel_to_collision: OPENCU ID CLOSECU COLLIDE OPENCU ID COMMA ID CLOSECU
                | OPENCU ID CLOSECU COLLIDE OPENCU ID CLOSECU
                | OPENCU ID CLOSECU TIME_TO_COLLIDE OPENCU ID CLOSECU
                ;

miscellaneous: OPENCU ID CLOSECU S_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU ID CLOSECU ROC_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU ID CLOSECU P_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU ID CLOSECU TIME_TO_R OPENCU term_misc COMMA term_misc CLOSECU
             | OPENCU ID CLOSECU TIME_TO_V OPENCU term_misc COMMA term_misc CLOSECU
             ; 

term_misc : rhs_exp
          | QUESTION
          ;

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

function_decl : datatypes ID ASSGN OPENCU parameters CLOSECU DARR OPENCU {fprintf(parsefile," : function declaration");} body CLOSECU
              | datatypes ID ASSGN OPENCU CLOSECU DARR OPENCU {fprintf(parsefile," : function declaration");} body CLOSECU  
              ;

parameters: datatypes ID
          | datatypes ID COMMA parameters
          ;

/*  */

%%

void yyerror(char* s){
	printf("Syntax Error : In line number %d\n",yylineno);
	fprintf(parsefile," %s\n",s);
}

int main(int argc ,char * argv[]){
    char inp_file[100],tok[100],parse[100];

    sprintf(inp_file,"./Phase II/Test Cases:/inp%s.phic",argv[1]);

    yyin = fopen(inp_file,"r");

    sprintf(tok,"./Output/Output_token/tokenfile_%s.txt",argv[1]); 
    
	tokfile = fopen(tok,"w");

    sprintf(parse,"./Output/Output_parsed/parsefile_%s.parsed",argv[1]);

	parsefile = fopen(parse,"w"); 

	int i = yyparse();

	if(i) printf("Failure\n");
	else printf("Success\n");

	return 0;
}
