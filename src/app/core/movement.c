/*
** EPITECH PROJECT, 2023
** player_movement.c
** File description:
** Functions that will help player movement
*/

#include "app/app.h"
#include "types/players/players.h"
#include "app/events/types.h"
#include "app/network/network.h"

static bool movement_is_possible(sfVector2f position, sfVector2f offset,
int **collision_layer)
{
    int collision = 0;
    int x = position.x + offset.x / 16;
    int y = position.y + offset.y / 16;
    collision = collision_layer[(int) y][(int) x];
    if (collision_layer == 1) {
        return true;
    }
}

static sfVector2f increment_position(sfVector2f position, sfVector2f offset)
{
    position.x += offset.x;
    position.y += offset.y;
    return position;
}

void core_handle_movement(control_t *control, int **collision_layer,
app_t *app)
{
    player_t *player = app->player;

    if (app->state != ST_INGAME)
        return;
    for (size_t i = 0; i < 4; i++) {
        if (control[i].direction && movement_is_possible(player->colision_pos,
        control[i].offset, collision_layer)) {
            player->position = increment_position(player->position,
            control[i].offset);
            player->colision_pos = increment_position(player->colision_pos,
            (sfVector2f) {control[i].offset.x / 16, control[i].offset.y / 16});
        }
    }
    if (app->partner)
        network_send_position(app);
}
