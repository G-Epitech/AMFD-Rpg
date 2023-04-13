/*
** EPITECH PROJECT, 2023
** player_movement.c
** File description:
** Functions that will help player movement
*/

#include <stdio.h>
#include "app/app.h"
#include "types/players/players.h"
#include "app/events/types.h"
#include "app/network/network.h"

static bool detect_interaction(sfVector2f position, sfImage *collision,
size_t y)
{
    sfColor pixel = {0, 0, 0, 255};

    for (size_t x = 0; x < 12; x++) {
        pixel = sfImage_getPixel(collision, position.x + x,
        position.y + y);
        if (pixel.a != 0) {
            return false;
        }
    }
}

static int movement_is_possible(sfVector2f position, sfVector2f offset,
sfImage *collision)
{
    position.x += offset.x + 2;
    position.y += offset.y + 18;
    for (size_t y = 0; y < 14; y++) {
        if (!detect_interaction(position, collision, y))
            return false;
    }
    return true;
}

static sfVector2f increment_position(sfVector2f position, sfVector2f offset)
{
    position.x += offset.x;
    position.y += offset.y;
    return position;
}

void core_handle_movement(control_t *control, sfImage *collision, app_t *app)
{
    player_t *player = app->player;

    if (app->state != ST_INGAME)
        return;
    for (size_t i = 0; i < 4; i++) {
        if (control[i].direction && movement_is_possible(player->position,
        control[i].offset, collision)) {
            player->position = increment_position(player->position,
            control[i].offset);
        }
    }
    if (app->partner)
        network_send_position(app);
}
