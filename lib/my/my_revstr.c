/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** Day 06, task 03
*/

#include "include/my.h"

char * my_revstr(char *str)
{
    int last = my_strlen(str);

    for (int i = 0; i != last / 2; i++) {
        my_swap_char(str + i,str + last - i - 1);
    }
    return str;
}
