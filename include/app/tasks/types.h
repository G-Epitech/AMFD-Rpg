/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** task.h
*/

#ifndef TYPE_TASK_H_
    #define TYPE_TASK_H_

    #include "app/types.h"
    #include "types/renderer/types.h"
    #include "app/tasks/bash/types.h"

typedef union s_task_content {
    task_bash_t script;
} task_content_t;

typedef struct s_task {
    task_content_t content;
} task_t;

#endif /* !TYPE_TASK_H_ */