#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
    char keywords[][10] = {
        "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while"
    };

    int i;
    for(i = 0; i < 32; i++)
    {
        if(strcmp(buffer, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;
    char ch;
    char buffer[100];
    char number[100];
    int j = 0, k = 0;

    fp = fopen("program.txt", "r");

    if(fp == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(isalpha(ch) || ch == '_')
        {
            buffer[j++] = ch;
        }
        else
        {
            if(j > 0)
            {
                buffer[j] = '\0';

                if(isKeyword(buffer))
                    printf("%s is Keyword\n", buffer);
                else
                    printf("%s is Identifier\n", buffer);

                j = 0;
            }
        }

        if(isdigit(ch))
        {
            number[k++] = ch;
        }
        else
        {
            if(k > 0)
            {
                number[k] = '\0';
                printf("%s is Constant\n", number);
                k = 0;
            }
        }

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' ||
           ch=='%' || ch=='=')
        {
            printf("%c is Operator\n", ch);
        }

        if(ch==';' || ch==',' || ch=='(' || ch==')' ||
           ch=='{' || ch=='}' || ch=='[' || ch==']')
        {
            printf("%c is Special Character\n", ch);
        }
    }

    /* Print remaining token if EOF occurs */
    if(j > 0)
    {
        buffer[j] = '\0';
        if(isKeyword(buffer))
            printf("%s is Keyword\n", buffer);
        else
            printf("%s is Identifier\n", buffer);
    }

    if(k > 0)
    {
        number[k] = '\0';
        printf("%s is Constant\n", number);
    }

    fclose(fp);
    return 0;
}
