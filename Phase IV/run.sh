#!/bin/bash

yacc -d -v parse.y
lex lex.l
g++ -g lex.yy.c y.tab.c -o src
./src
