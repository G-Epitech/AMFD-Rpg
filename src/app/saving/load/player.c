/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** save
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/app.h"
#include "app/saving/saving.h"
#include "cjson/include/cjson.h"

static void save_load_restore_player_map_data(player_t *player,
cjson_t *player_file)
{
    cjson_t *position = cjson_get_prop(player_file, "position");
    int state = 0;

    player->position = (sfVector2f) PLAYER_DEFAULT_SPAWN;
    if (!position)
        return;
    cjson_get_prop_float(position, "x", &player->position.x);
    cjson_get_prop_float(position, "y", &player->position.y);
    cjson_get_prop_int(player_file, "orientation", &player->orientation);
    cjson_get_prop_int(player_file, "state", &state);
    player->state = (enitity_state_t) state;
}

static void save_load_restore_player_stats(player_t *player,
cjson_t *player_file)
{
    cjson_get_prop_int(player_file, "credits", &player->credits);
    cjson_get_prop_int(player_file, "xp_max", &player->xp_max);
    cjson_get_prop_int(player_file, "level", &player->level);
}

void save_load_restore_player(app_t *app, cjson_t *player_file)
{
    player_t *player = app->player;

    free(player->name);
    cjson_get_prop_string(player_file, "name", &player->name);
    cjson_get_prop_int(player_file, "skin_id", &player->skin_id);
    save_load_restore_player_map_data(player, player_file);
    save_load_restore_player_stats(player, player_file);
    save_load_restore_player_inventory(player, player_file, app->items);
    save_load_restore_player_competences(player, player_file);
}
