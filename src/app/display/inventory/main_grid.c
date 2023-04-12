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

static void get_position(size_t i, sfVector2f *position)
{
    int line = i / INVENTORY_MAIN_GRID_SIZE.x;
    int col = i - (INVENTORY_MAIN_GRID_SIZE.x * line);

    position->x = INVENTORY_MAIN_GRID_POS.x;
    position->x += INVENTORY_MAIN_GRID_MARGIN.x * col;
    position->x += INVENTORY_MAIN_GRID_ITEM_SIZE * col;
    position->y = INVENTORY_MAIN_GRID_POS.y;
    position->y += INVENTORY_MAIN_GRID_MARGIN.y * line;
    position->y += INVENTORY_MAIN_GRID_ITEM_SIZE * line;
}

static void display_item(renderer_t *renderer, size_t i)
{
    sfVector2f position = {0, 0};
    sfTexture *utils = renderer->ressources->inventory->grid;
    sfSprite *sprite = renderer->objects->sprite;
    sfIntRect rect = INVENTORY_GRID_ITEM_ACTIVE_RECT;
    float scale = (float) INVENTORY_MAIN_GRID_ITEM_SIZE / (float) rect.width;

    get_position(i, &position);
    if (!utils)
        return;
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, utils, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, position);
    sfSprite_setScale(sprite, (sfVector2f) {scale, scale});
    sfRenderWindow_drawSprite(renderer->objects->window, sprite, NULL);
}

void display_inventory_main_grid(renderer_t *renderer, app_t *app)
{
    sfVector2i size = INVENTORY_MAIN_GRID_SIZE;
    size_t nb_items = size.x * size.y;

    (void) app;
    for (size_t i = 0; i < nb_items; i++) {
        display_item(renderer, i);
    }
}
