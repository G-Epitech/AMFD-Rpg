/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include "types/list/list.h"
#include "types/list/types.h"
#include "app/tasks/bash/script_bash.h"
#include "app/tasks/bruteforce/bruteforce.h"

list_t *task_create(void)
{
    list_t *task = list_new();
    node_t *script_bash = task_create_nodes_bash();
    node_t *brute_force = task_create_nodes_brute();

    if (!script_bash)
        return NULL;
    list_append(task, script_bash);
    list_append(task, brute_force);
    return task;
}
