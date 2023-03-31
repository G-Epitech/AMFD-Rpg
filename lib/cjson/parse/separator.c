/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** separator
*/

#include <stdbool.h>

void internal_cjson_check_separator(char *json, int *i, bool *error)
{
    if (json[*i] != ':')
        *error = true;
    *i += 1;
}
