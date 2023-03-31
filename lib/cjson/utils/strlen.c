/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** strlen
*/

#include <stddef.h>

size_t internal_cjson_strlen(const char *s)
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }
    return i;
}
