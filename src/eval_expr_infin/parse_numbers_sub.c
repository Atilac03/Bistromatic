/*
** EPITECH PROJECT, 2021
** parse_numbers.c
** File description:
** parse_numbers
*/

#include "my.h"
#include "infin_sub.h"
#include <stdlib.h>

char *parse_nbr(char *nbr)
{
    int len = my_strlen(nbr);

    while (len > 1 && nbr[len - 1] == '0') {
        nbr[len - 1] = '\0';
        len--;
    }
    return (nbr);
}

char *copy_fill_reverse_res(char *nbr, char *str, int size)
{
    my_memset(nbr, '0', size);
    if (str != 0)
        my_strcpy(nbr, str);
    nbr[size] = '\0';
    my_revstr(nbr);
    return (nbr);
}

void copy_nbrs(char *nbr1, char *nbr2, char *str1, char *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);
    int len_diff = 0;

    if (str1_len == str2_len) {
        my_strcpy(nbr1, str1);
        my_strcpy(nbr2, str2);
    }
    if (str1_len > str2_len) {
        len_diff = str1_len - str2_len;
        my_strcpy(nbr1, str1);
        my_strcpy(nbr2 + len_diff, str2);
    }
    if (str1_len < str2_len) {
        len_diff = str2_len - str1_len;
        my_strcpy(nbr1 + len_diff, str1);
        my_strcpy(nbr2, str2);
    }
}

void fill_nbrs(char *nbr1, char *nbr2, char *str1, char *str2)
{
    int res_size = get_size_longest_str(str1, str2);

    my_memset(nbr1, '0', res_size);
    my_memset(nbr2, '0', res_size);
    nbr1[res_size] = '\0';
    nbr2[res_size] = '\0';

    copy_nbrs(nbr1, nbr2, str1, str2);
    my_revstr(nbr1);
    my_revstr(nbr2);
}

char *alloc_nbrs(char *str1, char *str2, char *res)
{
    int res_size = get_size_longest_str(str1, str2);
    char *nbr1 = malloc(sizeof(char) * res_size + 1);
    char *nbr2 = malloc(sizeof(char) * res_size + 1);

    fill_nbrs(nbr1, nbr2, str1, str2);
    res = do_substraction(res, nbr1, nbr2);
    parse_nbr(res);
    free(nbr1);
    free(nbr2);
    return (res);
}
