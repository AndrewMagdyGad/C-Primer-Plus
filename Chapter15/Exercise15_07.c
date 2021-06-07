/*
 * Exercise15_07.c
 *
 *  Created on: June 7, 2021
 *      Author: andrew
 */
#include <stdio.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define OFF 0
#define ON 1

#define ID_SHIFT 0
#define SIZE_SHIFT 8
#define ALIGN_SHIFT 15
#define BOLD_SHIFT 18
#define ITALIC_SHIFT 19
#define UNDERLINE_SHIFT 20

#define ID_MASK (255U << ID_SHIFT)
#define SIZE_MASK (127U << SIZE_SHIFT)
#define ALIGN_MASK (3U << ALIGN_SHIFT)
#define BOLD_MASK (1U << BOLD_SHIFT)
#define ITALIC_MASK (1U << ITALIC_SHIFT)
#define UNDERLINE_MASK (1U << UNDERLINE_SHIFT)

typedef unsigned long Font;

int get_id(Font);
int get_size(Font);
int get_alignment(Font);
char *get_alignment_str(Font);
int get_bold(Font);
int get_italic(Font);
int get_underline(Font);

void set_font(Font *);
void set_size(Font *);
void set_alignment(Font *);
void toggle_bold(Font *);
void toggle_italic(Font *);
void toggle_underline(Font *);

void display_font(Font);
void print_menu(void);
void clear_input(void);
char *is_on(int);

int main(void)
{
    Font font = 3073;

    while (1)
    {
        display_font(font);
        print_menu();
        int ch = getchar();
        if (ch != '\n')
            clear_input();

        if (ch == EOF || ch == 'q')
            break;
        else if (ch == 'f')
            set_font(&font);
        else if (ch == 's')
            set_size(&font);
        else if (ch == 'a')
            set_alignment(&font);
        else if (ch == 'b')
            toggle_bold(&font);
        else if (ch == 'i')
            toggle_italic(&font);
        else if (ch == 'u')
            toggle_underline(&font);
        else
            puts("Sorry, I don't understand that input. Try again.");
    }

    puts("Bye.");
    return 0;
}

char *is_on(int status)
{
    return status == 0 ? "off" : "on";
}

void clear_input(void)
{
    while (getchar() != '\n')
        continue;
}

int get_id(Font font)
{
    return (font & ID_MASK) >> ID_SHIFT;
}

int get_size(Font font)
{
    return (font & SIZE_MASK) >> SIZE_SHIFT;
}

int get_alignment(Font font)
{
    return (font & ALIGN_MASK) >> ALIGN_SHIFT;
}

char *get_alignment_str(Font font)
{
    int alignment = get_alignment(font);

    if (alignment == 0)
        return "left";
    else if (alignment == 1)
        return "center";
    else
        return "right";
}

int get_bold(Font font)
{
    return (font & BOLD_MASK) >> BOLD_SHIFT;
}

int get_italic(Font font)
{
    return (font & ITALIC_MASK) >> ITALIC_SHIFT;
}

int get_underline(Font font)
{
    return (font & UNDERLINE_MASK) >> UNDERLINE_SHIFT;
}

void display_font(Font font)
{
    puts("");
    puts("ID  SIZE ALIGNMENT  B   I   U ");
    printf("%-3u %-4u %-9s %3s %3s %3s\n", get_id(font), get_size(font),
           get_alignment_str(font), is_on(get_bold(font)), is_on(get_italic(font)),
           is_on(get_underline(font)));
    puts("");
}

void print_menu(void)
{
    puts("f)change fonts	s)change size 	 a)change alignment");
    puts("b)toggle bold 	i)toggle italic  u)toggle underline");
    puts("q)quit");
}

void set_font(Font *font)
{
    unsigned int id;
    printf("Enter font id (0 - 255): ");
    while (scanf("%u", &id) != 1 || id < 0 || id > 255)
    {
        clear_input();
        puts("Invalid input. Try again.");
        printf("Enter font id (0 - 255): ");
    }

    *font &= ~ID_MASK;
    *font |= (id << ID_SHIFT) & ID_MASK;
    clear_input();
}

void set_size(Font *font)
{
    unsigned int size;
    printf("Enter font size (0 - 127): ");
    while (scanf("%u", &size) != 1 || size < 0 || size > 127)
    {
        clear_input();
        puts("Invalid input. Try again.");
        printf("Enter font size (0 - 127): ");
    }

    *font &= ~SIZE_MASK;
    *font |= (size << SIZE_SHIFT) & SIZE_MASK;
    clear_input();
}

void set_alignment(Font *font)
{
    puts("Select alignment:");
    puts("l)left   c)center   r)right");
    int ch;
    while (!((ch = getchar()) == 'l' || ch == 'c' || ch == 'r'))
    {
        clear_input();
        puts("That is not a valid option. Try again.");
        puts("Select alignment:");
        puts("l)left   c)center   r)right");
    }

    *font &= ~ALIGN_MASK;
    if (ch == 'l')
        *font |= (LEFT << ALIGN_SHIFT) & ALIGN_MASK;
    else if (ch == 'c')
        *font |= (CENTER << ALIGN_SHIFT) & ALIGN_MASK;
    else if (ch == 'r')
        *font |= (RIGHT << ALIGN_SHIFT) & ALIGN_MASK;

    clear_input();
}

void toggle_bold(Font *font)
{
    *font ^= BOLD_MASK;
}

void toggle_italic(Font *font)
{
    *font ^= ITALIC_MASK;
}

void toggle_underline(Font *font)
{
    *font ^= UNDERLINE_MASK;
}
