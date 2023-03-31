/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** int
*/

#include <stdbool.h>
#include "cjson.h"

bool cjson_get_bool(cjson_t *cjson, bool *value)
{
    if (!cjson)
        return false;
    if (!CJSON_IS_BOOL(cjson))
        return false;
    *value = cjson->value.v_bool;
    return true;
}

bool cjson_get_bool_unsafe(cjson_t *cjson)
{
    bool value = false;

    cjson_get_bool(cjson, &value);
    return value;
}
