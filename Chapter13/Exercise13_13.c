/*
 * Exercise13_13.c
 *
 *  Created on: Dec 08, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;
    int rows = 0, cols = 0, lastrow_cols;
    int first_line = 1;
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

    while ((ch = getc(fp)) != EOF && isdigit(ch))
    {
        cols = 1;
        while ((ch = getc(fp)) != EOF && ch != '\n')
            if (isdigit(ch))
                cols++;

        if (first_line)
        {
            first_line = 0;
        }
        else
        {
            if (cols != lastrow_cols)
            {
                fprintf(stderr, "Invalid data file: unequal number of columns in rows.\n");
                exit(EXIT_FAILURE);
            }
        }
        lastrow_cols = cols;
    }

    if (cols == 0)
    {
        fprintf(stderr, "Invalid data file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    while ((ch = getc(fp)) != EOF)
        if (ch == '\n')
            rows++;

    int data[rows][cols];
    char image[rows][cols + 1];

    rewind(fp);
    // read ints from file
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
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
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            image[i][j] = trans[data[i][j]];
        }
        image[i][cols] = '\0';
    }

    // open image file
    if ((fp = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
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
