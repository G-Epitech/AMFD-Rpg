/*
** EPITECH PROJECT, 2023
** core.h
** File description:
** Core functions
*/

#ifndef CORE_H_
    #define CORE_H_

    #include "app/competences_tree/types.h"

typedef struct s_list list_t;
typedef struct s_renderer renderer_t;
typedef struct s_app app_t;

list_t *player_init_competence(void);

void competences_tree(renderer_t *renderer, app_t *app);

void display_competences_tree(renderer_t *renderer, app_t *app);

void event_handler_skills_tree(app_t *app, renderer_t *renderer);

competences_node_t *find_skill(app_t *app, int id);

#endif /* !CORE_H_ */