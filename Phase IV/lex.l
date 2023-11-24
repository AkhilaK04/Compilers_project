%{
	#include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    int yylex();
    FILE* tokfile;
    FILE* parsefile;
    FILE* outfile;
%}

arrow ("->")

punctuation [:.,]

special_sym [\{\}\[\]\(\)$]

primi_datatype ("int"|"double"|"string"|"bool")

non_pri_datatype ("mass"|"time"|"position"|"velocity"|"acceleration"|"energy"|"theta"|"e"|"distance"|"momentum")

reserved_keywords ("input"|"output"|"true"|"false"|"setr"|"addr"|"setv"|"addv"|"seta"|"adda"|"ke_after"|"pe_after"|"te_after"|"angle_after"|"get_traj"|"collide"|"time_to_collide"|"roc_after"|"p_after"|"s_after"|"time_to_r"|"time_to_v"|"loop"|"break"|"sin"|"cos"|"tan"|"mag"|"setp"|"v_after"|"r_after"|"getr"|"getv"|"geta"|"first"|"second"|"otherwise")

bi_op ("^"|"*"|"/"|"%"|"+"|"-")

rel_op ("=="|"!="|"<="|"<"|">"|">=")

logic_op [&|]

uni_op ("++"|"--")

uni_neg ("!")

assgn_op ("=")

d_arr ("=>")

question ("?")


%%



\$[ \t\n]*[^$]*[ \t\n]*\$ {
    yylval.object.value = strdup(yytext);
    fprintf(outfile, "/* %.*s */", yyleng - 2, yytext + 1);
    char* newlinePtr = strchr(yytext, '\n');
    while (newlinePtr != NULL) {
    yylineno++;
    newlinePtr = strchr(newlinePtr + 1, '\n');
    }
    return CMT;
}

SCOPEOPEN {
    yylval.object.value = strdup(yytext);
    return SCOPEOPEN;
}

SCOPECLOSE {
    yylval.object.value = strdup(yytext);
    return SCOPECLOSE;
}

"start" {
    yylval.object.value = strdup(yytext);
    return START;
}

{question} {
    yylval.object.value = strdup(yytext);
    yylval.object.type = 16;
    return QUESTION;
}

{primi_datatype} {
    if(strcmp(yytext,"int") == 0){
        yylval.object.value = strdup(yytext);
        yylval.object.type = 1;
        return INT;
    }
    if(strcmp(yytext,"double") == 0){
        yylval.object.value = strdup(yytext);
        yylval.object.type = 2;
        return DOUBLE;
    }
    if(strcmp(yytext,"string") == 0){
        yylval.object.value = strdup(yytext);
        yylval.object.type = 3;
        return STRING;
    }
    if(strcmp(yytext,"bool") == 0){
        yylval.object.value = strdup(yytext);
        yylval.object.type = 4;
        return BOOL;
    }
}

{non_pri_datatype} {
    if(strcmp(yytext,"mass") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 11; return MASS;}
    else if(strcmp(yytext,"time") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 12; return TIME;}
    else if(strcmp(yytext,"position") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 6; return POSITION;}
    else if(strcmp(yytext,"velocity") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 5; return VELOCITY;}
    else if(strcmp(yytext,"acceleration") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 7; return ACC;}
    else if(strcmp(yytext,"energy") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 13; return ENERGY;}
    else if(strcmp(yytext,"theta") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 14; return THETA;}
    else if(strcmp(yytext,"e") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 15; return E;}
    else if(strcmp(yytext,"distance") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 8; return DISTANCE;}
    else if(strcmp(yytext,"momentum") == 0) {yylval.object.value = strdup(yytext); yylval.object.type = 9; return MOMENTUM;}
}

{reserved_keywords} {
    if(strcmp(yytext,"input") == 0) {yylval.object.value = strdup(yytext); return INPUT;}
    else if(strcmp(yytext,"output") == 0) {yylval.object.value = strdup(yytext); return OUTPUT;}
    else if(strcmp(yytext,"true") == 0) {yylval.object.value = strdup(yytext); return TRUE;}
    else if(strcmp(yytext,"false") == 0) {yylval.object.value = strdup(yytext); return FALSE;}
    else if(strcmp(yytext,"setr") == 0) {yylval.object.value = strdup(yytext); return SETR;}
    else if(strcmp(yytext,"addr") == 0) {yylval.object.value = strdup(yytext); return ADDR;}
    else if(strcmp(yytext,"setv") == 0) {yylval.object.value = strdup(yytext); return SETV;}
    else if(strcmp(yytext,"addv") == 0) {yylval.object.value = strdup(yytext); return ADDV;}
    else if(strcmp(yytext,"seta") == 0) {yylval.object.value = strdup(yytext); return SETA;}
    else if(strcmp(yytext,"adda") == 0) {yylval.object.value = strdup(yytext); return ADDA;}
    else if(strcmp(yytext,"ke_after") == 0) {yylval.object.value = strdup(yytext); return KE_AFTER;}
    else if(strcmp(yytext,"pe_after") == 0) {yylval.object.value = strdup(yytext); return PE_AFTER;}
    else if(strcmp(yytext,"te_after") == 0) {yylval.object.value = strdup(yytext); return TE_AFTER;}
    else if(strcmp(yytext,"angle_after") == 0) {yylval.object.value = strdup(yytext); return ANGLE_AFTER;}
    else if(strcmp(yytext,"get_traj") == 0) {yylval.object.value = strdup(yytext); return GET_TRAJ;}
    else if(strcmp(yytext,"collide") == 0) {yylval.object.value = strdup(yytext); return COLLIDE;}
    else if(strcmp(yytext,"time_to_collide") == 0) {yylval.object.value = strdup(yytext); return TIME_TO_COLLIDE;}
    else if(strcmp(yytext,"roc_after") == 0) {yylval.object.value = strdup(yytext); return ROC_AFTER;}
    else if(strcmp(yytext,"p_after") == 0) {yylval.object.value = strdup(yytext); return P_AFTER;}
    else if(strcmp(yytext,"s_after") == 0) {yylval.object.value = strdup(yytext); return S_AFTER;}
    else if(strcmp(yytext,"time_to_r") == 0) {yylval.object.value = strdup(yytext); return TIME_TO_R;}
    else if(strcmp(yytext,"time_to_v") == 0) {yylval.object.value = strdup(yytext); return TIME_TO_V;}
    else if(strcmp(yytext,"loop") == 0) {yylval.object.value = strdup(yytext); return LOOP;}
    else if(strcmp(yytext,"break") == 0) {yylval.object.value = strdup(yytext); return BREAK;}
    // else if(strcmp(yytext,"start") == 0) return START;
    else if(strcmp(yytext,"sin") == 0) {yylval.object.value = strdup(yytext); return SIN;}
    else if(strcmp(yytext,"cos") == 0) {yylval.object.value = strdup(yytext); return COS;}
    else if(strcmp(yytext,"tan") == 0) {yylval.object.value = strdup(yytext); return TAN;}
    else if(strcmp(yytext,"mag") == 0) {yylval.object.value = strdup(yytext); return MAG;}
    else if(strcmp(yytext,"setp") == 0) {yylval.object.value = strdup(yytext); return SETP;}
    else if(strcmp(yytext,"v_after") == 0) {yylval.object.value = strdup(yytext); return V_AFTER;}
    else if(strcmp(yytext,"r_after") == 0) {yylval.object.value = strdup(yytext); return R_AFTER;}
    else if(strcmp(yytext,"getr") == 0) {yylval.object.value = strdup(yytext); return GETR;}
    else if(strcmp(yytext,"getv") == 0) {yylval.object.value = strdup(yytext); return GETV;}
    else if(strcmp(yytext,"geta") == 0) {yylval.object.value = strdup(yytext); return GETA;}
    else if(strcmp(yytext,"first") == 0) {yylval.object.value = strdup(yytext); return FIRST;}
    else if(strcmp(yytext,"second") == 0) {yylval.object.value = strdup(yytext); return SECOND;}
    else if(strcmp(yytext,"otherwise") == 0) {yylval.object.value = strdup(yytext); return OTHERWISE;}

}



{special_sym} {
    if(strcmp(yytext,"(") == 0) {yylval.object.value = strdup(yytext); return OPENCC;}
    else if(strcmp(yytext,")") == 0) {yylval.object.value = strdup(yytext); return CLOSECC;}
    else if(strcmp(yytext,"[") == 0) {yylval.object.value = strdup(yytext); return OPENSQ;}
    else if(strcmp(yytext,"]") == 0) {yylval.object.value = strdup(yytext); return CLOSESQ;}
    else if(strcmp(yytext,"{") == 0) {yylval.object.value = strdup(yytext); return OPENCU;}
    else if(strcmp(yytext,"}") == 0) {yylval.object.value = strdup(yytext); return CLOSECU;}
    else if(strcmp(yytext,"$") == 0) {yylval.object.value = strdup(yytext); return DOLLAR;}
}

{punctuation} {
    if(strcmp(yytext,"\"") == 0) {yylval.object.value = strdup(yytext); return DOUBLE_QUOTE;}
    else if(strcmp(yytext,"'") == 0) {yylval.object.value = strdup(yytext); return SINGLE_QUOTE;}
    else if(strcmp(yytext,":") == 0) {yylval.object.value = strdup(yytext); return COLON;}
    else if(strcmp(yytext,",") == 0) {yylval.object.value = strdup(yytext); return COMMA;}
    else if(strcmp(yytext,".") == 0) {yylval.object.value = strdup(yytext); return DOT;}
}

{arrow} {
    yylval.object.value = strdup(yytext); 
    return ARROW;
}

{bi_op} {
    if(strcmp(yytext,"+") == 0) {yylval.object.value = strdup(yytext); return ADD;}
    else if(strcmp(yytext,"-") == 0) {yylval.object.value = strdup(yytext); return SUB;}
    else if(strcmp(yytext,"*") == 0) {yylval.object.value = strdup(yytext); return MUL;}
    else if(strcmp(yytext,"/") == 0) {yylval.object.value = strdup(yytext); return DIV;}
    else if(strcmp(yytext,"%") == 0) {yylval.object.value = strdup(yytext); return MOD;}
    else if(strcmp(yytext,"^") == 0) {yylval.object.value = strdup(yytext); return EXP;}
}

{rel_op} {
    if(strcmp(yytext,"==") == 0) {yylval.object.value = strdup(yytext); return EQ;}
    else if(strcmp(yytext,"!=") == 0) {yylval.object.value = strdup(yytext); return NEQ;}
    else if(strcmp(yytext,">=") == 0) {yylval.object.value = strdup(yytext); return GEQ;}
    else if(strcmp(yytext,">") == 0) {yylval.object.value = strdup(yytext); return GT;}
    else if(strcmp(yytext,"<=") == 0) {yylval.object.value = strdup(yytext); return LEQ;}
    else if(strcmp(yytext,"<") == 0) {yylval.object.value = strdup(yytext); return LT;}
}

{logic_op} {
    yylval.object.value = strdup(yytext); 
    return LOGICOP; 
}

{uni_op} {
    yylval.object.value = strdup(yytext); 
    return UNIOP; 
}

{uni_neg} {
    yylval.object.value = strdup(yytext); 
    return UNINEG; 
}

{assgn_op} {
    yylval.object.value = strdup(yytext); 
    return ASSGN; 
}

{d_arr} {
    yylval.object.value = strdup(yytext); 
    return DARR; 
}

[1-9][0-9]* {
    yylval.object.value = strdup(yytext); 
    yylval.object.type = 1;
    return NON_NEGATIVE_INT; 
}

[-]?[1-9][0-9]*|0 {
    yylval.object.value = strdup(yytext); 
    yylval.object.type = 1;
    return INTEGER_CONSTANT; 
}

[-]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
    yylval.object.value = strdup(yytext); 
    yylval.object.type = 2;
    return FLOAT_CONSTANT;
}


[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.object.value = strdup(yytext); 
    return ID;
}

\"([^"]*)\" {
    yylval.object.value = strdup(yytext); 
    yylval.object.type = 3;
    return STRING_CONSTANT;
}

[ \t] {
	fprintf(outfile, "%s", yytext);
}

[\n]  { yylineno++; fprintf(outfile, "%s", yytext);}

. {
	fprintf(tokfile,"ERROR! Invalid token");
    return 0; 
}
%%

int yywrap(){
    return 1;
}