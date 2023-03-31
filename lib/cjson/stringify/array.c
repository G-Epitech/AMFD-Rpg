/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** array
*/

#include "cjson.h"
#include "internal/stringify.h"

static bool stringify_elements(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error)
{
    cjson_t *element = cjson->value.v_array->first;
    bool lined = false;

    while (element && !(*error)) {
        if (!CJSON_IS_PRIMARY(element) || CJSON_IS_STRING(element))
            lined = true;
        if (lined) {
            json->content[json->i++] = '\n';
            internal_cjson_stringify_add_tabs(json, depth);
        }
        internal_cjson_stringify(element, json, depth, error);
        if (element->next)
            json->content[json->i++] = ',';
        if (element->next && !lined)
            json->content[json->i++] = ' ';
        element = element->next;
    }
    return lined;
}

void internal_cjson_stringify_array(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error)
{
    bool lined = false;

    json->content[json->i++] = '[';
    lined = stringify_elements(cjson, json, depth + 1, error);
    if (lined) {
        json->content[json->i++] = '\n';
        internal_cjson_stringify_add_tabs(json, depth);
    }
    json->content[json->i++] = ']';
}
