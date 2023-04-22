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

static void update_cursor(cursor_t *cursor, sfRenderWindow *window)
{
    cursor->pos = sfRenderWindow_mapPixelToCoords(window,
    sfMouse_getPositionRenderWindow(window), NULL);
}

static void mouse_event(app_t *app,
renderer_t *renderer, sfEvent event)
{
    inventory_onmove(app, event);
    update_cursor(app->control->cursor, renderer->window);
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
