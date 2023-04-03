/*
** EPITECH PROJECT, 2023
** player_movement.c
** File description:
** Functions that will help player movement
*/

#include "app/app.h"
#include "types/players/players.h"
#include "app/events/types.h"

void core_handle_movement(player_t *player, control_t *control,
int **collision_layer)
{
    if (control->down)
        player->position = POSITION_DOWN(player->position);
    if (control->up)
        player->position = POSITION_UP(player->position);
    if (control->right)
        player->position = POSITION_RIGHT(player->position);
    if (control->left)
        player->position = POSITION_LEFT(player->position);
}
