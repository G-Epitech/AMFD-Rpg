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

static void shop_append(list_t *shops, cjson_t *shop_config)
{
    node_t *node = NULL;
    shop_t *shop = malloc(sizeof(shop_t));
    cjson_array_t *array = NULL;
    size_t len = 0;

    if (!shop)
        return;
    shop->name = cjson_get_prop_string_unsafe(shop_config, "name");
    shop->world = cjson_get_prop_int_unsafe(shop_config, "world");
    shop->pos = cjson_vector(shop_config, "pos");
    array = cjson_get_prop_array_unsafe(shop_config, "items");
    shop->total_items = cjson_array_to_int_array(array, &len);
    shop->total_items_len = len;
    shop->curr_items_len = cjson_get_prop_int_unsafe(shop_config,
    "curr_items_len");
    shop->tile_len = cjson_get_prop_int_unsafe(shop_config, "tile_len");
    shop->direction = cjson_get_prop_int_unsafe(shop_config, "direction");
    shop->id = cjson_get_prop_int_unsafe(shop_config, "id");
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
