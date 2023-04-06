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
#include "app/tasks/types.h"

static int task_bash(renderer_t *renderer, app_t *app, int states)
{
    if (states == display) {
        app_task_bash_display(renderer, app);
    }
    if (states == core) {
        if (app_task_bash_core(app) == 84)
            return 84;
    }
    return 0;
}

int task(renderer_t *renderer, app_t *app, int states)
{
    if (app->state == ST_TASK_BASH) {
        if (task_bash(renderer, app, states) == 84)
            return 84;
    }
    return 0;
}
