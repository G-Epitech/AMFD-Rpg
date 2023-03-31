/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include "types.h"
#include "internal/defs.h"

static void get_whole_part_size(long whole, size_t *size)
{
    while (whole > 9) {
        *size += 1;
        whole /= 10;
    }
    *size += 1;
}

void internal_cjson_string_size_number(cjson_t *cjson, size_t *size)
{
    float number = cjson->value.v_number;

    if (number < 0) {
        *size += 1;
        number = -number;
    }
    get_whole_part_size(((int) number), size);
    if (((int) number) != number)
        *size += CJSON_ROUNDING_LIMIT + 1;
}
