/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void display_inventory(renderer_t *renderer, app_t *app)
{
    if (app->state != ST_INVENTORY)
        return;
    display_inventory_profile(renderer, app);
    display_inventory_grids(renderer, app);
    display_inventory_levels(renderer, app);
}
