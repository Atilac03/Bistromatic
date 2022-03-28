/*
** EPITECH PROJECT, 2021
** main
** File description:
** main file
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my.h"
#include "calculations.h"
#include "eval_expr.h"
#include "usage.h"
#include "handle_main_error.h"
#include "exit.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    char *res;
    char *expr;
    unsigned int size;

    if (ac != 4) {
        display_how_to_usage(av[0]);
        return (EXIT_USAGE);
    }
    check_errors(av);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    res = eval_expr(av[1], av[2], expr, size);
    my_putstr(res);
    free(res);
    return (EXIT_SUCCESS);
}
