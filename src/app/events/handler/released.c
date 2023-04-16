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

void event_key_released(sfEvent event, renderer_t *renderer, app_t *app)
{
    if (event.type == sfEvtKeyReleased) {
        keyboard_release_move(event, app);
        keyboard_interaction(event, renderer, app);
        keyboard_inventory(event, app);
    }
}
