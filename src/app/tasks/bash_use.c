/*
** EPITECH PROJECT, 2023
** bash_use.c
** File description:
** Use the bash task
*/

#include <stdio.h>
#include "app/types.h"
#include "app/items/items.h"

void tasks_bash_use(app_t *app, item_t *item)
{
    if (app->interaction->interaction &&
    app->interaction->type == IT_NPC && !app->interaction->active) {
        app->state = ST_TASK_BASH;
        app->interaction->active = true;
    }
    inventory_add_item(app->player, item);
}
