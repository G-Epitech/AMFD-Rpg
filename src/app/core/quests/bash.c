/*
** EPITECH PROJECT, 2023
** brute.c
** File description:
** Handle brute force quest
*/

#include "app/quests/quests.h"
#include "app/types.h"
#include "my/include/my.h"
#include "types/list/list.h"

void core_quests_bash(renderer_t *renderer, app_t *app)
{
    quest_t *quest = NULL;

    if (!app || !app->quests)
        return;
    quest = core_quest_get(app);
    if (!quest)
        return;
    if (!quest || my_strcmp(quest->type, "bash"))
        return;
    core_quests_upgrade(renderer, app);
}
