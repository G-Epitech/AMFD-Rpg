/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include <unistd.h>
#include "internal/display.h"

void internal_cjson_display_null(void)
{
    write(1, CJSON_INTERNAL_PURPLE, 7);
    write(1, "null", 4);
    write(1, CJSON_INTERNAL_COLOR_RESET, 4);
}
