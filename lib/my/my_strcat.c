/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** Day 07, Task 02
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int i = 0;
    char *final = malloc(sizeof(char) * dest_len + src_len + 1);

    for (int y = 0; y < dest_len; y++) {
        final[y] = dest[y];
    }
    for (int y = 0; y < dest_len; y++) {
        final[dest_len + y] = src[y];
    }
    final[dest_len + src_len] = '\0';
    return final;
}
