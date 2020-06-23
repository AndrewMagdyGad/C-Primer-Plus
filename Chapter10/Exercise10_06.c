/*
 * Exercise10_06.c
 *
 *  Created on: Jun 22, 2020
 *      Author: andrew
 */
#include <stdio.h>
#define LENGTH 10

void reverse_array(double arr[], int size);
void print_array(const double arr[], int size);

int main(void)
{
    double array[LENGTH] = {1.1, 2, 3, 4, 12, 61.3, 7, 8, 9, 10};

    printf("The content of the array before reversing\n");
    print_array(array, LENGTH);
    reverse_array(array, LENGTH);
    printf("The content of the array after reversing\n");
    print_array(array, LENGTH);

    return 0;
}

void reverse_array(double arr[], int size)
{
    int i;
    for (i = 0; i < size / 2; i++)
    {
        double temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void print_array(const double arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    putchar('\n');
}
