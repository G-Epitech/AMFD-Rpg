/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** swap
*/


#include <stdlib.h>
#include "types/list/list.h"
#include "types/list/types.h"

static void prevent_first_last(list_t *list, node_t *node1, node_t *node2)
{
    if (node1->prev == NULL)
        list->first = node2;
    if (node1->next == NULL)
        list->last = node2;
    if (node2->prev == NULL)
        list->first = node1;
    if (node2->next == NULL)
        list->last = node1;
}

static void swap_neighboring_nodes(node_t *node1, node_t *node2)
{
    node_t tmp = *node1;

    node1->next = node2->next;
    node1->prev = node2;
    node2->next = node1;
    node2->prev = tmp.prev;
    if (node1->next != NULL)
        node1->next->prev = node1;
    if (node2->prev != NULL)
        node2->prev->next = node2;
}

static void swap_no_neighboring_nodes(node_t *node1, node_t *node2)
{
    node_t tmp = *node1;

    node1->next = node2->next;
    node1->prev = node2->prev;
    if (node1->next != NULL)
        node1->next->prev = node1;
    if (node1->prev != NULL)
        node1->prev->next = node1;
    node2->next = tmp.next;
    node2->prev = tmp.prev;
    if (node2->next != NULL)
        node2->next->prev = node2;
    if (node2->prev != NULL)
        node2->prev->next = node2;
}

void node_swap(list_t *list, node_t *node1, node_t *node2)
{
    prevent_first_last(list, node1, node2);

    if (node1->next == node2 && node2->prev == node1) {
        swap_neighboring_nodes(node1, node2);
    } else if (node2->next == node1 && node1->prev == node2) {
        swap_neighboring_nodes(node2, node1);
    } else {
        swap_no_neighboring_nodes(node1, node2);
    }
}
