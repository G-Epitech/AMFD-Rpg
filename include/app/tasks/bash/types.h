/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** script_bash
*/

#ifndef TYPE_BASH_H_
    #define TYPE_BASH_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>

typedef struct s_node node_t;
typedef struct s_list list_t;

    #define STRUCT_BASH(app) (app->tasks_setup->first->data.task->content.script)
    #define STR_CMD current_cmd->data.node_bash->cmd
    #define STR_CMD_MODEL current_cmd_model->data.node_bash->cmd
    #define INDEX_CMD app->tasks_setup->first->data.task->content.script.handler_placing->index_cmd
    #define INDEX_LIFE app->tasks_setup->first->data.task->content.script.handler_placing->index_life
    #define CLOCK app->tasks_setup->first->data.task->content.script.handler_time->clock_time
    #define TIME_FLOAT app->tasks_setup->first->data.task->content.script.handler_time->time_float
    #define TIME_INT app->tasks_setup->first->data.task->content.script.handler_time->timer_int
    #define LEN_MAX_CMD 27

typedef struct s_timer_handler {
    sfClock *clock_time;
    sfTime time;
    float time_float;
    int timer_int;
} timer_handler_t;

typedef struct s_placing {
    bool just_started;
    int index_cmd;
    int index_life;
} placing_t;

typedef struct s_task_bash {
    list_t *cmd_model;
    list_t *cmd;
    list_t *prompt;
    timer_handler_t *handler_time;
    placing_t *handler_placing;
    sfTexture *phone;
    sfFont *font_phone;
} task_bash_t;

typedef struct s_task_bash_node {
    char *cmd;
    sfVector2f pos;
} task_bash_node_t;

#endif /* !TYPE_BASH_H_ */
