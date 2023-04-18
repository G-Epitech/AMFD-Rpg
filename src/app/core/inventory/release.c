/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** released
*/

#include "app/types.h"
#include "my/include/my.h"
#include "app/inventory/types.h"

void inventory_onrelease(app_t *app, sfEvent event)
{
    (void) event;
    if (!app->inventory_event->pressed)
        return;
    if (!app->inventory_event->moved) {
        my_putstr("Just clic\n");
    } else {
        my_putstr("Moved item\n");
    }
    app->inventory_event->pressed = false;
    app->inventory_event->moved = false;
}
