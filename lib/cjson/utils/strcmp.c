/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** strcmp
*/

#include "internal/utils.h"

static char get_i_char(char const *str, int i, int len)
{
    if (i < len) {
        return str[i];
    } else {
        return (0);
    }
}

int internal_cjson_strcmp(char const *s1, char const *s2)
{
    int len_s1 = internal_cjson_strlen(s1);
    int len_s2 = internal_cjson_strlen(s2);
    char cs1 = 0;
    char cs2 = 0;
    int i = 0;

    while (i < len_s1 || i < len_s2) {
        cs1 = get_i_char(s1, i, len_s1);
        cs2 = get_i_char(s2, i, len_s2);
        if (cs1 - cs2 != 0) {
            return (cs1 - cs2);
        }
        i++;
    }
    return (0);
}

int internal_cjson_strncmp(char const *s1, char const *s2, unsigned int n)
{
    unsigned int i = 0;

    if (n < 1)
        return 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n) {
        i++;
    }
    if (i != n)
        return -1;
    return s1[i - 1] - s2[i - 1];
}
