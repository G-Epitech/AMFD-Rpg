/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions to load items into the stock
*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "my/include/my.h"
#include "app/shop/shop_handle.h"
#include "types/list/list.h"
#include "app/app.h"

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

void load_items_stock(app_t *app)
{
    node_t *node = app->shops->first;
    shop_t *shop = NULL;

    srand(time(NULL));
    while (node) {
        shop = node->data.shop;
        for (size_t i = 0; i < shop->stock->curr_items_len; i++) {
            choose_random_item(&shop->stock->curr_items[i], app->items,
            shop->stock->total_items_len - 1);
        }
        node = node->next;
    }
}
