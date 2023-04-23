/*
** EPITECH PROJECT, 2023
** npc.c
** File description:
** Npc quests
*/

#include "app/quests/quests.h"
#include "app/types.h"
#include "my/include/my.h"
#include "app/competences_tree/competences_tree.h"

void core_quests_tree(renderer_t *renderer, quest_t *quest, app_t *app)
{
    if (!quest || my_strcmp(quest->type, "tree"))
        return;
    if (find_skill(app, quest->id)->unlock)
        core_quests_upgrade(renderer, app);
}
