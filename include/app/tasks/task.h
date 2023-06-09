/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** task.h
*/

#ifndef TASK_H_
    #define TASK_H_

    #include "app/types.h"
    #include "types/renderer/types.h"
    #include "app/tasks/types.h"
    #include "app/items/types.h"

/**
 * @brief Handler of display task
 * @param renderer Main renderer function
 * @param app Application structure
*/
int display_tasks_handler(renderer_t *renderer, app_t *app);

/**
 * @brief Handler of core task
 * @param app Application structure
*/
int core_tasks_handler(app_t *app, renderer_t *renderer);

/**
 * @brief Handler of core task
 * @param app Application structure
 * @param id Id of node
*/
task_t *find_task_node(app_t *app, int id);

/**
 * @brief Use a bash script
 * @param app App object
 * @param item Item object
 */
void tasks_bash_use(app_t *app, item_t *item);

#endif /* !TASK_H_ */
