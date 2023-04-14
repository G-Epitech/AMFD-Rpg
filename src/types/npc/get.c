/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get
*/

#include "app/types.h"
#include "types/npc/npc.h"
#include "types/list/list.h"

npc_data_t *npc_get_data_by_id(list_t *npcs, int id, worlds_t world)
{
    node_t *node = npcs->first;
    npc_t npc;

    while (node) {
        npc = node->data.npc;
        if (npc.id == id)
            return npc_get_data_of_world(&npc, world);
        node = node->next;
    }
    return NULL;
}

npc_data_t *npc_get_data_of_world(npc_t *npc, worlds_t world)
{
    node_t *node = npc->worlds_data ? npc->worlds_data->first : NULL;

    while (node) {
        if (node->data.npc_data.world == (int) world)
            return &node->data.npc_data;
        node = node->next;
    }
    return NULL;
}
