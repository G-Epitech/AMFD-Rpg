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
    int line_real = real / INVENTORY_MAIN_GRID_SIZE.x;
    int x = real + i;
    int line_new = x / INVENTORY_MAIN_GRID_SIZE.x;

    return (line_real != line_new || x <= 0) ? -1 : x;
}

static int get_y(int i, int real)
{
    int y = real + (INVENTORY_MAIN_GRID_SIZE.x * i);
    int line = y / INVENTORY_MAIN_GRID_SIZE.x;

    return line < 0 || line >= INVENTORY_MAIN_GRID_SIZE.x ? -1 : y;
}

static bool check_positions_x(int i, list_t *inventory,
inventory_event_t *event)
{
    int x_l = get_x(-i, event->target.pos);
    int x_r = get_x(i, event->target.pos);
    inventory_item_t *i_l = inventory_get_item_at_pos(inventory, x_l, false);
    inventory_item_t *i_r = inventory_get_item_at_pos(inventory, x_r, false);
    bool valid = false;

    if (!i_l && x_l > 0 && x_l <= INVENTORY_MAX) {
        event->target_ref_tmp.pos = x_l;
        valid = true;
    } else if (!i_r && x_r > 0 && x_r <= INVENTORY_MAX) {
        event->target_ref_tmp.pos = x_r;
        valid = true;
    }
    return valid;
}

static bool check_positions_y(int i, list_t *inventory,
inventory_event_t *event)
{
    int y_t = get_y(-i, event->target.pos);
    int y_b = get_y(i, event->target.pos);
    inventory_item_t *i_t = inventory_get_item_at_pos(inventory, y_t, false);
    inventory_item_t *i_b = inventory_get_item_at_pos(inventory, y_b, false);
    bool valid = false;

    if (!i_t && y_t > 0 && y_t <= INVENTORY_MAX) {
        event->target_ref_tmp.pos = y_t;
        valid = true;
    } else if (!i_b && y_b > 0 && y_b <= INVENTORY_MAX) {
        event->target_ref_tmp.pos = y_b;
        valid = true;
    }
    return valid;
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
