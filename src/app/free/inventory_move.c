/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory_move
*/

#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/types.h"

void app_free_inventory_move(app_t *app)
{
    if (!app->inventory_move)
        return;
    free(app->inventory_move);
}
