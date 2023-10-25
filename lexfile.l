%{
	#include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    int yylex();
    FILE* tokfile;
    FILE* parsefile;
%}

bi_op ("^"|"*"|"/"|"%"|"+"|"-")
rel_op ( "==" | "!=" | "<=" | "<" | ">" | ">=" )
logic_op [&|]
uni_op ("++" | "--")
assgn_op ("=") /* only assignment operator */
d_arr ("=>")
/* Comment  */
%%
{bi_op} {
    
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    if(strcmp(yytext,"^") == 0 || strcmp(yytext,"*") == 0 || strcmp(yytext,"/") == 0 || strcmp(yytext,"%") == 0 || strcmp(yytext,"+") == 0 || strcmp(yytext,"-") == 0) return BIOP; 
}

{rel_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    if(strcmp(yytext,"==") == 0 || strcmp(yytext,"!=") == 0 || strcmp(yytext,"<=") == 0 || strcmp(yytext,"<") == 0 || strcmp(yytext,">") == 0 || strcmp(yytext,">=") == 0) return RELOP; 
}

{logic_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    if(strcmp(yytext,"&") == 0 || strcmp(yytext,"|") == 0 ) return LOGICOP; 
}

{uni_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    if(strcmp(yytext,"++") == 0 || strcmp(yytext,"--") == 0 ) return UNIOP; 
}

{assgn_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    if(strcmp(yytext,"=") == 0 ) return ASSGN; 
}

{d_arr} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    if(strcmp(yytext,"=>") == 0 ) return DARR; 
}

%%
int yywrap(){
    return 1;
}