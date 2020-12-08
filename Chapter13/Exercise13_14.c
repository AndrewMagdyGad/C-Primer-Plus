/*
 * Exercise13_14.c
 *
 *  Created on: Dec 08, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ROWS 20
#define COLS 30

void deglitch(int data[ROWS][COLS]);

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

    // de-glitch the data
    deglitch(data);

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

void deglitch(int data[ROWS][COLS])
{
    float total;
    int count;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            total = 0;
            count = 0;
            if (i + 1 < ROWS)
            {
                if (abs(data[i][j] - data[i + 1][j]) < 2)
                    continue;

                total += data[i + 1][j];
                count++;
            }
            if (j + 1 < COLS)
            {
                if (abs(data[i][j] - data[i][j + 1]) < 2)
                    continue;

                total += data[i][j + 1];
                count++;
            }
            if (i > 0)
            {
                if (abs(data[i][j] - data[i - 1][j]) < 2)
                    continue;

                total += data[i - 1][j];
                count++;
            }
            if (j > 0)
            {
                if (abs(data[i][j] - data[i][j - 1]) < 2)
                    continue;

                total += data[i][j - 1];
                count++;
            }

            data[i][j] = (int)rintf(total / count);
        }
    }
}
