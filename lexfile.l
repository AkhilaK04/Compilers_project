%{
	#include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    int yylex();
    FILE* tokfile;
    FILE* parsefile;
%}


arrow ("->")

punctuation [,""'':]

dot (".")

special_sym ("(" | ")" | "[" | "]" | "{" | "}")

primi_datatype ("int"|"double"|"string"|"bool")

bi_op ("^"|"*"|"/"|"%"|"+"|"-")
rel_op ( "==" | "!=" | "<=" | "<" | ">" | ">=" )
logic_op [&|]
uni_op ("++" | "--")
assgn_op ("=") /* only assignment operator */
d_arr ("=>")

%%

{primi_datatype} {
    // fprintf(out_token,"datatype: %s\n",yytext)
    return PRIMI_DATATYPE;
}

{special_sym} {
    if(strcmp(yytext,"(") == 0){
        fprintf(tokenout,"special symbol: %s\n",yytext);
        return OPENCC;
    }
    if(strcmp(yytext,")") == 0){
        fprintf(tokenout,"special symbol: %s\n",yytext);
        return OPENCC;
    }
    if(strcmp(yytext,"[") == 0){
        fprintf(tokenout,"special symbol: %s\n",yytext);
        return OPENSQ;
    }
    if(strcmp(yytext,"]") == 0){
        fprintf(tokenout,"special symbol: %s\n",yytext);
        return CLOSESQ;
    }
    if(strcmp(yytext,"{") == 0){
        fprintf(tokenout,"special symbol: %s\n",yytext);
        return OPENCU;
    }
    if(strcmp(yytext,"}") == 0){
        fprintf(tokenout,"special symbol: %s\n",yytext);
        return CLOSECU;
    }
}

{dot} {
    fprintf(tokenout,"punctuation: %s\n",yytext);
    return DOT;
}

{punctuation} {
    fprintf(tokenout,"punctuation: %s\n",yytext);
    return PUNCTUATION;
}

{arrow} {
    fprintf(tokenout,"operator: %s\n",yytext);
    return ARROW;
}

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