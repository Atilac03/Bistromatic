/*
** EPITECH PROJECT, 2021
** find_sign.c
** File description:
** find_sign
*/

#include "my.h"
#include "infin_sub.h"

void add_neg_sign(char *res)
{
    int len = my_strlen(res);

    res[len] = '-';
    res[len + 1] = '\0';
}

char find_greatest_str(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] > str2[i])
            return ('+');
        if (str1[i] < str2[i])
            return ('-');
    }
    return ('+');
}

char find_res_sign(char *str1, char *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);
    char sign;

    if (str1_len == str2_len)
        sign = find_greatest_str(str1, str2);
    if (str1_len > str2_len)
        sign = '+';
    if (str1_len < str2_len)
        sign = '-';
    return (sign);
}
