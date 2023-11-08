#include <bits/stdc++.h>
using namespace std;

extern char* yytext;
// string scope;
bool q;
string type;
bool is_func_bool = false;


struct sym_tab_entries {
  string id_name;
  string data_type;
  string type;
  // string scope;
};
typedef sym_tab_entries sym_tab_entries;
vector<sym_tab_entries*> symbol_table;

struct var_records{
  string name;
  string type;
};
typedef var_records var_records;
vector <var_records*> var_list;

struct par_records{
  string name;
  string type;
};
typedef par_records par_records;
vector <par_records*> par_list;

struct function_records{
  string name;
  string result_type;
  int num_of_param;
  // string scope;
  int ret_counter;
  vector<par_records*> par_list; 
  vector<var_records*> var_list;
};
typedef function_records function_records;
vector <function_records*> function_sym_table;


void new_func_entry(string name, string result_type,int num_of_param, vector<par_records*> par_list,vector<var_records*>var_list){
  function_records* temp = new function_records;
  temp->name = name;
  temp->result_type = result_type;
  temp->num_of_param = num_of_param;
  temp->par_list = par_list;
  temp->var_list = var_list;
  // temp->scope = scope;
  // function_sym_table.push_back({name,result_type,num_of_param,par_list,var_list});
  function_sym_table.push_back(temp);
}

void new_entry(string id_name,string data_type, string type) {
	struct sym_tab_entries* temp = new sym_tab_entries;
  cout<<"id: "<<id_name<<endl;
  temp->id_name = id_name;
	temp->data_type = data_type;
	temp->type = type;
	// temp->scope = scope;
  // symbol_table.push_back({id_name,data_type,type});
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
  q = search_in_symtab(yytext);
  if(q) {
    if(c == 'V') {
        new_entry(yytext,type,"Variable");
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
  }
}

void print_table(){
  printf("\n\n");
	printf("\nNAME   DATATYPE   TYPE   SCOPE \n");
	printf("_______________________________________\n\n");
	for(int i = 0; i< symbol_table.size(); i++) {
    cout<< symbol_table[i]->id_name<<" "<<symbol_table[i]->data_type<<" "<<symbol_table[i]->type<<endl;
		// printf("%s\t%s\t%s\t%d\t\n", symbol_table[i]->id_name, symbol_table[i]->data_type, symbol_table[i]->type);
	}

}



