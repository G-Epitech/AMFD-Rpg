/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** dependencies
*/

#ifndef APP_DEPENDENCIES_H_
    #define APP_DEPENDENCIES_H_

    #include "app/app.h"
    #include "app/types.h"

static const app_init_member_t app_init_members[] = {
    &app_init_controller,
    &app_init_players,
    &app_init_npcs,
    &app_init_items,
    &app_init_tasks,
    &app_init_settings,
    &app_init_network,
    &app_init_interactions,
    &app_init_animations,
    &app_init_sounds,
    &app_init_quests,
    NULL
};

static const app_free_member_t app_free_members[] = {
    &app_free_animations,
    &app_free_players,
    &app_free_sounds,
    NULL
};

#endif /* !APP_DEPENDENCIES_H_ */
