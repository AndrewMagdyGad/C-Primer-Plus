/*
 * Exercise14_05.c
 *
 *  Created on: Jan 21, 2021
 *      Author: andrew
 */
#include <stdio.h>
#define CSIZE 4
#define MAXNAME 20
#define GRADELEN 3

struct name
{
    char first[MAXNAME];
    char second[MAXNAME];
};

struct student
{
    struct name s_name;
    double grade[GRADELEN];
    double average;
};

void get_grades(struct student *s);
void get_average(struct student *s);
void print_info(struct student *s);

int main(void)
{
    struct student students[CSIZE] = {
        {.s_name = {"Zack", "Morris"}},
        {.s_name = {"Kelly", "Kapowski"}},
        {.s_name = {"AC", "Slater"}},
        {.s_name = {"Screech", "Powers"}},
    };

    // get student grades
    for (int i = 0; i < CSIZE; i++)
        get_grades(&students[i]);

    // get grade averages
    for (int i = 0; i < CSIZE; i++)
        get_average(&students[i]);

    // print student info
    for (int i = 0; i < CSIZE; i++)
        print_info(&students[i]);

    // print class average
    for (int j = 0; j < GRADELEN; j++)
    {
        double total = 0;
        for (int i = 0; i < CSIZE; i++)
            total += students[i].grade[j];
        printf("Average of grade %d: %.3f\n", j + 1, total / CSIZE);
    }
    double total = 0;
    for (int i = 0; i < CSIZE; i++)
        total += students[i].average;
    printf("Average of all: %.3f\n", total / CSIZE);

    return 0;
}

void get_grades(struct student *s)
{
    for (int i = 0; i < GRADELEN; i++)
    {
        printf("Enter grade %d for student %s %s: ", i + 1, s->s_name.first,
               s->s_name.second);
        while (scanf("%lf", s->grade + i) != 1)
        {
            while (getchar() != '\n')
                continue;
            printf("Invalid input, please enter grade %d for student %s %s: ", i + 1, s->s_name.first,
                   s->s_name.second);
        }
        while (getchar() != '\n')
            continue;
    }
    puts("\n");
}

void get_average(struct student *s)
{
    double total = 0;
    for (int i = 0; i < GRADELEN; i++)
        total += s->grade[i];
    s->average = total / GRADELEN;
}

void print_info(struct student *s)
{
    printf("Name: %s %s\n", s->s_name.first, s->s_name.second);
    printf("Grade 1: %.1f\n", s->grade[0]);
    printf("Grade 2: %.1f\n", s->grade[1]);
    printf("Grade 3: %.1f\n", s->grade[2]);
    printf("Average Grade: %.1f\n\n", s->average);
}
