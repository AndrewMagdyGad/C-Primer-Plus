/*
 * Exercise13_04.c
 *
 *  Created on: Nov 27, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, ch;
    FILE *fp;

    if (argc == 1)
    {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Could not open file %s.\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        while ((ch = getc(fp)) != EOF)
            putc(ch, stdout);

        if (fclose(fp) != 0)
            printf("Could not close file %s\n", argv[i]);
    }

    return 0;
}
