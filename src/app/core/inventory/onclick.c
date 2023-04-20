/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** onclick
*/

#include "app/types.h"
#include "my/include/my.h"
#include "types/list/types.h"
#include "app/inventory/types.h"
#include "app/display/display.h"

static void inventory_onclick_item_non_active(app_t *app,
inventory_item_t *item)
{
    if (item->target->type == IVT_CONSUMABLE)
        return inventory_onclick_item_consumable(app, item);
    else
        return inventory_onclick_item_equipement(app, item);
}

void inventory_onclick(app_t *app)
{
    inventory_event_t *event = app->inventory_event;

    if (!event->selected)
        return;
    if (event->selected->active)
        return inventory_onclick_item_active(app, event->selected);
    return inventory_onclick_item_non_active(app, event->selected);
}
