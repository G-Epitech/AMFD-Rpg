/*
** EPITECH PROJECT, 2023
** Project By Axel.F
** File description:
** Axel.F
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

int len_nb(int nb)
{
    int l = 0;
    int nb_donne = nb;

    while ((nb_donne != 0)) {
        l = l + 1;
        nb_donne = nb_donne / 10;
    }
    return (l);
}

int handle_negative(int *number, char *number_str, int *index_number)
{
    if ((*number) < 0) {
        (*number) *= -1;
        number_str[(*index_number)] = '-';
        (*index_number)++;
    }
    return 0;
}

char *nbr_to_str(int num)
{
    int len_num = len_nb(num);
    char *number_str = malloc(sizeof(char) * len_num + 1);
    int index_number = 0;
    int nb_moment = 0;

    if (num == 0)
        return my_strdup("0");
    handle_negative(&num, number_str, &index_number);
    for (int index = 0; index < len_num; index++, index_number++) {
        if (index == len_num - 1) {
            nb_moment = num % (my_compute_power_rec(10, (len_num - index)));
        } else {
            nb_moment = num /
            (my_compute_power_rec(10, (len_num - index - 1)));
            num -= nb_moment * my_compute_power_rec(10, (len_num - index - 1));
        }
        number_str[index_number] = nb_moment + '0';
    }
    number_str[index_number] = '\0';
    return number_str;
}
