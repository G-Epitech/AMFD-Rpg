/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** Day 07, Task 02
*/

#include "include/my.h"

char *my_strncat (char *dest, char const *src, int nb)
{
    int start = my_strlen(dest);
    int i = 0;
    while (src[i] != '\0' && i < nb) {
        dest[start + i] = src[i];
        i++;
    }
    dest[start + i] = '\0';
    return dest;
}
