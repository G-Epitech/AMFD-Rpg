/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** value
*/

#include <stdio.h>
#include "internal/error.h"
#include "internal/utils.h"
#include "internal/parsing.h"

static void get_object_array(cjson_t *cjson, char *json,
int *i, bool *error)
{
    if (json[*i] == '{') {
        *i += 1;
        cjson->type = CJSON_OBJECT_T;
        cjson->value = internal_cjson_parse_object(json, i, error);
    } else {
        *i += 1;
        cjson->type = CJSON_ARRAY_T;
        cjson->value = internal_cjson_parse_array(json, i, error);
    }
}

static void get_string_number(cjson_t *cjson, char *json,
int *i, bool *error)
{
    if (json[*i] == '"') {
        *i += 1;
        cjson->type = CJSON_STRING_T;
        cjson->value = internal_cjson_parse_string(json, i, error);
    } else {
        cjson->type = CJSON_NUMBER_T;
        cjson->value = internal_cjson_parse_number(json, i, error);
    }
}

static void get_bool_null(cjson_t *cjson, char *json,
int *i, bool *error)
{
    if (json[*i] == 'f' || json[*i] == 't') {
        cjson->type = CJSON_BOOL_T;
        cjson->value = internal_cjson_parse_bool(json, i, error);
    } else {
        cjson->type = CJSON_NULL_T;
        cjson->value = internal_cjson_parse_null(json, i, error);
    }
}

void internal_cjson_get_value(cjson_t *cjson, char *json,
int *i, bool *error)
{
    if (json[*i] == '{' || json[*i] == '[')
        return get_object_array(cjson, json, i, error);
    if (json[*i] == '"' || CJSON_INTERNAL_ISNUM(json[*i]) || json[*i] == '-')
        return get_string_number(cjson, json, i, error);
    if (json[*i] == 'f' || json[*i] == 't' || json[*i] == 'n')
        return get_bool_null(cjson, json, i, error);
    return internal_cjson_error("unknown value type", error);
}
