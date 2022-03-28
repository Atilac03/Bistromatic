/*
** EPITECH PROJECT, 2021
** test_infin_sub.c
** File description:
** test_infin_sub
*/

#include <criterion/criterion.h>
#include "infin_sub.h"

Test(infin_sub, 1_number_substraction)
{
    cr_assert_str_eq(infin_sub("0", "0"), "0");
    cr_assert_str_eq(infin_sub("1", "0"), "1");
    cr_assert_str_eq(infin_sub("5", "2"), "3");
}

Test(infin_sub, handle_strange_numbers)
{
    cr_assert_str_eq(infin_sub("0000", "00"), "0");
    cr_assert_str_eq(infin_sub("0010", "0"), "10");
    cr_assert_str_eq(infin_sub("050", "02"), "48");
    cr_assert_str_eq(infin_sub("02", "050"), "-48");
}

Test(infin_sub, 1_plus_2_number_substraction)
{
    cr_assert_str_eq(infin_sub("12", "0"), "12");
    cr_assert_str_eq(infin_sub("65", "4"), "61");
    cr_assert_str_eq(infin_sub("06", "2"), "4");
}

Test(infin_sub, 2_plus_2_number_substraction)
{
    cr_assert_str_eq(infin_sub("12", "11"), "1");
    cr_assert_str_eq(infin_sub("92", "65"), "27");
    cr_assert_str_eq(infin_sub("98", "06"), "92");
}

Test(infin_sub, 2_plus_2_number_substraction_res_neg)
{
    cr_assert_str_eq(infin_sub("11", "12"), "-1");
    cr_assert_str_eq(infin_sub("65", "92"), "-27");
    cr_assert_str_eq(infin_sub("06", "98"), "-92");
}

Test(infin_sub, complex_number_substraction_res_neg)
{
    cr_assert_str_eq(infin_sub("245", "287163"), "-286918");
    cr_assert_str_eq(infin_sub("99", "99999"), "-99900");
    cr_assert_str_eq(infin_sub("498", "737"), "-239");
    cr_assert_str_eq(infin_sub("312498617", "2746737842"), "-2434239225");
}

Test(infin_sub, long_number_substraction)
{
    cr_assert_str_eq(infin_sub("34569278562485548795400057828743", "5092543574098749874273487"), "34569273469941974696650183555256");
    cr_assert_str_eq(infin_sub("259081743095874398754387549873509874387450987547985980743754437858", "3240579547598426498712347862315786543279861514768659864256876987541798"), "-3240320465855330624313593474765913033405474063781111878276133233103940");
}
