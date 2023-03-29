/*
** EPITECH PROJECT, 2022
** my_is_prime.c
** File description:
** Day 05, Task 06
*/

#include "include/my.h"

int my_is_prime (int nb)
{
    if (nb == 2) {
        return 1;
    }
    if (nb == 1 || nb < 0) {
        return 0;
    }
    int test = 1;
    for (int i = 2; i < 10000000; i++) {
        if (nb % i == 0 && nb != i) {
            test = 0;
        }
    }
    return test;
}
