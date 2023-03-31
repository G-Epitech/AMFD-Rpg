/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** skip
*/

#include "internal/utils.h"

void internal_cjson_skip_blank(char *json, int *i)
{
    bool in = true;

    while (in && json[*i] != '\0') {
        in = internal_cjson_char_in_str(json[*i], CJSON_INTERNAL_BLANKS);
        if (in)
            (*i)++;
    }
}
