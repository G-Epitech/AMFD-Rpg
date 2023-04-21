/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** strlen
*/

#include <stddef.h>
#include "internal/utils.h"

size_t internal_cjson_strlen_with_specials(const char *s)
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0') {
        if (CJSON_INTERNAL_IS_SPECIAL(s[i]))
            j++;
        j++;
        i++;
    }
    return j;
}

size_t internal_cjson_strlen(const char *s)
{
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }
    return i;
}
