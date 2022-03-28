/*
** EPITECH PROJECT, 2021
** test_infin_sub_find_sign.c
** File description:
** test_infin_sub_find_sign
*/

#include <criterion/criterion.h>
#include "infin_sub.h"

Test(test_infin_sub_find_sign, 1_digit_compare_to_1_digit)
{
    cr_assert_eq(find_res_sign("0", "0"), '+');
    cr_assert_eq(find_res_sign("1", "0"), '+');
    cr_assert_eq(find_res_sign("0", "1"), '-');
    cr_assert_eq(find_res_sign("4", "2"), '+');
    cr_assert_eq(find_res_sign("2", "4"), '-');
    cr_assert_eq(find_res_sign("3", "9"), '-');
}

Test(test_infin_sub_find_sign, 2_digits_compare_to_1_digit)
{
    cr_assert_eq(find_res_sign("10", "0"), '+');
    cr_assert_eq(find_res_sign("38", "3"), '+');
    cr_assert_eq(find_res_sign("93", "2"), '+');
    cr_assert_eq(find_res_sign("72", "9"), '+');
}

Test(test_infin_sub_find_sign, 1_digits_compare_to_2_digit)
{
    cr_assert_eq(find_res_sign("0", "10"), '-');
    cr_assert_eq(find_res_sign("1", "99"), '-');
    cr_assert_eq(find_res_sign("2", "20"), '-');
    cr_assert_eq(find_res_sign("9", "39"), '-');
}

Test(test_infin_sub_find_sign, 2_digits_compare_to_2_digits)
{
    cr_assert_eq(find_res_sign("10", "10"), '+');
    cr_assert_eq(find_res_sign("99", "11"), '+');
    cr_assert_eq(find_res_sign("11", "99"), '-');
    cr_assert_eq(find_res_sign("91", "92"), '-');
    cr_assert_eq(find_res_sign("43", "40"), '+');
    cr_assert_eq(find_res_sign("03", "99"), '-');
}

Test(test_infin_sub_find_sign, large_numbers_comparaison)
{
    cr_assert_eq(find_res_sign("8743278375984172509842", "3878"), '+');
    cr_assert_eq(find_res_sign("7231698976243187", "3817420987342987430987"), '-');
    cr_assert_eq(find_res_sign("234", "282743987"), '-');
    cr_assert_eq(find_res_sign("32748", "39"), '+');
}
