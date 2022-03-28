/*
** EPITECH PROJECT, 2020
** evalexpr.c
** File description:
** evalexpr
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "exit.h"
#include "number.h"
#include "calculations.h"
#include "eval_expr.h"
#include "eval_expr_infin.h"

void loop_hover_ops(char const *base, char const *ops,
                    char **expr_ptr, int *res)
{
    int (*operations[])(char **, int *) = {
        &add, &minus, &multiply, &divide, &modulo};

    for (int i = 0; ops[i] != '\0'; i++) {
        if (**expr_ptr == ops[i + 2]) {
            operations[i](expr_ptr, res);
            break;
        }
    }
}

int compare_sign(char *expr, char *ops, int i)
{
    for (int j = 0; ops[j] != '\0'; j++)
        if (expr[i] == ops[j])
            return (1);
    return (0);
}

int is_only_add_sub(char *expr)
{
    char *ops = "-/*%";

    for (int i = 0; expr[i] != '\0'; i++)
        if (compare_sign(expr, ops, i) == 1)
            return (0);
    return (1);
}

char *eval_expr(char const *base, char const *ops, char *expr, int size)
{
    int res = 0;

    if (is_only_add_sub(expr) == 1)
        return (eval_expr_infin(expr));
    res = number(&expr);
    while (*expr != '\0')
        loop_hover_ops(base, ops, &expr, &res);
    return (my_getstr(res));
}
