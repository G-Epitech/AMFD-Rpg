/*
** EPITECH PROJECT, 2023
** hanlder.c
** File description:
** Handle fight
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/types.h"
#include "types/players/players.h"
#include "app/core/core.h"
#include "types/list/types.h"
#include "app/app.h"
#include "app/network/network.h"
#include "app/animations/animations.h"

void core_fight_handler(app_t *app, renderer_t *renderer)
{
    if (!app->interaction->interaction && app->interaction->type != IT_FIGHT)
        return;
    if (app->interaction->data.fight->state == FT_NPC_ATTACK) {
        core_fight_enemy(app, renderer);
        return;
    }
}
