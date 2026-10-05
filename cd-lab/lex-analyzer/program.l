%{
#include <stdio.h>
%}

%%

(int|float|char|double|if|else|while|for|return|break|continue|void|main)   { printf("Keyword               : %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*        { printf("Identifier            : %s\n", yytext); }

[0-9]+\.[0-9]+                { printf("Floating Constant     : %s\n", yytext); }

[0-9]+                        { printf("Integer Constant      : %s\n", yytext); }

("=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"%"|"<"|">")   { printf("Operator              : %s\n", yytext); }

(";"|","|"("|")"|"{"|"}"|"["|"]")   { printf("Delimiter             : %s\n", yytext); }

[ \t\n]+                      ;

.                             { printf("Invalid Character     : %s\n", yytext); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the C program (Press Ctrl+D to stop):\n");
    yylex();
    return 0;
}
