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
#include "app/app.h"

static void event_analyse(sfRenderWindow *window, sfEvent event, app_t *app,
renderer_t *renderer)
{
    if (event.type == sfEvtClosed) {
        event_window_close(window);
    }
    if (event.type == sfEvtKeyPressed) {
        keyboard_move(event, app);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        event_components_buttons(renderer, app, event);
    }
}

void event_handler(sfRenderWindow *window, app_t *app, renderer_t *renderer)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        event_analyse(window, event, app, renderer);
    }
}
