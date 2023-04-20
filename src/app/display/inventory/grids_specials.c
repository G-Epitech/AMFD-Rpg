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

static void display_selected(renderer_t *renderer, inventory_event_t *event)
{
    display_inventory_item_box_at_pos(renderer, event->position,
    event->target.active, false);
    display_inventory_item_content(renderer, event->selected, event);
}

static void display_target(renderer_t *renderer, inventory_event_t *event)
{
    if (!event->target_ref) {
        display_inventory_item_box(renderer, event->selected->pos,
        event->selected->active, true);
        return;
    }
    display_inventory_item_box(renderer, event->target_ref_tmp.pos,
    event->target_ref_tmp.active, event->target_ref == event->selected);
    display_inventory_item_content(renderer, event->target_ref, event);
    if (event->target_ref_tmp.active != event->selected->active &&
        event->target_ref_tmp.pos != event->selected->pos) {
        display_inventory_item_box(renderer, event->selected->pos,
        event->selected->active, true);
    }
}

void display_inventory_grids_specials(renderer_t *renderer,
inventory_event_t *event)
{
    if (!event->pressed || !event->moved)
        return;
    display_target(renderer, event);
    display_selected(renderer, event);
}
