/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** set
*/

#include <stdio.h>
#include <stdlib.h>
#include "cjson.h"
#include "internal/utils.h"

int cjson_set_key(cjson_t *prop, char *key)
{
    if (!prop)
        return 0;
    if (prop->key)
        free(prop->key);
    prop->key = internal_cjson_strdup(key);
    if (!prop->key)
        return -1;
    return 0;
}
