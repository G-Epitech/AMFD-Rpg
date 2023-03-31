/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** bool
*/

#include <stdbool.h>
#include "cjson.h"
#include "internal/error.h"
#include "internal/utils.h"

cjson_value_t internal_cjson_parse_null(char *json, int *i, bool *error)
{
    if (internal_cjson_strncmp(json + (*i), "null", 4) != 0) {
        internal_cjson_error("unable to parse null value", error);
    } else {
        *i += 4;
    }
    return CJSON_NULL;
}
