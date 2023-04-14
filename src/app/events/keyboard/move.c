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
#include "app/sound/sound_control.h"

void keyboard_press_move(sfEvent event, app_t *app)
{
    int current_dir = -1;

    for (size_t i = 0; i < 4; i++) {
        if (event.key.code == app->control[i].key) {
            app->player->orientation = i;
            app->control[i].direction = true;
            current_dir = i;
            break;
        }
    }
    if (current_dir != -1)
        sound_control(app->sound_board, WALK, sfPlaying);
    for (size_t i = 0; i < 4; i++) {
        if ((int) i != current_dir)
            app->control[i].direction = false;
    }
}

void keyboard_release_move(sfEvent event, app_t *app)
{
    for (size_t i = 0; i < 4; i++) {
        if (event.key.code == app->control[i].key) {
            sound_control(app->sound_board, WALK, sfStopped);
            app->control[i].direction = false;
        }
    }
}
