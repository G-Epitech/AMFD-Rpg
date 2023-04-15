/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include <stdlib.h>
#include <time.h>
#include "types/list/list.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"

static int init_time(task_t *task)
{
    CAMERA(task).handler_time = malloc(sizeof(timer_handler_t));
    if (CAMERA(task).handler_time == NULL)
        return 84;
    CAMERA(task).handler_time->time_float = 0.0;
    CAMERA(task).handler_time->timer_int = 0;
    return 0;
}

node_t *task_create_nodes_camera(void)
{
    task_t *task = malloc(sizeof(task_t));

    if (!task)
        return NULL;
    task->content.camera.just_started = true;
    task->content.camera.index_equations = 1;
    task->content.camera.nb_lifes = 3;
    if (init_time(task) == 84)
        return NULL;
    return node_new((node_data_t) task);
}
