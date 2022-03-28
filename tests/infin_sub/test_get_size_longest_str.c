/*
** EPITECH PROJECT, 2021
** get_size_longest_str.c
** File description:
** get_size_longest_str
*/

#include <criterion/criterion.h>
#include "infin_sub.h"

Test(test_get_size_longest_str, equal_lenght)
{
    cr_assert_eq(get_size_longest_str("0", "0"), 1);
    cr_assert_eq(get_size_longest_str("2823", "0192"), 4);
    cr_assert_eq(get_size_longest_str("12", "92"), 2);
    cr_assert_eq(get_size_longest_str("937439817324508762", "937439814322555762"), 18);
}

Test(test_get_size_longest_str, str1_greater_than_str2)
{
    cr_assert_eq(get_size_longest_str("12", "0"), 2);
    cr_assert_eq(get_size_longest_str("2823", "01"), 4);
    cr_assert_eq(get_size_longest_str("124675", "27392"), 6);
    cr_assert_eq(get_size_longest_str("937439817324508762", "937439814322"), 18);
}

Test(test_get_size_longest_str, str2_greater_than_str1)
{
    cr_assert_eq(get_size_longest_str("0", "12"), 2);
    cr_assert_eq(get_size_longest_str("23", "0123"), 4);
    cr_assert_eq(get_size_longest_str("14675", "273922"), 6);
    cr_assert_eq(get_size_longest_str("9374398173245", "937439817324508762"), 18);
}
