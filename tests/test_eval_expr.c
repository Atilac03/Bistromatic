/*
** EPITECH PROJECT, 2021
** test_eval_expr.c
** File description:
** test_eval_expr
*/

#include <criterion/criterion.h>
#include "eval_expr.h"

Test(eval_expr, one_digit_addition)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "0+0", 3), "0");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "3+4", 3), "7");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "5+4", 3), "9");
}

Test(eval_expr, simple_operations_with_parenthesis)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "(1+2)*2", 7), "6");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "2*(1+2)", 7), "6");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "3+2*(4+6)+1", 11), "24");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "(12+2*3)*4+2+34*1", 17), "108");
    cr_assert_eq(eval_expr("0123456789", "()+-*/%", "(1+2)*2", 5), "6");
    cr_assert_eq(eval_expr("0123456789", "()+-*/%", "2*(1+2)", 5), "6");
    cr_assert_eq(eval_expr("0123456789", "()+-*/%", "3+2*(4+6)+1", 11), "24");
    cr_assert_eq(eval_expr("0123456789", "()+-*/%", "(12+2*3)*4+34", 17), "106");
}

Test(eval_expr, operations_with_neg_nbr)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5+4", 4), "-1");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5+4", 4), "-1");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-0+5", 4), "5");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5-4", 4), "-9");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5*4", 4), "-20");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-10/2", 4), "-5");
}

Test(eval_expr, operations_with_zeros)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "00003+03", 9), "6");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "00003+00003", 12), "6");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "000030*3", 9), "90");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "000030/03", 9), "10");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "0000300-00030", 14), "270");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "00003+003", 10), "6");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "000030%0004", 9), "2");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-00003+3", 9), "0");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-00003-3", 9), "-6");
}

Test(eval_expr, operation_neg_mult_div) 
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-10*2", 4), "-20");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5*2", 4), "-10");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-6*7", 4), "-42");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-22*2", 4), "-44");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-64/4", 4), "-16");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-10/2", 4), "-5");
}
