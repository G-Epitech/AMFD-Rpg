/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** Day 05, Task 03
*/

#include "include/my.h"

int my_compute_power_it(int nb, int p)
{
    int result = 1;

    if (p < 0) {
        return 0;
    }
    if (nb == 0 || p == 0) {
        return 1;
    }
    for (int i = p; i > 0; i--) {
        result *= nb;
    }
    return result;
}
