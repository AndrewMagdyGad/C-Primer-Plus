/*
 * Exercise10_02.c
 *
 *  Created on: Jun 22, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define LENGTH 5

void copy_arr(double target[], double source[], int size);
void copy_ptr(double *target, double *source, int size);
void copy_ptrs(double *target, double *source, double *lastElement);

int main(void)
{
    int i;
    double source[LENGTH] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[LENGTH];
    double target2[LENGTH];
    double target3[LENGTH];

    copy_arr(target1, source, LENGTH);
    copy_ptr(target2, source, LENGTH);
    copy_ptrs(target3, source, source + LENGTH);

    printf("%15s|%15s|%15s\n", "target1", "target2", "target3");
    for (i = 0; i < LENGTH; i++)
        printf("%15.3f|%15.3f|%15.3f\n", target1[i], target2[i], target3[i]);

    return 0;
}

void copy_arr(double target[], double source[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i];
}

void copy_ptr(double *target, double *source, int size)
{
    int i;
    for (i = 0; i < size; i++)
        *(target + i) = *(source + i);
}

void copy_ptrs(double *target, double *source, double *lastElement)
{
    while (source < lastElement)
        *target++ = *source++;
}
