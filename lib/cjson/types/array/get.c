/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** get
*/

#include <stdlib.h>
#include "cjson.h"
#include "internal/error.h"

static bool prevent_error(cjson_array_t *array, size_t index)
{
    if (!array) {
        internal_cjson_error(
            "unable to get array element (null array pointer)",
            NULL
        );
        return true;
    }
    if (index >= array->len) {
        internal_cjson_error(
            "unable to get array element (index out of range)",
            NULL
        );
        return true;
    }
    return false;
}

cjson_t *cjson_array_get(cjson_array_t *array, size_t index)
{
    size_t i = 0;
    cjson_t *cjson = array ? array->first : NULL;

    if (prevent_error(array, index))
        return NULL;
    while (cjson && i < index) {
        cjson = cjson->next;
        i += 1;
    }
    if (i == index)
        return cjson;
    else
        return NULL;
}
