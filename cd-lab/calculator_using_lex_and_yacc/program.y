%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);

int flag = 0;
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'

%%

ArithmeticExpression
    : E
      {
          printf("\nResult = %d\n", $1);
          return 0;
      }
    ;

E
    : E '+' E   { $$ = $1 + $3; }
    | E '-' E   { $$ = $1 - $3; }
    | E '*' E   { $$ = $1 * $3; }
    | E '/' E
      {
          if ($3 == 0)
          {
              printf("Division by zero is not allowed.\n");
              YYABORT;
          }
          $$ = $1 / $3;
      }
    | E '%' E
      {
          if ($3 == 0)
          {
              printf("Modulo by zero is not allowed.\n");
              YYABORT;
          }
          $$ = $1 % $3;
      }
    | '(' E ')' { $$ = $2; }
    | NUMBER    { $$ = $1; }
    ;

%%

int main(void)
{
    printf("Enter an arithmetic expression:\n");
    yyparse();

    if (flag == 0)
        printf("Entered arithmetic expression is Valid\n");

    return 0;
}

void yyerror(const char *s)
{
    printf("Entered arithmetic expression is Invalid\n");
    flag = 1;
}
