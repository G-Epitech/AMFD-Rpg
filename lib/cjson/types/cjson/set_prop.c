/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** set_prop
*/

#include <stdio.h>
#include <stdlib.h>
#include "cjson.h"
#include "internal/utils.h"

static bool set_prop_value(cjson_t **prop, char *key, cjson_value_t value,
cjson_type_t type)
{
    if (type == CJSON_OBJECT_T && value.v_object) {
        cjson_set_key(value.v_object, key);
        *prop = value.v_object;
    } else {
        *prop = cjson_new(key);
        if (cjson_set_value(*prop, value, type) == -1) {
            cjson_free(*prop);
            return false;
        }
    }
    return true;
}

int cjson_set_prop(cjson_t *object, char *key, cjson_value_t value,
cjson_type_t type)
{
    cjson_t *prop = NULL;

    if (!object)
        return -1;
    cjson_unset_prop(object, key);
    if (!set_prop_value(&prop, key, value, type) || !prop)
        return -1;
    prop->next = object->value.v_object;
    if (prop->next)
        prop->next->prev = prop;
    prop->prev = NULL;
    object->value.v_object = prop;
    return 0;
}

void cjson_unset_prop(cjson_t *object, char *key)
{
    cjson_t *prop = NULL;

    if (!object)
        return;
    prop = cjson_get_prop(object, key);
    if (!prop)
        return;
    if (prop->prev)
        prop->prev->next = prop->next;
    if (prop->next)
        prop->next->prev = prop->prev;
    cjson_free(prop);
}
