/*
** EPITECH PROJECT, 2023
** player_movement.c
** File description:
** Functions that will help player movement
*/

#include <stdbool.h>
#include <stdio.h>
#include "app/app.h"
#include "types/players/players.h"
#include "app/events/types.h"
#include "app/network/network.h"
#include "app/core/core.h"

static bool detect_interaction(sfVector2f position, sfImage *collision,
size_t y, app_t *app)
{
    sfColor pixel = {0, 0, 0, 255};

    app->interaction->interaction = false;
    for (size_t x = 0; x < 12; x++) {
        pixel = sfImage_getPixel(collision, position.x + x,
        position.y + y);
        if (pixel.a != 0) {
            core_interactions_npc(pixel, app);
            core_interactions_travel(pixel, app);
            return false;
        }
    }
    return true;
}

static int movement_is_possible(sfVector2f position, sfVector2f offset,
sfImage *collision, app_t *app)
{
    position.x += offset.x + 2;
    position.y += offset.y + 18;
    for (size_t y = 0; y < 14; y++) {
        if (!detect_interaction(position, collision, y, app))
            return false;
    }
    return true;
}

static sfVector2f increment_position(sfVector2f position, sfVector2f offset,
app_t *app, control_t *control)
{
    if (control->direction_nb > 1) {
        offset.x /= 1.3;
        offset.y /= 1.3;
    }
    position.x += offset.x;
    position.y += offset.y;
    if (app->partner)
        network_send_position(app);
    return position;
}

void core_handle_movement(control_t *control, sfImage *collision, app_t *app)
{
    player_t *player = app->player;

    if (app->state != ST_INGAME)
        return;
    for (size_t i = 0; i < 4; i++) {
        if (control[i].direction && movement_is_possible(player->position,
        control[i].offset, collision, app)) {
            player->position = increment_position(player->position,
            control[i].offset, app, control);
        }
    }
}
