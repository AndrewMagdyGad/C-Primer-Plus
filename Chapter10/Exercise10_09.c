/*
 * Exercise10_09.c
 *
 *  Created on: Jun 23, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define ROWS 3
#define COLUMNS 5

void copy_two_dimensional_array(int rows, int columns, double target[rows][columns], const double source[rows][columns]);
void print_two_dimensional_array(int rows, int columns, const double arr[rows][columns]);

int main(void)
{
    int i, j;
    double count = 0;
    double source[ROWS][COLUMNS];
    double target[ROWS][COLUMNS];

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLUMNS; j++)
            source[i][j] = count += 1.1;

    copy_two_dimensional_array(ROWS, COLUMNS, target, source);

    printf("The content of the source array\n");
    print_two_dimensional_array(ROWS, COLUMNS, source);
    printf("The content of the target array\n");
    print_two_dimensional_array(ROWS, COLUMNS, target);

    return 0;
}

void copy_two_dimensional_array(int rows, int columns, double target[rows][columns], const double source[rows][columns])
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            target[i][j] = source[i][j];
}

void print_two_dimensional_array(int rows, int columns, const double arr[rows][columns])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            printf("%10.2f ", arr[i][j]);
        putchar('\n');
    }
    putchar('\n');
}
