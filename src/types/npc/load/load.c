/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load_npc
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"

static void append_npc(list_t *npcs, npc_t *npc)
{
    node_t *node = node_new((node_data_t) (*npc));

    if (!node)
        return;
    list_append(npcs, node);
}

void npc_load(list_t *npcs, cjson_t *config)
{
    cjson_array_t *worlds_data = NULL;
    npc_t npc = { NULL, 0, NULL };

    if (!cjson_get_prop_string(config, "name", &npc.name))
        return;
    if (!cjson_get_prop_int(config, "id", &npc.id))
        return;
    if (!cjson_get_prop_array(config, "worlds_data", &worlds_data))
        return free(npc.name);
    if (!npc_load_worlds_data(worlds_data, &npc))
        return free(npc.name);
    append_npc(npcs, &npc);
}
