/*
 * Exercise10_03.c
 *
 *  Created on: Jun 22, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 20

int max_int(const int arr[], int size);

int main(void)
{
    int i;
    int array[LENGTH];
    srand(time(NULL));
    for (i = 0; i < LENGTH; i++)
        array[i] = rand() % 100;

    printf("The maximum of ");
    for (i = 0; i < LENGTH; i++)
        printf("%d ", array[i]);
    printf("is: %d\n", max_int(array, LENGTH));

    return 0;
}

int max_int(const int arr[], int size)
{
    int i;
    int max = arr[0];
    for (i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
