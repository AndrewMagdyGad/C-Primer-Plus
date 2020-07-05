/*
 * Exercise11_02.c
 *
 *  Created on: Jun 30, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>
#define LENGTH 21

char *getnchar(char *s, int n);

int main(void)
{
    char input[LENGTH];
    char *check;

    printf("What is your name? ");
    check = getnchar(input, LENGTH - 1);
    if (check == NULL)
        puts("Input failed.");
    else
        printf("Hello, %s\n", input);
    puts("Done.\n");

    return 0;
}

char *getnchar(char *s, int n)
{
    int ch = 0, i;

    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch != EOF && !isspace(ch))
            s[i] = ch;
        else
            break;
    }

    if (ch == EOF)
        return NULL;
    else
    {
        s[i] = '\0';
        return s;
    }
}
