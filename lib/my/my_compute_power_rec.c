/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** Day 05, Task 04
*/

#include "include/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p <= 0) {
        return 1;
    }
    return nb * my_compute_power_rec(nb, p - 1);
}
