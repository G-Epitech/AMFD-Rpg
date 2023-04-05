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

void app_task_bash_core(app_t *app)
{
    if (STRUCT_BASH(app).handler_placing->just_started) {
        init_task(app);
    }
    if (STRUCT_BASH(app).handler_time->time_float > 20.0) {
        app->state = ST_INGAME;
        my_putstr("You lose\n");
    }
}
