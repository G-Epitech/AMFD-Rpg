/*
** EPITECH PROJECT, 2023
** RPG [WSL: Ubuntu]
** File description:
** display_shop_ui
*/

#include <stdbool.h>
#include "types/list/list.h"
#include "app/shop/shop_handle.h"
#include "types/renderer/renderer.h"
#include "app/app.h"
#include "my/include/my.h"

void display_shop_info(shop_t *shop, renderer_objects_t *objects,
sfRenderWindow *window, int player_gold)
{
    renderer_objects_reset_text(objects);
    sfText_setString(objects->text, shop->name);
    sfText_setCharacterSize(objects->text, 50);
    sfText_setPosition(objects->text, SHOP_NAME_POS);
    sfRenderWindow_drawText(window, objects->text, NULL);
    renderer_objects_reset_text(objects);
    sfText_setString(objects->text, nbr_to_str(player_gold));
    sfText_setCharacterSize(objects->text, 50);
    sfText_setPosition(objects->text, SHOP_PLAYER_GOLD_VALUE_POS);
    sfRenderWindow_drawText(window, objects->text, NULL);
}
