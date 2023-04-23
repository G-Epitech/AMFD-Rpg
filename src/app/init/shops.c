/*
** EPITECH PROJECT, 2023
** Init shops
** File description:
** shops
*/

#include <stdlib.h>
#include "time.h"
#include "app/types.h"
#include "app/shop/shop.h"
#include "app/shop/shop_handle.h"
#include "types/list/list.h"

static bool init_shop_stock(app_t *app)
{
    node_t *node = app->shops->first;
    shop_t *shop = NULL;

    srand(time(NULL));
    while (node) {
        shop = node->data.shop;
        if (!load_items_stock(shop, app))
            return false;
        node = node->next;
    }
    return true;
}

bool app_init_shops(app_t *app, renderer_t *renderer)
{
    app->shops = load_shop(renderer);
    if (init_shop_stock(app) == false)
        return false;
    return app->shops ? true : false;
}
