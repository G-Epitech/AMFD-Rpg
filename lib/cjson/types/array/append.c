/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** append
*/

#include <stdlib.h>
#include "cjson.h"

void cjson_array_append(cjson_array_t *array, cjson_t *element)
{
    if (!element)
        return;
    if (array->last != NULL) {
        array->last->next = element;
        element->prev = array->last;
    } else {
        array->first = element;
        element->prev = NULL;
    }
    array->last = element;
    array->last->next = NULL;
    array->len++;
}
