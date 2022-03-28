/*
** EPITECH PROJECT, 2021
** number.c
** File description:
** get number, do operation and handle priorities
*/

#include "number.h"
#include "exit.h"
#include "stdlib.h"
#include "handle_calculations_error.h"

void eval_parenthesis_2(char **str_ptr, int *res)
{
    switch (**str_ptr) {
    case '+':
        (*str_ptr)++;
        *res += number(str_ptr);
        break;
    case '-':
        (*str_ptr)++;
        *res -= number(str_ptr);
        break;
    }
}

int eval_parenthesis(char **str_ptr)
{
    int par = 1;
    int res;

    res = number(str_ptr);
    while (par != 0) {
        switch (**str_ptr) {
        case ')':
            par--;
            (*str_ptr)++;
            break;
        default:
            eval_parenthesis_2(str_ptr, &res);
        }
    }
    return (res);
}

int get_next_nbr(char **str_ptr)
{
    int nb = 0;
    int power = 10;

    if (**str_ptr == '(') {
        (*str_ptr)++;
        nb = eval_parenthesis(str_ptr);
    }
    while (**str_ptr >= '0' && **str_ptr <= '9') {
        nb *= power;
        nb += (**str_ptr - '0');
        (*str_ptr)++;
    }
    return (nb);
}

int test_number(char **str_ptr, int nb)
{
    while (**str_ptr == '/' || **str_ptr == '*' || **str_ptr == '%') {
        switch (**str_ptr) {
        case '/':
            (*str_ptr)++;
            if (**str_ptr == '0' && number(str_ptr) == -1)
                exit(EXIT_OPS);
            nb /= get_next_nbr(str_ptr);
            break;
        case '*':
            (*str_ptr)++;
            nb *= get_next_nbr(str_ptr);
            break;
        case '%':
            (*str_ptr)++;
            nb = nb % get_next_nbr(str_ptr);
            break;
        }
    }
    return (nb);
}

int number(char **str_ptr)
{
    int nb = 0;
    int power = 10;

    while (**str_ptr >= '0' && **str_ptr <= '9') {
        nb *= power;
        nb += (**str_ptr - '0');
        (*str_ptr)++;
    }
    if (**str_ptr == '(') {
        (*str_ptr)++;
        nb = eval_parenthesis(str_ptr);
    }
    nb = test_number(str_ptr, nb);
    return (nb);
}
