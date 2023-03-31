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

static bool fill_array(cjson_array_t *cjson, char **array)
{
    bool valid = true;
    cjson_t *element = NULL;
    size_t i = 0;

    while (array[i]) {
        element = cjson_new(CJSON_ARRAY_KEY);
        if (!element) {
            valid = false;
            break;
        }
        element->type = CJSON_STRING_T;
        element->value.v_string = internal_cjson_strdup(array[i]);
        cjson_array_append(cjson, element);
    }
    return valid;
}

cjson_array_t *cjson_array_from_string_array(char **array)
{
    cjson_array_t *cjson = cjson_array_new();

    if (!cjson) {
        internal_cjson_error("cjson array from string array failed (malloc)",
        NULL);
        return NULL;
    }
    if (!array)
        return cjson;
    if (!fill_array(cjson, array)) {
        internal_cjson_error(
            "cjson array filling from string failed (malloc)",
            NULL
        );
        cjson_array_free(cjson);
        return NULL;
    }
    return cjson;
}
