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

void event_key_pressed(sfEvent event, app_t *app)
{
    if (event.type == sfEvtKeyPressed) {
        if (app->state == ST_INGAME)
            keyboard_press_move(event, app);
    }
}
