/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** npc
*/

#include "app/types.h"
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

static bool npc_is_in_world(npc_t *npc, npc_data_t **world_data,
worlds_t world)
{
    node_t *node = npc->worlds_data ? npc->worlds_data->first : NULL;
    bool in_world = false;

    while (node && !in_world) {
        if ((worlds_t) node->data.npc_data.world == world) {
            in_world = true;
            *world_data = &node->data.npc_data;
        }
        node = node->next;
    }
    return in_world;
}

void display_npcs_of_world(renderer_t *renderer, list_t *npcs,
worlds_t world)
{
    node_t *node = npcs ? npcs->first : NULL;
    npc_data_t *world_data = NULL;

    while (node) {
        if (npc_is_in_world(&node->data.npc, &world_data, world))
            display_npc(renderer, world_data);
        node = node->next;
    }
}
