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
 * @brief Handler of display task
 * @param renderer Main renderer function
 * @param app Application structure
*/
int tasks_display_handler(renderer_t *renderer, app_t *app);

/**
 * @brief Handler of core task
 * @param renderer Main renderer function
 * @param app Application structure
*/
int tasks_core_handler(renderer_t *renderer, app_t *app);

#endif /* !TASK_H_ */
