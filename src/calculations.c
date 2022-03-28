/*
** EPITECH PROJECT, 2021
** calculations
** File description:
** do operations
*/

#include "number.h"
#include "infin_add.h"
#include "my.h"
#include "exit.h"
#include <stdlib.h>

int add(char **expr_ptr, int *res)
{
    char *res_str = my_getstr(*res);
    char *nbr_str = my_getstr(number(expr_ptr));
    char *str;
    int nbr = 0;

    (*expr_ptr)++;
    nbr = number(expr_ptr);
    nbr_str = my_getstr(nbr);
    str = infin_add(res_str, nbr_str);
    *res += my_getnbr(str);
    free(res_str);
    free(nbr_str);
    free(str);
    return (1);
}

int minus(char **expr_ptr, int *res)
{
    (*expr_ptr)++;
    *res -= number(expr_ptr);
    return (1);
}

int multiply(char **expr_ptr, int *res)
{
    (*expr_ptr)++;
    *res *= number(expr_ptr);
    return (1);
}

int divide(char **expr_ptr, int *res)
{
    int is_0 = 0;

    (*expr_ptr)++;
    is_0 = number(expr_ptr);
    if (is_0 == 0)
        exit (DIVISION_BY_0);
    *res /= is_0;
    return (1);
}

int modulo(char **expr_ptr, int *res)
{
    int is_0 = 0;

    (*expr_ptr)++;
    is_0 = number(expr_ptr);
    if (is_0 == 0)
        exit (MODULO_BY_0);
    *res = *res % is_0;
    return (1);
}
