/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** Day 09, task02
*/

#include <stdlib.h>
#include "include/my.h"

char *concat_params (int argc, char **argv)
{
    int len = 0;
    char *newstr;

    for (int i = 0; i < argc; i++)
        len += my_strlen(argv[i]) + 1;

    newstr = malloc(len);

    for (int i = 0; i < argc; i++) {
        my_strcat(newstr, argv[i]);
        my_strcat(newstr, "\n");
    }
    return newstr;
}
