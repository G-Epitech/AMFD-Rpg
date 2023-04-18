/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** released
*/

#include "app/types.h"
#include "my/include/my.h"
#include "app/display/display.h"
#include "app/inventory/types.h"


void inventory_onrelease(app_t *app, sfEvent event)
{
    (void) event;
    if (!app->inventory_event->pressed)
        return;
    if (!app->inventory_event->moved) {
        my_putstr("Just clic\n");
    } else {
        inventory_swap_items_on_event(app->player, app->inventory_event);
    }
    app->inventory_event->pressed = false;
    app->inventory_event->moved = false;
}
