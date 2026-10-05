%{
#include <stdio.h>

int line = 0, word = 0, ch = 0;
FILE *yyin;
%}

%%

[a-zA-Z0-9]   { ch++; }
" "           { word++; }
\n            { line++; word++; }
.             ;

%%

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
    yylex();

    printf("line=%d\n", line);
    printf("word=%d\n", word);
    printf("character=%d\n", ch);

    return 0;
}

int yywrap(void)
{
    return 1;
}
