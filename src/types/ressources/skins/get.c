/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** get
*/

#include <stdlib.h>
#include "types/list/types.h"
#include "types/players/types.h"
#include "types/ressources/types.h"

const skin_t *ressources_get_skin(list_t *skins, int skin_id)
{
    node_t *node = skins ? skins->first : NULL;
    skin_t *skin = NULL;

    while (node && !skin) {
        if (node->data.skin.id == skin_id)
            skin = &node->data.skin;
    }
    return skin;
}
