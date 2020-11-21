/*
 * Exercise12_06.c
 *
 *  Created on: Nov 21, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define NUMBERS_LIMIT 10

void generate_random_numbers(void);

int main(void)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("Random Sample: run #%d\n", i);
        srand(i);
        generate_random_numbers();
        putchar('\n');
    }

    return 0;
}

void generate_random_numbers(void)
{
    int count[NUMBERS_LIMIT] = {0};

    for (int i = 0; i < SIZE; i++)
    {
        int temp = rand() % 10;
        count[temp]++;
    }

    puts("Counts");
    for (int i = 0; i < NUMBERS_LIMIT; i++)
        printf("%2d: %3d  ", i + 1, count[i]);
    putchar('\n');
}
