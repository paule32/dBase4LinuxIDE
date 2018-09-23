#!/bin/sh

flex  -o pro.lex.cpp -l  pro.lpp
bison -o pro.tab.cpp -vd pro.ypp

gcc -DNO_IDE -o parser pro.lex.cpp pro.tab.cpp -lm -ll
