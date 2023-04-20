/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** dialogs
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app/app.h"
#include "types/players/types.h"
#include "app/events/events.h"
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "app/animations/animations.h"

void keyboard_interaction_dialogs(renderer_t *renderer, app_t *app)
{
    interactions_t *interaction = app->interaction;
    npc_data_t *npc = NULL;

    (void) renderer;
    if (interaction->type != IT_NPC)
        return;
    interaction->active = true;
    interaction->type = IT_DIALOGS;
    npc = interaction->data.npc;
    interaction->data.dialogs = malloc(sizeof(interaction_dialogs_t));
    if (!interaction->data.dialogs)
        return;
    interaction->data.dialogs->npc = npc;
    interaction->data.dialogs->index = 0;
    app->state = ST_DIALOGS;
}
