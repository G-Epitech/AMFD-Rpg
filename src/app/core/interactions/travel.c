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
#include "types/list/list.h"


void core_interactions_travel(sfColor pixel, app_t *app)
{
    if (core_interaction_detect_color(pixel, sfBlue)) {
        app->interaction->type = IT_TRAVEL;
        app->interaction->data.entry_id = 255 - pixel.a;
        app->interaction->interaction = true;
        app->interaction->active = false;
    }
}

static entry_t *get_entry_by_id(list_t *entries, int entry_id)
{
    node_t *node = entries->first;
    entry_t *entry = NULL;

    while (node) {
        entry = node->data.entry;
        if (entry->id == entry_id) {
            return entry;
        }
        node = node->next;
    }
    return NULL;
}

static void travel_player(app_t *app, map_t *curr_map)
{
    player_t *player = app->player;
    entry_t *entry = get_entry_by_id(curr_map->entry,
    app->interaction->data.entry_id);

    app->world = entry->child;
    player->position.x = entry->player_spawn.x;
    player->position.y = entry->player_spawn.y;
    app->interaction->type = IT_NULL;
    app->interaction->interaction = false;
    app->interaction->active = false;
}

void core_handle_travel(renderer_t *renderer, app_t *app, map_t *curr_map)
{
    (void) renderer;
    if (PLAYER_TRAVELING(app->interaction->type) &&
    app->interaction->active) {
        travel_player(app, curr_map);
    }
}
