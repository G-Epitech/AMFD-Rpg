/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Displays shop interface
*/

#include <stdbool.h>
#include "types/list/list.h"
#include "app/shop/shop_handle.h"
#include "types/renderer/renderer.h"
#include "app/app.h"
#include "my/include/my.h"

static void display_shop_item_stock(shop_stock_t *stock,
sfRenderWindow *window, renderer_objects_t *objects)
{
    sfVector2f grid_pos = GRID_POS;

    renderer_objects_reset_sprite(objects);
    sfSprite_setTexture(objects->sprite, stock->item_grid, sfTrue);
    sfSprite_setTextureRect(objects->sprite, GRID_BASIC_RECT);
    sfSprite_setPosition(objects->sprite, grid_pos);
    for (size_t i = 0; i < stock->curr_items_len; i++) {
        sfRenderWindow_drawSprite(window, objects->sprite, NULL);
        grid_pos.x += GRID_NEXT_POS_OFFSET;
        sfSprite_setPosition(objects->sprite, grid_pos);
    }
}

static void display_shop_interface(list_t *shops, int curr_shop_id,
renderer_t *renderer)
{
    node_t *node = shops->first;
    shop_t *shop = NULL;

    while (node) {
        shop = node->data.shop;
        if (curr_shop_id == shop->id) {
            display_shop_item_stock(shop->stock, renderer->window,
            renderer->objects);
        }
        node = node->next;
    }
}

void display_shop(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    if (app->state != ST_SHOP)
        return;
    display_shop_interface(app->shops, app->interaction->data.shop_id,
    renderer);
}
