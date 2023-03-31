/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** new
*/

#include <stdlib.h>
#include "cjson.h"

cjson_array_t *cjson_array_new(void)
{
    cjson_array_t *array = malloc(sizeof(cjson_array_t));

    if (!array)
        return NULL;
    array->first = NULL;
    array->last = NULL;
    array->len = 0;
    return array;
}

void cjson_array_free(cjson_array_t *array)
{
    cjson_t *item = array->first;
    cjson_t *next = NULL;

    while (item) {
        next = item->next;
        cjson_free(item);
        item = next;
    }
    free(array);
}
