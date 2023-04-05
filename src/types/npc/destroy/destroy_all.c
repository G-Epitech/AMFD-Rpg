/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdlib.h>
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"

static void npc_destroy(npc_t *npc)
{
    free(npc->name);
    npc_destroy_worlds_data(npc->worlds_data);
}

void npcs_destroy(list_t *npcs)
{
    node_t *node = npcs ? npcs->first : NULL;

    while (node) {
        npc_destroy(&node->data.npc);
        node = node->next;
    }
    list_free(npcs);
}
