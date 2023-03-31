/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** int
*/

#include <stdbool.h>
#include "cjson.h"

bool cjson_get_prop_int(cjson_t *cjson, char *key, int *value)
{
    cjson_t *prop = cjson_get_prop(cjson, key);

    if (!prop)
        return false;
    if (!CJSON_IS_NUMBER(prop))
        return false;
    *value = (int) prop->value.v_number;
    return true;
}

int cjson_get_prop_int_unsafe(cjson_t *cjson, char *key)
{
    int value = 0;

    cjson_get_prop_int(cjson, key, &value);
    return value;
}

bool cjson_get_prop_float(cjson_t *cjson, char *key, float *value)
{
    cjson_t *prop = cjson_get_prop(cjson, key);

    if (!prop)
        return false;
    if (!CJSON_IS_NUMBER(prop))
        return false;
    *value = prop->value.v_number;
    return true;
}

float cjson_get_prop_float_unsafe(cjson_t *cjson, char *key)
{
    float value = 0;

    cjson_get_prop_float(cjson, key, &value);
    return value;
}
