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

void display_inventory_get_item_position(size_t i, bool active,
sfVector2f *position)
{
    sfVector2i grid_size = INVENTORY_MAIN_GRID_SIZE;
    sfVector2f grid_pos = INVENTORY_MAIN_GRID_POS;
    sfVector2f grid_margin = INVENTORY_MAIN_GRID_MARGIN;
    float item_size = INVENTORY_MAIN_GRID_ITEM_SIZE;
    sfVector2i pos = {0, 0};

    if (active) {
        grid_size = INVENTORY_ACTIVE_GRID_SIZE;
        grid_pos = INVENTORY_ACTIVE_GRID_POS;
        grid_margin = INVENTORY_ACTIVE_GRID_MARGIN;
        item_size = INVENTORY_ACTIVE_GRID_ITEM_SIZE;
    }
    pos.y = (i / grid_size.x);
    pos.x = (i - grid_size.x * pos.y);
    position->x = grid_pos.x + (grid_margin.x * pos.x) + (item_size * pos.x);
    position->y = grid_pos.y + (grid_margin.y * pos.y) + (item_size * pos.y);
}

static void get_rect_and_scale(bool active, bool empty, sfIntRect *rect,
float *scale)
{
    if (empty)
        *rect = INVENTORY_GRID_ITEM_INACTIVE_RECT;
    else
        *rect = INVENTORY_GRID_ITEM_ACTIVE_RECT;
    if (active)
        *scale = INVENTORY_ACTIVE_GRID_ITEM_SIZE / (float) rect->width;
    else
        *scale = INVENTORY_MAIN_GRID_ITEM_SIZE / (float) rect->width;
}

static void display_item_box(renderer_t *renderer, bool active, bool empty,
size_t i)
{
    sfVector2f position = {0, 0};
    sfTexture *utils = renderer->ressources->inventory->grid;
    sfSprite *sprite = renderer->objects->sprite;
    sfIntRect rect = {0, 0, 0, 0};
    float scale = 0;

    get_rect_and_scale(active, empty, &rect, &scale);
    display_inventory_get_item_position(i, active, &position);
    if (!utils)
        return;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, utils, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, (sfVector2f) {scale, scale});
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}

void display_inventory_item_box(renderer_t *renderer, size_t i,
bool active, bool empty)
{
    i -= 1;
    display_item_box(renderer, active, empty, i);
}
