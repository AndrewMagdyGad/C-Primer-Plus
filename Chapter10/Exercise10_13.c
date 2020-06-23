/*
 * Exercise10_13.c
 *
 *  Created on: Jun 23, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define ROWS 3
#define COLUMNS 5

void initialize(double arr[][COLUMNS], int size);
void print_array(const double arr[][COLUMNS], int size);
double average(const double arr[], int size);
double average2d(const double arr[][COLUMNS], int size);
double max2d(const double arr[][COLUMNS], int size);

int main(void)
{
    int i;
    double array[ROWS][COLUMNS];

    initialize(array, ROWS);
    printf("array contents:\n");
    print_array(array, ROWS);

    for (i = 0; i < ROWS; i++)
        printf("average value of row %d = %g\n", i + 1, average(array[i], COLUMNS));

    printf("average value of all rows = %g\n", average2d(array, ROWS));
    printf("largest value = %g\n", max2d(array, ROWS));
    printf("Bye!\n");

    return 0;
}

void initialize(double arr[][COLUMNS], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        printf("Enter %d numbers for row %d\n", COLUMNS, i + 1);
        for (j = 0; j < COLUMNS; j++)
        {
            printf("Enter value #%d: ", j + 1);
            scanf("%lf", &arr[i][j]);
        }
    }
}

void print_array(const double arr[][COLUMNS], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < COLUMNS; j++)
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

double average2d(const double arr[][COLUMNS], int size)
{
    int i, j;
    double sum = 0;
    for (i = 0; i < size; i++)
        for (j = 0; j < COLUMNS; j++)
            sum += arr[i][j];
    if (size * COLUMNS > 0)
        return sum / (size * COLUMNS);
    else
        return 0.0;
}

double max2d(const double arr[][COLUMNS], int size)
{
    int i, j;
    double max = arr[0][0];
    for (i = 0; i < size; i++)
        for (j = 0; j < COLUMNS; j++)
            if (arr[i][j] > max)
                max = arr[i][j];
    return max;
}
