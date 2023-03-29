/*
** EPITECH PROJECT, 2023
** nbr_to_str.c
** File description:
** Number to string
*/

#include <stdio.h>
#include <stdlib.h>

char* nbr_to_str(int n)
{
    int num_digits = 0;
    int tmp = n;
    char *str = 0;

    while (tmp != 0) {
        num_digits++;
        tmp /= 10;
    }
    str = malloc(num_digits + 1);
    if (n == 0) {
        str[0] = '0';
        return str;
    }
    for (int i = num_digits - 1; i >= 0; i--) {
        str[i] = (n % 10) + '0';
        n /= 10;
    }
    str[num_digits] = '\0';
    return str;
}
