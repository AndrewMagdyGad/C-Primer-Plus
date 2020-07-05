/*
 * Exercise11_05.c
 *
 *  Created on: Jun 30, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#define LENGTH 50

char *findchar(const char *str, int ch);
char *s_gets(char *s, int n);

int main(void)
{
    char input[LENGTH];
    char *input_check;
    char *check;
    int ch;
    int temp;

    printf("Enter a string to search (empty line to terminate): ");
    input_check = s_gets(input, LENGTH);
    while (input[0] != '\0' && input_check)
    {
        printf("Enter a character to search for: ");
        ch = getchar();

        if (ch != '\n')
            while ((temp = getchar()) != '\n' && temp != EOF)
                continue;

        check = findchar(input, ch);
        puts("\n");
        if (check == NULL)
            printf("Character %c not found in %s", ch, input);
        else
            printf("Character %c found at index %td in %s", ch, check - input, input);

        printf("\nEnter another string to search (empty line to terminate): ");
        input_check = s_gets(input, LENGTH);
    }
    puts("Done.");

    return 0;
}

char *findchar(const char *str, int ch)
{
    while (*str)
    {
        if (*str == ch)
            return (char *)str;
        str++;
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
