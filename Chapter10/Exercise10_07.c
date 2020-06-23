/*
 * Exercise10_07.c
 *
 *  Created on: Jun 22, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define WIDTH 10
#define LENGTH 5

void copy_ptr(double *target, double *source, int size);
void print_two_dimensional_array(double arr[][WIDTH], int size);

int main(void)
{
    int i, j, count = 1;
    double source[LENGTH][WIDTH];
    double target[LENGTH][WIDTH];

    for (i = 0; i < LENGTH; i++)
        for (j = 0; j < WIDTH; j++)
            source[i][j] = count++;

    for (i = 0; i < LENGTH; i++)
        copy_ptr(target[i], source[i], WIDTH);

    printf("The content of the source array\n");
    print_two_dimensional_array(source, LENGTH);
    printf("The content of the target array\n");
    print_two_dimensional_array(target, LENGTH);

    return 0;
}

void copy_ptr(double *target, double *source, int size)
{
    int i;
    for (i = 0; i < size; i++)
        *(target + i) = *(source + i);
}

void print_two_dimensional_array(double arr[][WIDTH], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < WIDTH; j++)
            printf("%.1f ", arr[i][j]);
        putchar('\n');
    }
    putchar('\n');
}
