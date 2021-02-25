/*
 * Exercise14_10.c
 *
 *  Created on: Feb 25, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <math.h>
#define NUM 4

double twice(double x);
double half(double x);
double thrice(double x);
void showmenu(void);

int main(void)
{
    double (*pf[NUM])(double) = {twice, half, thrice, sqrt};
    double val;
    double ans;
    int sel;

    printf("Enter a number (negative to quit): ");
    while (scanf("%lf", &val) && val >= 0)
    {
        showmenu();
        while (scanf("%d", &sel) && sel >= 0 && sel <= 3)
        {
            ans = (*pf[sel])(val); // first notation
            printf("answer = %.3f\n", ans);
            ans = pf[sel](val); // alternative notation
            printf("to repeat, answer = %.3f\n", ans);
            showmenu();
        }
        printf("Enter next number (negative to quit): ");
    }
    puts("bye");

    return 0;
}

void showmenu(void)
{
    puts("Enter one of the following choices:");
    puts("0) double the value 1) halve the value");
    puts("2) triple the value 3) square root the value");
    puts("4) next number");
}

double twice(double x)
{
    return 2.0 * x;
}

double half(double x)
{
    return x / 2.0;
}

double thrice(double x)
{
    return 3.0 * x;
}
