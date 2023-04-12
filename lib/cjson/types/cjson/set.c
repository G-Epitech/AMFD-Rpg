/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** set
*/

#include <stdlib.h>
#include <stdio.h>
#include "cjson.h"
#include "internal/utils.h"

void cjson_unset_prop(cjson_t *object, char *key)
{
    if (!object)
        return;
    cjson_free(cjson_get_prop(object, key));
}

int cjson_set_prop(cjson_t *object, char *key, cjson_value_t value,
cjson_type_t type)
{
    cjson_t *prop = NULL;

    if (!object)
        return 0;
    cjson_unset_prop(object, key);
    prop = cjson_new(key);
    if (cjson_set_value(prop, value, type) == -1) {
        cjson_free(prop);
        return -1;
    }
    prop->next = object->value.v_object;
    if (prop->next)
        prop->next->prev = prop;
    prop->prev = NULL;
    object->value.v_object = prop;
    return 0;
}

int cjson_set_key(cjson_t *cjson, char *key)
{
    if (!cjson)
        return 0;
    if (cjson->key)
        free(cjson->key);
    cjson->key = internal_cjson_strdup(key);
    if (!cjson->key)
        return -1;
    return 0;
}

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
