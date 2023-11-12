#include <bits/stdc++.h>
using namespace std;

extern char* yytext;
bool q;
string type;
bool is_func_bool = false;
int count_opencc = 0;
int count_closecc = 0;
stack<string> curr;
vector<int> curr_scopes(100000,0);
int current_pointer = 0;

void construct_stack(){
  curr.push("1");
  curr_scopes[0] = 1;
}


string convert_scope_to_string(int x){
  string ans;
  for(int i=0; i<x; i++){
      ans.push_back('_');
      ans = ans + to_string(curr_scopes[i]);
  }
  return ans;
} 

int find_curr_scopes_len(vector<int> cur_scope){
  int ans = 0;

  for(int i=0; i<cur_scope.size(); i++){
    if(curr_scopes[i] == 0) break;
    else ans++;
  }

  return ans;
} 


struct sym_tab_entries {
  string id_name;
  string data_type;
  string type;
  string scope;
  int num_of_scopes = 0;
};
typedef struct sym_tab_entries sym_tab_entries;
vector<sym_tab_entries*> symbol_table;

struct var_records{
  string name;
  string type;
  string scope;
};
typedef struct var_records var_records;
vector <var_records*> var_list;
vector<string> func_args_list;
struct par_records{
  string name;
  string type;
};

typedef struct par_records par_records;
vector <par_records*> par_list;

// bool compare_par_records(par_records A,par_records B){

//   if(A.name != B.type){
//     return A.name > B.name;
//   }

// return A.type >= B.type;
// }


struct function_records{
  string name;
  string result_type;
  int num_of_param;
  string scope;
  int ret_counter;
  vector<par_records*> par_list; 
  vector<var_records*> var_list;
  int num_of_scopes = 0;
};
typedef struct function_records function_records;
vector <function_records*> function_sym_table;



bool bool_fn_var_entry(var_records* rec){
  string check = rec->name;

    for(int i=0;i<var_list.size();i++){
      if(check == var_list[i]->name){
        return false;
      }
    }
return true;
}

void fn_var_entry(var_records* rec){
  if(bool_fn_var_entry(rec)) var_list.push_back(rec);
  else {
    cout<<rec->name<<" Re-def of var "<<rec->type<<endl;
  }
}

bool  new_func_entry(string name, string result_type,int num_of_param, vector<par_records*> par_list,vector<var_records*>var_list){

  if(valid_func_entry(name,par_list)){
    function_records* temp = new function_records;
    temp->name = name;
    temp->result_type = result_type;
    temp->num_of_param = num_of_param;
    temp->par_list = par_list;
    temp->var_list = var_list;
    temp->scope = convert_scope_to_string(find_curr_scopes_len(curr_scopes));
    function_sym_table.push_back(temp);

    return true;
  }else{
    return false;
  }
  
}

void new_entry(string id_name,string data_type, string type) {
	sym_tab_entries* temp = new sym_tab_entries;
  cout<<"id: "<<id_name<<endl;
  temp->id_name = id_name;
	temp->data_type = data_type;
	temp->type = type;
	temp->scope = convert_scope_to_string(find_curr_scopes_len(curr_scopes));
  symbol_table.push_back(temp);
}

void insert_type() {
	type = yytext;
}

bool search_in_symtab(string name) { 
  int i; 
  if(is_func_bool){
    for(int i = 0; i < par_list.size(); i++) {
      if(par_list[i]->name == name) {   
        return false;
      }
    }
    for(i = 0; i < var_list.size(); i++) {
      if(var_list[i]->name == name) {   
        return false;
      }
   }
  }
  else {
    for(i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i]->id_name == name) {   
        return false;
      }
    }
  } 
  return true;
}

void add(char c) {
  // q = search_in_symtab(yytext);
  // if(q) {
    if(c == 'V') {

      q = search_in_symtab(yytext);
      if(q){
        new_entry(yytext,type,"Variable");
      }else{
        cout<<"Error re defining variable"<<endl;
        //WRITE ERROR IN ERROR FN.
      }
    } 
    // else if(c == 'K') {
    //   new_entry(yytext,"N/A",scope,"Keyword");
    // }    
    // else if(c == 'H') {
    //   new_entry(yytext,type,scope,"Header");
    // }  
    // else if(c == 'C') {
    //   new_entry(yytext,"CONST",scope,"Constant");
    // }  
    else if(c == 'F') {
      new_entry(yytext,type,"Function");
    }
  // }
}

void print_table(){
  printf("\n\n");
	printf("\nNAME   DATATYPE   TYPE   SCOPE \n");
	printf("_______________________________________\n\n");
	for(int i = 0; i< symbol_table.size(); i++) {
    cout<< symbol_table[i]->id_name<<" "<<symbol_table[i]->data_type<<" "<<symbol_table[i]->type<<" "<<symbol_table[i]->scope<<endl;
	}

}


void print_function_table() {
    printf("\n\n");
    printf("NAME   RETURNTYPE   NO_OF_PARAM  PAR_LIST   VAR_LIST  SCOPE \n");
    printf("______________________________________________________________\n\n");
    
    for (int i = 0; i < function_sym_table.size(); i++) {
        cout << function_sym_table[i]->name << "   " << function_sym_table[i]->result_type << "   " << function_sym_table[i]->num_of_param << "   ";
        
        // Print the parameter list
        cout << "[";
        for (int j = 0; j < function_sym_table[i]->par_list.size(); j++) {
            cout << "(" << function_sym_table[i]->par_list[j]->name << ", " << function_sym_table[i]->par_list[j]->type << ")";
            if (j < function_sym_table[i]->par_list.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]   ";
        
        // Print the variable list
        cout << "[";
        for (int j = 0; j < function_sym_table[i]->var_list.size(); j++) {
            cout << "(" << function_sym_table[i]->var_list[j]->name << ", " << function_sym_table[i]->var_list[j]->type << ", " << function_sym_table[i]->var_list[j]->scope << ")\n";
            if (j < function_sym_table[i]->var_list.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]   " << /* Add scope information here */ endl;
    }
}