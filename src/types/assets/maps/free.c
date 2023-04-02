/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** Free all maps data
*/

#include <SFML/Graphics.h>
#include "types/assets/types.h"
#include "types/list/types.h"

void maps_free_data(list_t *maps)
{
    node_t *node = NULL;

    if (!maps)
        return;
    node = maps->first;
    while (node) {
        if (node->data.map->back)
            sfTexture_destroy(node->data.map->back);
        if (node->data.map->front)
            sfTexture_destroy(node->data.map->front);
        node = node->next;
    }
}
