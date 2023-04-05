/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** script_bash
*/

#ifndef SCRIPT_BASH_H_
    #define SCRIPT_BASH_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>
    #include "types/list/types.h"

node_t *task_create_nodes_bash(void);

list_t *task_create(void);

void app_task_bash_display(renderer_t *renderer, app_t *app);

void init_task(app_t *app);

#endif /* !SCRIPT_BASH_H_ */
