/*
** EPITECH PROJECT, 2023
** quests.c
** File description:
** Handle quests
*/

#include "app/quests/quests.h"
#include "app/types.h"
#include "my/include/my.h"
#include "types/list/list.h"

static void quests_dispatch(renderer_t *renderer, quest_t *quest, app_t *app)
{
    core_quests_world(renderer, quest, app);
    core_quests_npc(renderer, quest, app);
}

void core_quests(renderer_t *renderer, app_t *app)
{
    quest_t *quest = NULL;

    if (!app || !app->quests)
        return;
    quest = core_quest_get(app);
    if (!quest)
        return;
    quests_dispatch(renderer, quest, app);
}
