/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** set
*/

#include <stdio.h>
#include <stdlib.h>
#include "cjson.h"
#include "internal/utils.h"

int cjson_set_value(cjson_t *cjson, cjson_value_t value,
cjson_type_t type)
{
    if (!cjson)
        return -1;
    cjson_free_value(cjson);
    cjson->type = type;
    if (type == CJSON_STRING_T && value.v_string)
        cjson->value = CJSON(internal_cjson_strdup(value.v_string));
    else
        cjson->value = value;
    return 0;
}
