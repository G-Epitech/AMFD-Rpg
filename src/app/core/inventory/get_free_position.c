/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tmp_move
*/

#include <stdio.h>
#include "app/types.h"
#include "app/display/display.h"
#include "app/inventory/types.h"

static int get_x(int i, int real)
{
    int col_real = real / INVENTORY_MAIN_GRID_SIZE.y;
    int x = real + i;
    int col_new = x / INVENTORY_MAIN_GRID_SIZE.y;

    return (col_real != col_new || x <= 0) ? -1 : x;
}

static int get_y(int i, int real)
{
    int y = real + (INVENTORY_MAIN_GRID_SIZE.x * i) - 1;
    int line = y / INVENTORY_MAIN_GRID_SIZE.x;

    return line < 0 || line >= INVENTORY_MAIN_GRID_SIZE.x ? -1 : y;
}

static bool check_positions_x(int i, list_t *inventory,
inventory_event_t *event)
{
    int x_l = get_x(-i, event->target.pos);
    int x_r = get_x(i, event->target.pos);
    inventory_item_t *i_l = inventory_get_item_at_pos(inventory, x_l, true);
    inventory_item_t *i_r = inventory_get_item_at_pos(inventory, x_r, true);

    if (!i_l && x_l > 0) {
        event->target_ref_tmp.pos = x_l;
    } else if (!i_r && x_r > 0) {
        event->target_ref_tmp.pos = x_r;
    }
    return (!i_l && x_l > 0) || (!i_r && x_r > 0) ? true : false;
}

static bool check_positions_y(int i, list_t *inventory,
inventory_event_t *event)
{
    int y_t = get_y(-i, event->target.pos);
    int y_b = get_y(i, event->target.pos);
    inventory_item_t *i_t = inventory_get_item_at_pos(inventory, y_t, true);
    inventory_item_t *i_b = inventory_get_item_at_pos(inventory, y_b, true);

    if (!i_t)
        event->target_ref_tmp.pos = y_t;
    else if (!i_b)
        event->target_ref_tmp.pos = y_b;
    return !i_t || !i_b ? true : false;
}

bool inventory_onmove_get_free_positions(int i, list_t *inventory,
inventory_event_t *event)
{
    if (check_positions_x(i, inventory, event))
        return true;
    if (check_positions_y(i, inventory, event))
        return true;
    return false;
}
