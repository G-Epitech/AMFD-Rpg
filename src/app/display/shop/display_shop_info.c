/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** display_shop_ui
*/

#include <stdbool.h>
#include "stdlib.h"
#include "types/list/list.h"
#include "app/shop/shop_handle.h"
#include "types/renderer/renderer.h"
#include "app/app.h"
#include "my/include/my.h"

static void shop_center_text_horizontally(sfText *text, sfRenderWindow *window,
float y_axis)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f origin = {0, 0};

    origin.x = rect.width / 2;
    origin.y = rect.height / 2;
    sfText_setOrigin(text, origin);
    sfText_setPosition(text, (sfVector2f) {window_size.x / 2,
    y_axis});
}

static void display_shop_message(renderer_objects_t *objects,
sfRenderWindow *window)
{
    renderer_objects_reset_text(objects);
    sfText_setString(objects->text, "Tu n'as pas assez d'argent");
    sfText_setCharacterSize(objects->text, 20);
    shop_center_text_horizontally(objects->text, window, 850);
    sfRenderWindow_drawText(window, objects->text, NULL);
}

void display_shop_info(shop_t *shop, renderer_objects_t *objects,
sfRenderWindow *window, int player_gold)
{
    renderer_objects_reset_text(objects);
    sfText_setString(objects->text, shop->name);
    sfText_setCharacterSize(objects->text, 50);
    shop_center_text_horizontally(objects->text, window, 300);
    sfRenderWindow_drawText(window, objects->text, NULL);
    renderer_objects_reset_text(objects);
    sfText_setString(objects->text, nbr_to_str(player_gold));
    sfText_setCharacterSize(objects->text, 50);
    sfText_setPosition(objects->text, SHOP_PLAYER_GOLD_VALUE_POS);
    sfRenderWindow_drawText(window, objects->text, NULL);
    if (shop->stock->active == false)
        display_shop_message(objects, window);
}
