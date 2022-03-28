/*
** EPITECH PROJECT, 2021
** usage
** File description:
** what's writte if "-h"
*/

#include "my.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n");
    my_putstr("\nDESCRIPTION\n- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the parentheses ");
    my_putstr("and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
}

void display_how_to_usage(char *av0)
{
    my_putstr("Usage: ");
    my_putstr(av0);
    my_putstr(" base ops\"()+_*/%\" exp_len\n");
}
