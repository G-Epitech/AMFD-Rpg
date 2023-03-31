/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** bool
*/

#include <stdbool.h>
#include "types.h"

void internal_cjson_string_size_bool(cjson_t *cjson, size_t *size)
{
    if (cjson->value.v_bool == true) {
        *size += 4;
    } else {
        *size += 5;
    }
}
