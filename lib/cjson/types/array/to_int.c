/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** convert
*/

#include <stdlib.h>
#include "types/array.h"
#include "internal/error.h"
#include "internal/utils.h"

static bool fill_array(cjson_array_t *cjson, int *array)
{
    cjson_t *element = cjson->first;
    size_t i = 0;
    bool valid = true;

    while (element && valid) {
        if (!CJSON_IS_NUMBER(element)) {
            valid = false;
            break;
        }
        array[i++] = (int) element->value.v_number;
        element = element->next;
    }
    return valid;
}

int *cjson_array_to_int_array(cjson_array_t *cjson, size_t *size)
{
    int *array = NULL;

    *size = 0;
    array = malloc(sizeof(int) * cjson->len);
    if (!array)
        return NULL;
    if (!fill_array(cjson, array)) {
        free(array);
        internal_cjson_error("not all array elements are number", NULL);
        return NULL;
    }
    *size = cjson->len;
    return array;
}
