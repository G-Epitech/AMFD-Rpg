/*
** EPITECH PROJECT, 2023
** npc.c
** File description:
** NPCs interactions
*/

#include <stdbool.h>
#include <stdio.h>
#include "app/app.h"
#include "app/core/core.h"
#include "types/npc/npc.h"

void core_interactions_npc(sfColor pixel, app_t *app)
{
    int id = pixel.a;

    if (core_interaction_detect_color(pixel, sfYellow) == false)
        return;
    app->interaction->interaction = true;
    app->interaction->type = IT_NPC;
    app->interaction->data.npc = npc_get_data_by_id(app->npcs, id, app->world);
}
