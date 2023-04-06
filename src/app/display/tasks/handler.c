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

int tasks_display_handler(renderer_t *renderer, app_t *app)
{
    if (app->state == ST_TASK_BASH) {
        app_task_bash_display(renderer, app);
    }
    return 0;
}
