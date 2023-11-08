#!/bin/bash

yacc -d -v new.y
lex new.l
g++ -g lex.yy.c y.tab.c -o src
./src
