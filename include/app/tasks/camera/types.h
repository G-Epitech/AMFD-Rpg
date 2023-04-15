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
    #define CAMERA_LIFE(node) node->content.camera.nb_lifes
    #define CAMERA_EQUATIONS(task) task->content.camera.equations
    #define CAMERA_SOLUTION(node) node->content.camera.solution
    #define CAMERA_RESULT(node) node->content.camera.result
    #define LENGHT_MAX_SOLUTION 3

typedef struct s_timer_handler timer_handler_t;
typedef struct s_node node_t;
typedef struct s_list list_t;

typedef struct s_task_camera {
    timer_handler_t *handler_time;
    list_t *equations;
    char *result;
    char *solution;
    int nb_lifes;
    bool just_started;
} task_camera_t;

typedef struct s_task_camera_node {
    char *equation;
    sfVector2f pos;
} task_camera_node_t;

#endif /* !TYPE_CAMERA_H_ */
