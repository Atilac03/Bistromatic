/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** header files of my library
*/

#include <stddef.h>
#ifndef MY_H_
    #define MY_H_
    #define ATOD(x) (x - '0')
    #define DTOA(x) (x + '0')

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int is_negative(char const *str);
int get_nbr_from_str(char *str, int len);
int check_nbr_error(int sign, char *str, int nb);
char *clean_str(char *str);
char *get_first_nbr(char *str, char *dest);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_show_word_array(char *const *tab);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char **my_str_to_word_array(char const *str);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int parse_string(char const *str, int *count, int *words_nb, int i);
void *my_memset(void *s, int c, size_t n);
char *my_getstr(int nbr);

#endif /* MY_H_ */
