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

bool cjson_get_prop_array(cjson_t *object, char *key, cjson_array_t **value)
{
    cjson_t *prop = cjson_get_prop(object, key);

    if (!prop)
        return false;
    if (!CJSON_IS_ARRAY(prop))
        return false;
    *value = prop->value.v_array;
    return true;
}

cjson_array_t *cjson_get_prop_array_unsafe(cjson_t *object, char *key)
{
    cjson_array_t *value = NULL;

    cjson_get_prop_array(object, key, &value);
    return value;
}
