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

bool inventory_add_item(player_t *player, item_t *target_item)
{
    list_t *inventory = player ? player->inventory : NULL;
    node_t *node = NULL;
    inventory_item_t *inventory_item = NULL;
    int available = INVENTORY_MAX - (inventory ? inventory->len : 0);

    if (available <= 0)
        return false;
    inventory_item = inventory_item_new(target_item);
    if (!inventory_item)
        return false;
    node = node_new((node_data_t) inventory_item);
    if (!node) {
        free(inventory_item);
        return false;
    }
    inventory_item->pos = inventory->len + 1;
    inventory_item->active = false;
    list_append(inventory, node);
    return true;
}
