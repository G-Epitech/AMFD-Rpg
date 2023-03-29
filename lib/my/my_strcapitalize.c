/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** Day 06, Task 10
*/

#include "include/my.h"

char *my_strcapitalize (char *str)
{
    int a = 0;
    int have_upper = 0;

    for (; str[a] != '\0'; a++) {
        if (have_upper && str[a] >= 'A' && str[a] <= 'Z') {
            str[a] += 32;
        }
        if (!have_upper && str[a] >= 'a' && str[a] <= 'z') {
            str[a] -= 32;
            have_upper = 1;
        }
        have_upper = 1;
        if (str[a] == ' ' || str[a] == '+' || str[a] == '-') {
            have_upper = 0;
        }
    }

    return str;
}
