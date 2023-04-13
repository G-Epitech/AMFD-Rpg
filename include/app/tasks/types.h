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
    #include "app/tasks/bruteforce/types.h"
    #include "app/tasks/flipper/types.h"

    #define CLOCK(node) node.handler_time->clock_time
    #define TIME_FLOAT(node) node.handler_time->time_float
    #define TIME_INT(node) node.handler_time->timer_int
    #define TIME(node) node.handler_time->time

typedef union s_task_content {
    task_bash_t script;
    task_brute_t force;
    task_flipper_t flipper;
} task_content_t;

typedef struct s_task {
    task_content_t content;
} task_t;

typedef struct s_timer_handler {
    sfClock *clock_time;
    sfTime time;
    float time_float;
    int timer_int;
} timer_handler_t;

#endif /* !TYPE_TASK_H_ */
