/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

    #include <stdbool.h>
    #include "app/tasks/types.h"
    #include "types/npc/types.h"
    #include "app/sound/types.h"
    #include "app/items/types.h"
    #include "types/players/types.h"
    #include "app/tasks/bash/types.h"
    #include "types/components/types.h"
    #include "types/ressources/types.h"
    #include "app/tasks/bash/types.h"
    #include "app/tasks/flipper/types.h"
    #include "app/competences_tree/types.h"
    #include "app/tasks/types.h"
    #include "app/quests/types.h"
    #include "app/animate_player/type.h"

typedef struct s_list list_t;

typedef union u_node_data {
    animation_event_t *animations_event;
    inventory_item_t *inventory_item;
    task_camera_node_t *node_camera;
    task_flipper_node_t *node_flip;
    competences_node_t *competence;
    task_bash_node_t *node_bash;
    background_t *background;
    npc_dialog_t npc_dialog;
    animation_t *animation;
    sound_theme_t *theme;
    progress_t *progress;
    npc_data_t npc_data;
    attack_t *attack;
    quests_t *quests;
    player_t *player;
    button_t *button;
    quest_t *quest;
    sound_t *sound;
    lever_t *lever;
    entry_t *entry;
    shop_t *shop;
    item_t *item;
    task_t *task;
    list_t *list;
    skin_t skin;
    map_t *map;
    anim_t *anim;
    npc_t npc;
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
