/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** list
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "types/list/types.h"

list_t *list_new(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list) {
        list->first = NULL;
        list->last = NULL;
        list->len = 0;
    }
    return (list);
}

void list_remove(list_t *list, node_t *node)
{
    node_unlink(node);
    if (list->first == node)
        list->first = node->next;
    if (list->first)
        list->first->prev = NULL;
    if (list->last == node)
        list->last = node->prev;
    if (list->last)
        list->last->next = NULL;
    list->len--;
}

void list_delete(list_t *list, node_t *node)
{
    list_remove(list, node);
    node_free(node);
}

void list_free(list_t *list)
{
    node_t *node = list ? list->first : NULL;
    node_t *next = NULL;

    while (node) {
        next = node->next ? node->next : NULL;
        node_free(node);
        node = next;
    }
    free(list);
}
