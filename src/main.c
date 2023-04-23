/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** @Hackers Quest 💻
** Main file
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "my/include/my.h"
#include "app/core/core.h"
#include "types/list/types.h"
#include "app/events/events.h"
#include "app/display/display.h"
#include "app/sound/sound_control.h"
#include "types/renderer/renderer.h"
#include "types/components/components.h"
#include "types/ressources/ressources.h"

void print_shops(list_t *shops)
{
    node_t *node = shops->first;
    shop_t *shop = NULL;

    while (node) {
        shop = node->data.shop;
        printf("%s is in world %d has id%d, at x:%.0f y:%.0f has %ld items and a max of"
        "%ld curr items direction %d and tile len of %d\n", shop->name, shop->world, shop->id,
        shop->pos.x, shop->pos.y,
        shop->stock->total_items_len, shop->stock->curr_items_len, shop->direction,
        shop->tile_len);
        node = node->next;
    }
}

void print_shop_stock_items(list_t *shops)
{
    node_t *node = shops->first;
    shop_t *shop = NULL;

    while (node) {
        shop = node->data.shop;
            printf("Loading items for shop %s\n", shop->name);
        for (size_t i = 0; i < shop->stock->curr_items_len; i++) {
            printf("Item %ld has id %d, label %s, price %d, type %d, consumer %d, life %d, speed %d, xp %d\n"
            "rect top %d, left %d, width %d, height %d\n",
            i, shop->stock->curr_items[i].id, shop->stock->curr_items[i].label,
            shop->stock->curr_items[i].price, shop->stock->curr_items[i].type,
            shop->stock->curr_items[i].consumer, shop->stock->curr_items[i].life,
            shop->stock->curr_items[i].speed, shop->stock->curr_items[i].xp,
            shop->stock->curr_items[i].rect.top, shop->stock->curr_items[i].rect.left,
            shop->stock->curr_items[i].rect.width, shop->stock->curr_items[i].rect.height);
        }
        node = node->next;
    }
}

int main(void)
{
    renderer_t *renderer = renderer_init();
    app_t *app = NULL;

    load_renderer(renderer);
    app = app_init(renderer);
    if (!renderer)
        return 84;
    if (!app) {
        renderer_destroy(renderer);
        return 84;
    }
    my_put_nbr(app->items->len);
    print_shops(app->shops);
    print_shop_stock_items(app->shops);
    while (sfRenderWindow_isOpen(renderer->window)) {
        if (app_run(renderer, app) == 84)
            return 84;
    }
    renderer_destroy(renderer);
    app_free(app);
    return 0;
}
