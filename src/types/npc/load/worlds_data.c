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

bool npc_load_worlds_data(cjson_array_t *config, npc_t *npc)
{
    list_t *worlds_data = list_new();
    cjson_t *world_data = config->first;

    if (!worlds_data)
        return false;
    while (world_data) {
        npc_load_world_data(world_data, worlds_data);
        world_data = world_data->next;
    }
    npc->worlds_data = worlds_data;
    return true;
}
