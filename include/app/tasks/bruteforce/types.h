/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** bruteforce
*/

#ifndef TYPE_BRUTEFORCE_H_
    #define TYPE_BRUTEFORCE_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/Clock.h>

    #define NB_CLICK(app) app->tasks_setup->first->next->data.task->content.force.nb_click

typedef struct s_task_brute {
    int nb_click;
} task_brute_t;

#endif /* !TYPE_BRUTEFORCE_H_ */