/*
** EPITECH PROJECT, 2022
** my_str_islower
** File description:
** Day 06, task14
*/

#include "include/my.h"

int my_str_islower(char const *str)
{
    int ok = 0;

    if (my_strlen(str) < 1)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            ok++;
        }
    }
    if (my_strlen(str) != ok){
        return 0;
    }

    return 1;
}
