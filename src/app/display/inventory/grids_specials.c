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

static void display_selected(renderer_t *renderer, inventory_event_t *event,
inventory_item_t *selected)
{
    display_inventory_item_box_at_pos(renderer, event->position,
    event->target_active, false);
    display_inventory_item_content(renderer, selected, event);
}

static void display_target(renderer_t *renderer, inventory_event_t *event,
inventory_item_t *target)
{
    if (!target) {
        display_inventory_item_box(renderer, event->item_pos,
        event->item_active, true);
    } else {
        display_inventory_item_box(renderer, event->item_pos,
        event->item_active, false);
        display_inventory_item_content(renderer, target, event);
    }
}

void display_inventory_grids_specials(renderer_t *renderer, list_t *inventory,
inventory_event_t *event)
{
    inventory_item_t *target = NULL;
    inventory_item_t *selected = NULL;

    if (!event->pressed || !event->moved)
        return;
    inventory_get_target_and_selected(inventory, event, &selected, &target);
    display_target(renderer, event, target);
    display_selected(renderer, event, selected);
}
