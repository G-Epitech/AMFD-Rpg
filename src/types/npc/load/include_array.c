/*
** EPITECH PROJECT, 2023
** include.c
** File description:
** Include NPCs to map collisions
*/

#include "app/types.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

static int **get_collisions_by_id(renderer_t *renderer, worlds_t id)
{
    list_t *maps = renderer->ressources->maps;
    node_t *node = maps->first;
    map_t *map;

    while (node) {
        map = node->data.map;
        if (map->world == id) {
            return map->collision_layer;
        } 
        node = node->next;
    }
    return NULL;
}

static void include_data(renderer_t *renderer, list_t *npc_data)
{
    node_t *node = npc_data->first;
    npc_data_t data;
    int **collisions = NULL;

    while (node) {
        data = node->data.npc_data;
        collisions = get_collisions_by_id(renderer, data.world);
        if (collisions) { 
            collisions[(int) data.position.y / 16]
            [(int) data.position.x / 16] = IT_NPC;
        }
        node = node->next;
    }
}

void npcs_include_to_array(renderer_t *renderer, list_t *npcs)
{
    node_t *node = NULL;
    npc_t npc;

    if (!npcs)
        return;
    node = npcs->first;
    while (node) {
        npc = node->data.npc;
        include_data(renderer, npc.worlds_data);
        node = node->next;
    }
}

