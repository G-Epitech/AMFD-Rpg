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
#include "types/character/types.h"

static sfVector2f get_position_vector(cjson_t *position)
{
    sfVector2f vector = {
        cjson_get_prop_int_unsafe(position, "x"),
        cjson_get_prop_int_unsafe(position, "y")
    };

    return vector;
}

static void append_world_data(npc_data_t *world_data, list_t *worlds_data)
{
    node_t *node = node_new((node_data_t) (*world_data));

    if (!world_data)
        return;
    list_append(worlds_data, node);
}

static bool load_world_data(cjson_t *config, list_t *worlds_data)
{
    npc_data_t world_data = {0, 0, SO_FACE, (sfVector2f) {0, 0}, NULL};
    cjson_t *position = NULL;
    cjson_array_t *dialogs = NULL;

    if (!cjson_get_prop_int(config, "world", &world_data.world))
        return false;
    if (!cjson_get_prop_int(config, "skin", &world_data.skin))
        return false;
    position = cjson_get_prop(config, "position");
    if (!position)
        return false;
    if (!cjson_get_prop_array(config, "dialogs", &dialogs))
        return false;
    world_data.position = get_position_vector(position);
    npc_load_world_dialogs(dialogs, &world_data);
    append_world_data(&world_data, worlds_data);
    return true;
}

bool npc_load_worlds_data(cjson_array_t *config, npc_t *npc)
{
    list_t *worlds_data = list_new();
    cjson_t *world_data = config->first;

    if (!worlds_data)
        return false;
    while (world_data) {
        load_world_data(world_data, worlds_data);
        world_data = world_data->next;
    }
    npc->worlds_data = worlds_data;
    return true;
}
