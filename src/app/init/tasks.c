/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tasks
*/

#include <stdlib.h>
#include "app/types.h"
#include "app/network/network.h"
#include "app/tasks/bash/script_bash.h"

bool app_init_tasks(app_t *app)
{
    app->tasks_setup = task_create();
    return app->tasks_setup ? true : false;
}
