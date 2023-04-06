/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** npc
*/

#include "app/types.h"
#include "types/npc/npc.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

static void display_npc(renderer_t *renderer, npc_data_t *world_data)
{
    sfVector2f position = world_data->position;
    int skin_id = world_data->skin_id;
    skin_orientation_t orientation = world_data->orientation;

    display_character(renderer, position, skin_id, orientation);
}

void display_npcs_of_world(renderer_t *renderer, list_t *npcs,
worlds_t world)
{
    node_t *node = npcs ? npcs->first : NULL;
    npc_data_t *world_data = NULL;

    while (node) {
        world_data = npc_get_data_of_world(&node->data.npc, world);
        if (world_data)
            display_npc(renderer, world_data);
        node = node->next;
    }
}
