/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** Day 05, Task 06
*/

#include "include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0')
        a++;
    return s1[a] - s2[a];
}
