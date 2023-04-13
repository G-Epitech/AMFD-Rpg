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
int app_task_flipper_core(app_t *app);

/**
 * @brief Reset setup of flipper struct when its finish
 * @param app Application structure
*/
void reset_setup_flipper(app_t *app, int *pres_sec, int *pres_mili_sec);

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
*/
int handler_create_circle(int time_int, app_t *app, int pres_mili_int, int time_mili_int);

void life_loose(app_t *app, int time_int);

void open_circle(app_t *app, int time_int);

void circle_expension(app_t *app);

void event_task_flipper(renderer_t *renderer, app_t *app);

#endif /* !FLIPPER_H_ */
