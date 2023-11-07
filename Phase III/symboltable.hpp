#include <bits/stdc++.h>
#include <string.h>

using namespace std;

extern char* yytext;
extern int line_no;
string scope;
int q;
string type;
string result_type;
int num_of_param;
bool is_function = false;


struct sym_tab_entries {
  string id_name;
  string data_type;
  string type;
  string scope;
};
vector<sym_tab_entries*> symbol_table;


struct function_records{
  string name;
  string result_type;
  int num_of_param;
  string scope;
  int ret_counter;
  vector<par_records> par_list; 
  vector<var_records> var_list;
};
vector <function_records*> function_sym_table;


struct var_records{
  string name;
  string type;
};

vector <var_records*> var_list;


struct par_records{
  string name;
  string type;
};

vector <par_records*> par_list;


void new_func_entry(string name, string result_type,int num_of_param, string scope, vector<par_records> par_list){
  struct function_records* temp = new function_records;
  temp->name = name;
  temp->result_type = result_type;
  temp->num_of_param = num_of_param;
  temp->par_list = par_list;
  temp->scope = scope;
  function_sym_table.push_back(temp);
}

void new_entry(string id_name,string data_type, string scope, string type ) {
	sym_tab_entries* temp = new sym_tab_entries;
  temp->id_name = id_name;
	temp->data_type = data_type;
	temp->scope = scope;
	temp->type = type;
  symbol_table.push_back(temp);
}

void insert_type() {
	type = yytext;
}

void add(char c) {
  q = search_in_symtab(yytext);
  if(q) {
    if(c == 'V') {
      if(!is_function) {
        new_entry(yytext,type,scope,"Variable");
      }
    } 
    // else if(c == 'K') {
    //   new_entry(yytext,"N/A",scope,"Keyword");
    //   count++;  
    // }    
    // else if(c == 'H') {
    //   new_entry(yytext,type,scope,"Header");
    //   count++;  
    // }  
    // else if(c == 'C') {
    //   new_entry(yytext,"CONST",scope,"Constant");
    //   count++;  
    // }  
    else if(c == 'F') {
      new_entry(yytext,type,scope,"Function");
    }
  }
}

bool search_in_symtab(string name) { 
  int i; 
  if(is_function){
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


void print_table(){
  printf("\n\n");
	printf("\nNAME   DATATYPE   TYPE   SCOPE \n");
	printf("_______________________________________\n\n");
	for(int i = 0; i< symbol_table.size(); i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i]->id_name, symbol_table[i]->data_type, symbol_table[i]->type, symbol_table[i]->scope);
	}

}



