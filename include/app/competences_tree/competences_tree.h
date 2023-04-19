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

void display_competences_tree(renderer_t *renderer, app_t *app);

#endif /* !CORE_H_ */