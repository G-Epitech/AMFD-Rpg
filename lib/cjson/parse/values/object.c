/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** object
*/

#include <stdlib.h>
#include "types.h"
#include "cjson.h"
#include "internal/error.h"
#include "internal/utils.h"
#include "internal/parsing.h"

static cjson_t *parse_prop(char *json, int *i, bool *error)
{
    cjson_t *prop = cjson_new(NULL);

    internal_cjson_skip_blank(json, i);
    prop->key = internal_cjson_parse_key(json, i, error);
    if (*error)
        return NULL;
    internal_cjson_skip_blank(json, i);
    internal_cjson_check_separator(json, i, error);
    if (*error) {
        cjson_free(prop);
        return NULL;
    }
    internal_cjson_skip_blank(json, i);
    internal_cjson_get_value(prop, json, i, error);
    if (*error) {
        cjson_free(prop);
        return NULL;
    }
    return prop;
}

static void add_prop(cjson_t **first, cjson_t **last, cjson_t *prop)
{
    if (!(*first))
        *first = prop;
    if ((*last)) {
        (*last)->next = prop;
        prop->prev = *last;
    }
    *last = prop;
}

cjson_value_t internal_cjson_parse_object(char *json, int *i, bool *error)
{
    cjson_t *first = NULL;
    cjson_t *last = NULL;
    cjson_t *prop = NULL;

    internal_cjson_skip_blank(json, i);
    while (json[*i] != '\0' && json[*i] != '}' && !(*error)) {
        prop = parse_prop(json, i, error);
        if (!prop || (*error))
            break;
        add_prop(&first, &last, prop);
        internal_cjson_skip_blank(json, i);
        if (json[*i] == ',' || json[*i] == '}')
            *i += (json[*i] == ',') ? 1 : 0;
        else
            internal_cjson_error("missing ',' or '}' in object", error);
    }
    *i += (!(*error) ? 1 : 0);
    return CJSON(first);
}
