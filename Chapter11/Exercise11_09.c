/*
 * Exercise11_09.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#define LIMIT 51

void *reverse_string(char *string);
char *s_gets(char *s, int n);

int main(void)
{
    char string[LIMIT];
    char *input_check;

    printf("Enter a string to reverse (empty line to quit): ");
    input_check = s_gets(string, LIMIT);
    while (string[0] != '\0' && input_check)
    {
        reverse_string(string);
        printf("Your string reversed: %s\n", string);

        printf("Enter a string to reverse (empty line to quit): ");
        input_check = s_gets(string, LIMIT);
    }
    puts("Done.");

    return 0;
}

void *reverse_string(char *start)
{
    char *end = start + strlen(start) - 1;
    char temp;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

char *s_gets(char *s, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        find = strchr(s, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
