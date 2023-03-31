/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec.c
** File description:
** Day 05, Task 02
*/

#include "include/my.h"

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb > 12) {
        return 0;
    }
    if (nb <= 1) {
        return 1;
    }
    return nb * my_compute_factorial_rec(nb - 1);
}
