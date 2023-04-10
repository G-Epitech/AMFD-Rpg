/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** new
*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "cjson.h"
#include "internal/utils.h"

cjson_t *cjson_new(char *key)
{
    cjson_t *cjson = malloc(sizeof(cjson_t));

    if (!cjson)
        return NULL;
    cjson->next = NULL;
    cjson->prev = NULL;
    cjson->type = CJSON_OBJECT_T;
    cjson->value = CJSON((cjson_t *) NULL);
    if (key)
        cjson->key = internal_cjson_strdup(key);
    else
        cjson->key = NULL;
    return cjson;
}
