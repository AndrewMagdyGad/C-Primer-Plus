/*
 * Exercise16_05.c
 *
 *  Created on: Aug 17, 2021
 *      Author: andrew
 */
#include "Exercise16_01.h"
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

void random_pick(int arr[], int size, int picks);

int main(void)
{
    int picks;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;

    printf("How many items would you like to pick (between 1 and %d, enter q to quit): ", SIZE);
    while (scanf("%d", &picks) == 1 && picks > 0 && picks <= SIZE)
    {
        CLEARINPUT;
        random_pick(arr, SIZE, picks);
        printf("How many items would you like to pick (between 1 and %d, enter q to quit): ", SIZE);
    }
    puts("Bye.");

    return 0;
}

void random_pick(int arr[], int size, int picks)
{
    bool chosen[size];
    for (int i = 0; i < size; i++)
        chosen[i] = false;

    srand(time(NULL));

    for (int i = 0; i < picks; i++)
    {
        int index = rand() % size;
        while (chosen[index])
            index = rand() % size;
        printf("%d\n", arr[index]);
        chosen[index] = true;
    }
}
