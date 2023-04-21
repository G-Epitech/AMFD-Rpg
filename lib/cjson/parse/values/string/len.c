/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** len
*/

#include <stdbool.h>
#include "internal/error.h"
#include "internal/utils.h"

static void prevent_specials_chars(char *json, int *i)
{
    if (json[*i] != '\\')
        return;
    if (!json[*i + 1])
        return;
    if (CJSON_INTERNAL_IS_ESC_SPECIAL(json[*i + 1]))
        *i += 1;
}

size_t internal_cjson_parse_string_get_len(char *json,
int i, bool *error)
{
    size_t len = 0;

    while (json[i] != '\0' && json[i] != '"') {
        len += 1;
        prevent_specials_chars(json, &i);
        i += 1;
    }
    if (json[i] != '"')
        internal_cjson_error("unable to reach end of string", error);
    return len;
}
