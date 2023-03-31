/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** new
*/

#include <stdlib.h>
#include "cjson.h"

static void cjson_free_object(cjson_t *cjson)
{
    cjson_t *child = cjson;
    cjson_t *next = NULL;

    while (child) {
        next = child->next;
        cjson_free(child);
        child = next;
    }
}

void cjson_free_value(cjson_t *cjson)
{
    if (!cjson)
        return;
    switch (cjson->type) {
        case CJSON_STRING_T:
            free(cjson->value.v_string);
            break;
        case CJSON_OBJECT_T:
            cjson_free_object(cjson->value.v_object);
            break;
        case CJSON_ARRAY_T:
            cjson_array_free(cjson->value.v_array);
            break;
        default:
            break;
    }
    cjson->type = CJSON_NULL_T;
}

void cjson_free(cjson_t *cjson)
{
    if (!cjson)
        return;
    free(cjson->key);
    cjson_free_value(cjson);
    free(cjson);
}
