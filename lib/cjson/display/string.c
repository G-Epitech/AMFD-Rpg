/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include <unistd.h>
#include "internal/utils.h"
#include "internal/display.h"

void internal_cjson_display_string(cjson_t *cjson)
{
    char *string = cjson->value.v_string;
    int len = internal_cjson_strlen(string);

    write(1, CJSON_INTERNAL_GREEN, 7);
    write(1, "\"", 1);
    write(1, string, len);
    write(1, "\"", 1);
    write(1, CJSON_INTERNAL_COLOR_RESET, 4);
}
