/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** Updates periodically the shop stock
*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "my/include/my.h"
#include "app/shop/shop_handle.h"
#include "types/list/list.h"
#include "app/app.h"

void core_shop_update_stock(app_t *app)
{
    node_t *node = app->shops->first;
    shop_t *shop = NULL;

    srand(time(NULL));
    while (node) {
        shop = node->data.shop;
        if (sfTime_asSeconds(sfClock_getElapsedTime(shop->clock)) > 900) {
            shop->stock->curr_items_len = rand() % 7;
            load_items_stock(shop, app);
            sfClock_restart(shop->clock);
        }
        node = node->next;
    }
}
