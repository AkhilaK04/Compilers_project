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

// bool std_lib_semantics (string name,string ID1,vector<string> ID2){
//     if(ID2.size() == 2){
//         // collide function.
//         bool rhs1;
//         if(ID2[1] == "e" || ID2[1] == "int" ) rhs1 = true; // || ID2 == "int_const" 
//         if(ID1 == "mass" && ID2[1] == "mass" && rhs1){
//             cout<<"ERROR in type check of Function args in collide!!"<<endl;
//             return true;
//         }
//     return false;
//     }else{
//         //MAG
//         bool rhs;
//         if(ID2[0] == "velocity" || ID2[0] == "position" || ID2[0] == "acceleration" || ID2[0] == "momentum" || )
//         if(ID1 == "mass" && )
//     }
// }

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


// bool redeclaration_check(string name, string scope){

//   if(is_func_bool){

//     for(int i = 0; i < par_list.size(); i++) {
//       if(par_list[i]->name == name) {   
//         return false;
//       }
//     }
//     for(int i = 0; i < var_list.size(); i++) {
//       if(var_list[i]->name == name && var_list[i]->scope == scope) {   
//         return false;
//       }
//     }
//   }
//   else{
//     for(int i = 0; i < symbol_table.size(); i++) {
//       if(symbol_table[i]->id_name == name) {   
//         return false;
//       }
//     }
//   }
//   return true;

// }

// Function name should not be same as globally declared variables
bool func_red_var(string name){

      for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name && symbol_table[i]->type == "Variable") {   
        return false;
      }
    }
    return true;
}