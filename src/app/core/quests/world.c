/*
** EPITECH PROJECT, 2023
** world.c
** File description:
** World quests
*/

#include "app/quests/quests.h"
#include "app/types.h"
#include "my/include/my.h"

void core_quests_world(renderer_t *renderer, quest_t *quest, app_t *app)
{
    if (!quest || my_strcmp(quest->type, "world"))
        return;
    if (quest->id == (int) app->world) {
        core_quests_upgrade(renderer, app);
    }
}
