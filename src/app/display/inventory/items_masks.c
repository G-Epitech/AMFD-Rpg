/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** items_masks
*/

#include <stdio.h>
#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "app/inventory/types.h"
#include "types/ressources/ressources.h"

static void display_consumable_mask(renderer_t *renderer,
sfVector2f position, float scale)
{
    sfTexture *texture = renderer->ressources->inventory->grid;
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, INVENTORY_GRID_ITEM_CONSUMABLE_RECT);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, (sfVector2f) {scale, scale});
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}

void inventory_display_item_masks(renderer_t *renderer, item_t *item,
sfVector2f position, float scale)
{
    if (item->type == IVT_CONSUMABLE)
        display_consumable_mask(renderer, position, scale);
}
