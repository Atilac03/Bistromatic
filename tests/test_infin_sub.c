/*
** EPITECH PROJECT, 2021
** test_infin_sub.c
** File description:
** test_infin_sub
*/

#include <criterion/criterion.h>
#include "infin_sub.h"

Test(test_infin_sub, 1_digit_substraction_with_1_digit_result)
{
    cr_assert_str_eq(infin_sub("0", "0"), "0");
    cr_assert_str_eq(infin_sub("2", "0"), "2");
    cr_assert_str_eq(infin_sub("0", "2"), "-2");
    /* cr_assert_str_eq(infin_sub("1", "3"), "-2"); */
    cr_assert_str_eq(infin_sub("3", "1"), "2");
    cr_assert_str_eq(infin_sub("5", "4"), "1");
    cr_assert_str_eq(infin_sub("3", "2"), "1");
    cr_assert_str_eq(infin_sub("2", "9"), "-7");
}

/* Test(test_infin_add, 1_digit_addition_with_2_digit_result) */
/* { */
/*     cr_assert_str_eq(infin_add("3", "8"), "11"); */
/*     cr_assert_str_eq(infin_add("2", "9"), "11"); */
/*     cr_assert_str_eq(infin_add("4", "8"), "12"); */
/*     cr_assert_str_eq(infin_add("8", "4"), "12"); */
/*     cr_assert_str_eq(infin_add("5", "5"), "10"); */
/*     cr_assert_str_eq(infin_add("8", "5"), "13"); */
/*     cr_assert_str_eq(infin_add("9", "9"), "18"); */
/* } */

/* Test(test_infin_add, 2_digits_addition) */
/* { */
/*     cr_assert_str_eq(infin_add("13", "18"), "31"); */
/*     cr_assert_str_eq(infin_add("32", "29"), "61"); */
/*     cr_assert_str_eq(infin_add("43", "83"), "126"); */
/*     cr_assert_str_eq(infin_add("82", "99"), "181"); */
/*     cr_assert_str_eq(infin_add("62", "91"), "153"); */
/* } */

/* Test(test_infin_add, long_addition) */
/* { */
/*     cr_assert_str_eq(infin_add("2874378", "21477"), "2895855"); */
/*     cr_assert_str_eq(infin_add("329243172", "234873821"), "564116993"); */
/*     cr_assert_str_eq(infin_add("234", "23874321"), "23874555"); */
/*     cr_assert_str_eq(infin_add("321988", "9398"), "331386"); */
/* } */

/* Test(test_infin_add, more_than_20_digits_addition) */
/* { */
/*     cr_assert_str_eq(infin_add("32790859087514980759807541", "237480"), "32790859087514980760045021"); */
/*     cr_assert_str_eq(infin_add("374837", "327549858976487647816"), "327549858976488022653"); */
/* } */

/* Test(test_infin_add, more_than_100_digits_addition) */
/* { */
/*     cr_assert_str_eq(infin_add("324987158907451798550498742314320987549784375499807094250987349807215480743209875892348752386523846987549786548346023107856807635487042360547086543270865708261538984576984786912495610251876943213768954217986523769854216", "3469871326521768432123058907532890721378321580932509854784126478437084370864387643278430847848959874785777745207549782981542"), "324987158907451798550498742314320987549784375499807094250987349807215480743209875892348752386527316858876308316778146166764340526208420682128019053125649834739976068947849174555774041099725903088554731963194073552835758"); */
/* } */
