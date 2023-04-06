/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get
*/

#include "types/npc/npc.h"
#include "types/list/list.h"

npc_data_t * npc_get_data_of_world(npc_t *npc, int world)
{
    node_t *node = npc->worlds_data ? npc->worlds_data->first : NULL;

    while (node) {
        if (node->data.npc_data.world == world)
            return &node->data.npc_data;
        node = node->next;
    }
    return NULL;
}
