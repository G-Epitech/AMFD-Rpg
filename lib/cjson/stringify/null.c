/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include "internal/utils.h"
#include "internal/stringify.h"

void internal_cjson_stringify_null(internal_cjson_string_t *json)
{
    internal_cjson_strncpy(json->content + json->i, "null", 4);
    json->i += 4;
}
