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

static void event_analyse(sfRenderWindow *window, sfEvent event, app_t *app,
renderer_t *renderer)
{
    event_close(window, event);
    event_text_entered(renderer, event, app);
    event_key_pressed(event, app);
    event_key_released(event, renderer, app);
    event_mouse_button_pressed(app, renderer, event);
    event_mouse_button_released(app, renderer, event);
    event_mouse_moved(app, renderer, event);
    if (event.type == sfEvtMouseWheelScrolled)
        app->state = ST_TASK_BRUTEFORCE;
}

void event_handler(sfRenderWindow *window, app_t *app, renderer_t *renderer)
{
    sfEvent event;

    (void) window;
    while (sfRenderWindow_pollEvent(renderer->window, &event)) {
        event_analyse(renderer->window, event, app, renderer);
    }
}
