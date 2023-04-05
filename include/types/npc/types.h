/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** types
*/

#ifndef NPC_TYPES_H_
    #define NPC_TYPES_H_

    #include <SFML/Graphics.h>

typedef struct s_list list_t;

typedef struct s_npc_dialog {
    char *label;
    char *content;
} npc_dialog_t;

typedef struct s_npc_data {
    int world;
    int skin;
    sfVector2f position;
    list_t *dialogs;
} npc_data_t;

typedef struct s_npc {
    char *name;
    int id;
    list_t *worlds_data;
} npc_t;

#endif /* !NPC_TYPES_H_ */
