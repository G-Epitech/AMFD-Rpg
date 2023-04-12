/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/list.h"
#include "app/inventory/types.h"
#include "types/players/types.h"

void player_init_inventory(player_t *player, list_t *items)
{
    node_t *node = items ? items->first : NULL;
    int i = items->len;

    while (i < INVENTORY_MAX && node) {
        if (!(node->data.item->by_default)) {
            node = node->next;
            continue;
        }
        if (inventory_add_item(player, node->data.item))
            i += 1;
        node = node->next;
    }
}
