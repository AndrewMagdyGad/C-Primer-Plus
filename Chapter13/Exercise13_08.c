/*
 * Exercise13_08.c
 *
 *  Created on: Nov 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char character;
    int ch;
    unsigned counter;
    FILE *fp;

    if (argc < 2)
    {
        printf("Usage: %s <char> [file1] [file2] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    character = *(argv[1]);

    if (argc == 2)
    {
        counter = 0;

        while ((ch = getchar()) != EOF)
            if (ch == character)
                counter++;

        printf("Character count for %c in the standard input: %u\n", character, counter);
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            counter = 0;
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                fprintf(stderr, "Can't open file %s\n", argv[i]);
                continue;
            }

            while ((ch = getc(fp)) != EOF)
                if (ch == character)
                    counter++;

            printf("Character count for %c in %s: %u\n", character, argv[i], counter);

            if (fclose(fp) != 0)
                printf("Could not close file %s\n", argv[i]);
        }
    }

    return 0;
}
