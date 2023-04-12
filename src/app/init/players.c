/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** player
*/


#include <stdlib.h>
#include "app/types.h"
#include "types/players/players.h"

bool app_init_players(app_t *app)
{
    app->players = players_list_init();
    return app->players ? true : false;
}
