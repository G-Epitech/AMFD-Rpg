/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include "types.h"
#include "internal/utils.h"
#include "internal/stringify.h"

void internal_cjson_stringify_string(cjson_t *cjson,
internal_cjson_string_t *json)
{
    char *string = cjson->value.v_string;
    int len = internal_cjson_strlen(string);

    json->content[json->i++] = '"';
    internal_cjson_strncpy(json->content + json->i, string, len);
    json->i += len;
    json->content[json->i++] = '"';
}
