/*
 * Exercise11_06.c
 *
 *  Created on: Jun 30, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <string.h>
#define LENGTH 50

int is_within(const char *str, char ch);
char *s_gets(char *s, int n);

int main(void)
{
    char input[LENGTH];
    char *input_check;
    int check;
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

        check = is_within(input, ch);
        puts("\n");
        if (check)
            printf("Character %c found in %s", ch, input);
        else
            printf("Character %c not found in %s", ch, input);

        printf("\nEnter another string to search (empty line to terminate): ");
        input_check = s_gets(input, LENGTH);
    }
    puts("Done.");

    return 0;
}

int is_within(const char *str, char ch)
{
    while (*str)
    {
        if (*str == ch)
            return 1;
        str++;
    }

    return 0;
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
