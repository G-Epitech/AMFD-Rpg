/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tmp_move
*/

#include <stdio.h>
#include "app/types.h"
#include "app/display/display.h"
#include "app/inventory/types.h"

static void get_more_close_free_box(list_t *inventory,
inventory_event_t *event)
{
    sfVector2i main_size = INVENTORY_MAIN_GRID_SIZE;

    for (int i = 1; i <= (main_size.x * main_size.y); i++) {
        if (inventory_onmove_get_free_positions(i, inventory, event)) {
            event->target_ref_tmp.active = false;
            return;
        }
    }
    event->target.pos = -1;
}

void inventory_onmove_prevent_bad(list_t *inventory,
inventory_event_t *event)
{
    (void) inventory;
    event->target_ref_tmp = *event->selected;
    if (!event->target_ref || !event->selected->active)
        return;
    if (event->target_ref->target->type == IVT_EQUIPEMENT)
        return;
    get_more_close_free_box(inventory, event);
}
