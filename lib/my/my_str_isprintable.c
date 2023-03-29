/*
** EPITECH PROJECT, 2022
** testmy_str_isupper.c
** File description:
** Day 06, task15
*/

#include "include/my.h"

int my_str_isprintable(char const *str)
{
    int ok = 0;

    if (my_strlen(str) < 1)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 127) {
            ok++;
        }
    }
    if (my_strlen(str) != ok){
        return 0;
    }

    return 1;
}
