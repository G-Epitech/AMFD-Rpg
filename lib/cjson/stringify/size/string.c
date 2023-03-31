/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** null
*/

#include <stdlib.h>
#include "internal/utils.h"

void internal_cjson_string_size_string(cjson_t *cjson, size_t *size)
{
    *size += 2;
    *size += internal_cjson_strlen(cjson->value.v_string);
}
