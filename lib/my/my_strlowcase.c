/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** Day 06, Task 09
*/

#include "include/my.h"

char *my_strlowcase (char *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++) {
        if (str[a] >= 'A' && str[a] <= 'Z') {
            str[a] += 32;
        }
    }

    return str;
}
