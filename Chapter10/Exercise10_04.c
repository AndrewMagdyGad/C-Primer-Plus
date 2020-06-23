/*
 * Exercise10_04.c
 *
 *  Created on: Jun 22, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 20

int index_of_max(const double arr[], int size);

int main(void)
{
    int i;
    double array[LENGTH];
    srand(time(NULL));
    for (i = 0; i < LENGTH; i++)
        array[i] = rand() / (double)RAND_MAX;

    printf("The maximum of\n");
    for (i = 0; i < LENGTH; i++)
        printf("%.4f ", array[i]);
    printf("\noccurs at index: %d\n", index_of_max(array, LENGTH));

    return 0;
}

int index_of_max(const double arr[], int size)
{
    int i;
    int maximum_index = 0;
    for (i = 1; i < size; i++)
        if (arr[i] > arr[maximum_index])
            maximum_index = i;
    return maximum_index;
}
