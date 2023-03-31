/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** Day 05, Task 07
*/

#include "include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;

    if (n < 1) {
        return 0;
    }
    while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0' && a != n)
        a++;
    return s1[a] - s2[a];
}
