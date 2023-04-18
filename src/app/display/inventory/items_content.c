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

static void adapt_scale_and_position(bool active, float *scale,
sfVector2f *position)
{
    float size = INVENTORY_MAIN_GRID_ITEM_SIZE;
    sfVector2f real = {ITEM_SIZE.x, ITEM_SIZE.y};

    if (active)
        size = INVENTORY_ACTIVE_GRID_ITEM_SIZE;
    *scale = (float) size / INVENTORY_ACTIVE_GRID_ITEM_SIZE;
    real.x *= *scale;
    real.y *= *scale;
    position->x += (size - real.x) / 2;
    position->y += (size - real.y) / 2;
}

static void display_item(renderer_t *renderer, item_t *item,
sfVector2f position, bool active)
{
    sfTexture *texture = renderer->ressources->items;
    sfSprite *sprite = renderer->objects->sprite;
    sfIntRect rect = item->rect;
    float scale = 0;

    adapt_scale_and_position(active, &scale, &position);
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, (sfVector2f) {scale, scale});
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}

static bool prevent_special(renderer_t *renderer,
inventory_item_t *item, inventory_event_t *event)
{
    sfVector2f position = {0, 0};

    if (!event->moved || !event->pressed)
        return false;
    if (event->item_pos == item->pos && item->active == event->item_active) {
        display_item(renderer, item->target, event->position,
        event->target_active);
        return true;
    }
    if (event->target_pos == item->pos
        && item->active == event->target_active) {
        display_inventory_get_item_position(event->item_pos,
        event->item_active, &position);
        display_item(renderer, item->target, position, event->item_active);
        return true;
    }
    return false;
}

void display_inventory_item_content(renderer_t *renderer,
inventory_item_t *item, inventory_event_t *event)
{
    sfVector2f position = {0, 0};

    if (!prevent_special(renderer, item, event)) {
        display_inventory_get_item_position(item->pos, item->active, &position);
        display_item(renderer, item->target, position, item->active);
    }
}
