/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** profile
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "app/inventory/types.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "types/characters/characters.h"

void display_inventory_profile(renderer_t *renderer, app_t *app)
{
    sfSprite *sprite = renderer->objects->sprite;
    const skin_t *skin = ressources_get_skin(
        renderer->ressources->skins,
        app->player->skin_id
    );
    sfIntRect rect = character_get_rect(SO_FACE);
    sfVector2f origin = {rect.width / 2, rect.height / 2};
    sfVector2f position = INVENTORY_PROFILE_POS;

    position.x += INVENTORY_PROFILE_SIZE.x / 2;
    position.y += INVENTORY_PROFILE_SIZE.y / 2 - 35;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, skin->texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) {10, 10});
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setOrigin(sprite, origin);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}
