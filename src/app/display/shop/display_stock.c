/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Display shop stock
*/

#include <stdbool.h>
#include "types/list/list.h"
#include "app/shop/shop_handle.h"
#include "types/renderer/renderer.h"
#include "app/app.h"
#include "my/include/my.h"

static void display_item_price(item_t *item, sfRenderWindow *window,
renderer_objects_t *objects, sfVector2f item_pos)
{
    sfVector2f price_pos = (sfVector2f) {item_pos.x - 2, item_pos.y + 80};

    renderer_objects_reset_text(objects);
    sfText_setString(objects->text, nbr_to_str(item->price));
    sfText_setCharacterSize(objects->text, 30);
    sfText_setPosition(objects->text, price_pos);
    sfRenderWindow_drawText(window, objects->text, NULL);
}

static void display_shop_item(item_t *item,
sfRenderWindow *window, renderer_objects_t *objects, sfVector2f grid_pos)
{
    sfVector2f item_pos = (sfVector2f) {grid_pos.x + 20, grid_pos.y + 20};

    sfSprite_setPosition(objects->sprite, item_pos);
    sfSprite_setTextureRect(objects->sprite, item->rect);
    sfRenderWindow_drawSprite(window, objects->sprite, NULL);
    display_item_price(item, window, objects, item_pos);
}

static void display_shop_grid(sfRenderWindow *window,
renderer_objects_t *objects, sfVector2f grid_pos, sfTexture *item_grid)
{
    sfSprite_setTexture(objects->sprite, item_grid, sfTrue);
    sfSprite_setTextureRect(objects->sprite, GRID_BASIC_RECT);
    sfSprite_setPosition(objects->sprite, grid_pos);
    sfRenderWindow_drawSprite(window, objects->sprite, NULL);
}

static void display_shop_item_stock(shop_t *shop,
sfRenderWindow *window, renderer_objects_t *objects, sfTexture *item_texture)
{
    shop_stock_t *stock = shop->stock;
    sfVector2f grid_pos = GRID_POS;

    for (size_t i = 0; i < stock->curr_items_len; i++) {
        renderer_objects_reset_sprite(objects);
        display_shop_grid(window, objects, grid_pos, stock->item_grid);
        sfSprite_setTexture(objects->sprite, item_texture, sfTrue);
        display_shop_item(&stock->curr_items[i], window, objects, grid_pos);
        grid_pos.x += GRID_NEXT_POS_OFFSET;
    }
}

void display_shop_interface(list_t *shops, int curr_shop_id, int player_gold,
renderer_t *renderer)
{
    node_t *node = shops->first;
    shop_t *shop = NULL;

    while (node) {
        shop = node->data.shop;
        if (curr_shop_id == shop->id) {
            display_shop_item_stock(shop, renderer->window,
            renderer->objects, renderer->ressources->items);
            display_shop_info(shop, renderer->objects, renderer->window,
            player_gold);
        }
        node = node->next;
    }
}

