/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** worlds_data
*/

#include <stdio.h>
#include <stdbool.h>
#include "app/types.h"
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "types/characters/types.h"

static sfVector2f get_position_vector(cjson_t *position)
{
    sfVector2f vector = {
        cjson_get_prop_int_unsafe(position, "x"),
        cjson_get_prop_int_unsafe(position, "y")
    };

    return vector;
}

static bool load_single_props(cjson_t *config, npc_data_t *world_data)
{
    cjson_t *position = NULL;

    if (!cjson_get_prop_int(config, "world", &world_data->world))
        return false;
    if (!cjson_get_prop_int(config, "skin_id", &world_data->skin_id))
        return false;
    if (!cjson_get_prop_int(config, "orientation", &world_data->orientation))
        return false;
    position = cjson_get_prop(config, "position");
    if (!position)
        return false;
    world_data->position = get_position_vector(position);
    world_data->position.x = (world_data->position.x / 16) * 16;
    world_data->position.y = (world_data->position.y / 16) * 16;
    return true;
}

static void append_world_data(npc_data_t *world_data, list_t *worlds_data)
{
    node_t *node = node_new((node_data_t) (*world_data));

    if (!world_data)
        return;
    list_append(worlds_data, node);
}

bool npc_load_world_data(cjson_t *config, list_t *worlds_data, npc_t *npc)
{
    npc_data_t world_data = {
        0, 0,
        SO_FACE, (sfVector2f) {0, 0},
        NULL, NULL, NULL
    };
    cjson_t *enemy = NULL;
    cjson_array_t *dialogs = NULL;

    if (!load_single_props(config, &world_data))
        return false;
    if (!cjson_get_prop_array(config, "dialogs", &dialogs))
        return false;
    enemy = cjson_get_prop(config, "enemy");
    if (enemy)
        npc_load_world_enemy(enemy, &world_data);
    npc_load_world_dialogs(dialogs, &world_data);
    append_world_data(&world_data, worlds_data);
    world_data.npc = npc;
    return true;
}
