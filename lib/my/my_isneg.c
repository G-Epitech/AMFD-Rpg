/*
** EPITECH PROJECT, 2022
** my_print_isngeg.c
** File description:
** task04
*/

#include "include/my.h"

int my_isneg(int n)
{
    if (n >= 0){
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
