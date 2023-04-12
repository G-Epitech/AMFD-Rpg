/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"

static int init_time(node_data_t brute_force)
{
    BRUTE(brute_force).handler_time = malloc(sizeof(timer_handler_t));
    if (BRUTE(brute_force).handler_time == NULL)
        return 84;
    BRUTE(brute_force).handler_time->time_float = 0.0;
    BRUTE(brute_force).handler_time->timer_int = 20;
    return 0;
}

node_t *task_create_nodes_brute(void)
{
    node_data_t brute_force;
    task_t *task = malloc(sizeof(task_t));

    if (!task)
        return NULL;
    brute_force.task = task;
    brute_force.task->content.force.nb_click = 0;
    brute_force.task->content.force.size_text = 50;
    brute_force.task->content.force.objectif = 60;
    brute_force.task->content.force.just_started = true;
    if (init_time(brute_force) == 84)
        return NULL;
    return node_new(brute_force);
}
