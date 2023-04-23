/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/app.h"
#include "types/list/list.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"
#include "app/competences_tree/types.h"

static item_t *get_item_by_id(list_t *items, int id)
{
    node_t *node = items ? items->first : NULL;

    while (node) {
        if (node->data.item->id == (unsigned int) id)
            return node->data.item;
        node = node->next;
    }
    return NULL;
}

static void set_item(cjson_t *item, player_t *player, list_t *items)
{
    int id = cjson_get_prop_int_unsafe(item, "id");
    bool active = cjson_get_prop_bool_unsafe(item, "active");
    item_t *ref = get_item_by_id(items, id);
    inventory_item_t *inventory_item = NULL;

    if (!ref)
        return;
    inventory_add_item(player, ref);
    if (player->inventory->last)
        inventory_item = player->inventory->last->data.inventory_item;
    if (inventory_item && active)
        inventory_set_item_active(player, inventory_item);
}

void save_load_restore_player_inventory(player_t *player,
cjson_t *player_file, list_t *items)
{
    cjson_array_t *array = NULL;
    cjson_t *item = NULL;

    if (!cjson_get_prop_array(player_file, "inventory", &array))
        return;
    item = array ? array->first : NULL;
    while (item) {
        set_item(item, player, items);
        item = item->next;
    }
}
