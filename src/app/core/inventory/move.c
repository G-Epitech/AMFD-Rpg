/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move
*/

#include <stdio.h>
#include "app/types.h"
#include "app/inventory/types.h"

void inventory_onmove(app_t *app, sfEvent event)
{
    sfVector2f mouse = {event.mouseButton.x, event.mouseButton.y};

    if (!app->inventory_event->pressed || app->state != ST_INVENTORY)
        return;
    if (app->inventory_event->moved) {
        app->inventory_event->position = mouse;
        return;
    }
    if (app->inventory_event->pressed_on.x != mouse.x &&
        app->inventory_event->pressed_on.y != mouse.y) {
        app->inventory_event->position = mouse;
        app->inventory_event->moved = true;
    }
}
