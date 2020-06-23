/*
 * Exercise10_10.c
 *
 *  Created on: Jun 23, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 10

void add_arrays(const int arr1[], const int arr2[], int sum[], int size);
void print_array(const int arr[], int size);

int main(void)
{
    int i;
    srand(time(NULL));

    int array1[LENGTH];
    int array2[LENGTH];
    int sum[LENGTH];

    for (i = 0; i < LENGTH; i++)
    {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    add_arrays(array1, array2, sum, LENGTH);

    printf("The content of the first array\n");
    print_array(array1, LENGTH);
    printf("The content of the second array\n");
    print_array(array2, LENGTH);
    printf("The content of the sum array\n");
    print_array(sum, LENGTH);

    return 0;
}

void add_arrays(const int arr1[], const int arr2[], int sum[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        sum[i] = arr1[i] + arr2[i];
}

void print_array(const int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%5d ", arr[i]);
    putchar('\n');
}
