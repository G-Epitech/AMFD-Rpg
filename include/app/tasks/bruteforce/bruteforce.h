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
    #include "app/types.h"


typedef struct s_renderer renderer_t;
typedef struct s_node node_t;
typedef struct s_button button_t;

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

/**
 * @brief Core handler of task brute
 * @param app Application structure
*/
int app_task_brute_core(app_t *app);

/**
 * @brief Reset setup of brute_force struct when its finish
 * @param app Application structure
*/
void reset_setup_brute(app_t *app);

/**
 * @brief Init task brute when first entrance
 * @param app Application structure
*/
int init_task_brute(app_t *app);

/**
 * @brief Handle when mouse was released
 * @param renderer Main renderer function
 * @param app Application structure
*/
int brute_force_released(renderer_t *renderer, app_t *app);

#endif /* !BRUTEFORCE_H_ */
