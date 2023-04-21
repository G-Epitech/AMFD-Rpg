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

void core_interactions_travel(sfColor pixel, app_t *app)
{
    if (core_interaction_detect_color(pixel, EXIT_COLOR))
        app->interaction->type = IT_EXIT;
    if (core_interaction_detect_color(pixel, ENTER_COLOR))
        app->interaction->type = IT_ENTER;
}

void core_handle_travel(renderer_t *renderer, app_t *app, map_t *curr_map)
{
    if (PLAYER_ON_EXIT(app->interaction->type))
        travel_exit(app, renderer, curr_map);
    if (PLAYER_ON_ENTER(app->interaction->type)) {
        travel_enter(app, renderer, curr_map);
    }
}
