%{
#include <bits/stdc++.h>
#include "semantics.hpp"

extern FILE *yyin, *tokfile, *parsefile, *outfile, *headerfile ;
extern int yylineno;
int yylex();
void yyerror(char *s);
bool arr_check = false;
int dim_count = 0;
int num_return = 0;
int function_return_type = 0;
%}

%union {
	struct variable {
		char* value;
		int type;
	} object;
  struct for_args {
    char* list[100];
    int present;
  } arg_object ;
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


%type <object> multiple_output dim_con check_rhs_exp stand_id single_variable_for_exp_stmt single_variable_declare code code_subpart comments startfn function_decl loop_body body exp_stmt call_stmt_with_dot conditional_stmt loop_stmt unary_operation_without_dot return_stmt output_stmt input_stmt inbuilt_functions_with_dot decl_stmt_with_exp bi_op relop vectors primi_datatype non_pri_datatype datatypes single_variable dimensions pos idadd2 anything_with_value operations rhs_exp rhs_term openccs closeccs call_stmt_without_dot conditional_stmt_start ids  rel_to_mag rel_to_vel rel_to_pos rel_to_acc rel_to_energy rel_to_angle  rel_to_collision rel_to_momentum miscellaneous term_misc expression expressions  parameters inbuilt_functions
%type <arg_object> funccallargs
%start code
%%

code: code_subpart
    | code code_subpart
	;

code_subpart: comments 
            | startfn 
            | function_decl 
            ;

startfn : START OPENCU 
          {is_func_bool = true; current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile,"int main() {");} 
          body 
           {
            if (valid_func_entry($1.value , par_list)){
              new_func_entry( $1.value, "null", par_list.size(), par_list, var_list);
              add('F',$1.value,"null");
            }
            else{
              cout<< "From startfn Function re-def, ERROR! at " << yylineno <<endl;
            }
            var_list.clear(); 
            par_list.clear();
            }
            CLOSECU 
            {is_func_bool = false;current_pointer--;
            fprintf(outfile,"   return 0;\n}");
            }
        ;

body : exp_stmt body
     | call_stmt_with_dot body
     | conditional_stmt body
     | loop_stmt body
     | unary_operation_without_dot DOT {fprintf(outfile, ";");} body
     | return_stmt body
     | comments body
     | output_stmt body
     | input_stmt body
     | {}
     | SCOPEOPEN { current_pointer++;  curr_scopes[current_pointer]++; }OPENCU {fprintf(outfile, "{");} body SCOPECLOSE {current_pointer--; }CLOSECU {fprintf(outfile, "}");} body
     | inbuilt_functions_with_dot body
     | decl_stmt_with_exp body 
     ;

loop_body : exp_stmt loop_body
     | call_stmt_with_dot loop_body
     | conditional_stmt loop_body
     | loop_stmt loop_body
     | unary_operation_without_dot DOT {fprintf(outfile, ";");} loop_body
     | return_stmt loop_body
     | comments loop_body
     | output_stmt loop_body
     | input_stmt loop_body
     | {}
     | SCOPEOPEN { current_pointer++;  curr_scopes[current_pointer]++; } OPENCU {fprintf(outfile, "{");} loop_body SCOPECLOSE {current_pointer--; } CLOSECU {fprintf(outfile, "}");} body
     | inbuilt_functions_with_dot loop_body
     | decl_stmt_with_exp loop_body 
     | BREAK DOT loop_body {fprintf(outfile, "break; %s", $3.value);}
     ;

bi_op : ADD {fprintf(outfile, "+");}
      | SUB {fprintf(outfile, "-");}
      | MUL {fprintf(outfile, "*");}
      | DIV {fprintf(outfile, "/");}
      | MOD {fprintf(outfile, "%%");}
      | EXP
      ;

relop : EQ {fprintf(outfile, "==");}
      | NEQ {fprintf(outfile, "!=");}
      | GEQ {fprintf(outfile, ">=");}
      | GT {fprintf(outfile, ">");}
      | LEQ {fprintf(outfile, "<=");}
      | LT {fprintf(outfile, "<");}
      ;

vectors : OPENSQ {fprintf(outfile, "{");} check_rhs_exp COMMA {fprintf(outfile, ",");} check_rhs_exp CLOSESQ {fprintf(outfile, "}");} {
              if(($3.type == 1 || $3.type == 4 || $3.type == 2) && ($3.type == 1 || $3.type == 4 || $3.type == 2)){
                $$.type = 10;
              }
              else{
                cout << "Invalid vector in line " << yylineno << endl;
              }
              
              }
        ;

primi_datatype: INT {insert_type($1.value);
                  fprintf(outfile, "int");} 
              | DOUBLE {insert_type($1.value);
               fprintf(outfile, "double");}
              | BOOL {insert_type($1.value);
              fprintf(outfile, "bool");}
              | STRING {insert_type($1.value);
              fprintf(outfile, "string");}
              ;
            
non_pri_datatype: MASS {insert_type($1.value); fprintf(outfile, "mass");}
                | TIME {insert_type($1.value); fprintf(outfile, "double");} 
                | POSITION {insert_type($1.value); fprintf(outfile, "pair<double,double>");}
                | VELOCITY {insert_type($1.value); fprintf(outfile, "pair<double,double>");}
                | ACC {insert_type($1.value); fprintf(outfile, "pair<double,double>");}
                | ENERGY {insert_type($1.value); fprintf(outfile, "double");}
                | THETA {insert_type($1.value); fprintf(outfile, "double");}
                | E       {insert_type($1.value); fprintf(outfile, "double");}
                | DISTANCE {insert_type($1.value); fprintf(outfile, "double");}
                | MOMENTUM {insert_type($1.value); fprintf(outfile, "double");}
                ;
            
datatypes : primi_datatype
          | non_pri_datatype
          ; 

/* DECLARATION STATEMENT needed things */

single_variable : ID { fprintf(outfile,"%s", $1.value); arr_check = false;}
                | ID { fprintf(outfile,"%s", $1.value); arr_check = true; } dimensions 
                {
                  int k;
                  if((k = get_num_dim($1.value,convert_scope_to_string())) != -1 && k != dim_count){
                    cout << "Invalid access of array at line no " << yylineno << endl;
                  } 
                }
                ;

dim_con : OPENSQ {fprintf(outfile, "[");} ;

dimensions : dim_con check_rhs_exp CLOSESQ {
              fprintf(outfile, "]");
              if($2.type == 1){
                $$.type = 10;
              }
              else{
                cout << "Invalid dimension in line " << yylineno << endl;
              }
              dim_count++;
              }
           | dim_con check_rhs_exp CLOSESQ {fprintf(outfile, "]");} dimensions{
              if($2.type == 1){
                $$.type = 10;
              }
              else{
                cout << "Invalid dimension in line " << yylineno << endl;
              }
              dim_count++;
           }
           ;


/* EXPRESSION STATEMENT */

single_variable_for_exp_stmt :  single_variable 
                                {
                                  if(($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                                    cout << "From single_variable_for_exp_stmt Undeclared variable used " << $1.value << " at " << yylineno << endl;
                                  }
                                  dim_count = 0;
                                }
                                ;

exp_stmt : single_variable_for_exp_stmt ASSGN { fprintf(outfile, "=");} check_rhs_exp DOT {fprintf(outfile, ";");} 
          {if(!type_checking_assign($1.type,$4.type)){
            cout << "From exp_stmt Expression statement types not compatible " << $1.type << ' ' << $4.type << ' ' <<" at " << yylineno << endl;
          }
          }
         ;

pos : FIRST
    | SECOND
    ;

anything_with_value : single_variable {if(($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
    cout << "From anything_with_value Undeclared variable used " << $1.value << " at " << yylineno<< endl;
  }
  dim_count = 0;}
                    | NON_NEGATIVE_INT {fprintf(outfile, "%s", $1.value);}
                    | INTEGER_CONSTANT {fprintf(outfile, "%s", $1.value);}
                    | FLOAT_CONSTANT {fprintf(outfile, "%s", $1.value);}
                    | STRING_CONSTANT {fprintf(outfile, "%s", $1.value);}
                    | TRUE {fprintf(outfile, "%s", $1.value);}
                    | FALSE {fprintf(outfile, "%s", $1.value);}
                    | call_stmt_without_dot
                    | vectors {$$.type = 10;}
                    | UNINEG {fprintf(outfile, "!");}anything_with_value {$$.type = 4;}
                    | call_stmt_without_dot ARROW pos {fprintf(outfile, ".%s",$3.value);}{if($1.type != 5 && $1.type != 6 && $1.type != 7 && $1.type != 8 && $1.type != 9 && $1.type != 10){
                      cout << "From anything with value call statement return is not a vector" << endl;
                    }}
                    | inbuilt_functions ARROW pos {fprintf(outfile, ".%s",$3.value);}
                    | inbuilt_functions
                    | vectors ARROW pos {fprintf(outfile, ".%s",$3.value);}
                    | ID ARROW pos {fprintf(outfile, ".%s",$3.value);} {
                      if(($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                        cout << "From anything_with_value Undeclared variable used " << $1.value << " at " << yylineno<< endl;
                      }
                      if($$.type == 5 || $$.type == 6 || $$.type == 7 || $$.type == 8 || $$.type == 9 || $$.type == 10){

                      }
                      else{
                        cout << "From anything_with_value " << $1.value << " is not a vector to access first or second" << endl;
                      }
                    }
                    | single_variable UNIOP {if(($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                        cout << "From anything_with_value Undeclared variable used " << $1.value << " at " << yylineno<< endl;
                      }}
                    | SIN OPENCC anything_with_value CLOSECC {
                      fprintf(outfile,"sin(%s * (M_PI / 180.0))",$3.value);
                      $$.type = 2;
                      if($3.type != 1 && $3.type != 2){cout << "Sin input is out of range" << endl;}
                    }
                    | COS OPENCC anything_with_value CLOSECC {
                      fprintf(outfile,"cos(%s * (M_PI / 180.0))",$3.value);
                      $$.type = 2;
                      if($3.type != 1 && $3.type != 2){cout << "Sin input is out of range" << endl;}
                      }
                    | TAN OPENCC anything_with_value CLOSECC {
                      fprintf(outfile,"tan(%s * (M_PI / 180.0))",$3.value);
                      $$.type = 2;
                      if($3.type != 1 && $3.type != 2){cout << "Sin input is out of range" << endl;}
                      }
                    ;
        
operations : bi_op 
           | LOGICOP {fprintf(outfile, "%s", $1.value);}
           | relop
           ;

rhs_term : openccs anything_with_value {$$.type = $2.type;}
         | openccs anything_with_value closeccs {$$.type = $2.type;}
         | anything_with_value closeccs {$$.type = $1.type;}
         ;

rhs_exp : rhs_term operations rhs_exp 
          {cout << $1.type << ' ' << $2.value << ' '<< $3.type << endl;
            $$.type = give_result_type($1.type,$2.value,$3.type); 
            if($$.type == -1){cout << "From rhs_exp Invalid operation in rhs side " << $1.type << " " << $2.value << " "  << $3.type << " at " << yylineno << endl;}}
        | anything_with_value operations rhs_exp 
        {cout << $1.type << ' ' << $2.value << ' '<< $3.type << endl; 
          $$.type = give_result_type($1.type,$2.value,$3.type); 
          if($$.type == -1){cout << "From rhs_exp Invalid operation in rhs side " << $1.type << " " << $2.value << " " << $3.type << " at " << yylineno  << endl;}}
        | rhs_term
        | anything_with_value
        ;

openccs : openccs OPENCC {open_brackets = open_brackets + 1; fprintf(outfile, "(");} 
        | OPENCC {open_brackets = open_brackets + 1; fprintf(outfile, "(");} 
        ;

closeccs : closeccs CLOSECC {close_brackets = close_brackets + 1; fprintf(outfile, ")");}
         | CLOSECC {close_brackets = close_brackets + 1; fprintf(outfile, ")");} 
         ;

/* CALL STATEMENT WITH DOT */

call_stmt_with_dot : call_stmt_without_dot DOT {fprintf(outfile, ";");} 
                   ;

call_stmt_without_dot : ID OPENCU CLOSECU 
                      {
                        char* templist[100];
                        int temp = 0;
                        if(!check_func_args($1.value,templist,temp )){
                          cout << "From call_stmt_without_dot Undeclared function " << $1.value <<" at " << yylineno  << endl;
                        }
                        func_args_list.clear();
                        $$.type = find_return_type($1.value,templist,temp);
                        fprintf(outfile, "%s()", $1.value);
                      }
	                  | ID OPENCU  {fprintf(outfile, "%s(",$1.value);} funccallargs CLOSECU 
                      {
                          if(!check_func_args($1.value, $4.list,$4.present)){
                            cout << "From call_stmt_without_dot Undeclared function " << $1.value <<" at " << yylineno  << endl;
                          }
                          func_args_list.clear();
                          $$.type = find_return_type($1.value,$4.list,$4.present);
                          fprintf(outfile, ")");
                      }
                      
	                  ;

funccallargs : check_rhs_exp 
                {
                  const char* temp = get_string_type($1.type).c_str();
                  $$.list[0] = strdup(temp);
                  $$.present = 1;
                }
             | check_rhs_exp COMMA {fprintf(outfile, ",");} funccallargs
              {
                for(int i=0;i<$4.present;i++){
                  $$.list[i+1] = $4.list[i];
                }
                $$.present = $4.present + 1;
                const char* temp = get_string_type($1.type).c_str();
                $$.list[0] = strdup(temp);
              }
             ;

/* CONDITIONAL STATEMENT  */

conditional_stmt_start : OPENSQ {fprintf(outfile, "if(");} check_rhs_exp CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "){");}
                      ;


conditional_stmt: conditional_stmt_start loop_body CLOSECU {current_pointer--; fprintf(outfile, "\n}\n");} 
                | conditional_stmt_start loop_body CLOSECU {current_pointer--; } OTHERWISE OPENCU { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "} else {");} loop_body  CLOSECU {current_pointer--; fprintf(outfile, "}");}
                ;

/* LOOP STATEMENT */
      
loop_stmt: LOOP OPENSQ {fprintf(outfile, "while(");} check_rhs_exp CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "){");} loop_body CLOSECU {current_pointer--; fprintf(outfile, "}");} 
         ; 

/* UNIRARY OPERATION WITHOUT DOT */

unary_operation_without_dot: single_variable UNIOP {
                              fprintf(outfile, "%s", $2.value);
                              if (($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0) cout << "Undeclaration error at " << yylineno << $1.value << endl;
                              if($1.type != 1 && $1.type != 2){
                                cout << "From unary_operation_without_dot cant perform operation" << yylineno<< endl;
                              }
                              $$.type = $1.type;
                              }
                           | UNINEG {fprintf(outfile, " !");} check_rhs_exp {
                            $$.type = 4;
                            if ($3.type != 1 && $3.type !=2 && $3.type != 4){
                              cout << "From unary_operation_without_dot invalid negation operation" << yylineno<< endl;
                            }
                           }
                           ;

/* RETURN STATEMENT */
    
return_stmt: DARR {fprintf(outfile, "return ");}  check_rhs_exp DOT {fprintf(outfile, ";"); num_return ++;if(type_checking_assign($3.type,function_return_type) == 0){
  cout << "Return type doesnot match with function defined return type " << yylineno << endl;
  cout << $3.type <<  ' ' << function_return_type << endl;
}} 
           /* | DARR DOT {fprintf(outfile, "return ;"); num_return ++; if()}  */
           ;

/* COMMENT STATEMENT */

comments : CMT // {fprintf(outfile, "%s", $1);} 
         ;

/* OUTPUT STATEMENT */

multiple_output : check_rhs_exp COMMA {fprintf(outfile, " << ");} multiple_output
                | check_rhs_exp
                ;
     
output_stmt : OUTPUT COLON {fprintf(outfile, "cout << ");} multiple_output DOT {fprintf(outfile, ";");} 
            ;

/* INPUT STATEMENT */
     
input_stmt : INPUT COLON {fprintf(outfile, "cin >>");} ids DOT {fprintf(outfile, ";");} 
           ;

ids : single_variable {if(undeclare_check($1.value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << $1.value << endl;
                        }}COMMA {fprintf(outfile, ">>");} ids
    | single_variable {if(undeclare_check($1.value,convert_scope_to_string()) == 0){
                          cout << "Undeclared variable used at " << yylineno << $1.value << endl;
                        }}
    ;

/* INBUILT STATEMENT */

inbuilt_functions_with_dot : inbuilt_functions DOT {fprintf(outfile, ";");} 
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

stand_id : ID {if(($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                          cout << "From stand_id Undeclared variable used at " << yylineno << $1.value << endl;
                        };
                if($$.type != 11){
                  cout << "From stand_id indentifier is of not mass datatype at " << yylineno << endl; 
                }
              }

rel_to_mag : MAG OPENCU check_rhs_exp CLOSECU {
              $$.type = 2;
              if(!std_lib_semantics($1.value,0,{$3.type})){
                cout<<"Invalid use of std-lib : mag"<<endl;
              }
              cout<<endl<<endl;
              cout<<$3.value<<" : this is check_rhs_exp"<<endl;
              cout<<endl<<endl;
              fprintf(outfile, "mag(%s)", $3.value);
            }
          
           ;

rel_to_pos : OPENCU stand_id CLOSECU SETR OPENCU check_rhs_exp CLOSECU {
  
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : setr"<<endl;
              }
              fprintf(outfile, "setr(%s, %s)", $2.value, $6.value);
            }
           | OPENCU stand_id CLOSECU ADDR OPENCU check_rhs_exp CLOSECU {
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : addr"<<endl;
              }
              fprintf(outfile, "addr(%s, %s)", $2, $6);
            }
           | OPENCU stand_id CLOSECU R_AFTER OPENCU check_rhs_exp CLOSECU {
              $$.type = 6; 
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : r_after"<<endl;
              }
              fprintf(outfile, "r_after(%s, %s)", $2, $6);
            }
           | OPENCU stand_id CLOSECU GETR {
              $$.type = 6;
              if(!std_lib_semantics($4.value,$2.type,{})){
                cout<<"Invalid use of std-lib : get_r"<<endl;
              }
              fprintf(outfile, "getr(%s)",$2);
            }
           ;

rel_to_vel : OPENCU stand_id CLOSECU SETV OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : setv"<<endl;
            }
            fprintf(outfile, "setv(%s, %s)", $2, $6);
          }
           | OPENCU stand_id CLOSECU ADDV OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : setv"<<endl;
            }
             fprintf(outfile, "addv(%s, %s)", $2, $6);
          }
           | OPENCU stand_id CLOSECU V_AFTER OPENCU check_rhs_exp CLOSECU {
            $$.type = 5; 
            if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : v_after"<<endl;
            }
            fprintf(outfile, "v_after(%s, %s)", $2, $6);
          }
           | OPENCU stand_id CLOSECU GETV {
            $$.type = 5;
            if(!std_lib_semantics($4.value,$2.type,{})){
                cout<<"Invalid use of std-lib : get_v"<<endl;
            }
            fprintf(outfile, "getv(%s)",$2);
          }
           ; 

rel_to_momentum : OPENCU stand_id CLOSECU SETP OPENCU check_rhs_exp CLOSECU {if($6.type != 9 && $6.type != 10){
  cout << "From rel_to_momentum invalid statement" << endl;
}}
                ;

rel_to_acc : OPENCU stand_id CLOSECU SETA OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : seta"<<endl;
            }
            fprintf(outfile, "seta(%s, %s)", $2, $6);
          }
           | OPENCU stand_id CLOSECU ADDA OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : adda"<<endl;
            }
            fprintf(outfile, "adda(%s, %s)", $2, $6);
          }
           | OPENCU stand_id CLOSECU GETA {
            $$.type = 7;
            if(!std_lib_semantics($4.value,$2.type,{})){
                cout<<"Invalid use of std-lib : get_a"<<endl;
            }
            fprintf(outfile, "geta(%s)",$2);
          }
           ;

rel_to_energy: OPENCU stand_id CLOSECU KE_AFTER OPENCU check_rhs_exp CLOSECU {
              $$.type = 13 ;
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : KE AFTER"<<endl;
              }
            }
             | OPENCU stand_id CLOSECU PE_AFTER OPENCU check_rhs_exp CLOSECU {
              $$.type = 13 ;
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : KE AFTER"<<endl;
              }
            }
             | OPENCU stand_id CLOSECU TE_AFTER OPENCU check_rhs_exp CLOSECU {
              $$.type = 13 ;
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : KE AFTER"<<endl;
              }
            }
             ;

rel_to_angle: OPENCU stand_id CLOSECU ANGLE_AFTER OPENCU check_rhs_exp CLOSECU {
            $$.type = 14;
            if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                cout<<"Invalid use of std-lib : angle()"<<endl;
              }
            }
            ;

rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id COMMA ID CLOSECU {
                $$.type = 13;

                  if(!std_lib_semantics($4.value,$2.type,{$6.type,$8.type})){
                  cout<<"Invalid use of std-lib : collide with e"<<endl;
                  }
                }
                | OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id CLOSECU {
                  $$.type = 13;
                  if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : collide without e"<<endl;
                  }
                }
                | OPENCU stand_id CLOSECU TIME_TO_COLLIDE OPENCU stand_id CLOSECU {
                  $$.type = 12 ;
                  if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : time to collide."<<endl;
                  }
                }
                ;

miscellaneous: OPENCU stand_id CLOSECU S_AFTER OPENCU check_rhs_exp CLOSECU {
              $$.type = 8; 
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : s_after"<<endl;
                }
              }
             | OPENCU stand_id CLOSECU ROC_AFTER OPENCU check_rhs_exp CLOSECU {
              $$.type = 2; 
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : roc_after(time)."<<endl;
                }
              }
             | OPENCU stand_id CLOSECU P_AFTER OPENCU check_rhs_exp CLOSECU {
              $$.type = 9;
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : p_after(time)."<<endl;
                }
              }
             | OPENCU stand_id CLOSECU TIME_TO_R OPENCU term_misc COMMA term_misc CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics($4.value,$2.type,{$6.type,$8.type})){
                  cout<<"Invalid use of std-lib : time_to_r()."<<endl;
                }

              }
             | OPENCU stand_id CLOSECU TIME_TO_R OPENCU check_rhs_exp CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : time_to_r()."<<endl;
                }

              }

             | OPENCU stand_id CLOSECU TIME_TO_V OPENCU term_misc COMMA term_misc CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics($4.value,$2.type,{$6.type,$8.type})){
                  cout<<"Invalid use of std-lib : time_to_v()."<<endl;
                }
              }

             | OPENCU stand_id CLOSECU TIME_TO_V OPENCU check_rhs_exp CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : time_to_v()."<<endl;
                }
              }
             ; 

term_misc : check_rhs_exp {if($1.type != 1 && $1.type != 2){
  cout << "From term_misc invalid statement" << endl;
}}
          | QUESTION
          ;

/* DECLARATION OR DECLARATION WITH INITIALIZATION STATEMENT */
     
decl_stmt_with_exp : datatypes expressions DOT {fprintf(outfile,";");}
                   ;

expressions : expression COMMA {fprintf(outfile,",");} expressions
            | expression
            ;

single_variable_declare : single_variable {
                          $$.type = give_type_index(type);
                          if(is_func_bool){
                          var_records* rec = new var_records;
													rec->name = $1.value;
													rec->type = type;
													rec->scope = convert_scope_to_string();
                          if(arr_check) rec->arr_type = "Array";
                          else rec->arr_type = "Simple";
                          rec->dim_countt = dim_count;
                          dim_count = 0;
                          fn_var_entry(rec);
                          }
                        else{
                          add('V',$1.value,type);
                        }
}

check_rhs_exp : {open_brackets = 0;close_brackets = 0;} rhs_exp {if(open_brackets != close_brackets){cout << "Incorrect RHS expression at " << yylineno << endl;}open_brackets = 0;close_brackets = 0;$$.type = $2.type;$$.value = $2.value;}

expression : single_variable_declare ASSGN {fprintf(outfile, "=");} check_rhs_exp { if(!type_checking_assign($1.type,$4.type)){cout << "Declaration with expression type error " <<  $1.type <<  ' ' << $4.type << " at " << yylineno << endl;}}
           | single_variable_declare 
            ;

/* FUNCTION DECLARATION */

idadd2 : ID {is_func_bool = true;
        if(!func_red_var($1.value)){cout << "Redeclaration error : Function is redeclared as variable name at " << yylineno << endl;}
        fprintf(outfile,"%s", $1.value);
        }
       ;

function_decl : datatypes idadd2 ASSGN OPENCU {fprintf(outfile,"(");function_return_type = give_type_index($1.value);} parameters CLOSECU {fprintf(outfile,")");} DARR OPENCU {fprintf(outfile,"{");}
{current_pointer++;  curr_scopes[current_pointer]++; }body
                {   
                  if (valid_func_entry($2.value , par_list)){
                    new_func_entry( $2.value, $1.value, par_list.size(), par_list, var_list);
                    add('F',$2.value,$1.value);
                  }
                  else{
                     cout<< "Function re-def, ERROR! at " << yylineno<<endl;
                  }
                  var_list.clear(); 
                  par_list.clear();
                }
                CLOSECU {is_func_bool = false;current_pointer--; fprintf(outfile,"}"); if(num_return  == 0){
                  cout << "No return statement" << endl;
                }
                num_return  = 0;
                }
                
                | datatypes idadd2 ASSGN OPENCU CLOSECU DARR OPENCU {fprintf(outfile,"(){");function_return_type = give_type_index($1.value);} {current_pointer++;  curr_scopes[current_pointer]++;}body 
                {
                    if (valid_func_entry($2.value , par_list)){
                      new_func_entry( $2.value, $1.value, par_list.size(), par_list, var_list);
                      add('F',$2.value,$1.value);
                    }
                    else{
                      cout<< "Function re-def, ERROR! at " << yylineno<<endl;
                  }
                    var_list.clear(); 
                    par_list.clear();
                }
                CLOSECU {is_func_bool = false;current_pointer--;
                fprintf(outfile,"}");
                if(num_return  == 0){
                  cout << "No return statement" << endl;
                }
                num_return  = 0;
                }
              ;

parameters: datatypes ID {fprintf(outfile,"%s", $2.value);}
        {
          if(!within_func_parameters_redeclaration($2.value)) cout << "Redeclaration of parameters in the function at " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = $2.value;
						rec->type = type;
            par_list.push_back(rec);
        }
          | datatypes ID 
          {
          if(!within_func_parameters_redeclaration($2.value)) cout << "Redeclaration of parameters in the function at " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = $2.value;
						rec->type = type;
            par_list.push_back(rec);
          }
          COMMA {fprintf(outfile,"%s,",$2.value);} parameters
          ;

/*  */

%%

void yyerror(char* s){
	printf("Syntax Error : In line number %d\n",yylineno);
	fprintf(parsefile," %s\n",s);
}

int main(int argc ,char * argv[]){
  char inp_file[100],tok[100],parse[100],out_file[100], header_file[100];

  sprintf(inp_file,"inp.phic");
  sprintf(out_file,"outc.cpp");
  sprintf(header_file,"std_lib.h");

  yyin = fopen(inp_file,"r");

  outfile = fopen(out_file,"w");
  fprintf(outfile,"#include <bits/stdc++.h> \nusing namespace std;\n\n");

  headerfile = fopen(header_file, "w");
  fprintf(headerfile, "#include <bits/stdc++.h>\nusing namespace std; \n\nclass mass{\npublic:\n\tint mass;\n\tpair<double,double> position;\n\tpair<double,double> velocity;\n\tpair<double,double> acceleration;\n};\n");

  fprintf(headerfile, "\n\n// Related to Magnitude\n\ndouble mag(pair<double,double> vec){\n\tdouble vecx = vec.first;\n\tdouble vecy = vec.second;\n\tdouble magnitude = sqrt(vecx * vecx + vecy * vecy);\n\treturn magnitude;\n}");
  fprintf(headerfile, "\n\n\n// Related to Position\n\npair<double,double> setr(mass* m, pair<double,double> r){\n\tm->position = r;\n}\n\npair<double,double> addr(mass* m, pair<double,double> r){\n\tm->position.first = m->position.first + r.first;\n\tm->position.second = m->position.second + r.second;\n}\npair<double,double> r_after(mass* m, double t){\n\tpair<double,double> temp;\n\ttemp.first = m->position.first + m->velocity.first*t + 0.5*m->acceleration.first*t*t;\n\ttemp.second = m->position.second + m->velocity.second*t + 0.5*m->acceleration.second*t*t;\n\treturn temp;\n}\n\npair<double,double> get_r(mass* m){\n\treturn m->position;\n}");
  fprintf(headerfile, "\n\n\n// Related to velocity\n\npair<double,double> setv(mass* m, pair<double,double> vec){\n\tm->velocity = vec;\n}\n\npair<double,double> addv(mass* m, pair<double,double> v){\n\tm->velocity.first = m->velocity.first + v.first;\n\tm->velocity.second = m->velocity.second + v.second;\n}\n\npair<double,double> v_after(mass* m, double t){\n\tpair<double,double> temp;\n\ttemp.first = m->velocity.first + m->acceleration.first*t;\n\ttemp.second = m->velocity.second + m->acceleration.second*t;\n}\n\npair<double,double> v_after(mass* m,  pair<double,double> r){\n\tpair<double,double> temp;\n\ttemp.first = sqrt(pow(m->velocity.first, 2) + 2 * m->acceleration.first * r.first);\n\ttemp.second = sqrt(pow(m->velocity.second, 2) + 2 * m->acceleration.second * r.second);\n\treturn temp;\n}\n\npair<double,double> get_v(mass* m){\n\treturn m->velocity;\n}");
  fprintf(headerfile, "\n\n\n// Related to accerlation\n\npair<double,double> seta(mass* m, pair<double,double> vec){\n\tm->acceleration = vec;\n}\n\npair<double,double> adda(mass* m, pair<double,double> a){\n\tm->acceleration.first = m->acceleration.first + a.first;\n\tm->acceleration.second = m->acceleration.second + a.second;\n}\n\npair<double,double> geta(mass* m){\n\treturn m->acceleration;\n}"); 
  fprintf(headerfile, "\n\n\n// Related to momentum\n\npair<double,double> setp(mass* m ,pair<double,double> p){\n\tm->velocity.first = p.first / m->mass;\n\tm->velocity.second = p.second / m->mass;\n}\n");
  fprintf(headerfile, "\n\n\n// Related to energy\n\ndouble keafter(mass* m,double time){\n\tpair<double,double> vel = v_after(m,time);\n\tdouble mag_value = mag(vel);\n\treturn 0.5*m->mass*mag_value*mag_value;\n}   \n\ndouble peafter(mass* m,double time){\n\tpair<double,double> pos = r_after(m,time);\n\tpair<double,double> acc = geta(m);\n\treturn m->mass*acc.second*pos.second + m->mass*acc.first*pos.first;\n}\n\n\ndouble teafter(mass* m,double time){\n\treturn keafter(m,time) + peafter(m,time);\n}\n");
  fprintf(headerfile, "\n\n\n// Related to angle\n\ndouble angleafter(mass* m,double time){\n\tpair<double,double> vel = v_after(m,time);\n\tif(vel.first == 0){\n\t\treturn 0;\n\t}\n\telse{\n\t\treturn atan2(vel.second,vel.first);\n\t}\n}");
  fprintf(headerfile, "\n\n\n// Related to momentum\n\npair<double,double> setp(mass* m ,pair<double,double> p){\n\tm->velocity.first = p.first / m->mass;\n\tm->velocity.second = p.second / m->mass;\n}");
  fprintf(headerfile, "\n\n\n// Related to Collision\n\ndouble collide(mass* m1, mass* m2, double e) {\n\t// Check if positions are the same\n\tif (m1->position == m2->position) {\n\t\t// Calculate relative velocity\n\t\tdouble v_rel_x = m2->velocity.first - m1->velocity.first;\n\t\tdouble v_rel_y = m2->velocity.second - m1->velocity.second;\n\n\t\t// Calculate final velocities using coefficient of restitution\n\t\tdouble v1_final_x = (m1->mass * m1->velocity.first + m2->mass * m2->velocity.first + e * m2->mass * v_rel_x) / (m1->mass + m2->mass);\n\t\tdouble v1_final_y = (m1->mass * m1->velocity.second + m2->mass * m2->velocity.second + e * m2->mass * v_rel_y) / (m1->mass + m2->mass);\n\t\tdouble v2_final_x = v1_final_x - m1->velocity.first + m2->velocity.first;\n\t\tdouble v2_final_y = v1_final_y - m1->velocity.second + m2->velocity.second;\n\n\t\t// Calculate energy loss\n\t\tdouble E_initial = 0.5 * m1->mass * (m1->velocity.first * m1->velocity.first + m1->velocity.second * m1->velocity.second) + 0.5 * m2->mass * (m2->velocity.first * m2->velocity.first + m2->velocity.second * m2->velocity.second);\n\t\tdouble E_final = 0.5 * (m1->mass + m2->mass) * (v1_final_x * v1_final_x + v1_final_y * v1_final_y + v2_final_x * v2_final_x + v2_final_y * v2_final_y);\n\t\tdouble E_loss = E_initial - E_final;\n\n\t\t// Update velocities\n\t\tm1->velocity = {v1_final_x, v1_final_y};\n\t\tm2->velocity = {v2_final_x, v2_final_y};\n\t\treturn E_loss;\n\n\t} else {\n\t\t// Positions are not the same, no collision\n\t\tcout << \"Error: No collision, positions are different.\" << endl;\n\t\treturn 0;\n\t}\n}");
  fprintf(headerfile, "\n\ndouble collide(mass* m1, mass* m2) {\n\t// Check if positions are the same\n\tif (m1->position == m2->position) {\n\n\t\t// Calculate final velocities and energy loss\n\t\tdouble v1_final_x = (m1->mass * m1->velocity.first + m2->mass * m2->velocity.first) / (m1->mass + m2->mass);\n\t\tdouble v1_final_y = (m1->mass * m1->velocity.second + m2->mass * m2->velocity.second) / (m1->mass + m2->mass);\n\t\tdouble v2_final_x = v1_final_x - m1->velocity.first + m2->velocity.first;\n\t\tdouble v2_final_y = v1_final_y - m1->velocity.second + m2->velocity.second;\n\n\t\t// Calculate energy loss (assuming perfectly elastic collision)\n\t\tdouble E_initial = 0.5 * m1->mass * (m1->velocity.first * m1->velocity.first + m1->velocity.second * m1->velocity.second) + 0.5 * m2->mass * (m2->velocity.first * m2->velocity.first + m2->velocity.second * m2->velocity.second);\n\t\tdouble E_final = 0.5 * (m1->mass + m2->mass) * (v1_final_x * v1_final_x + v1_final_y * v1_final_y + v2_final_x * v2_final_x + v2_final_y * v2_final_y);\n\t\tdouble E_loss = E_initial - E_final;\n\n\t\t// Update velocities\n\t\tm1->velocity = {v1_final_x, v1_final_y};\n\t\tm2->velocity = {v2_final_x, v2_final_y};\n\t\treturn E_loss;\n\n\t} else {\n\t\t// Positions are not the same, no collision\n\t\tcout << \"Error: No collision, positions are different.\" << endl;\n\t\treturn 0;\n\t}\n}");
  fprintf(headerfile, "\n\ndouble dotProduct(pair<double, double> v1, pair<double, double> v2) {\n\treturn v1.first * v2.first + v1.second * v2.second;\n}");
  fprintf(headerfile, "\n\ndouble magnitude(pair<double, double> v) {\n\treturn sqrt(v.first * v.first + v.second * v.second);\n}");
  fprintf(headerfile, "\n\ndouble time_to_collide(mass* m1, mass* m2) {\n\t// Calculate relative position, velocity, and acceleration\n\tpair<double, double> relative_position = {m2->position.first - m1->position.first, m2->position.second - m1->position.second};\n\tpair<double, double> relative_velocity = {m2->velocity.first - m1->velocity.first, m2->velocity.second - m1->velocity.second};\n\tpair<double, double> relative_acceleration = {m2->acceleration.first - m1->acceleration.first, m2->acceleration.second - m1->acceleration.second};\n\n\t// Calculate coefficients for the quadratic equation\n\tdouble a = dotProduct(relative_acceleration, relative_acceleration);\n\tdouble b = 2 * dotProduct(relative_velocity, relative_acceleration);\n\tdouble c = dotProduct(relative_position, relative_position) - (m1->mass + m2->mass) * (m1->mass + m2->mass);\n\n\t// Calculate discriminant\n\tdouble discriminant = b * b - 4 * a * c;\n\tif (discriminant < 0) {\n\t\t// No collision\n\t\tcout << \"Error: No collision, masses will not collide.\" << endl;\n\t\treturn -1;\n\t}\n\n\t// Calculate time to collision using quadratic formula\n\tdouble t1 = (-b + sqrt(discriminant)) / (2 * a);\n\tdouble t2 = (-b - sqrt(discriminant)) / (2 * a);\n\n\t// Choose the positive time (ignore negative time)\n\tdouble time_to_collision = (t1 > 0) ? t1 : t2;\n\treturn time_to_collision;\n}");

  construct_stack();
	int i = yyparse();

  print_table();
  print_function_table();

	if(i) printf("Failure\n");
	else printf("Success\n");

	return 0;
}
