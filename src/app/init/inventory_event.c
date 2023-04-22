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
    app->inventory_event->target.active = false;
    app->inventory_event->target.pos = -1;
    app->inventory_event->target.target = NULL;
    app->inventory_event->selected = NULL;
    app->inventory_event->pressed = false;
    app->inventory_event->target_ref = NULL;
    app->inventory_event->target_ref_tmp.active = false;
    app->inventory_event->target_ref_tmp.pos = -1;
    app->inventory_event->target_ref_tmp.target = NULL;
    app->inventory_event->position = (sfVector2f) {0, 0};
    return true;
}
