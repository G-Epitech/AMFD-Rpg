/*
** EPITECH PROJECT, 2023
** back.c
** File description:
** Display back of the map
*/

#include <SFML/Graphics.h>
#include "types/ressources/types.h"
#include "types/renderer/types.h"
#include "app/display/display.h"
#include "types/list/types.h"
#include "app/types.h"

void display_map_back(list_t *maps, sfRenderWindow *window, sfSprite *sprite,
worlds_t world)
{
    node_t *node = maps->first;

    while (node) {
        if (node->data.map->world == world)
            display_map(node->data.map->back, window, sprite);
        node = node->next;
    }
}
