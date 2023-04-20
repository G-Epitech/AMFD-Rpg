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

static bool is_special(int i, bool active, inventory_event_t *event)
{
    if (!event->pressed || !event->moved)
        return false;
    if (i == event->target.pos && active == event->target.active)
        return true;
    if (i == event->selected->pos && active == event->selected->active)
        return true;
    return false;
}

void display_inventory_grids_empty(renderer_t *renderer, int *actives_boxes,
int *main_boxes, inventory_event_t *event)
{
    sfVector2i active_size = INVENTORY_ACTIVE_GRID_SIZE;
    sfVector2i main_size = INVENTORY_MAIN_GRID_SIZE;
    size_t nb_actives_boxes = active_size.x * active_size.y;
    size_t nb_main_boxes = main_size.x * main_size.y;

    for (size_t i = 0; i < nb_actives_boxes; i++) {
        if (actives_boxes[i] == 0 && !is_special(i + 1, true, event))
            display_inventory_item_box(renderer, i + 1, true, true);
    }
    for (size_t i = 0; i < nb_main_boxes; i++) {
        if (main_boxes[i] == 0 && !is_special(i + 1, false, event))
            display_inventory_item_box(renderer, i + 1, false, true);
    }
}
