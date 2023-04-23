/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bruteforce/bruteforce.h"
#include "app/tasks/bruteforce/types.h"
#include "types/list/types.h"

int init_task_brute(app_t *app)
{
    task_t *brute = find_task_node(app, 2);

    CLOCK(brute->content.force) = sfClock_create();
    if (CLOCK(brute->content.force) == NULL)
        return 84;
    JUST_STARTED(app) = false;
    OBJECTIF(app) = 90 - (app->player->speed * 10);
    return 0;
}
