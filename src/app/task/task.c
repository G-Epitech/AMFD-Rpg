/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/bash/script_bash.h"

void task(renderer_t *renderer, app_t *app)
{
    if (app->state == ST_TASK_BASH) {
        app_task_bash_display(renderer, app);
    }
}