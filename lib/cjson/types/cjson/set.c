/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** set
*/

#include <stdlib.h>
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
    if (!prop)
        return -1;
    prop->type = type;
    prop->value = value;
    return 0;
}

int cjson_set_prop_key(cjson_t *prop, char *key)
{
    if (!prop)
        return 0;
    if (prop->key)
        free(prop->key);
    prop->key = internal_cjson_strdup(key);
    if (!prop->key)
        return -1;
    return 0;
}

int cjson_set_prop_value(cjson_t *prop, cjson_value_t value,
cjson_type_t type)
{
    if (!prop)
        return -1;
    cjson_free_value(prop);
    prop->type = type;
    prop->value = value;
    return 0;
}
