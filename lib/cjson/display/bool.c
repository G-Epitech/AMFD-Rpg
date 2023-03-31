/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** bool
*/

#include <unistd.h>
#include "internal/display.h"

void internal_cjson_display_bool(cjson_t *cjson)
{
    write(1, CJSON_INTERNAL_RED, 7);
    if (cjson->value.v_bool) {
        write(1, "true", 4);
    } else {
        write(1, "false", 5);
    }
    write(1, CJSON_INTERNAL_COLOR_RESET, 4);
}
