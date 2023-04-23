/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** flipper
*/

#ifndef FLIPPER_H_
    #define FLIPPER_H_

    #include "app/tasks/flipper/types.h"
    #include "app/types.h"


typedef struct s_renderer renderer_t;
typedef struct s_node node_t;
typedef struct s_button button_t;

/**
 * @brief Create the node for task flipper (hit circle)
*/
node_t *task_create_nodes_flipper(void);

/**
 * @brief Core handler of task flipper
 * @param app Application structure
*/
int app_task_flipper_core(app_t *app, renderer_t *renderer);

/**
 * @brief Reset setup of flipper struct when its finish
 * @param app Application structure
 * @param prev_sec Previous sec when entered in function
 * @param prev_mili_sec Previous mili second when entered in function
*/
void reset_setup_flipper(app_t *app, int *prev_sec, int *prev_mili_sec);

/**
 * @brief Init task flipper when first entrance
 * @param app Application structure
*/
int init_task_flipper(app_t *app);

/**
 * @brief Display handler of task flipper
 * @param renderer Main renderer function
 * @param app Application structure
*/
void app_task_flipper_display(renderer_t *renderer, app_t *app);

/**
 * @brief Handler of creation of circle
 * @param app Application structure
 * @param time_mili_int Time in millisecond
 * @param time_int Time in second
 * @param prev_mili_sec Previous mili second when entered in function
*/
int handler_create_circle(int time_int, app_t *app,
int pres_mili_int, int time_mili_int);

/**
 * @brief Handler of time when life is going to loose
 * @param app Application structure
 * @param time_int Time in second
*/
void life_loose(app_t *app, int time_int);

/**
 * @brief Handler of time when a circle going to be open
 * @param app Application structure
 * @param time_int Time in second
*/
void open_circle(app_t *app, int time_int);

/**
 * @brief Handler of time when a circle going to be expend (radius)
 * @param app Application structure
*/
void circle_expension(app_t *app);

/**
 * @brief Handler of event about task flipper
 * @param renderer Main renderer function
 * @param app Application structure
*/
void event_task_flipper(renderer_t *renderer, app_t *app);

#endif /* !FLIPPER_H_ */
