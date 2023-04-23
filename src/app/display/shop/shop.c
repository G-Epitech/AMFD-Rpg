/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Displays shop interface
*/

#include <stdbool.h>
#include "types/list/list.h"
#include "app/shop/shop_handle.h"
#include "types/renderer/renderer.h"
#include "app/app.h"
#include "my/include/my.h"

static void display_shop_interface(list_t *shops, int curr_shop_id,
int player_gold, renderer_t *renderer)
{
    node_t *node = shops->first;
    shop_t *shop = NULL;

    while (node) {
        shop = node->data.shop;
        if (curr_shop_id == shop->id) {
            display_shop_item_stock(shop, renderer->window,
            renderer->objects, renderer->ressources->items);
            display_shop_info(shop, renderer->objects, renderer->window,
            player_gold);
        }
        node = node->next;
    }
}

void display_shop(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    if (app->state != ST_SHOP)
        return;
    display_shop_interface(app->shops, app->interaction->data.shop_id,
    app->player->gold, renderer);
}
