/*
 * Exercise16_02.c
 *
 *  Created on: Aug 08, 2021
 *      Author: andrew
 */
#include "Exercise16_01.h"
#define INVERSE(X) (1.0 / (X))
#define HARMONIC_MEAN(X, Y) (1.0 / ((INVERSE(X) + INVERSE(Y)) / 2))

int main(void)
{
    double x, y;
    printf("Enter two numbers (q to quit): ");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        CLEARINPUT;
        printf("The harmonic mean of %.3f and %.3f is: %.3f.\n", x, y, HARMONIC_MEAN(x, y));
        printf("Enter two numbers (q to quit): ");
    }
    puts("Bye.");

    return 0;
}
