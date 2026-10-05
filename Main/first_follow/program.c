#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
char production[MAX][MAX];
char first[MAX][MAX], follow[MAX][MAX];
int n;

int isPresent(char str[], char ch) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) return 1;
    }
    return 0;
}

void addToSet(char str[], char ch) {
    if (!isPresent(str, ch)) {
        int len = strlen(str);
        str[len] = ch;
        str[len + 1] = '\0';
    }
}

void findFirst(char result[], char symbol) {
    int i, j;
    char temp[MAX] = "";
    if (!isupper(symbol)) {
        addToSet(result, symbol);
        return;
    }
    for (i = 0; i < n; i++) {
        if (production[i][0] == symbol) {
            if (production[i][2] == '#') {
                addToSet(result, '#');
            } else {
                int k = 2;
                int epsilon = 1;

                while (production[i][k] != '\0' && epsilon) {
                    epsilon = 0;

                    findFirst(temp, production[i][k]);

                    for (j = 0; temp[j] != '\0'; j++) {
                        if (temp[j] != '#') addToSet(result, temp[j]);
                    }

                    if (isPresent(temp, '#')) epsilon = 1;

                    k++;
                }

                if (epsilon) addToSet(result, '#');
            }
        }
    }
}
void findFollow(char symbol) {
    int i, j, k;
    char temp[MAX] = "";
    if (symbol == production[0][0])
        addToSet(follow[symbol - 'A'], '$');

    for (i = 0; i < n; i++) {
        for (j = 2; production[i][j] != '\0'; j++) {
            if (production[i][j] == symbol) {
                int next = j + 1;
                int epsilon = 1;

                while (production[i][next] != '\0' && epsilon) {
                    epsilon = 0;
                    strcpy(temp, "");

                    findFirst(temp, production[i][next]);

                    for (k = 0; temp[k] != '\0'; k++) {
                        if (temp[k] != '#')
                            addToSet(follow[symbol - 'A'], temp[k]);
                    }

                    if (isPresent(temp, '#'))
                        epsilon = 1;

                    next++;
                }

                /* If beta can produce epsilon */
                if (production[i][next] == '\0' && symbol != production[i][0]) {
                    findFollow(production[i][0]);

                    for (k = 0; follow[production[i][0] - 'A'][k] != '\0'; k++) {
                        addToSet(follow[symbol - 'A'],
                                 follow[production[i][0] - 'A'][k]);
                    }
                }
            }
        }
    }
}

int main()
{
    int i;
    char nonTerminals[MAX];
    int ntCount = 0;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");

    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    /* Find FIRST */
    for (i = 0; i < n; i++) {
        char lhs = production[i][0];

        if (!isPresent(nonTerminals, lhs)) {
            nonTerminals[ntCount++] = lhs;
            nonTerminals[ntCount] = '\0';
        }

        strcpy(first[lhs - 'A'], "");
        findFirst(first[lhs - 'A'], lhs);
    }

    /* Find FOLLOW */
    for (i = 0; i < ntCount; i++) {
        findFollow(nonTerminals[i]);
    }

    printf("\nFIRST sets:\n");

    for (i = 0; i < ntCount; i++) {
        char nt = nonTerminals[i];

        printf("FIRST(%c) = { ", nt);

        for (int j = 0; first[nt - 'A'][j] != '\0'; j++)
            printf("%c ", first[nt - 'A'][j]);

        printf("}\n");
    }

    printf("\nFOLLOW sets:\n");

    for (i = 0; i < ntCount; i++) {
        char nt = nonTerminals[i];

        printf("FOLLOW(%c) = { ", nt);

        for (int j = 0; follow[nt - 'A'][j] != '\0'; j++)
            printf("%c ", follow[nt - 'A'][j]);

        printf("}\n");
    }

    return 0;
}

