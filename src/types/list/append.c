/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** append
*/

#include "types/list/types.h"
#include <stdlib.h>

void list_append_after(list_t *list, node_t *ref, node_t *node)
{
    if (ref == list->last)
        list->last = node;
    if (ref != NULL) {
        node->next = ref->next;
        ref->next = node;
        node->prev = ref;
    } else {
        list->first = node;
        node->next = NULL;
        node->prev = NULL;
    }
    list->len++;
}

void list_append_before(list_t *list, node_t *ref, node_t *node)
{
    if (ref == list->first)
        list->first = node;
    if (ref == NULL)
        list->last = node;
    node->next = ref;
    if (ref != NULL) {
        node->prev = ref->prev;
        ref->prev = node;
    }
    list->len++;
}

void list_append(list_t *list, node_t *node)
{
    list_append_after(list, list->last, node);
}
