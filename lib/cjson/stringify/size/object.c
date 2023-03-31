/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** object
*/

#include <stdlib.h>
#include "types.h"
#include "internal/utils.h"
#include "internal/stringify.h"

static void get_props_sizes(cjson_t *cjson, size_t *size,
int depth, bool *error)
{
    cjson_t *prop = cjson->value.v_object;

    while (prop && !(*error)) {
        *size += 1;
        internal_cjson_string_size_add_tabs(depth, size);
        *size += 1;
        *size += internal_cjson_strlen(prop->key);
        *size += 3;
        internal_cjson_string_size(prop, size, depth, error);
        *size += 1;
        prop = prop->next;
    }
}

void internal_cjson_string_size_object(cjson_t *cjson, size_t *size,
int depth, bool *error)
{
    *size += 1;
    get_props_sizes(cjson, size, depth + 1, error);
    if (cjson->value.v_object) {
        internal_cjson_string_size_add_tabs(depth, size);
    }
    *size += 1;
}
