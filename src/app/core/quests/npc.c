/*
** EPITECH PROJECT, 2023
** npc.c
** File description:
** Npc quests
*/

#include "app/quests/quests.h"
#include "app/types.h"
#include "my/include/my.h"

void core_quests_npc(renderer_t *renderer, quest_t *quest, app_t *app)
{
    if (!quest || my_strcmp(quest->type, "NPC"))
        return;
    if (!app->interaction || app->interaction->type != IT_DIALOGS)
        return;
    if (app->interaction->data.dialogs->npc->npc->id == quest->id) {
        core_quests_upgrade(renderer, app);
    }
}
