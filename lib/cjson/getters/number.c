/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** int
*/

#include <stdbool.h>
#include "cjson.h"

bool cjson_get_int(cjson_t *cjson, int *value)
{
    if (!cjson)
        return false;
    if (!CJSON_IS_NUMBER(cjson))
        return false;
    *value = (int) cjson->value.v_number;
    return true;
}

int cjson_get_int_unsafe(cjson_t *cjson)
{
    int value = 0;

    cjson_get_int(cjson, &value);
    return value;
}

bool cjson_get_float(cjson_t *cjson, float *value)
{
    if (!CJSON_IS_NUMBER(cjson))
        return false;
    *value = cjson->value.v_number;
    return true;
}

float cjson_get_float_unsafe(cjson_t *cjson)
{
    float value = 0;

    cjson_get_float(cjson, &value);
    return value;
}
