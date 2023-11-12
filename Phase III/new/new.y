%{
#include <bits/stdc++.h>
#include "semantics.hpp"

extern FILE *yyin, *tokfile, *parsefile ;
extern int yylineno;
int yylex();
void yyerror(char *s);
%}

%union {
	struct variable {
		char* value;
		char* type;
	} object;
}

%token <object> INTEGER_CONSTANT STRING_CONSTANT FLOAT_CONSTANT TRUE FALSE
%token <object> INT DOUBLE STRING  BOOL
%token <object> MASS TIME POSITION VELOCITY ACC ENERGY THETA E DISTANCE MOMENTUM
%token <object> ID 
%token <object> INPUT OUTPUT
%token <object> SETR ADDR SETV ADDV SETA ADDA SETP GETR GETA GETV
%token <object> KE_AFTER PE_AFTER TE_AFTER ANGLE_AFTER V_AFTER R_AFTER
%token <object> GET_TRAJ COLLIDE TIME_TO_COLLIDE ROC_AFTER
%token <object> P_AFTER S_AFTER TIME_TO_R TIME_TO_V
%token <object> LOOP
%token <object> BREAK
%token <object> START
%token <object> SIN COS TAN
%token <object> MAG
%token <object> OPENCC CLOSECC OPENSQ CLOSESQ OPENCU CLOSECU
%token <object> DOLLAR
%token <object> DOT
%token <object> DOUBLE_QUOTE SINGLE_QUOTE
%token <object> COMMA
%token <object> COLON
%token <object> ARROW
%token <object> ADD SUB MUL DIV MOD EXP
%token <object> EQ NEQ GEQ LEQ GT LT
%token <object> LOGICOP UNIOP UNINEG
%token <object> ASSGN
%token <object> DARR
%token <object> CMT
%token <object> QUESTION
%token <object> NON_NEGATIVE_INT
%token <object> FIRST
%token <object> SECOND
%token <object> OTHERWISE
%token <object> SCOPEOPEN
%token <object> SCOPECLOSE


%type <object> single_variable_for_exp_stmt single_variable_2 code code_subpart comments startfn function_decl loop_body body exp_stmt call_stmt_with_dot conditional_stmt loop_stmt unary_operation_without_dot return_stmt output_stmt input_stmt inbuilt_functions_with_dot decl_stmt_with_exp bi_op relop vectors primi_datatype non_pri_datatype datatypes ID_singlevar single_variable dimensions pos idadd2 anything_with_value operations rhs_exp rhs_term openccs closeccs call_stmt_without_dot funccallargs conditional_stmt_start ids  rel_to_mag rel_to_vel rel_to_pos rel_to_acc rel_to_energy rel_to_angle  rel_to_collision rel_to_momentum miscellaneous term_misc expression expressions  parameters inbuilt_functions

%start code
%%

code: code_subpart
    | code code_subpart
	;

code_subpart: comments 
            | startfn 
            | function_decl 
            ;

startfn : START OPENCU {is_func_bool = true; current_pointer++;  curr_scopes[current_pointer]++;} body CLOSECU {is_func_bool = false;current_pointer--;}
        ;

body : exp_stmt body
     | call_stmt_with_dot body
     | conditional_stmt body
     | loop_stmt body
     | unary_operation_without_dot DOT body
     | return_stmt body
     | comments body
     | output_stmt body
     | input_stmt body
     | {}
     | SCOPEOPEN { current_pointer++;  curr_scopes[current_pointer]++; }OPENCU body SCOPECLOSE {current_pointer--; }CLOSECU body 
     | inbuilt_functions_with_dot body
     | decl_stmt_with_exp body 
     ;

loop_body : exp_stmt loop_body
     | call_stmt_with_dot loop_body
     | conditional_stmt loop_body
     | loop_stmt loop_body
     | unary_operation_without_dot DOT loop_body
     | return_stmt loop_body
     | comments loop_body
     | output_stmt loop_body
     | input_stmt loop_body
     | {}
     | SCOPEOPEN { current_pointer++;  curr_scopes[current_pointer]++; } OPENCU loop_body SCOPECLOSE {current_pointer--; } CLOSECU body 
     | inbuilt_functions_with_dot loop_body
     | decl_stmt_with_exp loop_body 
     | BREAK DOT loop_body
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

primi_datatype: INT {insert_type();}
              | DOUBLE {insert_type();}
              | BOOL {insert_type();}
              | STRING {insert_type();}
              ;
            
non_pri_datatype: MASS {insert_type();}
                | TIME {insert_type();}
                | POSITION {insert_type();}
                | VELOCITY {insert_type();}
                | ACC {insert_type();}
                | ENERGY {insert_type();}
                | THETA {insert_type();}
                | E       {insert_type();}
                | DISTANCE {insert_type();}
                | MOMENTUM {insert_type();}
                ;
            
datatypes : primi_datatype
          | non_pri_datatype
          ; 

/* DECLARATION STATEMENT needed things */

ID_singlevar: ID 
            ;

single_variable : ID_singlevar 
                | ID_singlevar dimensions 
                ;

dimensions : OPENSQ rhs_exp CLOSESQ
           | OPENSQ rhs_exp CLOSESQ dimensions
           ;

/* EXPRESSION STATEMENT */

single_variable_for_exp_stmt : single_variable {
	var_records* rec = new var_records;
	rec->name = $1.value;
	rec->type = type;
	rec->scope = convert_scope_to_string();
	fn_var_entry(rec)
}
;

exp_stmt : single_variable_for_exp_stmt // if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
          ASSGN rhs_exp DOT // { if(!type_checking_assign($1.type,$3.type)){cout<<"error"} }
         ;

pos : FIRST
    | SECOND
    ;


anything_with_value : single_variable // if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
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
                    | stand_id ARROW pos
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

call_stmt_without_dot : ID OPENCU CLOSECU //$1.name , $1.type if(!undeclared_function(name,type)) {error}
                      {
                        check_func_args($1.value, func_args_list);
                        func_args_list.clear();
                      }
	                  | ID OPENCU funccallargs CLOSECU 
                      {
                          check_func_args($1.value, func_args_list);
                          func_args_list.clear();
                      }
	                  ;

funccallargs : rhs_exp 
                {
                    func_args_list.push_back(rhs_exp.type);
                }
             | rhs_exp 
                {
                    func_args_list.push_back(rhs_exp.type);
                }
              COMMA funccallargs
             ;

/* CONDITIONAL STATEMENT  */

conditional_stmt_start : OPENSQ rhs_exp CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; }
                       | OPENSQ single_variable // if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
                        UNIOP CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; }
                      ;


conditional_stmt: conditional_stmt_start loop_body CLOSECU {current_pointer--; }
                | conditional_stmt_start loop_body CLOSECU {current_pointer--; } OTHERWISE OPENCU { current_pointer++;  curr_scopes[current_pointer]++; } loop_body  CLOSECU {current_pointer--; }
                ;

/* LOOP STATEMENT */
      
loop_stmt: LOOP OPENSQ rhs_exp CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; } loop_body CLOSECU {current_pointer--; }
         | LOOP OPENSQ single_variable // if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
          UNIOP CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; } loop_body CLOSECU {current_pointer--; }
         ; 

/* UNIRARY OPERATION WITHOUT DOT */
     
unary_operation_without_dot: single_variable // if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
                           UNIOP //{ $1.type == int or double}
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

ids : single_variable // if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
       COMMA ids
    | single_variable // if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
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

stand_id: ID //  if(!undeclare_check($1,curr_scope)) cout<< undeclaration error<<endl;
rel_to_mag : MAG OPENCU stand_id CLOSECU
           | MAG OPENCU vectors CLOSECU
           ;

rel_to_pos : OPENCU stand_id CLOSECU SETR OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU ADDR OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU R_AFTER OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU GETR
           ;

rel_to_vel : OPENCU stand_id CLOSECU SETV OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU ADDV OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU V_AFTER OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU GETV
           ; 

rel_to_momentum : OPENCU stand_id CLOSECU SETP OPENCU rhs_exp CLOSECU
                ;

rel_to_acc : OPENCU stand_id CLOSECU SETA OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU ADDA OPENCU rhs_exp CLOSECU
           | OPENCU stand_id CLOSECU GETA
           ;

rel_to_energy: OPENCU stand_id CLOSECU KE_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU stand_id CLOSECU PE_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU stand_id CLOSECU TE_AFTER OPENCU rhs_exp CLOSECU
             ;

rel_to_angle: OPENCU stand_id CLOSECU ANGLE_AFTER OPENCU rhs_exp CLOSECU
            ;

rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU ID COMMA ID CLOSECU
                | OPENCU stand_id CLOSECU COLLIDE OPENCU ID CLOSECU
                | OPENCU stand_id CLOSECU TIME_TO_COLLIDE OPENCU ID CLOSECU
                ;

miscellaneous: OPENCU stand_id CLOSECU S_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU stand_id CLOSECU ROC_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU stand_id CLOSECU P_AFTER OPENCU rhs_exp CLOSECU
             | OPENCU stand_id CLOSECU TIME_TO_R OPENCU term_misc COMMA term_misc CLOSECU
             | OPENCU stand_id CLOSECU TIME_TO_V OPENCU term_misc COMMA term_misc CLOSECU
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

single_variable_2 : single_variable {
                          // if(!redeclaration_check($1,curr_scope)) cout<< redeclaration error<<endl;

                          if(is_func_bool){
                          var_records* rec = new var_records;
													rec->name = $1.value;
													rec->type = type;
													rec->scope = convert_scope_to_string();
                          fn_var_entry(rec);
                          }
                        else{
                          add('V');
                        }
}
expression : single_variable_2 ASSGN rhs_exp // { if(!type_checking_assign($1.type,$3.type)){cout<<"type checking error"} }
           | single_variable_2 
            ;

/* FUNCTION DECLARATION */

idadd2: ID {is_func_bool = true; 
           // if(!func_red_var) cout<< "Redeclaration error:Function is reclared as varibale name"<<endl;
           };

function_decl : datatypes idadd2 ASSGN OPENCU parameters CLOSECU DARR OPENCU {current_pointer++;  curr_scopes[current_pointer]++; }body
                {   

                  bool valid = new_func_entry( $2, $1, par_list.size(), par_list, var_list);
                  if(valid) add('F'); // if(valid): add to SymTab. 
                  else{
                     cout<< "Function re-def, ERROR!"<<endl;
                  }
                  var_list.clear(); 
                  par_list.clear();
                }
                CLOSECU {is_func_bool = false;current_pointer--; }
              | datatypes idadd2 ASSGN OPENCU CLOSECU DARR OPENCU {current_pointer++;  curr_scopes[current_pointer]++;}body 
                {
                    if (valid_func_entry($2.value , par_list)){
                      new_func_entry( $2.value, $1.value, par_list.size(), par_list, var_list);
                      add('F');
                    }
                    else{
                      cout<< "Function re-def, ERROR!"<<endl;
                  }
                    var_list.clear(); 
                    par_list.clear();
                }
                CLOSECU {is_func_bool = false;current_pointer--; }
              ;

parameters: datatypes ID
        {
          // if(!within_func_parameters_redeclaration($2.name)) cout<<"Redeclaration of parameters in the function"<<endl;
            par_records* rec = new par_records;
						rec->name = $1.value;
						rec->type = type;
            par_list.push_back(rec);
        }
          | datatypes ID 
          {
         // if(!within_func_parameters_redeclaration($2.name)) cout<<"Redeclaration of parameters in the function"<<endl;
            par_records* rec = new par_records;
						rec->name = $1.value;
						rec->type = type;
            par_list.push_back(rec);
          }
          COMMA parameters
          ;

/*  */

%%

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
                