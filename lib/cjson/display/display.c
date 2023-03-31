/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** to_string
*/

#include <stdlib.h>
#include <unistd.h>
#include "cjson.h"
#include "internal/defs.h"
#include "internal/utils.h"
#include "internal/error.h"
#include "internal/display.h"

void internal_cjson_display_add_tabs(int depth)
{
    size_t tabs = depth * CJSON_TAB_SIZE;

    for (size_t j = 0; j < tabs; j++) {
        write(1, " ", 1);
    }
}

void internal_cjson_display(cjson_t *cjson, int depth, bool *error)
{
    if (CJSON_IS_OBJECT(cjson))
        return internal_cjson_display_object(cjson, depth, error);
    if (CJSON_IS_ARRAY(cjson))
        return internal_cjson_display_array(cjson, depth, error);
    if (CJSON_IS_STRING(cjson))
        return internal_cjson_display_string(cjson);
    if (CJSON_IS_NUMBER(cjson))
        return internal_cjson_display_number(cjson);
    if (CJSON_IS_BOOL(cjson))
        return internal_cjson_display_bool(cjson);
    if (CJSON_IS_NULL(cjson))
        return internal_cjson_display_null();
    return internal_cjson_error("unknown value type (display)", error);
}

void cjson_display(cjson_t *cjson)
{
    bool error = false;

    if (!cjson) {
        internal_cjson_error("null object (display)", &error);
        return;
    }
    internal_cjson_display(cjson, 0, &error);
    write(1, "\n", 1);
}
