/*
 * Exercise13_12.c
 *
 *  Created on: Dec 08, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 30

int main(int argc, char *argv[])
{
    FILE *fp;
    int data[ROWS][COLS];
    char image[ROWS][COLS + 1];
    const char trans[11] = " .':~*=&%@";

    if (argc != 3)
    {
        printf("Usage: %s <data file> <image file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // open data file
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // read ints from file
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (fscanf(fp, "%d", &data[i][j]) != 1)
            {
                fprintf(stderr, "Invalid or corrupted data file.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Could not close file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // convert ints to characters
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            image[i][j] = trans[data[i][j]];
        }
        image[i][COLS] = '\0';
    }

    // open image file
    if ((fp = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ROWS; i++)
    {
        puts(image[i]);
        fprintf(fp, "%s\n", image[i]);
    }
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Could not close file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
