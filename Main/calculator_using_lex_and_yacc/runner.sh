flex program.l
bison -dy program.y
gcc lex.yy.c y.tab.c -lfl
