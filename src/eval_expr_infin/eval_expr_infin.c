/*
** EPITECH PROJECT, 2021
** eval_expr_infin.c
** File description:
** eval_expr_infin
*/

#include "my.h"
#include "infin_add.h"
#include "infin_sub.h"
#include <stdlib.h>

int get_strnbr_len(char *expr)
{
    int i = 0;

    while (expr[i] >= '0' && expr[i] <= '9' && expr[i] != '\0')
        i++;
    return (i);
}

char *loop_hover_parenthesis(char *expr, char *res, int size)
{
    char *nbr;
    char *res_infin;
    int nbr_len = 0;

    while (*expr != '\0') {
        while ((*expr < '0' || *expr > '9') && *expr != '\0')
            expr++;
        nbr_len = get_strnbr_len(expr);
        nbr = malloc(sizeof(char) * (nbr_len + 1));
        nbr = my_strncpy(nbr, expr, nbr_len);
        nbr[nbr_len] = '\0';
        res_infin = infin_add(nbr, res);
        res = my_strcpy(res, res_infin);
        expr += nbr_len;
        free(nbr);
        free(res_infin);
    }
    return (res);
}

char *eval_expr_infin(char *expr)
{
    int size = my_strlen(expr);
    char *res = malloc(sizeof(char) * (size + 1));

    my_memset(res, '0', size);
    res[size] = '\0';
    res = loop_hover_parenthesis(expr, res, size);
    return (res);
}
