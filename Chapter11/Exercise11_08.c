/*
 * Exercise11_08.c
 *
 *  Created on: Jul 04, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#define LIMIT 51

char *string_in(const char *string, const char *substring);
char *s_gets(char *s, int n);

int main(void)
{
    char string[LIMIT];
    char substring[LIMIT];
    char *input_check;
    char *substring_location;

    printf("Enter a string (empty line to quit): ");
    input_check = s_gets(string, LIMIT);
    while (string[0] != '\0' && input_check)
    {
        printf("Enter a substring to look for: ");
        s_gets(substring, LIMIT);

        substring_location = string_in(string, substring);

        if (substring_location == NULL)
            printf("%s not in %s\n", substring, string);
        else
            printf("%s found in %s at index %td\n",
                   substring, string, substring_location - string);

        printf("Enter a string (empty line to quit): ");
        input_check = s_gets(string, LIMIT);
    }
    puts("Done.");

    return 0;
}

char *string_in(const char *string, const char *substring)
{
    int i;
    while (*string)
    {
        i = 0;
        while (string[i] == substring[i])
        {
            i++;
            if (substring[i] == '\0')
                return (char *)string;
        }
        string++;
    }
    return NULL;
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
