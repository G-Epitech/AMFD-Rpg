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

void event_mouse_button_pressed(app_t *app, renderer_t *renderer,
sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        event_components_buttons(renderer, app, event);
    }
}