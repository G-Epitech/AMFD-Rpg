/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "types/renderer/types.h"
#include "app/tasks/bash/script_bash.h"
#include "app/tasks/bruteforce/bruteforce.h"
#include "app/tasks/types.h"

int core_tasks_handler(app_t *app)
{
    if (app->state == ST_TASK_BASH) {
        if (app_task_bash_core(app) == 84)
            return 84;
    }
    if (app->state == ST_TASK_BRUTEFORCE) {
        if (app_task_brute_core(app) == 84)
                return 84;
    }
    return 0;
}
