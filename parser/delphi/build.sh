#!/bin/sh

flex  -o delphi.lex.cpp -l  delphi.lpp
bison -o delphi.tab.cpp -vd delphi.ypp

gcc -DNO_IDE -o parser delphi.lex.cpp delphi.tab.cpp -lm -ll
