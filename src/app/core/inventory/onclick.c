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

void inventory_onclick(app_t *app)
{
    inventory_event_t *event = app->inventory_event;

    if (!event->selected)
        return;
    if (event->selected->active)
        my_putstr("Remove item from active items\n");
    else
        my_putstr("Remove item from inventory\n");
}
