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
#include "app/core/core.h"
#include "app/shop/shop_handle.h"

static map_t *get_current_map(renderer_t *renderer, app_t *app)
{
    node_t *node = renderer->ressources->maps->first;
    size_t index = 0;

    while (node) {
        if (index == app->world)
            return node->data.map;
        index++;
        node = node->next;
    }
    return NULL;
}

void keyboard_interaction(sfEvent event, renderer_t *renderer, app_t *app)
{
    map_t *current_map = get_current_map(renderer, app);

    if (event.key.code == sfKeyF &&
        app->interaction->interaction &&
        !app->interaction->active) {
        core_handle_travel(renderer, app, current_map);
        shop_handler(app);
        keyboard_interaction_dialogs(renderer, app);
    }
    keyboard_interaction_choice(event, app, renderer);
    keyboard_interaction_dialogs_continue(event, renderer, app);
}
