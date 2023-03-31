/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** to_string
*/

#include <stdlib.h>
#include "cjson.h"
#include "internal/defs.h"
#include "internal/utils.h"
#include "internal/error.h"
#include "internal/stringify.h"

void internal_cjson_stringify_add_tabs(internal_cjson_string_t *json,
int depth)
{
    size_t tabs = depth * CJSON_TAB_SIZE;

    for (size_t j = 0; j < tabs; j++) {
        json->content[json->i++] = ' ';
    }
}

void internal_cjson_stringify(cjson_t *cjson, internal_cjson_string_t *json,
int depth, bool *error)
{
    if (CJSON_IS_OBJECT(cjson))
        return internal_cjson_stringify_object(cjson, json, depth, error);
    if (CJSON_IS_ARRAY(cjson))
        return internal_cjson_stringify_array(cjson, json, depth, error);
    if (CJSON_IS_STRING(cjson))
        return internal_cjson_stringify_string(cjson, json);
    if (CJSON_IS_NUMBER(cjson))
        return internal_cjson_stringify_number(cjson, json);
    if (CJSON_IS_BOOL(cjson))
        return internal_cjson_stringify_bool(cjson, json);
    if (CJSON_IS_NULL(cjson))
        return internal_cjson_stringify_null(json);
    return internal_cjson_error("unknown value type (stringify)", error);
}

static char *get_final_string(cjson_t *cjson, size_t size,
bool *error)
{
    internal_cjson_string_t json = { NULL, 0 };

    (void) size;
    json.content = malloc(size + 1);
    if (!json.content) {
        internal_cjson_error("unable to alloc string (stringify)", error);
        return NULL;
    }
    json.content[0] = '\0';
    internal_cjson_stringify(cjson, &json, 0, error);
    if (*error) {
        free(json.content);
        return NULL;
    }
    json.content[size] = '\0';
    return json.content;
}

char *cjson_stringify(cjson_t *cjson)
{
    size_t size = 0;
    bool error = false;

    if (!cjson)
        return NULL;
    if (!CJSON_IS_OBJECT(cjson) && !CJSON_IS_ARRAY(cjson)) {
        internal_cjson_error("unable to export non object or array to string",
        NULL);
        return NULL;
    }
    internal_cjson_string_size(cjson, &size, 0, &error);
    if (error)
        return NULL;
    return get_final_string(cjson, size, &error);
}
