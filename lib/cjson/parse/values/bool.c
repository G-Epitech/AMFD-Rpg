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
#include "internal/parsing.h"

static bool get_true(char *json, int *i, bool *error)
{
    if (internal_cjson_strncmp(json + (*i), "true", 4) != 0) {
        internal_cjson_error("unable to parse boolean value (true)", error);
        return true;
    }
    *i += 4;
    return true;
}

static bool get_false(char *json, int *i, bool *error)
{
    if (internal_cjson_strncmp(json + (*i), "false", 5) != 0) {
        internal_cjson_error("unable to parse boolean value (false)", error);
        return false;
    }
    *i += 5;
    return false;
}

cjson_value_t internal_cjson_parse_bool(char *json, int *i, bool *error)
{
    bool value = false;

    if (json[*i] != 't' && json[*i] != 'f') {
        internal_cjson_error("unable to parse boolean value (type)", error);
        return CJSON(value);
    }
    if (json[*i] == 't')
        value = get_true(json, i, error);
    else if (json[*i] == 'f')
        value = get_false(json, i, error);
    return CJSON(value);
}
