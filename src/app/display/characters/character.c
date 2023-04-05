/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** character
*/

#include "types/character/types.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

static sfIntRect get_rect(skin_orientation_t orientation)
{
    sfVector2i factor = skin_orientations[orientation];
    sfIntRect rect = {0, 0, 0, 0};

    rect.left = RESSOURCES_SKINS_RECT.x * factor.x;
    rect.top = RESSOURCES_SKINS_RECT.y * factor.y;
    return rect;
}

void display_character(renderer_t *renderer, sfVector2f position,
int skin_id, skin_orientation_t orientation)
{
    sfSprite *sprite = renderer->objects->sprite;
    list_t *skins = renderer->ressources->skins;
    const skin_t *skin = ressources_get_skin(skins, skin_id);
    sfIntRect rect = get_rect(orientation);

    if (!skin)
        return;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, skin->texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}
