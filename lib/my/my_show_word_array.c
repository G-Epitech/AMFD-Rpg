/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Day 09, task03
*/

#include "include/my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
