/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** Move keys
*/

#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/players/types.h"
#include "app/events/types.h"

void keyboard_press_move(sfEvent event, app_t *app)
{
    int current_dir = 0;

    for (size_t i = 0; i < 4; i++) {
        if (event.key.code == app->control[i].key) {
            app->control[i].direction = true;
            current_dir = i;
            break;
        }
    }
    for (size_t i = 0; i < 4; i++) {
        if ((int) i != current_dir)
            app->control[i].direction = false;
    }
}

void keyboard_release_move(sfEvent event, app_t *app)
{
    for (size_t i = 0; i < 4; i++) {
        if (event.key.code == app->control[i].key)
            app->control[i].direction = false;
    }
}
