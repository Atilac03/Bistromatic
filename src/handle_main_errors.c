/*
** EPITECH PROJECT, 2021
** handle_main_errors.c
** File description:
** handle_main_errors
*/

#include "exit.h"
#include "my.h"
#include <stdlib.h>

void check_ops(char const *ops)
{
    char *original_ops = "()+-*/%";

    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; original_ops[i] != '\0'; i++)
        if (ops[i] != original_ops[i]) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
}

void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    for (int i = 0; b[i] != '\0'; i++)
        if (b[i] != DTOA(i)) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
}

void check_errors(char **av)
{
    check_base(av[1]);
    check_ops(av[2]);
}
