/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** bruteforce
*/

#ifndef TYPE_BRUTEFORCE_H_
    #define TYPE_BRUTEFORCE_H_

    #include <SFML/Graphics.h>
    #include <SFML/System/Clock.h>

    #define NB_CLICK(app) app->tasks_setup->first->next->data.\
    task->content.force.nb_click
    #define SIZE_TEXT(app) app->tasks_setup->first->next->data.\
    task->content.force.size_text
    #define JUST_STARTED(app) app->tasks_setup->first->next->data.\
    task->content.force.just_started
    #define OBJECTIF(app) app->tasks_setup->first->next->data.\
    task->content.force.objectif
    #define BRUTE(brute_force) brute_force.task->content.force

typedef struct s_timer_handler timer_handler_t;

typedef struct s_task_brute {
    timer_handler_t *handler_time;
    int nb_click;
    int size_text;
    int objectif;
    bool just_started;
} task_brute_t;

#endif /* !TYPE_BRUTEFORCE_H_ */
