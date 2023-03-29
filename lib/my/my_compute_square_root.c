/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** Day 05, Task 05
*/

#include "include/my.h"

int my_compute_square_root (int nb)
{
    int result = nb;
    while (my_compute_power_it(result, 2) != nb && result != 0) {
        result--;
    }
    return result;
}
