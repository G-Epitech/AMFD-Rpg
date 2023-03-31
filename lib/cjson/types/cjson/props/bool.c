/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** int
*/

#include <stdbool.h>
#include "cjson.h"

bool cjson_get_prop_bool(cjson_t *object, char *key, bool *value)
{
    cjson_t *prop = cjson_get_prop(object, key);

    if (!prop)
        return false;
    if (!CJSON_IS_BOOL(prop))
        return false;
    *value = prop->value.v_bool;
    return true;
}

bool cjson_get_prop_bool_unsafe(cjson_t *object, char *key)
{
    bool value = false;

    cjson_get_prop_bool(object, key, &value);
    return value;
}
