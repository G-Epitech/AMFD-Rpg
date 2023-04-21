/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** string
*/

#include <stdbool.h>
#include <stdlib.h>
#include "cjson.h"
#include "internal/defs.h"
#include "internal/error.h"
#include "internal/parsing.h"

cjson_value_t internal_cjson_parse_string(char *json, int *i, bool *error)
{
    char *value = NULL;
    size_t len = internal_cjson_parse_string_get_len(json, *i, error);

    if (*error)
        return CJSON(value);
    value = internal_cjson_parse_string_dup(json, i, len);
    if (!value)
        internal_cjson_error("unable to alloc string value", error);
    *i += (!(*error) ? 1 : 0);
    return CJSON(value);
}
