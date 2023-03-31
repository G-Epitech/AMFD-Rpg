/*
** EPITECH PROJECT, 2023
** cjson
** File description:
** remove
*/

#include <stdlib.h>
#include "cjson.h"

static void element_unlink(cjson_t *element)
{
    if (!element)
        return;
    if (element->next)
        element->next->prev = element->prev;
    if (element->prev)
        element->prev->next = element->next;
}

void cjson_array_remove(cjson_array_t *array, cjson_t *element)
{
    element_unlink(element);
    if (array->first == element)
        array->first = element->next;
    if (array->first)
        array->first->prev = NULL;
    if (array->last == element)
        array->last = element->prev;
    if (array->last)
        array->last->next = NULL;
    array->len--;
}

void cjson_array_delete(cjson_array_t *array, cjson_t *element)
{
    cjson_array_remove(array, element);
    cjson_free(element);
}
