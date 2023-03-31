/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** bool
*/

#include "types.h"
#include "internal/utils.h"
#include "internal/stringify.h"

void internal_cjson_stringify_bool(cjson_t *cjson,
internal_cjson_string_t *json)
{
    char *value = cjson->value.v_bool ? "true" : "false";
    int len = cjson->value.v_bool ? 4 : 5;

    internal_cjson_strncpy(json->content + json->i, value, len);
    json->i += len;
}
