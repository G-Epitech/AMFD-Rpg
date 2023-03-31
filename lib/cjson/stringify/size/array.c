/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** array
*/

#include "types.h"
#include "internal/utils.h"
#include "internal/stringify.h"

static bool get_elements_size(cjson_t *cjson, size_t *size,
int depth, bool *error)
{
    cjson_t *element = cjson->value.v_array->first;
    bool lined = false;

    while (element && !(*error)) {
        if (!CJSON_IS_PRIMARY(element) || CJSON_IS_STRING(element))
            lined = true;
        if (lined) {
            *size += 1;
            internal_cjson_string_size_add_tabs(depth, size);
        }
        internal_cjson_string_size(element, size, depth, error);
        if (element->next)
            *size += 1;
        if (element->next && !lined)
            *size += 1;
        element = element->next;
    }
    return lined;
}

void internal_cjson_string_size_array(cjson_t *cjson, size_t *size,
int depth, bool *error)
{
    bool lined = false;

    *size += 1;
    lined = get_elements_size(cjson, size, depth + 1, error);
    if (lined) {
        *size += 1;
        internal_cjson_string_size_add_tabs(depth, size);
    }
    *size += 1;
}
