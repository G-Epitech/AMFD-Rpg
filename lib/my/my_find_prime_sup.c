/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** Day 05, Task 06
*/

#include <stdbool.h>
#include "include/my.h"

int my_find_prime_sup(int nb)
{
    int i = nb;

    while (true) {
        if (my_is_prime(i) == 1)
            return i;
        i++;
    }
}
