/*
** EPITECH PROJECT, 2021
** eval_expr.h
** File description:
** eval_expr
*/

#ifndef EVAL_EXPR_H_
    #define EVAL_EXPR_H_

void loop_hover_ops(char const *base, char const *ops,
                    char **expr_ptr, int *res);
char *eval_expr(char const *base, char const *ops, char *expr, int size);

#endif  /* EVAL_EXPR_H_ */
