/*
** EPITECH PROJECT, 2023
** player_movement.c
** File description:
** Functions that will help player movement
*/

#include "app/app.h"
#include "types/players/players.h"
#include "app/events/types.h"

static int movement_is_possible(sfVector2f position, int **collision_layer)
{
    if (collision_layer[(int)position.y][(int)position.x])
        return 1;
    return 0;
}

static sfVector2f increment_position(sfVector2f position, sfVector2f offset)
{
    position.x += offset.x;
    position.y += offset.y;
    return position;
}

void core_handle_movement(player_t *player, control_t *control,
int **collision_layer)
{
    for (size_t i = 0; i < 4; i++) {
        if (control[i].direction) {
            player->position = increment_position(player->position,
            control[i].offset);
        }
    }
}
