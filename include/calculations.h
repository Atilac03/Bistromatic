/*
** EPITECH PROJECT, 2021
** calculations.h
** File description:
** calculations.c header file
*/

#ifndef CALCULATIONS_H_
    #define CALCULATIONS_H_

int add(char **expr_ptr, int *res);
int minus(char **expr_ptr, int *res);
int multiply(char **expr_ptr, int *res);
int divide(char **expr_ptr, int *res);
int modulo(char **expr_ptr, int *res);
int opening_par(char **expr_ptr, int *res);
int closing_par(char **expr_ptr, int *res);

#endif  /* SRC_H_ */
