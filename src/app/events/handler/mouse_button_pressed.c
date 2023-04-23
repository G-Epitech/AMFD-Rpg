/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "app/shop/shop_handle.h"
#include "app/events/events.h"
#include "types/renderer/types.h"
#include "app/inventory/inventory.h"
#include "app/tasks/bash/script_bash.h"
#include "app/tasks/flipper/flipper.h"
#include "app/competences_tree/competences_tree.h"
#include "app/app.h"

static void mouse_event(sfEvent event, app_t *app,
renderer_t *renderer)
{
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(renderer->window,
    (sfVector2i) {event.mouseButton.x, event.mouseButton.y},
    renderer->default_view);

    event.mouseButton.x = coords.x;
    event.mouseButton.y = coords.y;
    event_components_buttons(renderer, app, event);
    event_components_levers(renderer, app, event);
    event_components_attacks(renderer, app, event);
    buy_item(app, event);
    if (app->state == ST_TASK_FLIPPER)
        event_task_flipper(renderer, app);
    event_handler_skills_tree(app, renderer);
    if (app->state == ST_INVENTORY)
        inventory_onpress(app, event);
}

void event_mouse_button_pressed(app_t *app, renderer_t *renderer,
sfEvent event)
{
    if (event.type != sfEvtMouseButtonPressed)
        return;
    if (!app->dialog_box->show)
        mouse_event(event, app, renderer);
}
