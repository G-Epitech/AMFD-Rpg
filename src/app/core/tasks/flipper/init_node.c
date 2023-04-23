/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** init
*/

#include <stdio.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/flipper/flipper.h"
#include "types/list/types.h"

int init_task_flipper(app_t *app)
{
    task_t *node = find_task_node(app, 3);

    CLOCK(node->content.flipper) = sfClock_create();
    if (CLOCK(node->content.flipper) == NULL)
        return 84;
    FLIPPER_STARTED(node) = false;
    NB_LIFE_FLIPPER(node) = app->player->intellect;
    NB_CIRCLE_FLIPPER(node) = (120 - (app->player->speed) * 10) + rand() % 11;
    return 0;
}
