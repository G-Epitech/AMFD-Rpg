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

bool cjson_get_array(cjson_t *cjson, cjson_array_t **value)
{
    if (!cjson)
        return false;
    if (!CJSON_IS_ARRAY(cjson))
        return false;
    *value = cjson->value.v_array;
    return true;
}

cjson_array_t *cjson_get_array_unsafe(cjson_t *cjson)
{
    cjson_array_t *value = NULL;

    cjson_get_array(cjson, &value);
    return value;
}
