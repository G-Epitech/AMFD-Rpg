/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** Creates the textures for the collision layers to
** see it in dev mode
*/

#include "types/list/list.h"
#include "types/renderer/types.h"

void map_charge_collision_textures(list_t *maps)
{
    node_t *node = maps->first;
    map_t *map = NULL;

    while (node) {
        map = node->data.map;
        map->col_texture = sfTexture_createFromImage(map->collision, NULL);
        node = node->next;
    }
}
