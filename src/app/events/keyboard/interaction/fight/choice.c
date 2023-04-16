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
#include "app/events/events.h"
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "app/animations/animations.h"
#include "types/renderer/types.h"

static void valid_choice(fight_t *fight, app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;

    if (fight->state == FT_CHOICE) {
        if (fight->choice == 0)
            fight->state = FT_PLAYER_ATTACK;
        if (fight->choice == 1) {
            app->interaction->active = false;
            app->interaction->interaction = false;
            app->state = ST_INGAME;
            free(app->interaction->data.fight);
            events = animation_event_new(app);
            animations_screen_zoom_add(events, renderer->map_view, 70, 2);
        } 
    }
}

void keyboard_interaction_choice(sfEvent event, app_t *app,
renderer_t *renderer)
{
    fight_t *fight = NULL;

    if (!app->interaction->interaction && !app->interaction->active)
        return;
    if (app->interaction->type != IT_FIGHT)
        return;
    fight = app->interaction->data.fight;
    if (event.key.code == sfKeyDown && fight->choice < 1) {
        fight->choice++;
    }
    if (event.key.code == sfKeyUp && fight->choice != 0) {
        fight->choice--;
    }
    if (event.key.code == sfKeyEnter) {
        valid_choice(fight, app, renderer);
    }
}
