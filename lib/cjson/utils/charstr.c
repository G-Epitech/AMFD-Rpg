/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** charstr
*/

#include <stdbool.h>

bool internal_cjson_char_in_str(char c, char *chars)
{
    while (*chars) {
        if (*chars == c)
            return true;
        chars++;
    }
    return false;
}
