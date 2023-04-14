/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** flipper types
*/

#ifndef TYPE_FLIPPER_H_
    #define TYPE_FLIPPER_H_

    #include <SFML/Graphics.h>
    #include <SFML/System/Clock.h>
    #include <stdbool.h>

    #define FLIPPER(flip) flip.task->content.flipper
    #define FLIPPER_STARTED(node) node->content.flipper.just_started
    #define NB_LIFE_FLIPPER(node) node->content.flipper.nb_lifes
    #define NB_CIRCLE_FLIPPER(node) node->content.flipper.nb_circles
    #define NB_CIRCLE_CREATE(node) node->content.flipper.nb_circle_create
    #define LIST_CIRCLE(node) node->content.flipper.circles
    #define NB_CIRCLE_HIT(node) node->content.flipper.nb_circle_hit
    #define OPEN 1
    #define CLOSE 0
    #define STATUS_CIRCLE(temp_circle) temp_circle->data.node_flip->status
    #define RAYON_CIRCLE(temp_circle) temp_circle->data.node_flip->rayon
    #define POS_CIRCLE(temp_circle) temp_circle->data.node_flip->pos
    #define TIME_CREATION(temp_circle) temp_circle->\
    data.node_flip->time_creation
    #define TIME_OPEN(temp_circle) temp_circle->data.node_flip->time_open
    #define COLOR_GRENN sfColor_fromRGB(45, 162, 51)
    #define COLOR_RED sfColor_fromRGB(203, 42, 42)

typedef struct s_timer_handler timer_handler_t;
typedef struct s_node node_t;
typedef struct s_list list_t;

typedef struct s_task_flipper {
    timer_handler_t *handler_time;
    list_t *circles;
    int nb_circles;
    int nb_circle_create;
    int nb_circle_hit;
    int nb_lifes;
    bool just_started;
} task_flipper_t;

typedef struct s_task_flipper_node {
    sfVector2f pos;
    float rayon;
    int status;
    int time_open;
    int time_creation;
} task_flipper_node_t;

#endif /* !TYPE_FLIPPER_H_ */
