/*
 * Exercise13_01.c
 *
 *  Created on: Nov 26, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STLEN 81

char *s_gets(char *string, int n);

int main(void)
{
    int ch;
    FILE *fp;
    char filename[STLEN];
    unsigned long count = 0;

    printf("Enter a file name: ");
    s_gets(filename, STLEN);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);

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
