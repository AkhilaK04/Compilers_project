#include "symbtab.hpp"

bool pred_brac_handle(int opencc,int closecc){
    if(count_opencc == count_opencc) return true;
return false;
}

bool valid_func_entry(vector <function_records*> &function_sym_table,string name,vector<par_records*> &new_par_list){
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

            for(int i=0;i<curr_par_list.size();i++){
                if(curr_par_list[i]->type != func_args_list[i]){
                    valid_fn = false;
                    break;
                }
            }
            if(valid_fn == true) return true;
        }
    }
return false;
}

bool std_lib_semantics (string name,string ID1,vector<string> ID2){
    if(ID2.size() == 2){
        // collide function.
        bool rhs1;
        if(ID2[1] == "e" || ID2[1] == "int" ) rhs1 = true; // || ID2 == "int_const" 
        if(ID1 == "mass" && ID2[1] == "mass" && rhs1){
            cout<<"ERROR in type check of Function args in collide!!"<<endl;
            return true;
        }
    return false;
    }else{
        //MAG
        bool rhs;
        if(ID2[0] == "velocity" || ID2[0] == "position" || ID2[0] == "acceleration" || ID2[0] == "momentum" || )
        if(ID1 == "mass" && )
    }
}

bool undeclare_check(string name, string scope){

  if(is_func_bool){

    for(int i = 0; i < par_list.size(); i++) {
      if(par_list[i]->name == name) {   
        return true;
      }
    }
    for(int i = 0; i < var_list.size(); i++) {
      if(var_list[i]->name == name && var_list[i]->scope == scope) {   
        return true;
      }
      else {
        int cnt = 0;
        for(int i = 0; i <curr_scopes.size(); i++) if(curr_scopes[i] != 0) cnt = cnt+1; break;
        bool x;
        while(cnt !=0 && !x){
            string newscope = convert_scope_to_string(cnt);
            x = undeclare_check(name,newscope);
            cnt --;
        }
      }
   }
  }
  if(scope=="1"){
    for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name) {   
        return true;
      }
    }
  } 
  return false;
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

bool undeclared_function(string name){

if(is_func_bool){
    for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name) {   
        return true;
      }
    }
  } 
  return false;
}

bool func_red_var(string name){

      for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name) {   
        return false;
      }
    }
    return true;
}

bool within_func_parameters_redeclaration(string name){
  for(int i = 0; i < par_list.size(); i++) {
      if(par_list[i]->name == name) {   
        return false;
      }
  }
  return true;
}
