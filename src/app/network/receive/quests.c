/*
** EPITECH PROJECT, 2023
** receive.c
** File description:
** Receive packets
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Network.h>
#include "app/types.h"
#include "app/network/network.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"
#include "app/quests/quests.h"
#include "types/list/list.h"
#include "app/sound/sound_control.h"

void network_receive_quests(app_t *app, renderer_t *renderer)
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
    sound_control(app->sound_board->sound_fx, NEW_LEVEL, sfPlaying);
    utils_give_xp(renderer, app, quest->xp);
}
