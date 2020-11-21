/*
 * Exercise12_04.c
 *
 *  Created on: Nov 21, 2020
 *      Author: andrew
 */
#include <stdio.h>

unsigned count(void);

int main(void)
{
    int iterations = 0;
    printf("How many times do you want to call count()? ");
    while ((scanf("%d", &iterations) != 1) || iterations <= 0)
    {
        printf("Invalid input, please enter a positive number.\n");
        while (getchar() != '\n')
            ;
        printf("How many times do you want to call count()? ");
    }
    for (int i = 0; i < iterations; i++)
        printf("count() returns %u\n", count());

    return 0;
}

unsigned count(void)
{
    static unsigned counter = 0;
    return ++counter;
}
