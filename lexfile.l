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
    
    return BIOP; 
}

{rel_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    return RELOP; 
}

{logic_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    return LOGICOP; 
}

{uni_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    return UNIOP; 
}

{assgn_op} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    return ASSGN; 
}

{d_arr} {
    //fprintf(tokfile,"operator: %s\n",yytext);
    //fprintf(parsefile,"%s",yytext);
    
    return DARR; 
}

%%
int yywrap(){
    return 1;
}