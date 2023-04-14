/*
** EPITECH PROJECT, 2023
** interaction.c
** File description:
** Keyboard interaction
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app/app.h"
#include "types/players/types.h"
#include "app/events/types.h"
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "app/animations/animations.h"

static void fight_event(interactions_t *interactions, app_t *app,
renderer_t *renderer)
{
    npc_data_t *data;
    list_t *events = NULL;

    if (interactions->type != IT_NPC)
        return;
    data = interactions->data.npc;
    if (data->enemy) {
        app->state = ST_FIGHT;
        events = animation_event_new(app);
        animations_screen_zoom_add(events, renderer->map_view, 70, 0.5);
    }
}

void keyboard_interaction(sfEvent event, renderer_t *renderer, app_t *app)
{
    if (event.key.code == sfKeyF && app->interaction->interaction) {
        fight_event(app->interaction, app, renderer);
    }
}
