/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** camera
*/

#ifndef TYPE_CAMERA_H_
    #define TYPE_CAMERA_H_

    #include <SFML/Graphics.h>
    #include <SFML/System/Clock.h>
    #include <stdbool.h>

    #define CAMERA(task) task->content.camera
    #define CAMERA_STARTED(node) node->content.camera.just_started
    #define INDEX_EQUATIONS(node) node->content.camera.index_equations
    #define CAMERA_LIFE(node) node->content.camera.nb_lifes

typedef struct s_timer_handler timer_handler_t;
typedef struct s_node node_t;
typedef struct s_list list_t;

typedef struct s_task_camera {
    timer_handler_t *handler_time;
    int index_equations;
    int nb_lifes;
    bool just_started;
} task_camera_t;

#endif /* !TYPE_CAMERA_H_ */