/*
** EPITECH PROJECT, 2023
** include.c
** File description:
** Include NPCs to map collisions
*/

#include "app/types.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

static void insert_npc(sfImage *collision, sfVector2f position, int id)
{
    sfColor color = sfYellow;

    color.a = id;
    position.y += 6;
    for (size_t y = 0; y < 26; y++) {
        for (size_t x = 0; x < 16; x++) {
            sfImage_setPixel(
                collision, position.x + x,
                position.y + y,
                color
            );
        }
    }
}

static sfImage *get_collision_by_id(renderer_t *renderer, worlds_t id)
{
    list_t *maps = renderer->ressources->maps;
    node_t *node = maps->first;
    map_t *map;

    while (node) {
        map = node->data.map;
        if (map->world == id) {
            return map->collision;
        }
        node = node->next;
    }
    return NULL;
}

static void include_data(renderer_t *renderer, npc_t *npc)
{
    list_t *npc_data = npc->worlds_data;
    node_t *node = npc_data->first;
    npc_data_t data;
    sfImage *collision = NULL;

    while (node) {
        data = node->data.npc_data;
        collision = get_collision_by_id(renderer, data.world);
        if (collision) {
            insert_npc(collision, data.position, npc->id);
        }
        node = node->next;
    }
}

void npcs_include_to_array(renderer_t *renderer, list_t *npcs)
{
    (void)renderer;
    (void)npcs;
    node_t *node = NULL;
    npc_t npc;

    if (!npcs)
        return;
    node = npcs->first;
    while (node) {
        npc = node->data.npc;
        include_data(renderer, &npc);
        node = node->next;
    }
}
