/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include "types/list/list.h"
#include "types/list/types.h"
#include "app/tasks/script_bash.h"

list_t *task_create(void)
{
    list_t *task = list_new();
    node_t *script_bash = task_create_nodes_bash(task);

    list_append(task, script_bash);
    return task;
}
