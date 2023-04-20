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

void keyboard_interaction(sfEvent event, renderer_t *renderer, app_t *app)
{
    if (event.key.code == sfKeyF &&
        app->interaction->interaction &&
        !app->interaction->active) {
        keyboard_interaction_dialogs(renderer, app);
    }
    keyboard_interaction_choice(event, app, renderer);
    keyboard_interaction_dialogs_continue(event, renderer, app);
}
