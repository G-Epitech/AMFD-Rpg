/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions for travelling throughout maps
*/

#include <stdbool.h>
#include <stdio.h>
#include "app/app.h"
#include "app/core/core.h"
#include "app/travel/travel.h"

static bool detect_enter_color(sfColor pixel)
{
    if (pixel.r < ENTER_COLOR.r || pixel.b != ENTER_COLOR.b ||
    pixel.g < ENTER_COLOR.g)
        return false;
    return true;
}

void core_interactions_travel(sfColor pixel, app_t *app)
{
    printf("r%d g%d %d\n", pixel.r, pixel.g, pixel.b);
    if (core_interaction_detect_color(pixel, EXIT_COLOR)) {
        app->interaction->type = IT_EXIT;
        return;
    }
    if (detect_enter_color(pixel)) {
        app->interaction->type = IT_ENTER;
        app->interaction->value = 135 - pixel.r;
    }
}

void core_handle_travel(renderer_t *renderer, app_t *app, map_t *curr_map)
{
    if (PLAYER_ON_EXIT(app->interaction->type))
        travel_exit(app, renderer, curr_map);
    if (PLAYER_ON_ENTER(app->interaction->type)) {
        travel_enter(app, renderer, curr_map);
    }
}
