/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** task07
*/

#include "include/my.h"

static void display_specific_num(void)
{
    my_putstr("-2147483648");
}

static int divide_number(long div, int nb)
{
    int print = 0;

    for (; div != 1; div /= 10){
        print = nb / div;
        my_putchar(print + '0');
        nb = nb % div;
    }
    my_putchar(nb + '0');
    return 0;
}

static int get_div_value(int nb)
{
    int test = nb;
    long up = 1;

    for (; test > 9; up = up * 10) {
        test = nb;
        test = test / up;
    }
    return up /= 10;
}

int my_put_nbr(int nb)
{
    int div = 0;

    if (nb < -2147483647) {
        display_specific_num();
        return 1;
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
        return 1;
    }
    div = get_div_value(nb);
    divide_number(div,nb);
    return 0;
}
