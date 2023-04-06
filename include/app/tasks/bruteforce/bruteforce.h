/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** brute_force
*/

#ifndef BRUTEFORCE_H_
    #define BRUTEFORCE_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>
    #include "types/list/types.h"

/**
 * @brief Create the node for task brute force
*/
node_t *task_create_nodes_brute(void);

/**
 * @brief Display handler of task brute
 * @param renderer Main renderer function
 * @param app Application structure
*/
void app_task_brute_display(renderer_t *renderer, app_t *app);

#endif /* !BRUTEFORCE_H_ */