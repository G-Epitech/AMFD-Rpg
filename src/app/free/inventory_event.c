/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory_move
*/

#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/types.h"

void app_free_inventory_event(app_t *app)
{
    if (!app->inventory_event)
        return;
    free(app->inventory_event);
}
