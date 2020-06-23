/*
 * Exercise10_14.c
 *
 *  Created on: Jun 23, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define ROWS 3
#define COLUMNS 5

void initialize(int rows, int columns, double arr[rows][columns]);
void print_array(int rows, int columns, const double arr[rows][columns]);
double average(const double arr[], int size);
double average2d(int rows, int columns, const double arr[rows][columns]);
double max2d(int rows, int columns, const double arr[rows][columns]);

int main(void)
{
    int i;
    double array[ROWS][COLUMNS];

    initialize(ROWS, COLUMNS, array);
    printf("array contents:\n");
    print_array(ROWS, COLUMNS, array);

    for (i = 0; i < ROWS; i++)
        printf("average value of row %d = %g\n", i + 1, average(array[i], COLUMNS));

    printf("average value of all rows = %g\n", average2d(ROWS, COLUMNS, array));
    printf("largest value = %g\n", max2d(ROWS, COLUMNS, array));
    printf("Bye!\n");

    return 0;
}

void initialize(int rows, int columns, double arr[rows][columns])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        printf("Enter %d numbers for row %d\n", columns, i + 1);
        for (j = 0; j < columns; j++)
        {
            printf("Enter value #%d: ", j + 1);
            scanf("%lf", &arr[i][j]);
        }
    }
}

void print_array(int rows, int columns, const double arr[rows][columns])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            printf("%g ", arr[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

double average(const double arr[], int size)
{
    int i;
    double sum = 0;
    for (i = 0; i < size; i++)
        sum += arr[i];

    if (size > 0)
        return sum / size;
    else
        return 0.0;
}

double average2d(int rows, int columns, const double arr[rows][columns])
{
    int i, j;
    double sum = 0;
    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            sum += arr[i][j];
    if (rows * columns > 0)
        return sum / (rows * columns);
    else
        return 0.0;
}

double max2d(int rows, int columns, const double arr[rows][columns])
{
    int i, j;
    double max = arr[0][0];
    for (i = 0; i < rows; i++)
        for (j = 0; j < columns; j++)
            if (arr[i][j] > max)
                max = arr[i][j];
    return max;
}
