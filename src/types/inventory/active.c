/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** add
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/list.h"
#include "app/inventory/types.h"
#include "types/players/types.h"

static bool id_used(list_t *inventory, int id)
{
    node_t *node = inventory ? inventory->first : NULL;
    bool used = false;

    while (node && !used) {
        if (node->data.inventory_item->pos == id
            && node->data.inventory_item->active) {
            used = true;
        }
        node = node->next;
    }
    return used;
}

static int get_next_non_used_id(list_t *inventory)
{
    for (int i = 1; i <= INVENTORY_ACTIVE_MAX; i++) {
        if (!id_used(inventory, i))
            return i;
    }
    return -1;
}

bool inventory_set_item_active(player_t *player,
inventory_item_t *inventory_item)
{
    list_t *inventory = player ? player->inventory : NULL;
    int id = get_next_non_used_id(inventory);

    if (id == -1)
        return false;
    inventory_item->pos = id;
    inventory_item->active = true;
    return true;
}

void inventory_set_item_inactive(player_t *player,
inventory_item_t *inventory_item)
{
    item_t *model = NULL;

    if (!inventory_item)
        return;
    model = inventory_item->target;
    inventory_remove_item(player, inventory_item);
    inventory_add_item(player, model);
}
