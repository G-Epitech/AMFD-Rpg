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

node_t *task_create_nodes_brute(void)
{
    node_data_t brute_force;
    task_t *task = malloc(sizeof(task_t));

    if (!task)
        return NULL;
    brute_force.task = task;
    brute_force.task->content.force.nb_click = 0;
    return node_new(brute_force);
}
