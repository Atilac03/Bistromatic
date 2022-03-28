/*
** EPITECH PROJECT, 2021
** infin_add.c
** File description:
** infin_add
*/

#include "my.h"
#include "parse_numbers.h"
#include "infin_sub.h"
#include <stdlib.h>

char *do_substraction(char *res, char *nbr1, char *nbr2)
{
    int hold = 0;
    int digit = 0;
    int i = 0;

    while (nbr1[i] != '\0') {
        if (ATOD(nbr1[i]) < ATOD(nbr2[i]) + hold) {
            digit = ATOD(nbr1[i]) + 10 - (ATOD(nbr2[i]) + hold);
            hold = 1;
        } else {
            digit = ATOD(nbr1[i]) - (ATOD(nbr2[i]) + hold);
            hold = 0;
        }
        res[i] = DTOA(digit);
        i++;
    }
    return (res);
}

int get_size_longest_str(char *str1, char *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);

    if (str1_len >= str2_len)
        return (str1_len);
    return (str2_len);
}

char *parse_zero_str(char *str)
{
    int i = 0;

    while (str[i] == '0' && str[i] != '\0')
        i++;
    return (str + i);
}

char *infin_sub(char const *str1, char const *str2)
{
    char *str1_parsed = parse_zero_str((char *)str1);
    char *str2_parsed = parse_zero_str((char *)str2);
    int res_size = get_size_longest_str(str1_parsed, str2_parsed);
    char *res = malloc(sizeof(char) * res_size + 3);
    char sign = find_res_sign(str1_parsed, str2_parsed);

    copy_fill_reverse_res(res, 0, res_size + 1);
    if (sign == '+')
        alloc_nbrs(str1_parsed, str2_parsed, res);
    if (sign == '-') {
        alloc_nbrs(str2_parsed, str1_parsed, res);
        add_neg_sign(res);
    }
    my_revstr(res);
    return (res);
}
