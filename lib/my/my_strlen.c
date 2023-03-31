/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** Day 04, Task 03
*/

#include "include/my.h"

int my_strlen(char const *str)
{
    int nb = 0;

    for (; str[nb] != '\0'; nb++) {}
    return nb;
}
