/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** permute
*/

#include "app/types.h"
#include "app/display/display.h"
#include "app/inventory/types.h"

void inventory_swap_items_on_event(player_t *player,
inventory_event_t *event)
{
    inventory_item_t *target = event->target_ref;
    inventory_item_t *selected = event->selected;

    (void) player;
    if (event->target.pos <= 0)
        return;
    if (target) {
        target->pos = event->target_ref_tmp.pos;
        target->active = event->target_ref_tmp.active;
    }
    selected->pos = event->target.pos;
    selected->active = event->target.active;
}
