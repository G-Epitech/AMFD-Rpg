/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move
*/

#include <stdio.h>
#include "app/types.h"
#include "app/display/display.h"
#include "app/inventory/types.h"

static bool is_on_item(sfVector2f mouse, int i, bool active)
{
    sfVector2f position = {0, 0};
    sfFloatRect rect = {0, 0, 0, 0};

    display_inventory_get_item_position(i, active, &position);
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

static void check_target(sfVector2f mouse, inventory_event_t *event)
{
    sfVector2i main_size = INVENTORY_MAIN_GRID_SIZE;
    sfVector2i active_size = INVENTORY_ACTIVE_GRID_SIZE;

    event->target.pos = -1;
    for (int i = 1; i <= (main_size.x * main_size.y); i++) {
        if (is_on_item(mouse, i, false)) {
            event->target.pos = i;
            event->target.active = false;
            return;
        }
    }
    for (int i = 1; i <= (active_size.x * active_size.y); i++) {
        if (is_on_item(mouse, i, true)
            && event->selected->target->type == IVT_EQUIPEMENT) {
            event->target.pos = i;
            event->target.active = true;
            return;
        }
    }
}

static void set_position_and_target(sfVector2f mouse,
inventory_event_t *event, list_t *inventory)
{
    int size = INVENTORY_MAIN_GRID_ITEM_SIZE;

    if (event->selected->active)
        size = INVENTORY_ACTIVE_GRID_ITEM_SIZE;
    event->position = mouse;
    event->position.x -= size / 2;
    event->position.y -= size / 2;
    event->target_ref = inventory_get_item_at_pos(inventory,
    event->target.pos, event->target.active);
    inventory_onmove_prevent_bad(inventory, event);
}

void inventory_onmove(app_t *app, sfEvent event)
{
    sfVector2f mouse = {event.mouseMove.x, event.mouseMove.y};
    inventory_event_t *inv_event = app->inventory_event;
    list_t *inventory = app->player->inventory;

    if (!app->inventory_event->pressed || app->state != ST_INVENTORY)
        return;
    if (app->inventory_event->moved) {
        check_target(mouse, inv_event);
        set_position_and_target(mouse, inv_event, inventory);
        return;
    }
    if (app->inventory_event->pressed_on.x != mouse.x &&
        app->inventory_event->pressed_on.y != mouse.y) {
        app->inventory_event->position = mouse;
        app->inventory_event->moved = true;
    }
    if (!app->inventory_event->moved)
        return;
}
