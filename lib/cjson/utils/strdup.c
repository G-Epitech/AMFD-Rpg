/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** strdup
*/

#include <stdlib.h>
#include "internal/utils.h"

char *internal_cjson_strdup(const char *s)
{
    size_t len = s ? internal_cjson_strlen(s) : 0;
    char *dup = s ? malloc(sizeof(char) * (len + 1)) : NULL;

    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        dup[i] = s[i];
    }
    dup[len] = '\0';
    return dup;
}

char *internal_cjson_strndup(const char *s, unsigned int n)
{
    size_t len = s ? internal_cjson_strlen(s) : 0;
    char *dup = n > len ? malloc(len + 1) : malloc(n + 1);

    len = (n < len) ? n : len;
    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        dup[i] = s[i];
    }
    dup[len] = '\0';
    return dup;
}
