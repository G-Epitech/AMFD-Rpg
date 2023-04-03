/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** Free all maps data
*/

#include <SFML/Graphics.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"

void skins_free(list_t *skins)
{
    node_t *node = NULL;

    if (!skins)
        return;
    node = skins->first;
    while (node) {
        if (node->data.skin.texture)
            sfTexture_destroy(node->data.skin.texture);
        node = node->next;
    }
    list_free(skins);
}
