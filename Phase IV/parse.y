%{
#include <bits/stdc++.h>
#include <fstream>
#include "semantics.hpp"

extern FILE *yyin, *tokfile, *parsefile, *outfile, *headerfile, *symbfile ;
extern int yylineno;
int yylex();
void yyerror(char *s);
bool arr_check = false;
int dim_count = 0;
int num_return = 0;
int function_return_type = 0;
int counter = 0;
%}

%union {
	struct variable {
		char* value;
		int type;
    int open_br ;
    int close_br;
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
%token <object> SETR ADDR SETV ADDV SETA ADDA SETP GETR GETA GETV GETM SETM
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



%type <object> rel_to_mass another_temp multiple_output dim_con check_rhs_exp stand_id single_variable_for_exp_stmt single_variable_declare code code_subpart comments startfn function_decl loop_body body exp_stmt call_stmt_with_dot conditional_stmt loop_stmt unary_operation_without_dot return_stmt output_stmt input_stmt inbuilt_functions_with_dot decl_stmt_with_exp bi_op relop vectors primi_datatype non_pri_datatype datatypes single_variable dimensions pos idadd2 anything_with_value operations rhs_exp rhs_term openccs closeccs call_stmt_without_dot conditional_stmt_start ids  rel_to_mag rel_to_vel rel_to_pos rel_to_acc rel_to_energy rel_to_angle  rel_to_collision rel_to_momentum miscellaneous term_misc expression expressions  parameters inbuilt_functions
%type <arg_object> funccallargs
%start code
%%

code: code_subpart
    | code code_subpart
	;

code_subpart: comments {fprintf(parsefile," : comment");}
            | startfn 
            | function_decl 
            ;

startfn : START OPENCU 
          {is_func_bool = true; current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile,"int main() {");fprintf(parsefile," : main function");} 
          body 
           {
            if (valid_func_entry($1.value , par_list)){
              new_func_entry( $1.value, "null", par_list.size(), par_list, var_list);
              add('F',$1.value,"null");
            }
            else{
              cout<< "Error : Redefination of start function at line no " << yylineno <<endl;
            }
            var_list.clear(); 
            par_list.clear();
            }
            CLOSECU 
            {is_func_bool = false;current_pointer--;
            fprintf(outfile,"   return 0;\n}");
            }
        ;

body : exp_stmt {fprintf(parsefile," : expression statement");} body
     | call_stmt_with_dot {fprintf(parsefile," : call statement");} body
     | conditional_stmt body
     | loop_stmt body
     | unary_operation_without_dot DOT { fprintf(parsefile," : call statement"); fprintf(outfile, ";");} body
     | return_stmt {fprintf(parsefile," : return statement");} body
     | comments {fprintf(parsefile," : comment ");} body
     | output_stmt {fprintf(parsefile," : output statement");} body
     | input_stmt {fprintf(parsefile," : input statement");} body
     | {}
     | SCOPEOPEN { current_pointer++;  curr_scopes[current_pointer]++; }OPENCU {fprintf(outfile, "{");fprintf(parsefile," : opening of scope");} body SCOPECLOSE {current_pointer--; }CLOSECU {fprintf(outfile, "}"); fprintf(parsefile," : ending of scope");} body
     | inbuilt_functions_with_dot {fprintf(parsefile," : standard-library");} body
     | decl_stmt_with_exp {fprintf(parsefile," : declaration statement");} body 
     ;

loop_body : exp_stmt {fprintf(parsefile," : expression statement");} loop_body
     | call_stmt_with_dot {fprintf(parsefile," : call statement");} loop_body
     | conditional_stmt loop_body
     | loop_stmt loop_body
     | unary_operation_without_dot DOT {fprintf(outfile, ";"); fprintf(parsefile," : call statement");} loop_body
     | return_stmt {fprintf(parsefile," : return statement");} loop_body
     | comments {fprintf(parsefile," : comment");} loop_body
     | output_stmt {fprintf(parsefile," : output statement");} loop_body
     | input_stmt {fprintf(parsefile," : input statement");} loop_body
     | {}
     | SCOPEOPEN {current_pointer++;  curr_scopes[current_pointer]++; } OPENCU {fprintf(outfile, "{"); fprintf(parsefile," : opening of scope");} loop_body SCOPECLOSE {current_pointer--; } CLOSECU {fprintf(outfile, "}");fprintf(parsefile," : ending of scope");} body
     | inbuilt_functions_with_dot {fprintf(parsefile," : standard-library");} loop_body
     | decl_stmt_with_exp {fprintf(parsefile," : declaration statement");} loop_body 
     | BREAK DOT {fprintf(outfile, "break; ");} loop_body 
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
                cout << "Error : Invalid vector in line no " << yylineno << endl;
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
            
non_pri_datatype: MASS {insert_type($1.value); fprintf(outfile, "Mass");}
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

another_temp : ID { fprintf(outfile,"%s", $1.value); arr_check = true; $1.type = undeclare_check($1.value,convert_scope_to_string())} dimensions 
                {
                  int k;
                  if((k = get_num_dim($1.value,convert_scope_to_string())) != -1 && k != dim_count){
                    cout << "Error : Invalid access of array at line no " << yylineno << endl;
                  } 
                  $$.value = $1.value;
                }
                ;

single_variable : ID { if(1){fprintf(outfile,"%s", $1.value);} arr_check = false;$$.type = undeclare_check($1.value,convert_scope_to_string());}
                | another_temp
                | another_temp ARROW pos {if(($1.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                        cout << "Error : Undeclared variable " << $1.value << " used at line no " << yylineno<< endl;
                      }
                      if($1.type == 5 || $1.type == 6 || $1.type == 7 || $1.type == 8 || $1.type == 9 || $1.type == 10){

                      }
                      else{
                        cout << "Error : " << $1.value << " is not a vector to access first or second at line no " << yylineno << endl;
                      }
                    $$.type = 2;
                    fprintf(outfile, ".%s",$3.value);
                    }
                ;

dim_con : OPENSQ {fprintf(outfile, "[");} ;

dimensions : dim_con check_rhs_exp CLOSESQ {
              fprintf(outfile, "]");
              if($2.type == 1){
                $$.type = 10;
              }
              else{
                cout << "Error : Invalid dimension in line no " << yylineno << endl;
              }
              dim_count++;
              }
           | dim_con check_rhs_exp CLOSESQ {fprintf(outfile, "]");} dimensions{
              if($2.type == 1){
                $$.type = 10;
              }
              else{
                cout << "Error : Invalid dimension in line no " << yylineno << endl;
              }
              dim_count++;
           }
           ;


/* EXPRESSION STATEMENT */

single_variable_for_exp_stmt :  single_variable 
                                {
                                  if(($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                                    cout << "Error : Undeclared variable " << $1.value << " used at line no " << yylineno << endl;
                                  }
                                  $$.type = $1.type;
                                  dim_count = 0;
                                }
                                | ID ARROW pos {fprintf(outfile, "%s.%s",$1.value,$3.value);} {
                                    if(($1.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                                      cout << "Error : Undeclared variable " << $1.value << " used at line no " << yylineno<< endl;
                                    }
                                    if($1.type == 5 || $1.type == 6 || $1.type == 7 || $1.type == 8 || $1.type == 9 || $1.type == 10){

                                    }
                                    else{
                                      cout << "Error : " << $1.value << " is not a vector to access first or second at line no " << yylineno << endl;
                                    }
                                    $$.type = 2;
                                  }
                                  ;
                                

exp_stmt : single_variable_for_exp_stmt ASSGN { fprintf(outfile, "=");} check_rhs_exp DOT {fprintf(outfile, ";");} 
          {if(!type_checking_assign($1.type,$4.type)){
            cout << "Error : Expression statement types not compatible at line no " << yylineno << endl;
          }
          }
         ;

pos : FIRST
    | SECOND
    ;

anything_with_value : single_variable {if(undeclare_check($1.value,convert_scope_to_string()) == 0){
    cout << "Error : Undeclared variable " << $1.value << " used at line no " << yylineno<< endl;
  }
  $$.type = $1.type;
  dim_count = 0;}
                    | NON_NEGATIVE_INT {fprintf(outfile, "%s", $1.value);}
                    | INTEGER_CONSTANT {fprintf(outfile, "%s", $1.value);}
                    | FLOAT_CONSTANT {fprintf(outfile, "%s", $1.value);}
                    | STRING_CONSTANT {fprintf(outfile, "%s", $1.value);}
                    | TRUE {fprintf(outfile, "%s", $1.value); $$.type = $1.type;}
                    | FALSE {fprintf(outfile, "%s", $1.value); $$.type = $1.type;}
                    | call_stmt_without_dot
                    | vectors {$$.type = 10;}
                    | UNINEG {fprintf(outfile, "!");}anything_with_value {$$.type = 4;}
                    | call_stmt_without_dot ARROW pos {fprintf(outfile, ".%s",$3.value);}{if($1.type != 5 && $1.type != 6 && $1.type != 7 && $1.type != 8 && $1.type != 9 && $1.type != 10){
                      cout << "Error : Return type is not a vector at line no " << yylineno << endl;
                    }
                    $$.type = 2;}
                    | inbuilt_functions ARROW pos {fprintf(outfile, ".%s",$3.value); $$.type = 2;}
                    | inbuilt_functions
                    | vectors ARROW pos {fprintf(outfile, ".%s",$3.value); $$.type = 2;}
                    | ID ARROW pos {fprintf(outfile, "%s.%s",$1.value,$3.value);} {
                      if(($1.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                        cout << "Error : Undeclared variable " << $1.value << " used at line no " << yylineno<< endl;
                      }
                      if($1.type == 5 || $1.type == 6 || $1.type == 7 || $1.type == 8 || $1.type == 9 || $1.type == 10){

                      }
                      else{
                        cout << "Error : " << $1.value << "1 is not a vector to access first or second at line no " << yylineno << endl;
                      }
                      $$.type = 2;
                    }
                    | single_variable UNIOP {if(($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0){
                        cout << "Error : Undeclared variable " << $1.value << " used at line no " << yylineno<< endl;
                      }}
                    | SIN OPENCC {counter = 1;fprintf(outfile,"sin_val(");} anything_with_value {counter = 0;}CLOSECC {
                      fprintf(outfile,")");
                      $$.type = 2;
                      if($4.type != 1 && $4.type != 2 && $4.type != 14){cout << "Error : Sin input is out of range at line no " << yylineno << endl;}
                      $$.type = 2;
                    }
                    | COS OPENCC {counter = 1;fprintf(outfile,"cos_val(");} anything_with_value {counter = 0;}CLOSECC {
                      fprintf(outfile,")");
                      $$.type = 2;
                      if($4.type != 1 && $4.type != 2 && $4.type != 14){cout << "Error : Cos input is out of range at line no " << yylineno << endl;}
                        $$.type = 2;
                      }
                    | TAN OPENCC {counter = 1;fprintf(outfile,"tan_val(");}anything_with_value {counter = 0;} CLOSECC {
                      fprintf(outfile,")");
                      $$.type = 2;
                      if($4.type != 1 && $4.type != 2 && $4.type != 14){cout << "Error : Tan input is out of range at line no " << yylineno << endl;}
                      $$.type = 2;
                      }
                    ;
        
operations : bi_op 
           | LOGICOP {fprintf(outfile, "%s", strcat($1.value,$1.value));}
           | relop
           ;

rhs_term : openccs anything_with_value {$$.type = $2.type;$$.open_br = $1.open_br;}
         | openccs anything_with_value closeccs {$$.type = $2.type;$$.open_br = $1.open_br;$$.close_br = $3.close_br;}
         | anything_with_value closeccs {$$.type = $1.type;$$.close_br = $2.close_br;}
         ;

rhs_exp : rhs_term operations rhs_exp {
            $$.open_br = $1.open_br + $3.open_br;
            $$.close_br = $1.close_br + $3.close_br;
            $$.type = give_result_type($1.type,$2.value,$3.type); 
            if($$.type == -1){cout << "Error : Invalid operation in rhs side at line no " << yylineno << endl;}}
        | anything_with_value operations rhs_exp {
          $$.open_br = $1.open_br + $3.open_br;
          $$.close_br = $1.close_br + $3.close_br;
          $$.type = give_result_type($1.type,$2.value,$3.type); 
          if($$.type == -1){cout << "Error : Invalid operation in rhs side at line no " << yylineno  << endl;}}
        | rhs_term {$$.type = $1.type}
        | anything_with_value {$$.type = $1.type}
        ;

openccs : openccs OPENCC {open_brackets = open_brackets + 1; fprintf(outfile, "(");$$.open_br = $1.open_br + 1;} 
        | OPENCC {open_brackets = open_brackets + 1; fprintf(outfile, "("); $$.open_br = 1;} 
        ;

closeccs : closeccs CLOSECC {close_brackets = close_brackets + 1; fprintf(outfile, ")");$$.close_br = $1.close_br + 1;}
         | CLOSECC {close_brackets = close_brackets + 1; fprintf(outfile, ")"); $$.close_br = 1;} 
         ;

/* CALL STATEMENT WITH DOT */

call_stmt_with_dot : call_stmt_without_dot DOT {fprintf(outfile, ";");} 
                   ;

call_stmt_without_dot : ID OPENCU CLOSECU 
                      {
                        char* templist[100];
                        int temp = 0;
                        if(!check_func_args($1.value,templist,temp )){
                          cout << "Error : Undeclared function " << $1.value <<" at line no " << yylineno  << endl;
                        }
                        func_args_list.clear();
                        $$.type = find_return_type($1.value,templist,temp);
                        fprintf(outfile, "%s()", $1.value);
                      }
	                  | ID OPENCU  {fprintf(outfile, "%s(",$1.value);} funccallargs CLOSECU 
                      {
                          if(!check_func_args($1.value, $4.list,$4.present)){
                            cout << "Error : Undeclared function " << $1.value <<" at line no " << yylineno  << endl;
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

conditional_stmt_start : OPENSQ {fprintf(outfile, "if(");} check_rhs_exp CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "){"); fprintf(parsefile," : conditional statement");}
                      ;


conditional_stmt: conditional_stmt_start loop_body CLOSECU {current_pointer--; fprintf(outfile, "\n}\n");} 
                | conditional_stmt_start loop_body CLOSECU {current_pointer--; } OTHERWISE OPENCU { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "}\n\telse {");} loop_body  CLOSECU {current_pointer--; fprintf(outfile, "}");}
                ;

/* LOOP STATEMENT */
      
loop_stmt: LOOP OPENSQ {fprintf(outfile, "while(");} check_rhs_exp CLOSESQ OPENCU { current_pointer++;  curr_scopes[current_pointer]++; fprintf(outfile, "){"); {fprintf(parsefile," : loop statement");}} loop_body CLOSECU {current_pointer--; fprintf(outfile, "}");} 
         ; 

/* UNIRARY OPERATION WITHOUT DOT */

unary_operation_without_dot: single_variable UNIOP {
                              fprintf(outfile, "%s", $2.value);
                              if (($$.type = undeclare_check($1.value,convert_scope_to_string())) == 0) cout << "Error : Undeclaration error at line no " << yylineno << endl;
                              if($1.type != 1 && $1.type != 2){
                                cout << "Error : Cant perform unary operation on this type (only int or float) at line no " << yylineno<< endl;
                              }
                              $$.type = $1.type;
                              }
                           | UNINEG {fprintf(outfile, " !");} check_rhs_exp {
                            $$.type = 4;
                            if ($3.type != 1 && $3.type !=2 && $3.type != 4){
                              cout << "Error : Invalid negation operation at line no " << yylineno<< endl;
                            }
                           }
                           ;

/* RETURN STATEMENT */
    
return_stmt: DARR {fprintf(outfile, "return ");}  check_rhs_exp DOT {fprintf(outfile, ";"); num_return ++;if(type_checking_assign($3.type,function_return_type) == 0){
  cout << "Error : type doesnot match with function defined return type at line no " << yylineno << endl;
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
     
output_stmt : OUTPUT COLON {fprintf(outfile, "cout << ");} multiple_output DOT {fprintf(outfile, "<< endl;");} 
            ;

/* INPUT STATEMENT */
     
input_stmt : INPUT COLON {fprintf(outfile, "cin >>");} ids DOT {fprintf(outfile, ";");} 
           ;

ids : single_variable {if(undeclare_check($1.value,convert_scope_to_string()) == 0){
                          cout << "Error : Undeclared variable used at line no " << yylineno << endl;
                        }}COMMA {fprintf(outfile, ">>");} ids
    | single_variable {if(undeclare_check($1.value,convert_scope_to_string()) == 0){
                          cout << "Error : Undeclared variable used at line no " << yylineno << endl;
                        }}
    ;

/* INBUILT STATEMENT */

inbuilt_functions_with_dot : inbuilt_functions DOT {fprintf(outfile, ";");} 
                           ;
     
inbuilt_functions : rel_to_mag
                  | rel_to_mass
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
                          cout << "Error : Undeclared variable used at line no " << yylineno << endl;
                        }
                if($$.type != 11){
                  cout << "Error : Indentifier is of not mass datatype at line no " << yylineno << endl; 
                }
              }
              ;

rel_to_mag : MAG OPENCU {fprintf(outfile, "mag(");}check_rhs_exp CLOSECU {
              $$.type = 2;
              if(!std_lib_semantics($1.value,0,{$4.type})){
                cout<<"Invalid use of std-lib : mag at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
          
           ;

rel_to_mass : OPENCU stand_id CLOSECU SETM {fprintf(outfile, "setm(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
  
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : setm at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
            | OPENCU stand_id CLOSECU GETM {
              $$.type = 2;
              if(!std_lib_semantics($4.value,$2.type,{})){
                cout<<"Invalid use of std-lib : get_m at line no " << yylineno<<endl;
              }
              fprintf(outfile, "getm(&%s)",$2.value);
            }
           ;
          

rel_to_pos : OPENCU stand_id CLOSECU SETR {fprintf(outfile, "setr(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
  
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : setr at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
           | OPENCU stand_id CLOSECU ADDR {fprintf(outfile, "addr(&%s,", $2.value);}OPENCU check_rhs_exp CLOSECU {
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : addr at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
           | OPENCU stand_id CLOSECU R_AFTER {fprintf(outfile, "r_after(&%s,", $2.value);}OPENCU check_rhs_exp CLOSECU {
              $$.type = 6; 
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : r_after at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
           | OPENCU stand_id CLOSECU GETR {
              $$.type = 6;
              if(!std_lib_semantics($4.value,$2.type,{})){
                cout<<"Invalid use of std-lib : get_r at line no " << yylineno<<endl;
              }
              fprintf(outfile, "getr(&%s)",$2.value);
            }
           ;

rel_to_vel : OPENCU stand_id CLOSECU SETV {fprintf(outfile, "setv(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : setv at line no " << yylineno<<endl;
            }
            fprintf(outfile, ")");
          }
           | OPENCU stand_id CLOSECU ADDV {fprintf(outfile, "addv(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : addv at line no " << yylineno<<endl;
            }
            fprintf(outfile, ")");
          }
           | OPENCU stand_id CLOSECU V_AFTER {fprintf(outfile, "v_after(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
            $$.type = 5; 
            if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : v_after at line no " << yylineno<<endl;
            }
            fprintf(outfile, ")");
          }
           | OPENCU stand_id CLOSECU GETV {
            $$.type = 5;
            if(!std_lib_semantics($4.value,$2.type,{})){
                cout<<"Invalid use of std-lib : get_v at line no " << yylineno<<endl;
            }
            fprintf(outfile, "getv(&%s)",$2.value);
          }
           ; 

rel_to_momentum : OPENCU stand_id CLOSECU SETP {fprintf(outfile, "setp(&%s,",$2.value);} OPENCU check_rhs_exp CLOSECU {if($7.type != 9 && $7.type != 10){
  cout << "Error : Invalid statement at line no at line no " << yylineno<<endl;
}
  fprintf(outfile, ")");}
                ;

rel_to_acc : OPENCU stand_id CLOSECU SETA {fprintf(outfile, "seta(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : seta at line no " << yylineno<<endl;
            }
            fprintf(outfile, ")");
          }
           | OPENCU stand_id CLOSECU ADDA {fprintf(outfile, "adda(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
            if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : adda at line no " << yylineno<<endl;
            }
            fprintf(outfile, ")");
          }
           | OPENCU stand_id CLOSECU GETA {
            $$.type = 7;
            if(!std_lib_semantics($4.value,$2.type,{})){
                cout<<"Invalid use of std-lib : get_a at line no " << yylineno<<endl;
            }
            fprintf(outfile, "geta(&%s)",$2.value);
          }
           ;

rel_to_energy: OPENCU stand_id CLOSECU KE_AFTER {fprintf(outfile, "keafter(&%s,",$2.value);} OPENCU check_rhs_exp CLOSECU {
              $$.type = 13 ;
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : KE AFTER at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
             | OPENCU stand_id CLOSECU PE_AFTER {fprintf(outfile, "peafter(&%s,",$2.value);} OPENCU check_rhs_exp CLOSECU {
              $$.type = 13 ;
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : PE AFTER at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
             | OPENCU stand_id CLOSECU TE_AFTER {fprintf(outfile, "teafter(&%s,",$2.value);} OPENCU check_rhs_exp CLOSECU {
              $$.type = 13 ;
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : TE AFTER at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
             ;

rel_to_angle: OPENCU stand_id CLOSECU ANGLE_AFTER {{fprintf(outfile, "angleafter(&%s,",$2.value);}} OPENCU check_rhs_exp CLOSECU {
            $$.type = 14;
            if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                cout<<"Invalid use of std-lib : angle() at line no " << yylineno<<endl;
              }
              fprintf(outfile, ")");
            }
            ;

rel_to_collision: OPENCU stand_id CLOSECU COLLIDE OPENCU stand_id COMMA ID {fprintf(outfile, "collide(&%s,&%s,%s)", $2.value, $6.value,$8.value);} CLOSECU {
                $$.type = 13;

                  if(!std_lib_semantics($4.value,$2.type,{$6.type,$8.type})){
                  cout<<"Invalid use of std-lib : collide with e at line no " << yylineno<<endl;
                  }
                }
                | OPENCU stand_id CLOSECU COLLIDE  OPENCU stand_id CLOSECU {
                  $$.type = 13;
                  if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : collide without e at line no " << yylineno<<endl;
                  }
                  {fprintf(outfile, "collide(&%s,&%s)", $2.value, $6.value);}
                }
                | OPENCU stand_id CLOSECU TIME_TO_COLLIDE {fprintf(outfile, "time_to_collide(&%s,", $2.value);}OPENCU stand_id CLOSECU {
                  $$.type = 12 ;
                  if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                  cout<<"Invalid use of std-lib : time to collide at line no " << yylineno<<endl;
                  }
                  fprintf(outfile, "&%s)", $7.value);
                }
                ;
extra : OPENCU stand_id CLOSECU TIME_TO_R OPENCU {fprintf(outfile, "time_to_r(&%s,", $2.value);}
extra2: OPENCU stand_id CLOSECU TIME_TO_V OPENCU {fprintf(outfile, "time_to_v(&%s,", $2.value);}  

miscellaneous: OPENCU stand_id CLOSECU S_AFTER {fprintf(outfile, "s_after(&%s,", $2.value);}OPENCU check_rhs_exp CLOSECU {
              $$.type = 8; 
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                  cout<<"Invalid use of std-lib : s_after at line no " << yylineno<<endl;
                }
                fprintf(outfile, ")");
              }
             | OPENCU stand_id CLOSECU ROC_AFTER {fprintf(outfile, "roc_after(&%s,", $2.value);}OPENCU check_rhs_exp CLOSECU {
              $$.type = 2; 
              if(!std_lib_semantics($4.value,$2.type,{$7.type})){
                  cout<<"Invalid use of std-lib : roc_after(time) at line no " << yylineno<<endl;
                }
                fprintf(outfile, ")");
              }
             | OPENCU stand_id CLOSECU P_AFTER {fprintf(outfile, "p_after(&%s,", $2.value);} OPENCU check_rhs_exp CLOSECU {
              $$.type = 9;
              if(!std_lib_semantics($4.value,$2.type,{$6.type})){
                  cout<<"Invalid use of std-lib : p_after(time) at line no " << yylineno<<endl;
                }
                fprintf(outfile, ")");
              }
             | extra term_misc COMMA {fprintf(outfile, ",");} term_misc CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics("time_to_r",11,{$2.type,$5.type})){
                  cout<<"Invalid use of std-lib : time_to_r() at line no " << yylineno<<endl;
                }
                fprintf(outfile, ")");
              }
             | extra check_rhs_exp CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics("time_to_r",11,{$2.type})){
                  cout<<"Invalid use of std-lib : time_to_r() at line no " << yylineno<<endl;
                }
                fprintf(outfile, ")");
              }

             | extra2 term_misc COMMA  {fprintf(outfile, ",");} term_misc CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics("time_to_v",11,{$2.type,$5.type})){
                  cout<<"Invalid use of std-lib : time_to_v() at line no " << yylineno<<endl;
                }
                fprintf(outfile, ")");
              }

             | extra2 check_rhs_exp CLOSECU {
              $$.type = 12;
              if(!std_lib_semantics("time_to_v",11,{$2.type})){
                  cout<<"Invalid use of std-lib : time_to_v() at line no " << yylineno<<endl;
                }
                fprintf(outfile, ")");
              }
             ; 

term_misc : check_rhs_exp {if($1.type != 1 && $1.type != 2){
  cout << "Error : Invalid statement at line no " << yylineno << endl;
}}
          | QUESTION {fprintf(outfile, "\"?\"");}
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
;

check_rhs_exp : {open_brackets = 0;close_brackets = 0;} rhs_exp {if($2.open_br != $2.close_br){cout << "Error : Incorrect RHS expression at line no " << yylineno << endl;}open_brackets = 0;close_brackets = 0;$$.type = $2.type;$$.value = $2.value;}

expression : single_variable_declare ASSGN {fprintf(outfile, "=");} check_rhs_exp { if(!type_checking_assign($1.type,$4.type)){cout << "Error : Declaration with expression type error at line no " << yylineno << endl;}}
           | single_variable_declare 
            ;

/* FUNCTION DECLARATION */

idadd2 : ID {is_func_bool = true;
        if(!func_red_var($1.value)){cout << "Error :  Function is redeclared as variable name at line no " << yylineno << endl;}
        fprintf(outfile,"%s", $1.value);
        }
       ;

function_decl : datatypes idadd2 ASSGN OPENCU {fprintf(outfile,"(");function_return_type = give_type_index($1.value);} parameters CLOSECU {fprintf(outfile,")");} DARR OPENCU {fprintf(outfile,"{"); fprintf(parsefile," : function declaration");}
{current_pointer++;  curr_scopes[current_pointer]++;if (valid_func_entry($2.value , par_list)){
                    new_func_entry( $2.value, $1.value, par_list.size(), par_list, var_list);
                    add('F',$2.value,$1.value);
                  }
                  else{
                     cout<< "Error : Function redefinition at line no " << yylineno<<endl;
                  }
                   }body
                   {
                    insert_var_list($2.value,par_list,var_list);
                    var_list.clear();
                    par_list.clear();
                   }
                CLOSECU {is_func_bool = false;current_pointer--; fprintf(outfile,"}"); if(num_return  == 0){
                  cout << "Error : No return statement" << endl;
                }
                num_return  = 0;
                }
                
                | datatypes idadd2 ASSGN OPENCU CLOSECU DARR OPENCU {fprintf(outfile,"(){");function_return_type = give_type_index($1.value);fprintf(parsefile," : function declaration");} {current_pointer++;  curr_scopes[current_pointer]++;
                if (valid_func_entry($2.value , par_list)){
                      new_func_entry( $2.value, $1.value, par_list.size(), par_list, var_list);
                      add('F',$2.value,$1.value);
                    }
                    else{
                      cout<< "Error : Function redefinition at line no " << yylineno<<endl;
                  }
                  }body {
                    insert_var_list($2.value,par_list,var_list);
                    var_list.clear();
                    par_list.clear();
                  }
                CLOSECU {is_func_bool = false;current_pointer--;
                fprintf(outfile,"}");
                if(num_return  == 0){
                  cout << "Error : No return statement" << endl;
                }
                num_return  = 0;
                }
              ;

parameters: datatypes ID {fprintf(outfile,"%s", $2.value);}
        {
          if(!within_func_parameters_redeclaration($2.value)) cout << "Error : Redeclaration of parameters in the function at line no " << yylineno << endl;
            par_records* rec = new par_records;
						rec->name = $2.value;
						rec->type = type;
            par_list.push_back(rec);
        }
          | datatypes ID 
          {
          if(!within_func_parameters_redeclaration($2.value)) cout << "Error : Redeclaration of parameters in the function atline no  " << yylineno << endl;
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
  char inp_file[100],tok[100],parse[100],out_file[100],symb[100], header_file[100];

  sprintf(inp_file,"inp.phic");
  sprintf(out_file,"output.cpp");
  sprintf(header_file,"std_lib.h");
  sprintf(tok, "tokenfile.txt");
  sprintf(parse, "parsefile.txt");
  sprintf(symb, "symbol_table.txt");

  yyin = fopen(inp_file,"r");

  tokfile = fopen(tok,"w");
  parsefile = fopen(parse,"w");
  symbfile = fopen(symb, "w"); 
  /* ofstream fout("symbol_table.txt"); */
  /* symbfile */

  outfile = fopen(out_file,"w");
  fprintf(outfile,"#include <bits/stdc++.h> \n#include \"std_lib.h\"\nusing namespace std;\n\n");

  headerfile = fopen(header_file, "w");
  fprintf(headerfile, "#include <bits/stdc++.h>\nusing namespace std; \n\nclass Mass{\npublic:\n\tdouble mass;\n\tpair<double,double> position;\n\tpair<double,double> velocity;\n\tpair<double,double> acceleration;\n\n\tMass(int initialMass = 1) {\n\t\tmass = initialMass;\n\t\tposition.first = 0.0;\n\t\tposition.second = 0.0;\n\t\tvelocity.first = 0.0;\n\t\tvelocity.second = 0.0;\n\t\tacceleration.first = 0.0;\n\t\tacceleration.second = 0.0;\n\t}\n};\n");
  fprintf(headerfile, "\n\nbool equal_double(double val1,double val2){\n\tif(abs(val1 - val2) < 0.01) return true;\n\treturn false;\n}");
  fprintf(headerfile, "\n\ndouble check_r(double r,double s,double v,double acc){\n\tdouble time;\n\n\t// r = s + v*t + 0.5*acc*t*t;\n\t// Calculate the coefficients for the quadratic equation\n\tdouble a = 0.5*acc;\n\tdouble b = v;\n\tdouble c = s;\n\n\t\n\tif(a == 0 && v != 0 ){\n\t\treturn (r-s)/v;\n\t}else if(a == 0){\n\t\tif(v==0 && (equal_double(r,s))) return 0;\n\t\treturn -1;\n\t}\n\t// Calculate the discriminant\n\tdouble discriminant = b*b - 4*a*c;\n\tif(discriminant < 0){\n\t\tcout << \"Error: Mass cannot reach the specified position.\" << endl;\n\treturn -1;\n\t} \n\n\t// Calculate the time using the quadratic formula\n\tdouble t1 = (-b + sqrt(discriminant)) / (2 * a);\n\tdouble t2 = (-b - sqrt(discriminant)) / (2 * a);\n\n\t// Choose the positive time (ignore negative time)\n\tdouble time_to_reach = (t2 > 0) ? t2 : t1;\n\tif(time_to_reach < 0) return -1;\n\treturn time_to_reach;\n}");
  fprintf(headerfile, "\n\nvoid setm(Mass* m, double r){\n\tm->mass = r;\n}\n\ndouble getm(Mass* m){\n\treturn m->mass;\n}");
  fprintf(headerfile, "\n\n// Related to Magnitude\n\ndouble mag(pair<double,double> vec){\n\tdouble vecx = vec.first;\n\tdouble vecy = vec.second;\n\tdouble magnitude = sqrt(vecx * vecx + vecy * vecy);\n\treturn magnitude;\n}");
  fprintf(headerfile, "\n\n\n// Related to Position\n\nvoid setr(Mass* m, pair<double,double> r){\n\tm->position = r;\n}\n\nvoid addr(Mass* m, pair<double,double> r){\n\tm->position.first = m->position.first + r.first;\n\tm->position.second = m->position.second + r.second;\n}\npair<double,double> r_after(Mass* m, double t){\n\tpair<double,double> temp;\n\ttemp.first = m->position.first + m->velocity.first*t + 0.5*m->acceleration.first*t*t;\n\ttemp.second = m->position.second + m->velocity.second*t + 0.5*m->acceleration.second*t*t;\n\treturn temp;\n}\n\npair<double,double> getr(Mass* m){\n\treturn m->position;\n}");
  fprintf(headerfile, "\n\n\n// Related to velocity\n\nvoid setv(Mass* m, pair<double,double> vec){\n\tm->velocity = vec;\n}\n\nvoid addv(Mass* m, pair<double,double> v){\n\tm->velocity.first = m->velocity.first + v.first;\n\tm->velocity.second = m->velocity.second + v.second;\n}\n\npair<double,double> v_after(Mass* m, double t){\n\tpair<double,double> temp;\n\ttemp.first = m->velocity.first + m->acceleration.first*t;\n\ttemp.second = m->velocity.second + m->acceleration.second*t;\n\treturn temp;\n}\n\npair<double,double> v_after(Mass* m,  pair<double,double> r){\n\tpair<double,double> temp;\n\ttemp.first = sqrt(pow(m->velocity.first, 2) + 2 * m->acceleration.first * r.first);\n\ttemp.second = sqrt(pow(m->velocity.second, 2) + 2 * m->acceleration.second * r.second);\n\treturn temp;\n}\n\npair<double,double> getv(Mass* m){\n\treturn m->velocity;\n}");
  fprintf(headerfile, "\n\n\n// Related to accerlation\n\nvoid seta(Mass* m, pair<double,double> vec){\n\tm->acceleration = vec;\n}\n\nvoid adda(Mass* m, pair<double,double> a){\n\tm->acceleration.first = m->acceleration.first + a.first;\n\tm->acceleration.second = m->acceleration.second + a.second;\n}\n\npair<double,double> geta(Mass* m){\n\treturn m->acceleration;\n}"); 
  fprintf(headerfile, "\n\n\n// Related to energy\n\ndouble keafter(Mass* m,double time){\n\tpair<double,double> vel = v_after(m,time);\n\tdouble mag_value = mag(vel);\n\treturn 0.5*m->mass*mag_value*mag_value;\n}   \n\ndouble peafter(Mass* m,double time){\n\tpair<double,double> pos = r_after(m,time);\n\tpair<double,double> acc = geta(m);\n\treturn m->mass*acc.second*pos.second + m->mass*acc.first*pos.first;\n}\n\n\ndouble teafter(Mass* m,double time){\n\treturn keafter(m,time) + peafter(m,time);\n}\n");
  fprintf(headerfile, "\n\n\n// Related to angle\n\ndouble angleafter(Mass* m,double time){\n\tpair<double,double> vel = v_after(m,time);\n\tif(vel.first == 0){\n\t\treturn 0;\n\t}\n\telse{\n\t\treturn atan2(vel.second,vel.first);\n\t}\n}");
  fprintf(headerfile, "\n\n\n// Related to momentum\n\nvoid setp(Mass* m ,pair<double,double> p){\n\tm->velocity.first = p.first / m->mass;\n\tm->velocity.second = p.second / m->mass;\n}");
  fprintf(headerfile, "\n\n\n// Related to Collision\n\ndouble collide(Mass* m1, Mass* m2, double e) {\n\t// Check if positions are the same\n\tif (equal_double(m1->position.first,m2->position.first) && equal_double(m1->position.second,m2->position.second)) {\n\t\t// Calculate relative velocity\n\t\tdouble v_rel_x = m2->velocity.first - m1->velocity.first;\n\t\tdouble v_rel_y = m2->velocity.second - m1->velocity.second;\n\n\t\t// Calculate final velocities using coefficient of restitution\n\t\tdouble v1_final_x = (m1->mass * m1->velocity.first + m2->mass * m2->velocity.first + e * m2->mass * v_rel_x) / (m1->mass + m2->mass);\n\t\tdouble v1_final_y = (m1->mass * m1->velocity.second + m2->mass * m2->velocity.second + e * m2->mass * v_rel_y) / (m1->mass + m2->mass);\n\t\tdouble v2_final_x = v1_final_x - m1->velocity.first + m2->velocity.first;\n\t\tdouble v2_final_y = v1_final_y - m1->velocity.second + m2->velocity.second;\n\n\t\t// Calculate energy loss\n\t\tdouble E_initial = 0.5 * m1->mass * (m1->velocity.first * m1->velocity.first + m1->velocity.second * m1->velocity.second) + 0.5 * m2->mass * (m2->velocity.first * m2->velocity.first + m2->velocity.second * m2->velocity.second);\n\t\tdouble E_final = 0.5 * (m1->mass + m2->mass) * (v1_final_x * v1_final_x + v1_final_y * v1_final_y + v2_final_x * v2_final_x + v2_final_y * v2_final_y);\n\t\tdouble E_loss = E_initial - E_final;\n\n\t\t// Update velocities\n\t\tm1->velocity = {v1_final_x, v1_final_y};\n\t\tm2->velocity = {v2_final_x, v2_final_y};\n\t\treturn E_loss;\n\n\t} else {\n\t\t// Positions are not the same, no collision\n\t\tcout << \"Error: No collision, positions are different.\" << endl;\n\t\treturn 0;\n\t}\n}");
  fprintf(headerfile, "\n\ndouble collide(Mass* m1, Mass* m2) {\n\t// Check if positions are the same\n\tif (equal_double(m1->position.first,m2->position.first) && equal_double(m1->position.second,m2->position.second)) {\n\n\t\t// Calculate final velocities and energy loss\n\t\tdouble v1_final_x = (m1->mass * m1->velocity.first + m2->mass * m2->velocity.first) / (m1->mass + m2->mass);\n\t\tdouble v1_final_y = (m1->mass * m1->velocity.second + m2->mass * m2->velocity.second) / (m1->mass + m2->mass);\n\t\tdouble v2_final_x = v1_final_x - m1->velocity.first + m2->velocity.first;\n\t\tdouble v2_final_y = v1_final_y - m1->velocity.second + m2->velocity.second;\n\n\t\t// Calculate energy loss (assuming perfectly elastic collision)\n\t\tdouble E_initial = 0.5 * m1->mass * (m1->velocity.first * m1->velocity.first + m1->velocity.second * m1->velocity.second) + 0.5 * m2->mass * (m2->velocity.first * m2->velocity.first + m2->velocity.second * m2->velocity.second);\n\t\tdouble E_final = 0.5 * (m1->mass + m2->mass) * (v1_final_x * v1_final_x + v1_final_y * v1_final_y + v2_final_x * v2_final_x + v2_final_y * v2_final_y);\n\t\tdouble E_loss = E_initial - E_final;\n\n\t\t// Update velocities\n\t\tm1->velocity = {v1_final_x, v1_final_y};\n\t\tm2->velocity = {v2_final_x, v2_final_y};\n\t\treturn E_loss;\n\n\t} else {\n\t\t// Positions are not the same, no collision\n\t\tcout << \"Error: No collision, positions are different.\" << endl;\n\t\treturn 0;\n\t}\n}");
  fprintf(headerfile, "\n\ndouble dotProduct(pair<double, double> v1, pair<double, double> v2) {\n\treturn v1.first * v2.first + v1.second * v2.second;\n}");
  fprintf(headerfile, "\n\ndouble magnitude(pair<double, double> v) {\n\treturn sqrt(v.first * v.first + v.second * v.second);\n}");
  fprintf(headerfile, "\n\ndouble time_to_collide(Mass* m1, Mass* m2) {\n\t// Calculate relative position, velocity, and acceleration\n\tpair<double, double> relative_position = {m2->position.first - m1->position.first, m2->position.second - m1->position.second};\n\tpair<double, double> relative_velocity = {m2->velocity.first - m1->velocity.first, m2->velocity.second - m1->velocity.second};\n\tpair<double, double> relative_acceleration = {m2->acceleration.first - m1->acceleration.first, m2->acceleration.second - m1->acceleration.second};\n\tdouble along_x = check_r(0,relative_position.first,relative_velocity.first,relative_acceleration.first);\n\tdouble along_y = check_r(0,relative_position.second,relative_velocity.second,relative_acceleration.second);\n\tif((equal_double(along_x,along_y)) && (along_x != -1)) return along_x;\n\tif(along_y == 0) return along_x;\n\telse if(along_x == 0) return along_y;\n\treturn -1;\n}");
  fprintf(headerfile, "\n\n\n// DISTANCE AFTER TIME t.\n\npair<double, double> s_after(Mass* m, double t) {\n\t// Calculate the new position using the kinematic equation\n\tdouble s_x = m->position.first + m->velocity.first * t + 0.5 * m->acceleration.first * t * t;\n\tdouble s_y = m->position.second + m->velocity.second * t + 0.5 * m->acceleration.second * t * t;\n\treturn {s_x, s_y};\n}");
  fprintf(headerfile, "\n\n\n// RADIUS OF CURVATURE\n\ndouble roc_after(Mass* m, double t) {\n\n\t// Calculate the new position using the kinematic equation\n\tdouble s_x = m->position.first + m->velocity.first * t + 0.5 * m->acceleration.first * t * t;\n\tdouble s_y = m->position.second + m->velocity.second * t + 0.5 * m->acceleration.second * t * t;\n\n\t// Calculate the new velocity using the kinematic equation\n\tdouble v_x = m->velocity.first + m->acceleration.first * t;\n\tdouble v_y = m->velocity.second + m->acceleration.second * t;\n\n\t// Calculate the magnitude of velocity\n\tdouble v_magnitude = sqrt(v_x * v_x + v_y * v_y);\n\n\t// Check if the magnitude of velocity is non-zero to avoid division by zero\n\tif (v_magnitude != 0) {\n\t\t// Calculate the radius of curvature using the formula: roc = v_magnitude / |acceleration perpendicular to velocity|\n\t\t\n\t\tdouble acc =  sqrt(m->acceleration.first * m->acceleration.first + m->acceleration.second * m->acceleration.second);\n\t\tif(acc == 0) return INT_MAX;\n\t\tdouble roc = v_magnitude / sqrt(m->acceleration.first * m->acceleration.first + m->acceleration.second * m->acceleration.second);\n\t\treturn roc;\n\t} else {\n\t\t// Velocity magnitude is zero, so the radius of curvature is infinite\n\t\treturn 0;\n\t}\n}");
  fprintf(headerfile, "\n\n\n// Momentum for m in time t\n\npair<double, double> p_after(Mass* m, double t) {\n\t// Calculate the new velocity using the kinematic equation\n\tdouble v_x = m->velocity.first + m->acceleration.first * t;\n\tdouble v_y = m->velocity.second + m->acceleration.second * t;\n\n\t// Calculate the momentum after time t\n\tdouble p_x = m->mass * v_x;\n\tdouble p_y = m->mass * v_y;\n\treturn {p_x, p_y};\n}");
  fprintf(headerfile, "\n\n// time taken for reach position r\n\ndouble time_to_r(Mass* m, pair<double, double> r) {\n\t\tdouble along_x = check_r(r.first,m->position.first,m->velocity.first,m->acceleration.first);\n\t\tdouble along_y = check_r(r.second,m->position.second,m->velocity.second,m->acceleration.second);\n\t\tif((equal_double(along_x,along_y)) && (along_x != -1)) return along_x;\n\treturn -1;\n}\n\ndouble time_to_r(Mass* m, double r1, string r2) {\n\tif(r2 == \"?\"){\n\t\tdouble pos = r1;\n\t\tdouble time = check_r(pos,m->position.first,m->velocity.first,m->acceleration.first);\n\t\tif(time < 0) return -1;\n\t\treturn time;\n\t}\n\treturn -1;\n}\n\ndouble time_to_r(Mass* m, string r1, double r2) {\n\tif(r1 == \"?\"){\n\t\tdouble pos = r2;\n\t\tdouble time = check_r(pos,m->position.second,m->velocity.second,m->acceleration.second);\n\t\tif(time < 0) return -1;\n\t\treturn time;\n\t}\n\treturn -1;\n}");
  fprintf(headerfile, "\n\ndouble check_v(double v,double v_old,double acc){\n\tdouble time;\n\t// v = u + a*t\n\t// Linear equation.\n\t\n\tif(acc == 0) return -1;\n\ttime = (v-v_old)/acc;\n\tif(time < 0) return -1;\n\treturn time;\n}");
  fprintf(headerfile, "\n\n\n// TIME TAKEN TO ACQUIRE velocity v.\n\ndouble time_to_v(Mass* m, double v1, string v2) {\n\tif(v2 == \"?\"){\n\t\tdouble vel = v1;\n\t\tdouble time = check_v(vel,m->velocity.first,m->acceleration.first);\n\t\tif(time < 0) return -1;\n\t\treturn time;\n\t}\n\treturn -1;\n}\n\ndouble time_to_v(Mass* m, string v1, double v2) {\n\tif(v1 == \"?\"){\n\t\tdouble vel = v2;\n\t\tdouble time = check_v(vel,m->velocity.second,m->acceleration.second);\n\t\tif(time < 0) return -1;\n\t\treturn time;\n\t}\n\treturn -1;\n}\n\ndouble time_to_v(Mass* m, pair<double, double> v) {\n\tdouble along_x = check_v(v.first,m->velocity.first,m->acceleration.first);\n\tdouble along_y = check_v(v.second,m->velocity.second,m->acceleration.second);\n\tif((equal_double(along_x, along_y)) && (along_x != -1)) return along_x;\n\treturn -1;\n}");
  fprintf(headerfile, "\n\ndouble sin_val(double angle) {\n\tdouble result = sin(angle * (M_PI / 180.0));\n\tint decimalPlaces =  3;\n\treturn round(result * pow(10, decimalPlaces)) / pow(10, decimalPlaces);\n}\n\ndouble cos_val(double angle) {\n\tdouble result = cos(angle * (M_PI / 180.0));\n\tint decimalPlaces =  3;\n\treturn round(result * pow(10, decimalPlaces)) / pow(10, decimalPlaces);\n}\n\ndouble tan_val(double angle) {\n\tdouble result = tan(angle * (M_PI / 180.0));\n\tint decimalPlaces =  3;\n\treturn round(result * pow(10, decimalPlaces)) / pow(10, decimalPlaces);\n}");

/* 


 */

  construct_stack();
	int i = yyparse();

  print_table();
  print_function_table();

	if(i) fprintf(symbfile,"Failure\n");
	else fprintf(symbfile,"Success\n");

	return 0;
}
