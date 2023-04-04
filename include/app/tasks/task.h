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
    #include "app/tasks/script_bash.h"

typedef union s_task_content {
    task_bash_t script;
} task_content_t;

typedef enum e_task_type {
    TSK_BASH
} task_type_t;

typedef struct s_task {
    task_content_t content;
    task_type_t type;
} task_t;


void task(renderer_t *renderer, app_t *app);

#endif /* !TASK_H_ */