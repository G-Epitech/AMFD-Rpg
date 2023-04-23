/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Include shops on collision layer
*/

#include <stdio.h>
#include "app/types.h"
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void insert_shop(shop_t *shop, sfImage *collision)
{
    float x_offset = 16;
    float y_offset = 16;
    sfColor color = sfRed;

    my_putchar('d');
    if (shop->direction == 1)
        y_offset = shop->tile_len * 16;
    if (shop->direction == 2)
        x_offset = shop->tile_len * 16;
    color.a = (sfUint8) (255 - shop->id);
    for (size_t y = 0; y < y_offset; y++) {
        for (size_t x = 0; x < x_offset; x++) {
            sfImage_setPixel(collision,
            x + shop->pos.x,
            y + shop->pos.y,
            color);
        }
    }
}

static map_t *get_map_by_id(renderer_t *renderer, worlds_t id)
{
    list_t *maps = renderer->ressources->maps;
    node_t *node = maps->first;
    map_t *map;

    while (node) {
        map = node->data.map;
        if (map->world == id) {
            return map;
        }
        node = node->next;
    }
    return NULL;
}

static void include_data(shop_t *shop, renderer_t *renderer)
{
    printf("Shold world %d\n", shop->world);
    map_t *map = get_map_by_id(renderer, shop->world);

    if (!map)
        return;
    if (shop->direction != 1 && shop->direction != 2)
        return;
    insert_shop(shop, map->collision);
}

void shop_include_to_array(renderer_t *renderer, list_t *shops)
{
    node_t *node = shops->first;
    shop_t *shop = NULL;

    if (!node)
        return;
    while (node) {
        shop = node->data.shop;
        include_data(shop, renderer);
        node = node->next;
    }
}
