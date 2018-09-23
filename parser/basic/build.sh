#!/bin/sh

flex  -o basic.lex.cpp -l  basic.lpp
bison -o basic.tab.cpp -vd basic.ypp

gcc -DNO_IDE -o parser basic.lex.cpp basic.tab.cpp -lm -ll
