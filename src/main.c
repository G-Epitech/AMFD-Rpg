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
    print_shops(app->shops);
    while (sfRenderWindow_isOpen(renderer->window)) {
        if (app_run(renderer, app) == 84)
            return 84;
    }
    renderer_destroy(renderer);
    app_free(app);
    return 0;
}
