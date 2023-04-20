/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get_target_selected
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/inventory/types.h"

inventory_item_t *inventory_get_item_at_pos(list_t *inventory,
int pos, bool active)
{
    node_t *node = inventory ? inventory->first : NULL;
    inventory_item_t *item = NULL;

    while (node) {
        item = node->data.inventory_item;
        if (!item) {
            node = node->next;
            continue;
        }
        if (item->active == active && item->pos == pos)
            return item;
        node = node->next;
    }
    return NULL;
}
