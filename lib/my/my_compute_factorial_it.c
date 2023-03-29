/*
** EPITECH PROJECT, 2022
** my_compute_factorial_it.c
** File description:
** Day 05, Task 02
*/

#include "include/my.h"

int my_compute_factorial_it (int nb)
{
    int value = 1;

    if (nb < 0 || nb > 12) {
        return 0;
    }
    for (; nb > 1; nb--) {
        value *= nb;
    }
    return value;
}
