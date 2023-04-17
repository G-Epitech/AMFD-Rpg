/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** add
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "app/inventory/types.h"
#include "types/players/types.h"

void inventory_remove_item(player_t *player,
inventory_item_t *inventory_item)
{
    list_t *inventory = player ? player->inventory : NULL;
    node_t *node = NULL;
    node_t *item_node = NULL;

    if (!inventory)
        return;
    node = inventory->first;
    while (node && !item_node) {
        if (node->data.inventory_item == inventory_item)
            item_node = node;
        node = node->next;
    }
    if (item_node) {
        inventory_item_free(inventory_item);
        list_delete(inventory, item_node);
    }
}
