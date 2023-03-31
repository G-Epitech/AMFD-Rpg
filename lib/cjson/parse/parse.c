/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** parse
*/

#include <stdlib.h>
#include "cjson.h"
#include "internal/defs.h"
#include "internal/error.h"
#include "internal/utils.h"
#include "internal/parsing.h"

static bool prevent_bad_syntax(char *json, int *i)
{
    internal_cjson_skip_blank(json, i);
    if (json[*i] != '{' && json[*i] != '[') {
        internal_cjson_error("unable to find first '{' or '[' of JSON file",
        NULL);
        return true;
    }
    return false;
}

cjson_t *cjson_parse(char *json)
{
    int i = 0;
    cjson_t *cjson = NULL;
    bool error = false;

    if (prevent_bad_syntax(json, &i))
        return NULL;
    cjson = cjson_new(CJSON_ROOT);
    if (!cjson) {
        internal_cjson_error("an error occured during object alloc", NULL);
        return NULL;
    }
    internal_cjson_get_value(cjson, json, &i, &error);
    if (error) {
        cjson_free(cjson);
        return NULL;
    }
    return cjson;
}
