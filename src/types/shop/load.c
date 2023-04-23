/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions to load shop
*/

#include <stddef.h>
#include <stdlib.h>
#include "my/include/my.h"
#include "app/app.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"
#include "app/shop/shop.h"
#include "types/components/components.h"

static shop_stock_t *shop_load_stock(cjson_t *shop_config)
{
    shop_stock_t *stock = malloc(sizeof(shop_stock_t));
    cjson_array_t *array = NULL;
    size_t len = 0;

    if (!stock)
        return NULL;
    array = cjson_get_prop_array_unsafe(shop_config, "items");
    stock->total_items = cjson_array_to_int_array(array, &len);
    stock->total_items_len = len;
    stock->curr_items_len = cjson_get_prop_int_unsafe(shop_config,
    "curr_items_len");
    if (stock->curr_items_len > ITEMS_MAX) {
        my_putstr("Too many current items in the shop, (capped to 8)\n");
    }
    stock->curr_items = malloc(sizeof(item_t) * stock->curr_items_len);
    stock->item_grid = sfTexture_createFromFile(GRID_FILE, NULL);
    if (!stock->curr_items || !stock->item_grid)
        return NULL;
    return stock;
}

static bool shop_load_props(shop_t *shop, cjson_t *shop_config)
{
    shop->stock = shop_load_stock(shop_config);
    if (!shop->stock)
        return false;
    shop->name = cjson_get_prop_string_unsafe(shop_config, "name");
    shop->world = cjson_get_prop_int_unsafe(shop_config, "world");
    shop->pos = cjson_vector(shop_config, "pos");
    shop->tile_len = cjson_get_prop_int_unsafe(shop_config, "tile_len");
    shop->direction = cjson_get_prop_int_unsafe(shop_config, "direction");
    shop->id = cjson_get_prop_int_unsafe(shop_config, "id");
    shop->clock = sfClock_create();
    if (!shop->clock)
        return false;
    return true;
}

static void shop_append(list_t *shops, cjson_t *shop_config)
{
    node_t *node = NULL;
    shop_t *shop = malloc(sizeof(shop_t));

    if (!shop || shop_load_props(shop, shop_config) == false)
        return;
    node = node_new((node_data_t) shop);
    if (node)
        list_append(shops, node);
}

list_t *load_shop(renderer_t *renderer)
{
    list_t *shops = list_new();
    cjson_t *shop_config = cjson_parse_file(SHOP_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *shop = NULL;

    if (!shop_config)
        return NULL;
    if (!cjson_get_array(shop_config, &array)) {
        cjson_free(shop_config);
        return NULL;
    }
    shop = array->first;
    while (shop) {
       shop_append(shops,shop);
       shop = shop->next;
    }
    cjson_free(shop_config);
    shop_include_to_array(renderer, shops);
    return shops;
}
