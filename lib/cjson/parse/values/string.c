/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** string
*/

#include <stdbool.h>
#include <stdlib.h>
#include "cjson.h"
#include "internal/error.h"
#include "internal/utils.h"

static unsigned int get_len(char *json, int i, bool *error)
{
    unsigned int len = 0;

    while (json[i] != '\0' && json[i] != '"') {
        len += 1;
        i += 1;
    }
    if (json[i] != '"')
        internal_cjson_error("unable to reach end of string", error);
    return len;
}

cjson_value_t internal_cjson_parse_string(char *json, int *i, bool *error)
{
    char *value = NULL;
    unsigned int len = get_len(json, *i, error);

    if (*error)
        return CJSON(value);
    value = internal_cjson_strndup(json + *i, len);
    if (!value)
        internal_cjson_error("unable to alloc string value", error);
    *i += len + (!(*error) ? 1 : 0);
    return CJSON(value);
}
