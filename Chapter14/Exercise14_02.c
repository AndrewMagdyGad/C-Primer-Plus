/*
 * Exercise14_02.c
 *
 *  Created on: Jan 20, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MONTHS 12
#define LEN 15

int get_month_index(char *month_name);
int number_of_days(int month_index, int extra_days);
char *s_gets(char *string, int n);

struct month
{
    char name[LEN];
    char abbreviation[4];
    int days;
    char month_number[3];
};

struct month months[MONTHS] =
    {
        {"January", "jan", 31, "01"},
        {"February", "feb", 28, "02"},
        {"March", "mar", 31, "03"},
        {"April", "apr", 30, "04"},
        {"May", "may", 31, "05"},
        {"June", "jun", 30, "06"},
        {"July", "jul", 31, "07"},
        {"August", "aug", 31, "08"},
        {"September", "sep", 30, "09"},
        {"October", "oct", 31, "10"},
        {"November", "nov", 30, "11"},
        {"December", "dec", 31, "12"}};

int main(void)
{
    int day, year, month_index;
    char month_input[LEN];
    int total;

    // Get year number
    printf("Please enter a year: ");
    while (scanf("%d", &year) != 1 || year < 1)
    {
        // clear input stream
        while (getchar() != '\n')
            continue;

        printf("Invalid input, please enter a valid year: ");
    }
    // clear input stream
    while (getchar() != '\n')
        continue;

    // check for leap year and adjust days in February if necessary
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        months[1].days = 29;

    // Get month
    printf("Please enter a month by name, abbreviation\n");
    printf("or two-digit number (eg. January, jan or 01): ");
    while (s_gets(month_input, LEN) == NULL || (month_index = get_month_index(month_input)) < 0)
    {
        printf("Invalid input, please enter a valid month by name, abbreviation\n");
        printf("or two-digit number (eg. January, jan or 01): ");
    }

    // Get day number
    printf("Please enter a day: ");
    while (scanf("%d", &day) != 1 || day < 1 || months[month_index].days < day)
    {
        // clear input stream
        while (getchar() != '\n')
            continue;

        printf("Invalid input, please enter a valid day: ");
    }
    // clear input stream
    while (getchar() != '\n')
        continue;

    // get total days in year up to given date
    total = number_of_days(month_index, day);
    printf("There are %d days in %d through %s %d.\n",
           total, year, months[month_index].name, day);
    puts("Done.");

    return 0;
}

int get_month_index(char *month_name)
{
    int i;
    // match input to month
    for (i = 0; i < MONTHS; i++)
    {
        // if match is found, break
        if (strcmp(month_name, months[i].name) == 0 ||
            strcmp(month_name, months[i].abbreviation) == 0 ||
            strcmp(month_name, months[i].month_number) == 0)
            break;
    }

    return i == MONTHS ? -1 : i;
}

int number_of_days(int month_index, int extra_days)
{
    int i;
    int total = 0;

    for (i = 0; i < month_index; i++)
        total += months[i].days;

    return total + extra_days;
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
