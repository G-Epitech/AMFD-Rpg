/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tasks
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/renderer/types.h"
#include "app/tasks/bash/script_bash.h"

bool app_init_tasks(app_t *app, renderer_t *renderer)
{
    (void) renderer;
    app->tasks_setup = task_create();
    return app->tasks_setup ? true : false;
}
