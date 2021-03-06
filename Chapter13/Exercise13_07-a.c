/*
 * Exercise13_07-a.c
 *
 *  Created on: Nov 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file1, *file2;
    int ch1, ch2;
    int prev_ch1, prev_ch2;

    if (argc < 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((file2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    ch1 = getc(file1);
    ch2 = getc(file2);

    while (ch1 != EOF || ch2 != EOF)
    {
        while (ch1 != EOF && ch1 != '\n')
        {
            putchar(ch1);
            prev_ch1 = ch1;
            ch1 = getc(file1);
        }
        if (ch1 != EOF)
        {
            putchar('\n');
            prev_ch1 = ch1;
            ch1 = getc(file1);
        }
        else if (prev_ch1 != '\n')
        {
            putchar('\n');
            prev_ch1 = '\n';
        }

        while (ch2 != EOF && ch2 != '\n')
        {
            putchar(ch2);
            prev_ch2 = ch2;
            ch2 = getc(file2);
        }
        if (ch2 != EOF)
        {
            putchar('\n');
            prev_ch2 = ch2;
            ch2 = getc(file2);
        }
        else if (prev_ch2 != '\n')
        {
            putchar('\n');
            prev_ch2 = '\n';
        }
    }

    if (fclose(file1) != 0)
        printf("Could not close file %s\n", argv[1]);
    if (fclose(file2) != 0)
        printf("Could not close file %s\n", argv[2]);

    return 0;
}
