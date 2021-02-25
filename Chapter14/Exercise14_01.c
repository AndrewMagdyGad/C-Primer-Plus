/*
 * Exercise14_01.c
 *
 *  Created on: Jan 20, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MONTHS 12
#define LEN 15

int number_of_days(char *month_name);
char *s_gets(char *string, int n);

struct month
{
    char name[LEN];
    char abbreviation[4];
    int days;
    int month_number;
};

const struct month months[MONTHS] =
    {
        {"January", "jan", 31, 1},
        {"February", "feb", 28, 2},
        {"March", "mar", 31, 3},
        {"April", "apr", 30, 4},
        {"May", "may", 31, 5},
        {"June", "jun", 30, 6},
        {"July", "jul", 31, 7},
        {"August", "aug", 31, 8},
        {"September", "sep", 30, 9},
        {"October", "oct", 31, 10},
        {"November", "nov", 30, 11},
        {"December", "dec", 31, 12}};

int main(void)
{
    char input[LEN];
    int total_days;

    printf("Enter the name of a month: ");
    while (s_gets(input, LEN) != NULL && input[0] != 'q')
    {
        total_days = number_of_days(input);
        if (total_days > 0)
            printf("There are %d days through %s.\n", total_days, input);
        else
            printf("%s is not valid input.\n", input);
        printf("Next month (q to quit): ");
    }
    puts("bye");

    return 0;
}

int number_of_days(char *month_name)
{
    int total = 0;
    int month_number = 0;
    int i;
    month_name[0] = toupper(month_name[0]);
    for (i = 1; month_name[i] != '\0'; i++)
        month_name[i] = tolower(month_name[i]);

    for (i = 0; i < MONTHS; i++)
        if (strcmp(month_name, months[i].name) == 0)
        {
            month_number = months[i].month_number;
            break;
        }

    if (month_number == 0)
        return -1;
    else
    {
        for (i = 0; i < month_number; i++)
            total += months[i].days;
    }

    return total;
}

char *s_gets(char *string, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(string, n, stdin);
    if (ret_val)
    {
        find = strchr(string, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
