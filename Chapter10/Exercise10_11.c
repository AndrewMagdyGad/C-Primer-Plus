/*
 * Exercise10_11.c
 *
 *  Created on: Jun 23, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLUMNS 5

void double_array(int arr[][COLUMNS], int size);
void print_array(const int arr[][COLUMNS], int size);

int main(void)
{
    int i, j;
    srand(time(NULL));

    int array[ROWS][COLUMNS];

    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLUMNS; j++)
            array[i][j] = rand() % 30;

    printf("The content of the original array\n");
    print_array(array, ROWS);

    double_array(array, ROWS);

    printf("The content of the doubled array\n");
    print_array(array, ROWS);

    return 0;
}

void double_array(int arr[][COLUMNS], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < COLUMNS; j++)
            arr[i][j] *= 2;
}

void print_array(const int arr[][COLUMNS], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < COLUMNS; j++)
            printf("%5d ", arr[i][j]);
        putchar('\n');
    }
    putchar('\n');
}
