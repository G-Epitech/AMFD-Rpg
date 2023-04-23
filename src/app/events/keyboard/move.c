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
    for (size_t i = 0; i < 4; i++) {
        if (event.key.code == app->control[i].key) {
            app->player->orientation = i;
            app->control[i].direction = true;
            app->control->direction_nb++;
            app->player->state = WALKING;
            sound_control(app->sound_board->sound_fx, WALK, sfPlaying);
        }
    }
    if (app->control->direction_nb > 1) {
        if (app->control[0].direction) {
            app->player->orientation = 0;
            return;
        }
        if (app->control[2].direction)
            app->player->orientation = 2;
    }
}

void keyboard_release_move(sfEvent event, app_t *app)
{
    int pressed_count = 0;

    for (size_t i = 0; i < 4; i++) {
        if (event.key.code == app->control[i].key) {
            app->control[i].direction = false;
        }
        if (app->control[i].direction) {
            pressed_count++;
            app->player->orientation = (int) i;
        }
    }
    if (pressed_count == 0) {
        app->player->state = IDLE;
        sound_control(app->sound_board->sound_fx, WALK, sfStopped);
    }
}
