/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** script_bash
*/

#ifndef SCRIPT_BASH_H_
    #define SCRIPT_BASH_H

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>
    #include "types/list/types.h"

    #define STRUCT_BASH(app) (app->tasks_setup->first->data.task->content.script)

typedef struct s_timer {
    sfClock *clock_time;
    sfTime time;
    float time_float;
    int timer_int;
} timer_t;

typedef struct s_placing {
    bool *just_started;
    int index_cmd;
    int index_life;
} placing_t;

typedef struct s_task_bash {
    list_t *cmd_model;
    list_t *cmd;
    list_t *prompt;
    timer_t *handler_time;
    placing_t *handler_placing;
} task_bash_t;

typedef struct s_task_bash_node {
    char *cmd;
    sfVector2f pos;
} task_bash_node_t;

node_t *task_create_nodes_bash(list_t *task_bash);

list_t *task_create(void);

void app_task_bash_display(renderer_t *renderer, app_t *app);

static init_task(app_t *app);

#endif /* !SCRIPT_BASH_H */
