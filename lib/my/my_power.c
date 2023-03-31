/*
** EPITECH PROJECT, 2022
** power.c
** File description:
** testing file
*/

#include "include/my.h"

int power (int nb,int power)
{
    int result = 1;

    for (int i = power; i > 0; i--) {
        result *= nb;
    }
    return result;
}
