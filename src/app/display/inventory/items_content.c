/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_grid
*/

#include <stdio.h>
#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "app/inventory/types.h"
#include "types/ressources/ressources.h"

static void adapt_scale_and_position(inventory_item_t *item, float *scale,
sfVector2f *position)
{
    float size = INVENTORY_MAIN_GRID_ITEM_SIZE;
    sfVector2f real = {ITEM_SIZE.x, ITEM_SIZE.y};

    if (item->active)
        size = INVENTORY_ACTIVE_GRID_ITEM_SIZE;
    *scale = (float) size / INVENTORY_ACTIVE_GRID_ITEM_SIZE;
    real.x *= *scale;
    real.y *= *scale;
    position->x += (size - real.x) / 2;
    position->y += (size - real.y) / 2;
}

static void display_item(renderer_t *renderer, inventory_item_t *item)
{
    sfTexture *texture = renderer->ressources->items;
    sfSprite *sprite = renderer->objects->sprite;
    sfVector2f position = {0, 0};
    sfIntRect rect = item->target->rect;
    float scale = 0;

    display_inventory_get_item_position(item->pos, item->active, &position);
    adapt_scale_and_position(item, &scale, &position);
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, (sfVector2f) {scale, scale});
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}

void display_inventory_item_content(renderer_t *renderer,
inventory_item_t *item)
{
    display_item(renderer, item);
}
