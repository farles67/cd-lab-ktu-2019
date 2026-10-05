#include <stdio.h>

#define MAX 20

int n;
int epsilon[MAX][MAX];
int closure[MAX];
int visited[MAX];

void eClosure(int state)
{
    int i;

    visited[state] = 1;
    closure[state] = 1;

    for (i = 0; i < n; i++)
    {
        if (epsilon[state][i] == 1 && !visited[i])
        {
            eClosure(i);
        }
    }
}

int main()
{
    int i, j, state;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon transition matrix:\n");
    printf("(Enter 1 if epsilon transition exists, otherwise 0)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &epsilon[i][j]);
        }
    }

    for (state = 0; state < n; state++)
    {
        for (i = 0; i < n; i++)
        {
            closure[i] = 0;
            visited[i] = 0;
        }

        eClosure(state);

        printf("Epsilon-closure(q%d) = { ", state);

        for (i = 0; i < n; i++)
        {
            if (closure[i])
                printf("q%d ", i);
        }

        printf("}\n");
    }

    return 0;
}

