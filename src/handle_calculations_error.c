/*
** EPITECH PROJECT, 2021
** handle_calculations_error.c
** File description:
** handle_calculations_error
*/

int check_divions_by_0(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
        i++;
    while (str[j] == '0' && str[j] != '\0')
        j++;
    if (i == j)
        return (-1);
    return (0);
}
