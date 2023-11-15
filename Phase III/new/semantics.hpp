#include "symbtab.hpp"


int give_type_index(string type){
  if(type == "int"){
    return 1;
  }
  else if (type == "double"){
    return 2;
  }
  else if (type == "string"){
    return 3;
  }
  else if (type == "bool"){
    return 4;
  }
} 

bool valid_func_entry(string name,vector<par_records*> &new_par_list){
    // sort(new_par_list.begin(),new_par_list.end(),compare_par_records);
    for(int i=0; i < function_sym_table.size(); i++){
        //check for name
        if(function_sym_table[i]->name == name){
            //check for par-list (overloading.)
            vector<par_records*> curr_par_list = function_sym_table[i]->par_list;
            // sort(curr_par_list.begin(),curr_par_list.end(),compare_par_records);
            if(curr_par_list == new_par_list) return false;
        }   
    }
return true;
}

bool check_func_args(string name,vector<string> &func_args_list){ //fn name, types of fn_args.
    
    for(int i=0; i < function_sym_table.size(); i++){
        if(function_sym_table[i]->name == name){
            bool valid_fn = true;
            vector<par_records*> curr_par_list = function_sym_table[i]->par_list;

            if(func_args_list.size() == curr_par_list.size()){
              for(int i=0;i<curr_par_list.size();i++){
                  if(curr_par_list[i]->type != func_args_list[i]){
                      valid_fn = false;
                      break;
                  }
              }
            }
            else{
              valid_fn = false;
            }
            if(valid_fn == true) return true;
        }
    }
return false;
}

bool std_lib_semantics (vector<string> ID2 = {}, string name,string ID1){

    //int_const,float_const,vec_const
    // note.  IN MISC LAST: vec_const can have ? as input arg.!!

    if(ID2.size() == 2){
        // collide function.
        bool rhs1;
        if(ID2[1] == "e" || ID2[1] == "int" ) rhs1 = true; // || ID2 == "int_const" 
        if(name == "collide" || ID1 == "mass" && ID2[1] == "mass" && rhs1){
            return true;
        }
        cout<<"ERROR in type check of Function args in collide!!"<<endl;
    return false;
    }else if(ID2.size() == 0){
        //GET R
        if(name == "getr" && ID1 == "mass"){
            return true;
        }
        // GET V
        else if(name == "getv" && ID1 == "mass"){
            return true;
        }

        //GET A
        else if(name == "geta" && ID1 == "mass"){
            return true;
        }

    return false;
    }else{
        //MAG

        if(name == "mag" && ID1 == "mass" && (ID2[0] == "velocity" || ID2[0] == "position" || ID2[0] == "acceleration" || ID2[0] == "momentum" || ID2[0] == "distance")){
            return true;
        }

        //SET_R ADD_R
        else if((name == "addr"|| name == "setr") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const")){
            return true;
        }

        //GET R
        else if((name == "addr"|| name == "setr") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const")){
            return true;
        }

        //R_AFTER.
        else if(name == "r_after" && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const")){
            return true;
        }

        //SET_V ADD_V
        else if((name == "setv" || name == "addv") && ID1 == "mass" && (ID2[0] == "velocity" || ID2[0] == "vec_const") ){
            return true;
        }

        //V_AFTER (time)
        else if((name == "v_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        //V_AFTER (distance)
        else if((name == "v_after") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const") ){
            return true;
        }

        //SET_A ADD_A
        else if((name == "seta" || name == "adda") && ID1 == "mass" && (ID2[0] == "acceleration" || ID2[0] == "vec_const")){
            return true;
        }

        // ENERGY KE,PE,TE
        else if((name == "ke_after" || name == "pe_after" || name == "te_after")  && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const")){
        return true;
        }

        //angle (time)
        else if((name == "angle_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        //angle (distance)
        else if((name == "angle_after") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const") ){
            return true;
        }

        //collision
        else if((name == "collide" || name == "time_to_collide") && ID1 == "mass" && ID2[0] == "mass"){
            return true;
        }

        // Misc Time:
        else if((name == "s_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        else if((name == "roc_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        else if((name == "p_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        //Misc time_to
         else if((name == "time_to_r") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const")){
            return true;
        }

        else if((name == "time_to_v") && ID1 == "mass" && (ID2[0] == "velocity" || ID2[0] == "vec_const")){
            return true;
        }
    }

cout<<"Errors! no std library found"<<endl;
return false;
}

int undeclare_check(string name, string scope){
  
  if(is_func_bool){
 
    for(int i = 0; i < par_list.size(); i++) {
      if(par_list[i]->name == name) {   
        return give_type_index(par_list[i]->type);
      }
    }

    for(int i=current_pointer;i>=0;i--){
      string scope_temp = to_string(curr_scopes[0]);
      for(int k=1;k<=i;k++){
        scope_temp.push_back('_');
        scope_temp = scope_temp + to_string(curr_scopes[k]);
      }
      for(int j=0;j<var_list.size();j++){
        if(var_list[j]->name == name && scope_temp == var_list[j]->scope){
          return give_type_index(var_list[i]->type);
        }
      }
    }

    for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name) {   
        return give_type_index(symbol_table[i]->type);
      }
    }

  }
  if(scope=="1"){
    for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name) {   
        return give_type_index(symbol_table[i]->type);
      }
    }
  } 
  return 0;
}


bool redeclaration_check(string name, string scope){

  if(is_func_bool){

    for(int i = 0; i < par_list.size(); i++) {
      if(par_list[i]->name == name) {   
        return false;
      }
    }
    for(int i = 0; i < var_list.size(); i++) {
      if(var_list[i]->name == name && var_list[i]->scope == scope) {   
        return false;
      }
    }
  }
  else{
    for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name) {   
        return false;
      }
    }
  }
  return true;

}

// Function name should not be same as globally declared variables
bool func_red_var(string name){

      for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name && symbol_table[i]->type == "Variable") {   
        return false;
      }
    }
    return true;
}

//checking the redeclaration of parameters within the function parameters
bool within_func_parameters_redeclaration(string name){
  for(int i = 0; i < par_list.size(); i++) {
      if(par_list[i]->name == name) {   
        return false;
      }
  }
  return true;
}

//Type checking for assigning variables
bool type_checking_assign(string type1, string type2){
    if(type1 == type2){
        return true;
    }
return false;
}