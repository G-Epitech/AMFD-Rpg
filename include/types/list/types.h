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

typedef struct s_list list_t;

typedef union u_node_data {
    list_t *list;
    player_t *player;
} node_data_t;

typedef struct s_node {
    struct s_node *prev;
    node_data_t data;
    struct s_node *next;
} node_t;

typedef struct s_list {
    node_t *first;
    node_t *last;
    int len;
} list_t;

#endif /* !TYPES_H_ */
