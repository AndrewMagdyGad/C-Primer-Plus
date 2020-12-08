/*
 * Exercise13_09.c
 *
 *  Created on: Nov 28, 2020
 *      Author: andrew
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    int ch;
    char words[MAX];
    char line[MAX + 6];
    unsigned word_count = 1;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    while ((ch = getc(fp)) != EOF)
    {
        while ((ch = getc(fp)) != '\n')
            continue;
        word_count++;
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%-3u %s\n", word_count++, words);

    puts("File contents:");
    rewind(fp);
    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
    }
    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
