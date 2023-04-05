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

void task(renderer_t *renderer, app_t *app, int states)
{
    if (app->state == ST_TASK_BASH) {
        fflush(stdout);
        if (states == display)
            app_task_bash_display(renderer, app);
        if (states == core)
            app_task_bash_core(app);
    }
}
