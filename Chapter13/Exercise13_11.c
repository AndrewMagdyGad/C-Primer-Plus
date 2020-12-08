/*
 * Exercise13_11.c
 *
 *  Created on: Nov 30, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINEMAX 256

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[LINEMAX];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <string> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINEMAX, fp) != NULL)
    {
        if (strstr(line, argv[1]) != NULL)
            fputs(line, stdout);
    }

    if (fclose(fp) != 0)
        printf("Could not close file %s\n", argv[2]);

    return 0;
}
