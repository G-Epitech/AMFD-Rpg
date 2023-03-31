/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** int
*/

#include <stdbool.h>
#include <stdlib.h>
#include "cjson.h"
#include "internal/utils.h"

bool cjson_get_string(cjson_t *cjson, char **value)
{
    if (!cjson)
        return false;
    if (!CJSON_IS_STRING(cjson))
        return false;
    *value = internal_cjson_strdup(cjson->value.v_string);
    return (*value) ? true : false;
}

char *cjson_get_string_unsafe(cjson_t *cjson)
{
    char *value = NULL;

    cjson_get_string(cjson, &value);
    return value;
}
