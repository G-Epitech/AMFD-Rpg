/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions to load items into the stock
*/

#include "stdio.h"
#include <stdlib.h>
#include "time.h"
#include "my/include/my.h"
#include "app/shop/shop_handle.h"
#include "types/list/list.h"
#include "app/app.h"

static sfIntRect *set_grid_rect(shop_t *shop)
{
    shop_stock_t *stock = shop->stock;
    sfIntRect *rect = malloc(sizeof(sfIntRect) * stock->curr_items_len);
    sfVector2f pos = GRID_POS;

    if (!rect)
        return NULL;
    for (size_t i = 0; i < stock->curr_items_len; i++) {
        rect[i].top = pos.y;
        rect[i].left = pos.x;
        rect[i].width = GRID_BASIC_RECT.width;
        rect[i].height = GRID_BASIC_RECT.height;
        pos.x += GRID_NEXT_POS_OFFSET;
    }
    return rect;
}

static void copy_item(item_t *shop_item, item_t *game_item)
{
    shop_item->consumer = game_item->consumer;
    shop_item->id = game_item->id;
    shop_item->label = my_strdup(game_item->label);
    shop_item->life = game_item->life;
    shop_item->price = game_item->price;
    shop_item->rect = game_item->rect;
    shop_item->speed = game_item->speed;
    shop_item->type = game_item->type;
    shop_item->xp = game_item->xp;
}

static void choose_random_item(item_t *shop_item, list_t *game_item,
int shop_item_len)
{
    unsigned int random = 0;
    node_t *node = game_item->first;
    item_t *item = NULL;

    random = (unsigned) rand() % shop_item_len;
    while (node) {
        item = node->data.item;
        if (item->id == random) {
            copy_item(shop_item, item);
            return;
        }
        node = node->next;
    }
}

bool load_items_stock(shop_t *shop, app_t *app)
{
    for (size_t i = 0; i < shop->stock->curr_items_len; i++) {
        choose_random_item(&shop->stock->curr_items[i], app->items,
        shop->stock->total_items_len - 1);
    }
    shop->grid = set_grid_rect(shop);
    if (!shop->grid)
        return false;
    return true;
}
