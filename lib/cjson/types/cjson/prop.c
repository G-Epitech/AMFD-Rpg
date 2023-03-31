/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** append
*/

#include <stdlib.h>
#include "types.h"
#include "internal/error.h"
#include "internal/utils.h"

static bool prevent_bad_object(cjson_t *object)
{
    if (!object) {
        internal_cjson_error(
            "unable to get prop in given 'object' : is NULL pointer",
            NULL
        );
        return true;
    }
    if (!CJSON_IS_OBJECT(object)) {
        internal_cjson_error(
            "unable to get prop in given 'object' : is not an object",
            NULL
        );
        return true;
    }
    return false;
}

cjson_t *cjson_get_prop(cjson_t *object, char *key)
{
    cjson_t *prop = NULL;
    cjson_t *read = NULL;

    if (prevent_bad_object(object))
        return NULL;
    read = object->value.v_object;
    while (read && !prop) {
        if (!read->key) {
            read = read->next;
            continue;
        }
        if (internal_cjson_strcmp(read->key, key) == 0)
            prop = read;
        read = read->next;
    }
    return prop;
}
