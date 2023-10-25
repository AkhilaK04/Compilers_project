%{
	#include <stdio.h>
    #include <string.h>
    #include "y.tab.h"
    int yylex();
    FILE* tokfile;
    FILE* parsefile;
%}

bi_op ("^"|"*"|"/"|"%"|"+"|"-")
rel_op ("=="|"!="|"<="|"<"|">"|">="|"&")