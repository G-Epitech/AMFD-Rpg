/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** array
*/

#include <unistd.h>
#include "cjson.h"
#include "internal/display.h"

static bool display_elements(cjson_t *cjson, int depth, bool *error)
{
    cjson_t *element = cjson->value.v_array->first;
    bool lined = false;

    while (element && !(*error)) {
        if (!CJSON_IS_PRIMARY(element) || CJSON_IS_STRING(element))
            lined = true;
        if (lined) {
            write(1, "\n", 1);
            internal_cjson_display_add_tabs(depth);
        }
        internal_cjson_display(element, depth, error);
        if (element->next)
            write(1, ",", 1);
        if (element->next && !lined)
            write(1, " ", 1);
        element = element->next;
    }
    return lined;
}

void internal_cjson_display_array(cjson_t *cjson,
int depth, bool *error)
{
    bool lined = false;

    write(1, "[", 1);
    lined = display_elements(cjson, depth + 1, error);
    if (lined) {
        write(1, "\n", 1);
        internal_cjson_display_add_tabs(depth);
    }
    write(1, "]", 1);
}
