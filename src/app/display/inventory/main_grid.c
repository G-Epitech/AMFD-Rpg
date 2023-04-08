/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main_grid
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "app/inventory/inventory.h"
#include "types/ressources/ressources.h"

static void get_position(size_t i, sfVector2f *position)
{
    int line = i / INVENTORY_MAIN_GRID_SIZE.x;
    int col = i - (INVENTORY_MAIN_GRID_SIZE.x * line);

    position->x = INVENTORY_ACTIVE_GRID_POS.x;
    position->x += INVENTORY_ACTIVE_GRID_MARGIN.x * (col - 1);
    position->y = INVENTORY_ACTIVE_GRID_POS.y;
    position->y += INVENTORY_ACTIVE_GRID_MARGIN.y * line;
}

static void display_item(renderer_t *renderer, size_t i)
{
    sfVector2f position = {0, 0};

    get_position(i, &position);
}

void display_inventory_main_grid(renderer_t *renderer, app_t *app)
{
}
