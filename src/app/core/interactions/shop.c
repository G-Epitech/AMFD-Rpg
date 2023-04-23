/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Shop interactions
*/

#include "app/app.h"
#include "app/core/core.h"

void core_interactions_shop(sfColor pixel, app_t *app)
{
    if (core_interaction_detect_color(pixel, SHOP_COLOR)) {
        app->interaction->interaction = true;
        app->interaction->active = false;
        app->interaction->type = IT_SHOP;
        app->interaction->data.shop_id = 255 - pixel.a;
    }
}
