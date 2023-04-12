/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** rect
*/

#include "types/characters/types.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

sfIntRect character_get_rect(skin_orientation_t orientation)
{
    skin_config_t config = skin_configs[orientation];
    sfIntRect rect = {0, 0, 0, 0};

    rect.height = RESSOURCES_SKINS_RECT.y;
    rect.width = RESSOURCES_SKINS_RECT.x  * config.weight;
    rect.top = RESSOURCES_SKINS_RECT.y * config.y;
    rect.left += RESSOURCES_SKINS_RECT.x * config.x;
    return rect;
}
