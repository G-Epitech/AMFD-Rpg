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
    inventory_item_t *target = NULL;
    inventory_item_t *selected = NULL;
    list_t *inventory = player->inventory;

    if (event->target_pos <= 0)
        return;
    inventory_get_target_and_selected(inventory, event, &selected, &target);
    if (target) {
        target->pos = event->item_pos;
        target->active = event->item_active;
    }
    selected->pos = event->target_pos;
    selected->active = event->target_active;
}
