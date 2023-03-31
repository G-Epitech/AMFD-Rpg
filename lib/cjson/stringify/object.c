/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** object
*/

#include "types.h"
#include "internal/utils.h"
#include "internal/stringify.h"

static void stringify_props(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error)
{
    cjson_t *prop = cjson->value.v_object;
    int key_len = 0;

    while (prop && !(*error)) {
        json->content[json->i++] = '\n';
        internal_cjson_stringify_add_tabs(json, depth);
        json->content[json->i++] = '"';
        key_len = internal_cjson_strlen(prop->key);
        internal_cjson_strncpy(json->content + json->i, prop->key, key_len);
        json->i += key_len;
        json->content[json->i++] = '"';
        json->content[json->i++] = ':';
        json->content[json->i++] = ' ';
        internal_cjson_stringify(prop, json, depth, error);
        json->content[json->i++] = (prop->next) ? ',' : '\n';
        prop = prop->next;
    }
}

void internal_cjson_stringify_object(cjson_t *cjson,
internal_cjson_string_t *json, int depth, bool *error)
{
    json->content[json->i++] = '{';
    stringify_props(cjson, json, depth + 1, error);
    if (cjson->value.v_object)
        internal_cjson_stringify_add_tabs(json, depth);
    json->content[json->i++] = '}';
}
