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

/**
 * @brief Handler of task
 * @param renderer Main renderer function
 * @param app Application structure
 * @param states Core or display
*/
int task(renderer_t *renderer, app_t *app, int states);

#endif /* !TASK_H_ */
