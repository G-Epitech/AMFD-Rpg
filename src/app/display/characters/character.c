/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** character
*/

#include "types/characters/characters.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void display_character(renderer_t *renderer, sfVector2f position,
int skin_id, skin_orientation_t orientation)
{
    sfSprite *sprite = renderer->objects->sprite;
    list_t *skins = renderer->ressources->skins;
    const skin_t *skin = ressources_get_skin(skins, skin_id);
    sfIntRect rect = character_get_rect(orientation);

    if (!skin)
        return;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, skin->texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}
