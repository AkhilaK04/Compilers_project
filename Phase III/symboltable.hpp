#include <bits/stdc++.h>
#include <string.h>

using namespace std;

extern char* yytext;
extern int line_no;
string scope;
int q;
extern int countn;
string type;
string result_type;
int num_of_param;


struct sym_tab_entries {
  string id_name;
  string data_type;
  string type;
  string scope;
};
vector<struct sym_tab_entries*> symbol_table;

struct function_records{
  string name;
  string result_type;
  int num_of_param;
  string scope;
  int ret_counter;
  vector<par_records> par_list; 
  vector<var_records> var_list;
};
vector <struct function_records*> function_sym_table;


void new_func_entry(string name, string result_type,int num_of_param, string scope, vector<par_records> par_list){

  struct function_records* temp = new function_records;
  temp->name=name;
  temp->result_type=result_type;
  temp->num_of_param= num_of_param;
  temp->par_list = create_par_list(name,par_list);
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

struct par_records{
  string name;
    string type;
};
typedef struct par_records par_records;


struct var_records{
  string name;
  string type;  
  int scope;
};
typedef struct var_records var_records;

vector<par_records> create_par_list(string func,string name, string type,vector<par_records> par_list){
  for(i = 0; i < no.ofparams; i++){
    par_list[i]->name = name;
    par_list[i]->type = type;
  }
  return par_list;
}


void insert_type() {
	type = yytext;
}

void add(char c) {
  q = search(yytext);
  if(!q) {
    if(c == 'H') {
      new_entry(yytext,type,scope,"Header");
    }  
    else if(c == 'K') {
      new_entry(yytext,"N/A",scope,"Keyword"); 
    }  
    else if(c == 'V') {
      new_entry(yytext,type,scope,"Variable"); 
    }  
    else if(c == 'C') {
      new_entry(yytext,"CONST",scope,"Constant"); 
    }  
    else if(c == 'F') {
      new_entry(yytext,type,scope,"Function");
      new_func_entry(yytext,result_type,num_of_param,scope,par_list);
    }
}
}

int search(string name) { 
    for(int i = 0; i < symbol_table.size(); i++) {
      if(symbol_table[i].id_name == name) {   
        return -1;
        break;  
      }
    } 
    return 0;
}


