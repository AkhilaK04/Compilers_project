%{
	#include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    int yylex();
    FILE* tokfile;
    FILE* parsefile;
%}


arrow ("->")

punctuation [.,""'':]

special_sym [\{\}\[\]\(\)]

primi_datatype ("int"|"double"|"string"|"bool")

non_pri_datatype ("mass"|"time"|"position"|"velocity"|"acc"|"energy"|"theta"|"e"|"distance"|"momentum")

reserved_keywords ("input"|"output"|"true"|"false"|"setr"|"addr"|"setv"|"addv"|"seta"|"adda"|"ke_after"|"pe_after"|"te_after"|"angle_after"|"get_traj"|"collide"|"time_to_collide"|"roc_after"|"p_after"|"s_after"|"time_to"|"loop"|"break"|"start"|"sin"|"cos"|"tan"|"mag")

bi_op ("^"|"*"|"/"|"%"|"+"|"-")
rel_op ("=="|"!="|"<="|"<"|">"|">=")
logic_op [&|]
uni_op ("++"|"--"|"!")
assgn_op ("=") /* only assignment operator */
d_arr ("=>")


%%

{primi_datatype} {
    fprintf(tokfile,"datatype: %s\n",yytext);
    return PRIMI_DATATYPE;
}

{non_pri_datatype} {
    fprintf(tokfile,"datatype: %s\n",yytext);
    return NON_PRI_DATATYPE;
}

{reserved_keywords} {
    fprintf(tokfile,"reserved keyword: %s\n",yytext);

    if(strcmp(yytext,"input") == 0) return INPUT;
    else if(strcmp(yytext,"output") == 0) return OUTPUT;
    else if(strcmp(yytext,"true") == 0) return TRUE;
    else if(strcmp(yytext,"false") == 0) return FALSE;
    else if(strcmp(yytext,"setr") == 0) return SETR;
    else if(strcmp(yytext,"addr") == 0) return ADDR;
    else if(strcmp(yytext,"setv") == 0) return SETV;
    else if(strcmp(yytext,"addv") == 0) return ADDV;
    else if(strcmp(yytext,"seta") == 0) return SETA;
    else if(strcmp(yytext,"adda") == 0) return ADDA;
    else if(strcmp(yytext,"ke_after") == 0) return KE_AFTER;
    else if(strcmp(yytext,"pe_after") == 0) return PE_AFTER;
    else if(strcmp(yytext,"te_after") == 0) return TE_AFTER;
    else if(strcmp(yytext,"angle_after") == 0) return ANGLE_AFTER;
    else if(strcmp(yytext,"get_traj") == 0) return GET_TRAJ;
    else if(strcmp(yytext,"collide") == 0) return COLLIDE;
    else if(strcmp(yytext,"time_to_collide") == 0) return TIME_TO_COLLIDE;
    else if(strcmp(yytext,"roc_after") == 0) return ROC_AFTER;
    else if(strcmp(yytext,"p_after") == 0) return P_AFTER;
    else if(strcmp(yytext,"s_after") == 0) return S_AFTER;
    else if(strcmp(yytext,"time_to") == 0) return TIME_TO;
    else if(strcmp(yytext,"loop") == 0) return LOOP;
    else if(strcmp(yytext,"break") == 0) return BREAK;
    else if(strcmp(yytext,"start") == 0) return START;
    else if(strcmp(yytext,"sin") == 0) return SIN;
    else if(strcmp(yytext,"cos") == 0) return COS;
    else if(strcmp(yytext,"tan") == 0) return TAN;
    else if(strcmp(yytext,"mag") == 0) return MAG;
    else if(strcmp(yytext,"setp") == 0) return SETP;
    else if(strcmp(yytext,"v_after") == 0) return V_AFTER;
}



{special_sym} {

    fprintf(tokfile,"special symbol: %s\n",yytext);

    if(strcmp(yytext,"(") == 0) return OPENCC;
    else if(strcmp(yytext,")") == 0) return CLOSECC;
    else if(strcmp(yytext,"[") == 0) return OPENSQ;
    else if(strcmp(yytext,"]") == 0) return CLOSESQ;
    else if(strcmp(yytext,"{") == 0) return OPENCU;
    else if(strcmp(yytext,"}") == 0) return CLOSECU;
    else if(strcmp(yytext,"$") == 0) return DOLLAR;
}

{punctuation} {
    fprintf(tokfile,"punctuation: %s\n",yytext);
    if(strcmp(yytext,"\"") == 0) return DOUBLE_QUOTE;
    else if(strcmp(yytext,"'") == 0) return SINGLE_QUOTE;
    else if(strcmp(yytext,":") == 0) return COLON;
    else if(strcmp(yytext,",") == 0) return COMMA;
    else if(strcmp(yytext,".") == 0) return DOT;
}

{arrow} {
    fprintf(tokfile,"operator: %s\n",yytext);
    return ARROW;
}

{bi_op} {
    
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext); 
    return BIOP; 
}

{rel_op} {
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return RELOP; 
}

{logic_op} {
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return LOGICOP; 
}

{uni_op} {
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return UNIOP; 
}

= {
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return ASSGN; 
}

{d_arr} {
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return DARR; 
}

[-]?[1-9][0-9]*|0 {
    fprintf(tokfile, "constant: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return INTEGER_CONSTANT; 
}

[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
    fprintf(tokfile, "constant: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return FLOAT_CONSTANT;
}

/* \"([^"]*)\" {
    fprintf(tokfile, "punctuation:    \"\nconstant:    %s\npunctuation:    \"\n", yytext);
    fprintf(yyc, "%s", yytext);
    return STRING_CONSTANT;
} */

[a-zA-Z0-9]*[a-zA-Z][a-zA-Z0-9]* {
    fprintf(tokfile, "ID: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return ID;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    fprintf(tokfile, "ID: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return ID;
}

/* [-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
    fprintf(tokfile, "constant: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    
    return FLOAT_CONSTANT;
} */


\"([^"]*)\" {
    fprintf(tokfile, "punctuation:    \"\nconstant:    %s\npunctuation:    \"\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return STRING_CONSTANT;
}

[\n] {
    fprintf(tokfile, " \n : %s\n", yytext);
    return SLASHN;
}

[ \n\t]  { /* ignore whitespace */ ; fprintf(parsefile, "%s", yytext);}

.* {
    fprintf(tokfile, "comment statement: %s\n", yytext);
    return LINE;
}

%%
int yywrap(){
    return 1;
}