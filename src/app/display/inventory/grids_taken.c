/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_grid
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "app/inventory/types.h"
#include "types/ressources/ressources.h"

static void display_item(renderer_t *renderer, inventory_event_t *event,
inventory_item_t *item)
{
    bool is_target = item == event->target_ref;
    bool is_selected = item == event->selected;

    if (event->moved && (is_selected || is_target))
        return;
    display_inventory_item_box(renderer, item->pos, item->active, false);
    display_inventory_item_content(renderer, item, event);
}

void display_inventory_grids_taken(renderer_t *renderer, list_t *inventory,
inventory_event_t *event)
{
    node_t *node = inventory ? inventory->first : NULL;
    inventory_item_t *item = NULL;

    while (node) {
        item = node->data.inventory_item;
        if (item)
            display_item(renderer, event, item);
        node = node->next;
    }
}
