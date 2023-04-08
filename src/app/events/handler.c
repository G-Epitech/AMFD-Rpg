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
#include "app/app.h"

static void mouse_event(sfEvent event, app_t *app,
renderer_t *renderer)
{
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(renderer->window, (sfVector2i)
    {event.mouseButton.x, event.mouseButton.y}, renderer->default_view);

    event.mouseButton.x = coords.x;
    event.mouseButton.y = coords.y;
    event_components_buttons(renderer, app, event);
    event_components_levers(renderer, app, event);
}

static void event_analyse(sfRenderWindow *window, sfEvent event, app_t *app,
renderer_t *renderer)
{
    if (event.type == sfEvtClosed) {
        event_window_close(window);
    }
    if (event.type == sfEvtKeyPressed) {
        if (app->state == ST_TASK_BASH) {
            cmd_write(event, app);
            good_or_bad_result(event, app);
        }
        if (app->state == ST_INGAME)
            keyboard_press_move(event, app);
    }
    if (event.type == sfEvtKeyReleased) {
        keyboard_release_move(event, app);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        mouse_event(event, app, renderer);
    }
}

void event_handler(sfRenderWindow *window, app_t *app, renderer_t *renderer)
{
    (void) window;
    sfEvent event;

    while (sfRenderWindow_pollEvent(renderer->window, &event)) {
        event_analyse(renderer->window, event, app, renderer);
    }
}
