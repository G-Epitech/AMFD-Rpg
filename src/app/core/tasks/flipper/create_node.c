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
    FLIPPER(flip).handler_time = malloc(sizeof(timer_handler_t));
    if (FLIPPER(flip).handler_time == NULL)
        return 84;
    FLIPPER(flip).handler_time->time_float = 0.0;
    FLIPPER(flip).handler_time->timer_int = 0;
    return 0;
}

node_t *task_create_nodes_flipper(void)
{
    task_t *task = malloc(sizeof(task_t));

    if (!task)
        return NULL;
    srand(time(NULL));
    task->content.flipper.just_started = true;
    task->content.flipper.nb_circles = 60 + rand() % 11;
    task->content.flipper.nb_lifes = 3;
    task->content.flipper.circles = list_new();
    task->content.flipper.nb_circle_create = 0;
    task->content.flipper.nb_circle_hit = 0;
    if (init_time(task) == 84)
        return NULL;
    return node_new((node_data_t) task);
}
