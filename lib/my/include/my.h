/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Day 09, task02
** Header file that contains the prototypes of all
** the functions exposed in lib/my/libmy.a.
** Start in lib/my/ the script build.sh to build/update the library.
*/

#pragma once

int my_compute_factorial_it (int nb);
int my_compute_factorial_rec (int nb);
int my_compute_power_it (int nb , int p);
int my_compute_power_rec (int nb , int p);
int my_compute_square_root (int nb);
void debug_nbr (char const *texte, int nbr);
void debug_str (char const *texte, const char *str);
void separator (void);
char *my_evil_str (char *str);
int my_find_prime_sup (int nb);
int my_getnbr( char const *str );
int my_is_prime (int nb);
int my_isneg(int n);
int power (int nb,int power);
int my_put_nbr (int nb);
void my_putchar (char c);
int my_putstr (char const *str);
char *my_revstr (char *str);
int my_showmem (char const *str,  int size);
int my_showstr (char const *str);
void my_sort_int_array (int *array , int size);
int my_str_isalpha (char const *str);
int my_char_isalpha (char value);
int my_str_islower (char const *str);
int my_str_isnum (char const *str);
int my_char_isnum (char value);
int my_str_isprintable (char const *str);
int my_str_isupper (char const *str);
char *my_strcapitalize (char *str);
char *my_strcat (char *dest, char const *src);
int my_strcmp (char const *s1, char const *s2);
char *my_strcpy (char *dest, char const *src );
int my_strlen (char const *str);
char *my_strlowcase (char *str);
char *my_strncat (char *dest, char const *src, int nb);
int my_strncmp (char const *s1, char const *s2, int n);
char *my_strncpy (char *dest , char const *src , int n);
char *my_strstr (char *str, char const *to_find);
char* my_strupcase (char *str);
void my_swap(int *a, int *b);
void my_swap_char(char *a, char *b);
char *concat_params (int argc, char **argv);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array (char const *str, char *del);
char *my_strdup (char const *src);
int error(char *str);
char* nbr_to_str(int n);
