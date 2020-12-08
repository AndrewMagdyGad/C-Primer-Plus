/*
 * Exercise13_02.c
 *
 *  Created on: Nov 26, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch;
    FILE *file_source;
    FILE *file_destination;

    if (argc != 3)
    {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file_source = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Could not open file %s for read\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((file_destination = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Could not open file %s for write\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(file_source)) != EOF)
        putc(ch, file_destination);

    if (fclose(file_source) != 0)
        printf("Could not close file %s\n", argv[1]);
    if (fclose(file_destination) != 0)
        printf("Could not close file %s\n", argv[2]);

    return 0;
}
