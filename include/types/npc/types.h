/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef NPC_TYPES_H_
    #define NPC_TYPES_H_

    #include <stdbool.h>
    #include <SFML/Graphics.h>

typedef struct s_list list_t;
typedef struct s_npc npc_t;

typedef struct s_npc_dialog {
    char *label;
    char *content;
} npc_dialog_t;

typedef struct s_npc_enemy {
    int life;
    int level;
    int *attacks;
    size_t nb_attacks;
} npc_enemy_t;

typedef struct s_npc_data {
    int world;
    int skin_id;
    int orientation;
    sfVector2f position;
    list_t *dialogs;
    npc_enemy_t *enemy;
    npc_t *npc;
} npc_data_t;

typedef struct s_npc {
    char *name;
    int id;
    list_t *worlds_data;
} npc_t;

#endif /* !NPC_TYPES_H_ */
