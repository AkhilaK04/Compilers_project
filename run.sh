#!/bin/bash

yacc -d -v par_pranav.y
lex lexfile.l
gcc -g lex.yy.c y.tab.c -o src
