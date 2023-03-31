/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** node
*/

#include "types/list/types.h"
#include <stdlib.h>


node_t *node_new(node_data_t data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node)
        node->data = data;
    return (node);
}

void node_unlink(node_t *node)
{
    if (node->next) {
        node->next->prev = node->prev;
    }
    if (node->prev) {
        node->prev->next = node->next;
    }
}

void node_free(node_t *node)
{
    free(node);
}
