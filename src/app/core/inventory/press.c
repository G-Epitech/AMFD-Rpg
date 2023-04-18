/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** pressed
*/

#include <stdio.h>
#include "app/types.h"
#include "types/list/types.h"
#include "app/inventory/types.h"
#include "app/display/display.h"

static bool is_on_item(sfVector2f mouse, int pos, bool active)
{
    sfVector2f position = {0, 0};
    sfFloatRect rect = {0, 0, 0, 0};

    display_inventory_get_item_position(pos, active, &position);
    rect.left = position.x;
    rect.top = position.y;
    if (active) {
        rect.height = INVENTORY_ACTIVE_GRID_ITEM_SIZE;
        rect.width = INVENTORY_ACTIVE_GRID_ITEM_SIZE;
    } else {
        rect.height = INVENTORY_MAIN_GRID_ITEM_SIZE;
        rect.width = INVENTORY_MAIN_GRID_ITEM_SIZE;
    }
    return sfFloatRect_contains(&rect, mouse.x, mouse.y);
}

static void set_item(inventory_event_t *event, inventory_item_t *item,
sfVector2f mouse)
{
    event->item_active = item->active;
    event->item_pos = item->pos;
    event->position = mouse;
    if (item->active) {
        event->position.x -= INVENTORY_ACTIVE_GRID_ITEM_SIZE / 2;
        event->position.y -= INVENTORY_ACTIVE_GRID_ITEM_SIZE / 2;
    } else {
        event->position.x -= INVENTORY_MAIN_GRID_ITEM_SIZE / 2;
        event->position.y -= INVENTORY_MAIN_GRID_ITEM_SIZE / 2;
    }
    event->pressed = true;
    event->moved = false;
    event->pressed_on = mouse;
}

static bool check_item_selected(sfVector2f mouse, inventory_event_t *event,
list_t *items)
{
    node_t *node = items ? items->first : NULL;
    inventory_item_t *item = NULL;
    bool on = false;

    while (node && !on) {
        item = node->data.inventory_item;
        if (is_on_item(mouse, item->pos, item->active))
            on = true;
        else
            node = node->next;
    }
    if (on)
        set_item(event, item, mouse);
    return false;
}

void inventory_onpress(app_t *app, sfEvent event)
{
    sfVector2f mouse = {event.mouseButton.x, event.mouseButton.y};

    check_item_selected(mouse, app->inventory_event, app->player->inventory);
}
