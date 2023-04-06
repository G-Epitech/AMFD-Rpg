/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** worlds_data
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/npc/npc.h"
#include "types/list/list.h"

static void npc_destroy_world_data_dialogs(list_t *dialogs)
{
    node_t *node = dialogs ? dialogs->first : NULL;

    while (node) {
        free(node->data.npc_dialog.label);
        free(node->data.npc_dialog.content);
        node = node->next;
    }
    list_free(dialogs);
}

void npc_destroy_worlds_data(list_t *worlds_data)
{
    node_t *node = worlds_data ? worlds_data->first : NULL;

    while (node) {
        npc_destroy_world_data_dialogs(node->data.npc_data.dialogs);
        npc_destroy_world_enemy(node->data.npc_data.enemy);
        node = node->next;
    }
    list_free(worlds_data);
}
