/*
 * Exercise12_05.c
 *
 *  Created on: Nov 21, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void generate_random_numbers(int *array);

int main(void)
{
    int array[SIZE];
    generate_random_numbers(array);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%2d ", array[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }

    return 0;
}

void generate_random_numbers(int *array)
{
    int temp;

    for (int i = 0; i < SIZE; i++)
        array[i] = rand() % 10 + 1;

    // sort the array
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[j] > array[i])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}
