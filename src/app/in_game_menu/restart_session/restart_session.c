/*
** EPITECH PROJECT, 2023
** EPG
** File description:
** Functions that will restart the app when
** pressing on the back to main menu button in the pause menu
*/

#include "app/types.h"
#include "app/in_game_menu/in_game_menu.h"

void restart_session(app_t *app)
{
    app->state = 1;
    app->prev_state = 1;
    app->world = 0;
    restart_player(app->player);
    restart_player(app->partner);
    restart_sound(app->sound_board);
    sfClock_restart(app->clock);
}
