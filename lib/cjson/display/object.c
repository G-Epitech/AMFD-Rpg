/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** object
*/

#include <unistd.h>
#include "internal/utils.h"
#include "internal/display.h"

static void display_key(char *key)
{
    int key_len = internal_cjson_strlen(key);

    write(1, "\"", 1);
    write(1, key, key_len);
    write(1, "\"", 1);
}

static void display_props(cjson_t *cjson,
int depth, bool *error)
{
    cjson_t *prop = cjson->value.v_object;

    while (prop && !(*error)) {
        write(1, "\n", 1);
        internal_cjson_display_add_tabs(depth);
        display_key(prop->key);
        write(1, ": ", 2);
        internal_cjson_display(prop, depth, error);
        write(1, (prop->next) ? "," : "\n", 1);
        prop = prop->next;
    }
}

void internal_cjson_display_object(cjson_t *cjson,
int depth, bool *error)
{
    write(1, "{", 1);
    display_props(cjson, depth + 1, error);
    if (cjson->value.v_object)
        internal_cjson_display_add_tabs(depth);
    write(1, "}", 1);
}
