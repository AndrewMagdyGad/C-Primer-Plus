/*
 * Exercise13_06.c
 *
 *  Created on: Nov 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STLEN 81

char *s_gets(char *string, int n);

int main(void)
{
    FILE *in;
    FILE *out;
    char source[STLEN];
    char dest[STLEN];
    int ch;
    unsigned count = 0;

    printf("Enter a file to reduce: ");
    s_gets(source, STLEN - 5);

    if ((in = fopen(source, "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", source);
        exit(EXIT_FAILURE);
    }

    strcpy(dest, source);
    strcat(dest, ".red");
    if ((out = fopen(dest, "w")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", dest);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0)
        printf("Error in closing file %s.\n", source);
    if (fclose(out) != 0)
        printf("Error in closing file %s.\n", dest);

    return 0;
}

char *s_gets(char *string, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(string, n, stdin);
    if (ret_val)
    {
        find = strchr(string, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
