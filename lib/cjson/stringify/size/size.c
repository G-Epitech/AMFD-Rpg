/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** common
*/

#include "cjson.h"
#include "internal/defs.h"
#include "internal/error.h"
#include "internal/stringify.h"

void internal_cjson_string_size_add_tabs(int depth, size_t *size)
{
    *size += depth * CJSON_TAB_SIZE;
}

void internal_cjson_string_size(cjson_t *cjson, size_t *size,
int depth, bool *error)
{
    if (CJSON_IS_OBJECT(cjson))
        return internal_cjson_string_size_object(cjson, size, depth, error);
    if (CJSON_IS_ARRAY(cjson))
        return internal_cjson_string_size_array(cjson, size, depth, error);
    if (CJSON_IS_STRING(cjson))
        return internal_cjson_string_size_string(cjson, size);
    if (CJSON_IS_NUMBER(cjson))
        return internal_cjson_string_size_number(cjson, size);
    if (CJSON_IS_BOOL(cjson))
        return internal_cjson_string_size_bool(cjson, size);
    if (CJSON_IS_NULL(cjson))
        return internal_cjson_string_size_null(size);
    return internal_cjson_error("unknown value type (string size)", error);
}
