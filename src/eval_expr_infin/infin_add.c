/*
** EPITECH PROJECT, 2021
** infin_add.c
** File description:
** infin_add
*/

#include "my.h"
#include "parse_numbers.h"
#include <stdlib.h>

char *do_addition(char *res, char *nbr1, char *nbr2)
{
    int hold = 0;
    int add = 0;
    int i = 0;

    while (nbr1[i] != '\0') {
        add = ATOD(nbr1[i]) + ATOD(nbr2[i]) + hold;
        if (add >= 10) {
            res[i] = DTOA(add - 10);
            hold = 1;
        } else {
            res[i] = DTOA(add);
            hold = 0;
        }
        i++;
    }
    if (hold == 1)
        res[i] = DTOA(hold);
    return (res);
}

int find_longest_str(char *str1, char *str2)
{
    int str1_len = my_strlen(str1);
    int str2_len = my_strlen(str2);

    if (str1_len >= str2_len)
        return (str1_len);
    return (str2_len);
}

char *infin_add(char *str1, char *str2)
{
    int res_size = find_longest_str(str1, str2);
    char *res = malloc(sizeof(char) * res_size + 2);

    copy_fill_reverse_res(res, 0, res_size + 1);
    alloc_nbrs(str1, str2, res);
    return (res);
}
