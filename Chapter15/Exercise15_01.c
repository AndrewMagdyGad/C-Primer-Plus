/*
 * Exercise15_01.c
 *
 *  Created on: May 17, 2021
 *      Author: andrew
 */
#include <stdio.h>
#include <limits.h>
#include <string.h>

int bstr_to_dec(const char *str);
_Bool check_value(const char *str);
char *s_gets(char *st, int n);

int main(void)
{
    const size_t SLEN = CHAR_BIT * sizeof(int) + 1;
    char value[SLEN];

    printf("Enter a binary number with up to %zu digits: ", SLEN - 1);
    while (s_gets(value, SLEN) && value[0] != '\0')
    {
        if (!check_value(value))
            puts("A binary number contains just 0s and 1s.");
        else
            printf("%s is %d\n", value, bstr_to_dec(value));
        printf("Enter next value (empty line to quit): ");
    }
    puts("Done");
    return 0;
}

int bstr_to_dec(const char *str)
{
    int val = 0;
    while (*str != '\0')
        val = 2 * val + (*str++ - '0');
    return val;
}

_Bool check_value(const char *str)
{
    _Bool valid = 1;
    while (valid && *str != '\0')
    {
        if (*str != '0' && *str != '1')
            valid = 0;
        ++str;
    }
    return valid;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find)                // if the address is not NULL,
            *find = '\0';        // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}
