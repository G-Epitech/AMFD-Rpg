/*
** EPITECH PROJECT, 2023
** get.c
** File description:
** Get quest by index or actual
*/

#include "app/quests/types.h"
#include "app/types.h"
#include "types/list/list.h"

quests_t *core_quests_get(app_t *app)
{
    app_quests_t *app_quests = app->quests;
    node_t *n_quests = app_quests->quests->first;

    for (size_t i = 0; i < (size_t)app_quests->index_quests; i++) {
        n_quests = n_quests->next;
        if (!n_quests)
            return NULL;
    }
    return n_quests->data.quests;
}

quest_t *core_quest_get(app_t *app)
{
    app_quests_t *app_quests = app->quests;
    quests_t *quests = core_quests_get(app);
    node_t *n_quest = NULL;

    if (!quests)
        return NULL;
    n_quest = quests->quests->first;
    for (size_t i = 0; i < (size_t)app_quests->index_quest; i++) {
        n_quest = n_quest->next;
        if (!n_quest)
            return NULL;
    }
    return n_quest->data.quest;
}
