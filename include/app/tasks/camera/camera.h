/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** camera
*/

#ifndef CAMERA_H_
    #define CAMERA_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>
    #include "app/types.h"
    #include "app/tasks/camera/types.h"


typedef struct s_renderer renderer_t;
typedef struct s_node node_t;
typedef struct s_button button_t;

/**
 * @brief Create the node for task camera (find digit code)
*/
node_t *task_create_nodes_camera(void);

/**
 * @brief Init task camera when first entrance
 * @param app Application structure
*/
int init_task_camera(app_t *app);

/**
 * @brief Reset setup of camera struct when its finish
 * @param app Application structure
*/
void reset_setup_camera(app_t *app);

/**
 * @brief Core handler of task camera
 * @param app Application structure
*/
int app_task_camera_core(app_t *app);

/**
 * @brief Display handler of task camera
 * @param renderer Main renderer function
 * @param app Application structure
*/
void app_task_camera_display(renderer_t *renderer, app_t *app);

void display_solution(renderer_t *renderer, app_t *app);

#endif /* !CAMERA_H_ */