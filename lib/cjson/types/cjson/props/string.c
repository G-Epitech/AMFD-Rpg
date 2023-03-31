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

bool cjson_get_prop_string(cjson_t *object, char *key, char **value)
{
    cjson_t *prop = cjson_get_prop(object, key);

    if (!prop)
        return false;
    if (!CJSON_IS_STRING(object))
        return false;
    *value = internal_cjson_strdup(prop->value.v_string);
    return (*value) ? true : false;
}

char *cjson_get_prop_string_unsafe(cjson_t *object, char *key)
{
    char *value = NULL;

    cjson_get_prop_string(object, key, &value);
    return value;
}
