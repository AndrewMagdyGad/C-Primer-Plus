/*
 * Exercise10_05.c
 *
 *  Created on: Jun 22, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define LENGTH 10

double max_difference(const double arr[], int size);

int main(void)
{
    int i;
    double array[LENGTH] = {1.1, 2, 3, 4, 12, 61.3, 7, 8, 9, 10};

    printf("The difference between the largest and smallest values of ");
    for (i = 0; i < LENGTH; i++)
        printf("%.1f ", array[i]);
    printf("is %.1f\n", max_difference(array, LENGTH));

    return 0;
}

double max_difference(const double arr[], int size)
{
    int i;
    double max = arr[0];
    double min = arr[0];
    for (i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    return max - min;
}
