/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Day 09, task01
*/

#include <stdlib.h>
#include "include/my.h"

char *my_strdup(char const *src)
{
    char *newstr = malloc(my_strlen(src) + 1);

    my_strcpy(newstr, src);
    return newstr;
}
