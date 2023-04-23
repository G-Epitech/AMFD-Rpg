/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init the application
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/types.h"
#include "types/list/list.h"
#include "app/dependencies.h"
#include "types/players/players.h"
#include "types/ressources/ressources.h"

void init_player_fake_inventory(player_t *player, list_t *items)
{
    node_t *node = items ? items->first : NULL;
    int i = 0;

    while (i < INVENTORY_MAX && node) {
        if (inventory_add_item(player, node->data.item))
            i += 1;
        node = node->next;
    }
}

static int init_player(app_t *app)
{
    app->player = players_add(app->players, "Player1");
    app->partner = NULL;
    if (!app->player)
        return 84;
    init_player_fake_inventory(app->player, app->items);
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
    app->world = WL_PLAYER_HOME_2;
    app->clock = sfClock_create();
    app->game_file = NULL;
    while (app_init_members[member]) {
        if (!(app_init_members[member++](app, renderer))) {
            app_free(app);
            return NULL;
        }
    }
    map_charge_collision_textures(renderer->ressources->maps);
    if (init_player(app) == 84)
        return NULL;
    return app;
}
