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
#include "app/tasks/bash/script_bash.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void time_handler(app_t *app)
{
    task_content_t bash = find_task_node(app, 1);

    TIME(bash.script) = sfClock_getElapsedTime(CLOCK(bash.script));
    TIME_FLOAT(bash.script) = TIME(bash.script).microseconds / (1000000.0);
}

int app_task_bash_core(app_t *app)
{
    if (STRUCT_BASH(app).handler_placing->just_started) {
        if (init_task_bash(app) == 84)
            return 84;
    }
    time_handler(app);
    if (STRUCT_BASH(app).handler_time->time_float > 20.0) {
        app->state = ST_INGAME;
        my_putstr("You lose\n");
        reset_setup_bash(app);
    }
    return 0;
}
