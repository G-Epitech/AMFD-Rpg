/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** items
*/

#include <stdlib.h>
#include "app/types.h"
#include "app/items/items.h"

bool app_init_items(app_t *app)
{
    app->items = items_load();
    return app->items ? true : false;
}
