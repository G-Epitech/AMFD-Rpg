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

void keyboard_move(sfEvent event, app_t *app)
{
    player_t *player = app->player;

    if (event.key.code == sfKeyZ)
        player->position = POSITION_UP(player->position);
    if (event.key.code == sfKeyS)
        player->position = POSITION_DOWN(player->position);
    if (event.key.code == sfKeyQ)
        player->position = POSITION_LEFT(player->position);
    if (event.key.code == sfKeyD)
        player->position = POSITION_RIGHT(player->position);
}
