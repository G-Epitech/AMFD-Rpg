/*
** EPITECH PROJECT, 2023
** upgrade.c
** File description:
** Ugrade quests index
*/

#include <stdio.h>
#include "app/quests/quests.h"
#include "app/types.h"
#include "my/include/my.h"
#include "types/list/list.h"

void core_quests_upgrade(renderer_t *renderer, app_t *app)
{
    app_quests_t *app_quests = app->quests;
    quests_t *quests = core_quests_get(app);
    quest_t *quest = core_quest_get(app);

    if (quests->quests->len == app_quests->index_quest + 1) {
        app_quests->index_quest = 0;
        app_quests->index_quests++;
    } else {
        app_quests->index_quest++;
    }
    utils_give_xp(renderer, app, quest->xp);
}
