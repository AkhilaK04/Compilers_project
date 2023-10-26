#!/bin/bash

yacc -d -v par.y
lex lexfile.l
gcc -g lex.yy.c y.tab.c -o inp.txt
