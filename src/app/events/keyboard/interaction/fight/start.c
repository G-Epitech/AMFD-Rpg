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
#include "types/characters/types.h"

static void rotate_npc(npc_data_t *data, player_t *player)
{
    if (player->orientation == SO_RIGHT)
        data->orientation = SO_LEFT;
    if (player->orientation == SO_LEFT)
        data->orientation = SO_RIGHT;
    if (player->orientation == SO_BACK)
        data->orientation = SO_FACE;
    if (player->orientation == SO_FACE)
        data->orientation = SO_BACK;
}

static void set_fight_interaction(interactions_t *interactions)
{
    npc_data_t *npc = interactions->data.npc;

    interactions->type = IT_FIGHT;
    interactions->data.fight = malloc(sizeof(fight_t));
    if (!interactions->data.fight)
        return;
    interactions->data.fight->npc = npc;
    interactions->data.fight->state = FT_CHOICE;
    interactions->data.fight->choice = 0;
}

void interaction_fight_start(interactions_t *interactions, app_t *app,
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
        rotate_npc(data, app->player);
        set_fight_interaction(interactions);
    }
}
