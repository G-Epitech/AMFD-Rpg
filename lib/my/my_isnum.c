/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** Day 06, task13
*/

#include "include/my.h"

int my_str_isnum(char const *str)
{
    int ok = 0;

    if (my_strlen(str) < 1)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            ok++;
        }
    }
    if (my_strlen(str) != ok){
        return 0;
    }
    return 1;
}

int my_char_isnum(char value)
{
    if (value >= '0' && value <= '9') {
        return 1;
    }
    return 0;
}
