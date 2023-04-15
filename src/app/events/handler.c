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
    event_text_entered(event, app);
    event_key_pressed(event, app);
    event_key_released(event, app);
    event_mouse_button_pressed(app, renderer, event);
    event_mouse_button_released(app, renderer, event);
    if (event.type == sfEvtMouseWheelScrolled) {
        app->state = ST_TASK_CAMERA;
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
