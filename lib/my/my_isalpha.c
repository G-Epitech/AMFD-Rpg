/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** Day 06, Task 12
*/

#include "include/my.h"

int my_str_isalpha(char const *str)
{
    int ok = 0;

    if (my_strlen(str) < 1)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ok++;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            ok++;
        }
    }
    if (my_strlen(str) != ok){
        return 0;
    }
    return 1;
}

int my_char_isalpha (char value)
{
    int ok = 0;

    if (value >= 'A' && value <= 'Z') {
        ok = 1;
    }
    if (value >= 'a' && value <= 'z') {
        ok = 1;
    }

    return ok;
}
