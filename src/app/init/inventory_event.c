/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory_event
*/

#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/types.h"

bool app_init_inventory_event(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->inventory_event = malloc(sizeof(inventory_event_t));
    if (!app->inventory_event)
        return false;
    app->inventory_event->item_active = false;
    app->inventory_event->pressed = false;
    app->inventory_event->item_pos = 0;
    app->inventory_event->target_pos = 0;
    app->inventory_event->target_active = false;
    app->inventory_event->position = (sfVector2f) {0, 0};
    return true;
}
