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

void keyboard_interaction_dialogs_continue(sfEvent event, renderer_t *renderer,
app_t *app)
{
    interaction_dialogs_t *dialogs = NULL;

    (void) renderer;
    if (event.key.code != sfKeyEnter || app->interaction->type != IT_DIALOGS)
        return;
    dialogs = app->interaction->data.dialogs;
    if (dialogs->index + 1 < dialogs->npc->dialogs->len) {
        dialogs->index++;
        return;
    }
    app->state = ST_INGAME;
    if (dialogs->npc->enemy) {
        interaction_fight_start(app->interaction, app, renderer);
    } else {
        app->interaction->active = false;
        app->interaction->interaction = false;
    }
}
