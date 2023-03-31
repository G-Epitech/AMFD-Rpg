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

static bool fill_array(cjson_array_t *cjson, char **array)
{
    cjson_t *element = cjson->first;
    size_t i = 0;
    bool valid = true;

    while (element && valid) {
        if (!CJSON_IS_STRING(element)) {
            valid = false;
            break;
        }
        array[i++] = internal_cjson_strdup(element->value.v_string);
        element = element->next;
    }
    array[i] = NULL;
    return valid;
}

void cjson_array_free_string_array(char **array)
{
    size_t i = 0;

    while (array[i]) {
        free(array[i++]);
    }
    free(array);
}

char **cjson_array_to_string_array(cjson_array_t *cjson)
{
    char **array = NULL;

    array = malloc(sizeof(char *) * (cjson->len + 1));
    if (!array)
        return NULL;
    if (!fill_array(cjson, array)) {
        cjson_array_free_string_array(array);
        internal_cjson_error("not all array elements are strings", NULL);
        return NULL;
    }
    return array;
}
