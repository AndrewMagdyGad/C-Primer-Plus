/*
 * Exercise13_10.c
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
    FILE *fp;
    char filename[STLEN];
    long pos;
    int ch;

    printf("Enter a filename: ");
    s_gets(filename, STLEN);

    if ((fp = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Enter a position: ");
    while (scanf("%ld", &pos) == 1)
    {
        if (pos < 0)
            break;

        fseek(fp, pos, SEEK_SET);
        while ((ch = getc(fp)) != EOF && ch != '\n')
            putchar(ch);
        putchar('\n');

        printf("Enter a position: ");
    }

    if (fclose(fp) != 0)
        printf("Could not close file %s\n", filename);
    puts("Done.");

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
