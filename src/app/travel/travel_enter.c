/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions working with core to assure traveling
*/

#include <stdbool.h>
#include <stdio.h>
#include "app/app.h"
#include "app/travel/travel.h"
#include "app/core/core.h"
#include "types/renderer/types.h"

void travel_enter_in_building(app_t *app, renderer_t *renderer)
{
    map_t *next_map = NULL;

    if (app->player->map_stage > 0) {
        app->world++;
        next_map =  get_current_map(renderer, app);
        app->player->map_stage++;
        app->player->position.x = next_map->enter.x;
        app->player->position.y = next_map->enter.y;
    }
}

void travel_enter(app_t *app, renderer_t *renderer, map_t *curr_map)
{
    if (curr_map->building) {
        travel_enter_in_building(app, renderer);
    }
    app->interaction->type = IT_NULL;
}
