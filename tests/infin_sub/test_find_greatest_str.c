/*
** EPITECH PROJECT, 2021
** test_find_greatest_str.c
** File description:
** test_find_greatest_str
*/

#include <criterion/criterion.h>
#include "infin_sub.h"

Test(test_find_greatest_str, equal_lenght)
{
    cr_assert_eq(find_greatest_str("0", "0"), '+');
    cr_assert_eq(find_greatest_str("2823", "0192"), '+');
    cr_assert_eq(find_greatest_str("012", "92"), '-');
    cr_assert_eq(find_greatest_str("12", "92"), '-');
    cr_assert_eq(find_greatest_str("12345", "12344"), '+');
    cr_assert_eq(find_greatest_str("12344", "12345"), '-');
}
