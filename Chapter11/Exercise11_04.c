/*
 * Exercise11_04.c
 *
 *  Created on: Jun 30, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <ctype.h>
#define LENGTH 21

char *getword(char *s, int n);

int main(void)
{
    char input[LENGTH];
    char *check;

    printf("What is your name? (maximum number of characters is %d): ", LENGTH - 1);
    check = getword(input, LENGTH - 1);
    if (check == NULL)
        puts("\nInput failed.");
    else
        printf("\nHello, %s\n", input);
    puts("Done.\n");

    return 0;
}

char *getword(char *s, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != EOF && isspace(ch))
        continue;

    if (ch == EOF)
        return NULL;
    else
        s[i++] = ch;

    while ((ch = getchar()) != EOF && !isspace(ch) && i < n)
        s[i++] = ch;

    if (ch == EOF)
        return NULL;
    else
    {
        s[i] = '\0';
        while (ch != '\n' && ch != EOF)
            ch = getchar();
        return s;
    }
}
