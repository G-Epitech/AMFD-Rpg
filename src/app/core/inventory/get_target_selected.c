/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get_target_selected
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/inventory/types.h"

void inventory_get_target_and_selected(list_t *inventory,
inventory_event_t *event, inventory_item_t **selected,
inventory_item_t **target)
{
    node_t *node = inventory ? inventory->first : NULL;
    inventory_item_t *item = NULL;

    while (node && (!(*target) || !(*selected))) {
        item = node->data.inventory_item;
        if (!item) {
            node = node->next;
            continue;
        }
        if (item->active == event->item_active &&
            item->pos == event->item_pos)
            *selected = item;
        if (item->active == event->target_active &&
            item->pos == event->target_pos)
            *target = item;
        node = node->next;
    }
}
