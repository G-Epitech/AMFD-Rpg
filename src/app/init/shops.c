/*
** EPITECH PROJECT, 2023
** Init shops
** File description:
** shops
*/

#include <stdlib.h>
#include "app/types.h"
#include "app/shop/shop.h"
#include "app/shop/shop_handle.h"

bool app_init_shops(app_t *app, renderer_t *renderer)
{
    app->shops = load_shop(renderer);
    load_items_stock(app);
    return app->shops ? true : false;
}
