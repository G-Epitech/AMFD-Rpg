/*
** EPITECH PROJECT, 2023
** levers.c
** File description:
** Events of buttons components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/app.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

static bool on_lever(lever_t *lever, app_t *app,
sfEvent event, renderer_t *renderer)
{
    sfVector2f cursor = (sfVector2f) {event.mouseButton.x,
    event.mouseButton.y};
    sfVector2u size = sfTexture_getSize(renderer->ressources->components->
    lever->on);

    if (app->state != lever->app_state)
        return false;
    if (cursor.x < lever->position.x || cursor.y < lever->position.y)
        return false;
    if (cursor.x > lever->position.x + size.x * lever->scale)
        return false;
    if (cursor.y > lever->position.y + size.y * lever->scale)
        return false;
    return true;
}

void event_components_levers(renderer_t *renderer, app_t *app, sfEvent event)
{
    list_t *levers = renderer->components->levers;
    node_t *node = levers->first;
    lever_t *lever = NULL;

    while (node) {
        lever = node->data.lever;
        if (on_lever(lever, app, event, renderer)) {
            event_lever_map[lever->event].function(renderer, app, lever);
            break;
        }
        node = node->next;
    }
}
