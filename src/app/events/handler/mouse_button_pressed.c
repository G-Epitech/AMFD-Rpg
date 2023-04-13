/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/events/events.h"
#include "app/tasks/bash/script_bash.h"
#include "app/tasks/flipper/flipper.h"
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
    event_task_flipper(renderer, app);
}

void event_mouse_button_pressed(app_t *app, renderer_t *renderer,
sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        mouse_event(event, app, renderer);
    }
}
