/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions for buying in shop
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/events/types.h"
#include "app/app.h"
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "app/inventory/inventory.h"

static bool click_on_grird(player_t *player, item_t *item)
{
    if (player->gold >= item->price) {
        player->gold -= item->price;
        inventory_add_item(player, item);
        return true;
    } else {
        return false;
    }
}

static void check_item_buy(player_t *player, sfEvent event,
shop_t *shop)
{
    shop_stock_t *stock = shop->stock;
    sfIntRect rect = {0, 0, 0, 0};

    for (size_t i = 0; i < shop->stock->curr_items_len; i++) {
        rect = shop->grid[i];
        printf("Player gold %d\n", player->gold);
        if (sfIntRect_contains(&rect, event.mouseButton.x,
        event.mouseButton.y) && event.mouseButton.button == sfMouseLeft) {
            shop->stock->active = click_on_grird(player, &stock->curr_items[i]);
            return;
        }
    }
}

static void buy_item_shop(app_t *app,sfEvent event)
{
    node_t *node = app->shops->first;
    shop_t *shop = NULL;

    while (node) {
        shop = node->data.shop;
        if (shop->id == app->interaction->data.shop_id)
            check_item_buy(app->player,event, shop);
        node = node->next;
    }
}

void buy_item(app_t *app,sfEvent event)
{
    if (app->state != ST_SHOP)
        return;
    buy_item_shop(app, event);
}