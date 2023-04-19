/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** Functions for the in game menu
*/

#include "app/app.h"

void update_prev_app_state(app_t *app)
{
    if (app->state == ST_INGAME || app->state > ST_TASK) {
        app->prev_state = app->state;
    }
}

int in_game_menu_exit(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    app->state = app->prev_state;
    return 0;
}
