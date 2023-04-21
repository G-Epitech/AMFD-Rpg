/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** move
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "app/events/events.h"
#include "types/renderer/types.h"
#include "app/inventory/inventory.h"

static void mouse_event(app_t *app,
renderer_t *renderer, sfEvent event)
{
    (void) renderer;
    inventory_onmove(app, event);
}

void event_mouse_moved(app_t *app, renderer_t *renderer,
sfEvent event)
{
    if (event.type != sfEvtMouseEntered && event.type != sfEvtMouseMoved)
        return;
    if (app->dialog_box->show)
        return;
    mouse_event(app, renderer, event);
}
