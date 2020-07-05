/*
 * Exercise11_10.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#define LIMIT 81

void *remove_spaces(char *string);
char *s_gets(char *s, int n);

int main(void)
{
    char string[LIMIT];
    char *input_check;

    printf("Enter a string (empty line to quit): ");
    input_check = s_gets(string, LIMIT);
    while (string[0] != '\0' && input_check)
    {
        remove_spaces(string);
        printf("Your string, without spaces: %s\n", string);

        printf("Enter a string (empty line to quit): ");
        input_check = s_gets(string, LIMIT);
    }
    puts("Done.");

    return 0;
}

void *remove_spaces(char *string)
{
    char *temp;

    while (*string)
    {
        if (*string == ' ')
        {
            temp = string;
            do
            {
                *temp = *(temp + 1);
                temp++;
            } while (*temp);
        }
        else
            string++;
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
