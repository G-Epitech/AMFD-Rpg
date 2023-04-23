/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** id
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/list.h"
#include "app/inventory/inventory.h"
#include "types/players/types.h"
#include "app/items/items.h"

bool inventory_add_item_by_id(app_t *app, int id)
{
    item_t *item = item_get_by_id(id, app);

    if (!item)
        return false;
    return inventory_add_item(app->player, item);
}
