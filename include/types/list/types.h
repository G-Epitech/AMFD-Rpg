/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

    #include <stdbool.h>
    #include "types/players/types.h"
    #include "types/components/types.h"
    #include "types/ressources/types.h"
    #include "app/tasks/bash/types.h"
    #include "app/tasks/types.h"

typedef struct s_list list_t;

typedef union u_node_data {
    player_t *player;
    button_t *button;
    lever_t *lever;
    skin_t *skin;
    list_t *list;
    map_t *map;
    task_t *task;
    task_bash_node_t *node_bash;
} node_data_t;

typedef struct s_node {
    struct s_node *prev;
    struct s_node *next;
    node_data_t data;
} node_t;

typedef struct s_list {
    node_t *first;
    node_t *last;
    int len;
} list_t;

#endif /* !TYPES_H_ */
