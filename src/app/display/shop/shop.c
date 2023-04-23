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

void display_shop(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    if (app->state != ST_SHOP)
        return;
    display_shop_interface(app->shops, app->interaction->data.shop_id,
    renderer);
}
