/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** convert
*/

#include <stdlib.h>
#include "cjson.h"
#include "types/array.h"
#include "internal/defs.h"
#include "internal/error.h"
#include "internal/utils.h"

static bool fill_array(cjson_array_t *cjson, float *array, size_t size)
{
    bool valid = true;
    cjson_t *element = NULL;

    for (size_t i = 0; i < size; i++) {
        element = cjson_new(CJSON_ARRAY_KEY);
        if (!element) {
            valid = false;
            break;
        }
        element->type = CJSON_NUMBER_T;
        element->value.v_number = array[i];
        cjson_array_append(cjson, element);
    }
    return valid;
}

cjson_array_t *cjson_array_from_float_array(float *array, size_t size)
{
    cjson_array_t *cjson = cjson_array_new();

    if (!cjson) {
        internal_cjson_error("cjson array from float array failed (malloc)",
        NULL);
        return NULL;
    }
    if (!array)
        return cjson;
    if (!fill_array(cjson, array, size)) {
        internal_cjson_error("cjson array filling from float failed (malloc)",
        NULL);
        cjson_array_free(cjson);
        return NULL;
    }
    return cjson;
}
