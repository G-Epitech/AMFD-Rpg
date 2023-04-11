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

void event_mouse_button_released(app_t *app, renderer_t *renderer,
sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        (void) app;
        (void) renderer;
        (void) event;
    }
}
