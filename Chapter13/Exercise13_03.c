/*
 * Exercise13_03.c
 *
 *  Created on: Nov 26, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STLEN 81

char *s_gets(char *string, int n);

int main(void)
{
    int ch;
    FILE *file_source;
    FILE *file_destination;
    char source[STLEN];
    char destination[STLEN];

    printf("Enter a source file: ");
    s_gets(source, STLEN);
    printf("Enter a destination file: ");
    s_gets(destination, STLEN);

    if ((file_source = fopen(source, "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s for read.\n", source);
        exit(EXIT_FAILURE);
    }

    if ((file_destination = fopen(destination, "w")) == NULL)
    {
        fprintf(stderr, "Could not open file %s for write.\n", destination);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(file_source)) != EOF)
    {
        if (islower(ch))
            ch = toupper(ch);
        putc(ch, file_destination);
    }

    if (fclose(file_source) != 0)
        printf("Could not close file %s\n", source);
    if (fclose(file_destination) != 0)
        printf("Could not close file %s\n", destination);

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
