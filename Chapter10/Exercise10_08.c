/*
 * Exercise10_08.c
 *
 *  Created on: Jun 23, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define LENGTH1 7
#define LENGTH2 3

void copy_arr(double target[], double source[], int size);

int main(void)
{
    int i;
    double source[LENGTH1] = {2.4, 5.9, 7.8, 1.5, 3.3, 5.3, 6.8};
    double target[LENGTH2];

    copy_arr(target, source + 2, LENGTH2);

    printf("The content of the source array\n");
    for (i = 0; i < LENGTH1; i++)
        printf("%.1f ", source[i]);
    putchar('\n');

    printf("The content of the target array\n");
    for (i = 0; i < LENGTH2; i++)
        printf("%.1f ", target[i]);
    putchar('\n');

    return 0;
}

void copy_arr(double target[], double source[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}
