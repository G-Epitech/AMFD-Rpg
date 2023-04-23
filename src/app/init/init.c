/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init the application
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/types.h"
#include "app/dependencies.h"
#include "types/players/players.h"
#include "types/ressources/ressources.h"

static int init_player(app_t *app)
{
    app->player = players_add(app->players, "Player1");
    app->partner = NULL;
    if (!app->player)
        return 84;
    player_init_inventory(app->player, app->items);
    return 0;
}

app_t *app_init(renderer_t *renderer)
{
    app_t *app = malloc(sizeof(app_t));
    size_t member = 0;

    if (!app)
        return NULL;
    app->state = ST_MAIN_MENU;
    app->prev_state = app->state;
    app->world = WL_STORE;
    app->clock = sfClock_create();
    while (app_init_members[member]) {
        if (!(app_init_members[member](app, renderer))) {
            app_free(app);
            return NULL;
        }
        member += 1;
    }
    map_charge_collision_textures(renderer->ressources->maps);
    if (init_player(app) == 84) {
        return NULL;
    }
    return app;
}
