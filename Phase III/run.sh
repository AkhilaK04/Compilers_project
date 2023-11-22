#!/bin/bash

yacc -d -v parsefile.y
lex lexfile.l
g++ -g lex.yy.c y.tab.c -o src
./src
