/*
** EPITECH PROJECT, 2023
** interaction.c
** File description:
** Keyboard interaction
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/players/types.h"
#include "app/events/types.h"
#include "types/npc/npc.h"

static void fight_event(interactions_t *interactions, app_t *app)
{
    npc_data_t *data;

    if (interactions->type != IT_NPC)
        return;
    data = interactions->data.npc;
    // Display dialogs
    if (data->enemy) {
        app->state = ST_FIGHT;
    }
}

void keyboard_interaction(sfEvent event, app_t *app)
{
    if (event.key.code == sfKeyF && app->interaction->interaction) {
        fight_event(app->interaction, app);
    }
}
