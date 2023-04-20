/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/app.h"

void event_key_pressed(sfEvent event, app_t *app)
{
    if (event.type == sfEvtKeyPressed) {
        if (app->state == ST_INGAME)
            keyboard_press_move(event, app);
        event_pause_menu(event, app);
    }
}
