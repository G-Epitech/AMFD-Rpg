/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory_move
*/

#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/types.h"

bool app_init_inventory_move(renderer_t *renderer, app_t *app)
{
    (void) renderer;
    app->inventory_move = malloc(sizeof(inventory_move_t));
    if (!app->inventory_move)
        return false;
    app->inventory_move->item_active = false;
    app->inventory_move->pressed = false;
    app->inventory_move->item_pos = 0;
    app->inventory_move->target_pos = 0;
    app->inventory_move->position = (sfVector2f) {0, 0};
    return true;
}
