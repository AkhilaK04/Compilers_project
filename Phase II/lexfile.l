%{
	#include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    int yylex();
    FILE* tokfile;
    FILE* parsefile;
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
    fprintf(tokfile,"comment: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return CMT;
}

SCOPEOPEN {
    fprintf(tokfile,"reserved keyword: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return SCOPEOPEN;
}

SCOPECLOSE {
    fprintf(tokfile,"reserved keyword: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return SCOPECLOSE;
}

"start" {
    fprintf(tokfile,"main function: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);

    return START;
}

{question} {
    fprintf(tokfile,"question: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    
    return QUESTION;
}

{primi_datatype} {
    fprintf(tokfile,"primitive datatype: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);

    if(strcmp(yytext,"int") == 0){
        return INT;
    }
    if(strcmp(yytext,"double") == 0){
        return DOUBLE;
    }
    if(strcmp(yytext,"string") == 0){
        return STRING;
    }
    if(strcmp(yytext,"bool") == 0){
        return BOOL;
    }
}

{non_pri_datatype} {
    fprintf(tokfile,"non-primitive datatype: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    if(strcmp(yytext,"mass") == 0) return MASS;
    else if(strcmp(yytext,"time") == 0) return TIME;
    else if(strcmp(yytext,"position") == 0) return POSITION;
    else if(strcmp(yytext,"velocity") == 0) return VELOCITY;
    else if(strcmp(yytext,"acceleration") == 0) return ACC;
    else if(strcmp(yytext,"energy") == 0) return ENERGY;
    else if(strcmp(yytext,"theta") == 0) return THETA;
    else if(strcmp(yytext,"e") == 0) return E;
    else if(strcmp(yytext,"distance") == 0) return DISTANCE;
    else if(strcmp(yytext,"momentum") == 0) return MOMENTUM;
}

{reserved_keywords} {
    fprintf(tokfile,"reserved keyword: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);

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
    else if(strcmp(yytext,"time_to_r") == 0) return TIME_TO_R;
    else if(strcmp(yytext,"time_to_v") == 0) return TIME_TO_V;
    else if(strcmp(yytext,"loop") == 0) return LOOP;
    else if(strcmp(yytext,"break") == 0) return BREAK;
    // else if(strcmp(yytext,"start") == 0) return START;
    else if(strcmp(yytext,"sin") == 0) return SIN;
    else if(strcmp(yytext,"cos") == 0) return COS;
    else if(strcmp(yytext,"tan") == 0) return TAN;
    else if(strcmp(yytext,"mag") == 0) return MAG;
    else if(strcmp(yytext,"setp") == 0) return SETP;
    else if(strcmp(yytext,"v_after") == 0) return V_AFTER;
    else if(strcmp(yytext,"r_after") == 0) return R_AFTER;
    else if(strcmp(yytext,"getr") == 0) return GETR;
    else if(strcmp(yytext,"getv") == 0) return GETV;
    else if(strcmp(yytext,"geta") == 0) return GETA;
    else if(strcmp(yytext,"first") == 0) return FIRST;
    else if(strcmp(yytext,"second") == 0) return SECOND;
    else if(strcmp(yytext,"otherwise") == 0) return OTHERWISE;

}



{special_sym} {
    fprintf(tokfile,"special symbol: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);

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
    fprintf(parsefile,"%s",yytext);
    if(strcmp(yytext,"\"") == 0) return DOUBLE_QUOTE;
    else if(strcmp(yytext,"'") == 0) return SINGLE_QUOTE;
    else if(strcmp(yytext,":") == 0) return COLON;
    else if(strcmp(yytext,",") == 0) return COMMA;
    else if(strcmp(yytext,".") == 0) return DOT;
}

{arrow} {
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return ARROW;
}

{bi_op} {
    fprintf(tokfile,"binary operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    if(strcmp(yytext,"+") == 0) return ADD;
    else if(strcmp(yytext,"-") == 0) return SUB;
    else if(strcmp(yytext,"*") == 0) return MUL;
    else if(strcmp(yytext,"/") == 0) return DIV;
    else if(strcmp(yytext,"%") == 0) return MOD;
    else if(strcmp(yytext,"^") == 0) return EXP;
}

{rel_op} {
    fprintf(tokfile,"relational operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    if(strcmp(yytext,"==") == 0) return EQ;
    else if(strcmp(yytext,"!=") == 0) return NEQ;
    else if(strcmp(yytext,">=") == 0) return GEQ;
    else if(strcmp(yytext,">") == 0) return GT;
    else if(strcmp(yytext,"<=") == 0) return LEQ;
    else if(strcmp(yytext,"<") == 0) return LT;
}

{logic_op} {
    fprintf(tokfile,"logical operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return LOGICOP; 
}

{uni_op} {
    fprintf(tokfile,"unary operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return UNIOP; 
}

{uni_neg} {
    fprintf(tokfile,"unary operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return UNINEG; 
}

{assgn_op} {
    fprintf(tokfile,"assignment operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return ASSGN; 
}

{d_arr} {
    fprintf(tokfile,"operator: %s\n",yytext);
    fprintf(parsefile,"%s",yytext);
    return DARR; 
}

[1-9][0-9]* {
    fprintf(tokfile, "constant: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return NON_NEGATIVE_INT; 
}

[-]?[1-9][0-9]*|0 {
    fprintf(tokfile, "constant: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return INTEGER_CONSTANT; 
}

[-]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? {
    fprintf(tokfile, "constant: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return FLOAT_CONSTANT;
}


[a-zA-Z_][a-zA-Z0-9_]* {
    fprintf(tokfile, "ID: %s\n", yytext);
    fprintf(parsefile, "%s", yytext);
    return ID;
}

\"([^"]*)\" {
    fprintf(tokfile,"punctuation: \"\n");
	fprintf(tokfile,"constant: ");
	for(int i=1;i<yyleng-1;i++){
		fprintf(tokfile,"%c",yytext[i]);
	}
	fprintf(tokfile,"\n");
	fprintf(tokfile,"punctuation: \"\n");
    fprintf(parsefile, "%s", yytext);
    return STRING_CONSTANT;
}

[ \n\t]  { /* ignore whitespace */ ; fprintf(parsefile, "%s", yytext);}

. {
	fprintf(tokfile,"ERROR! Invalid token");
    return 0; 
}
%%

int yywrap(){
    return 1;
}