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

task_content_t find_task_node(app_t *app, int id)
{
    node_t *task = app->tasks_setup->first;
    int index = 1;

    while (index != id) {
        task = task->next;
        index++;
    }
    return task->data.task->content;
}
