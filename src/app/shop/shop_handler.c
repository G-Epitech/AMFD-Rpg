/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Handles player shopping
*/

#include <stdbool.h>
#include "types/list/list.h"
#include "app/shop/shop_handle.h"
#include "app/app.h"
#include "my/include/my.h"

void shop_handler(app_t *app)
{
    if (PLAYER_SHOPING(app->interaction->type)) {
        app->state = ST_SHOP;
        app->interaction->type = IT_NULL;
    }
}
