/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** id
*/

#include <stdlib.h>
#include <stdbool.h>
#include "app/items/types.h"
#include "types/players/types.h"
#include "types/list/list.h"

item_t *item_get_by_id(int id, app_t *app)
{
    list_t *inventory = app->items;
    node_t *node = inventory->first;

    while (node) {
        if (node->data.item->id == (unsigned int) id)
            return node->data.item;
        node = node->next;
    }
    return NULL;
}
