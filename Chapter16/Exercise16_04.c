/*
 * Exercise16_04.c
 *
 *  Created on: Aug 12, 2021
 *      Author: andrew
 */
#include "Exercise16_01.h"
#include <time.h>

void delay(double time);

int main(void)
{
    double time;

    printf("Enter desired time delay in seconds (q to quit): ");
    while (scanf("%lf", &time) == 1)
    {
        CLEARINPUT;
        puts("Starting.");
        delay(time);
        printf("It is now %.2f seconds later!\n", time);
        printf("Enter desired time delay in seconds (q to quit): ");
    }
    puts("Bye.");

    return 0;
}

void delay(double time)
{
    clock_t start, end;
    start = clock();

    while (((end = clock()) - start) / (double)CLOCKS_PER_SEC < time)
        continue;
}
