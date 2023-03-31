/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** Day 04, Task 01
*/

#include "include/my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void my_swap_char(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}
