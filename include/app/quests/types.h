/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** types
*/

#ifndef QUESTS_TYPES_H_
    #define QUESTS_TYPES_H_

    #define QUESTS_CONFIG "configs/quests/quests.json"

typedef struct s_list list_t;

typedef struct s_quest {
    char *title;
    char *type;
    int id;
} quest_t;

typedef struct s_quests {
    char *title;
    list_t *quests;
} quests_t;

typedef struct s_app_quests {
    int index_quests;
    int index_quest;
    list_t *quests;
} app_quests_t;

#endif /* !QUESTS_TYPES_H_ */
