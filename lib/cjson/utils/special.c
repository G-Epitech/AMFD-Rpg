/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** special
*/

#include <stdbool.h>
#include "internal/defs.h"

bool internal_cjson_is_special_char(char *json, int i)
{
    if (json[i] != '\\')
        return false;
    if (!json[i + 1])
        return false;
    return internal_cjson_char_in_str(json[i + 1], CJSON_SPECIAL_CHARS);
}
