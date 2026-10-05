#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1;

void reduce()
{
    if (top >= 1 && stack[top-1] == 'i' && stack[top] == 'd')
    {
        stack[top-1] = 'E';
        top--;
        stack[top+1] = '\0';
        printf("$%s\t%s$\tREDUCE TO E\n", stack, input);
    }

    if (top >= 2 && stack[top-2] == 'E' &&
        (stack[top-1] == '+' || stack[top-1] == '-' || stack[top-1] == '*') &&
        stack[top] == 'E')
    {
        stack[top-2] = 'E';
        top -= 2;
        printf("$%s\t%s$\tREDUCE TO E\n", stack, input);
    }

    if (top >= 2 && stack[top-2] == '(' &&
        stack[top-1] == 'E' && stack[top] == ')')
    {
        stack[top-2] = 'E';
        top -= 2;
        printf("$%s\t%s$\tREDUCE TO E\n", stack, input);
    }
}

int main()
{
    int i = 0, n;

    printf("Grammar is E->E+E\n");
    printf("E->E-E\n");
    printf("E->E*E\n");
    printf("E->(E)\n");
    printf("E->id\n");

    printf("Enter input string:\n");
    scanf("%s", input);

    n = strlen(input);

    printf("stack\tinput\taction\n");

    while (i < n)
    {
        stack[++top] = input[i++];

        if (stack[top] == 'i' && i < n && input[i] == 'd')
        {
            stack[++top] = input[i++];
            stack[top+1] = '\0';
            printf("$%s\t%s$\tSHIFT->id\n", stack, input+i);
        }
        else
        {
            stack[top+1] = '\0';
            printf("$%s\t%s$\tSHIFT->symbol\n", stack, input+i);
        }

        reduce();
    }

    if (top == 0 && stack[0] == 'E')
        printf("$E\t$\tAccept\n");
    else
        printf("Reject\n");

    return 0;
}
