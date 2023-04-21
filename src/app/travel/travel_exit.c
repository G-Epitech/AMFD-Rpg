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
#include "types/renderer/types.h"

void travel_exit_in_building(app_t *app, map_t *curr_map)
{
    if (app->player->map_stage > 1) {
        app->world--;
    } else {
        app->world = curr_map->city;
    }
    app->player->map_stage--;
    app->player->position.x = curr_map->exit.x;
    app->player->position.y = curr_map->exit.y;
}

void travel_exit(app_t *app, renderer_t *renderer, map_t *curr_map)
{
    (void) renderer;
    printf("Exit\n");
    if (curr_map->building) {
        travel_exit_in_building(app, curr_map);
        printf("Curr is building\n");
    }
    printf("Player map stage %d\n", app->player->map_stage);
    app->interaction->type = IT_NULL;
}
