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

typedef struct s_task_bash {
    list_t *cmd_model;
    list_t *cmd;
    list_t *prompt;
} task_bash_t;

typedef struct s_task_bash_node {
    char *cmd;
    sfVector2f pos;
} task_bash_node_t;

node_t *task_create_nodes_bash(list_t *task_bash);

list_t *task_create(void);

#endif /* !SCRIPT_BASH_H */
