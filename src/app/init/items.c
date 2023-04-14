/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** items
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/renderer/types.h"
#include "app/items/items.h"

bool app_init_items(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->items = items_load();
    return app->items ? true : false;
}
