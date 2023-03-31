/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** object
*/

#include <stdlib.h>
#include "cjson.h"
#include "internal/defs.h"
#include "internal/error.h"
#include "internal/utils.h"
#include "internal/parsing.h"

static cjson_t *parse_element(char *json, int *i, bool *error)
{
    cjson_t *element = cjson_new(CJSON_ARRAY_KEY);

    internal_cjson_skip_blank(json, i);
    internal_cjson_get_value(element, json, i, error);
    if (*error) {
        cjson_free(element);
        return NULL;
    }
    return element;
}

cjson_value_t internal_cjson_parse_array(char *json, int *i, bool *error)
{
    cjson_array_t *array = cjson_array_new();
    cjson_t *element = NULL;

    if (!array)
        internal_cjson_error("unable to allocate array", error);
    internal_cjson_skip_blank(json, i);
    while (json[*i] != '\0' && json[*i] != ']' && !(*error)) {
        element = parse_element(json, i, error);
        if (*error)
            break;
        cjson_array_append(array, element);
        internal_cjson_skip_blank(json, i);
        if (json[*i] == ',' || json[*i] == ']')
            *i += (json[*i] == ',') ? 1 : 0;
        else
            internal_cjson_error("missing ',' or ']' in array", error);
    }
    *i += (!(*error) ? 1 : 0);
    return CJSON(array);
}
