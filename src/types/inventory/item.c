/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** item
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "app/inventory/types.h"
#include "types/players/types.h"

inventory_item_t *inventory_item_new(item_t *target_item)
{
    inventory_item_t *inventory_item = malloc(sizeof(inventory_item_t));

    if (!inventory_item)
        return NULL;
    inventory_item->active = false;
    inventory_item->pos = -1;
    inventory_item->target = target_item;
    return inventory_item;
}

void inventory_item_free(inventory_item_t *inventory_item)
{
    free(inventory_item);
}
