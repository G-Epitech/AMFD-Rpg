/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** Day 05, Task 08
*/

#include "include/my.h"

char *my_strupcase (char *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++) {
        if (str[a] >= 'a' && str[a] <= 'z') {
            str[a] -= 32;
        }
    }
    return str;
}
