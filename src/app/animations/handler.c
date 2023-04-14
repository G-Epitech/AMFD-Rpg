/*
** EPITECH PROJECT, 2023
** handler.c
** File description:
** Animation handler
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app/animations/animations.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/list/list.h"

static bool animation_event_data(animations_t *animation,
animation_event_t *data)
{
    bool end = false;

    if (data->type == AE_ZOOM) {
        if (animations_screen_zoom(data->data.zoom, animation->clock)) { 
            free(data->data.zoom);
            end = true;
        }
    }
    return end;
}

static void animations_event_handler(animations_t *animation)
{
    list_t *events = animation->events->first->data.list;
    node_t *node = NULL;
    node_t *tmp = NULL;
    animation_event_t *data = NULL;

    if (!events)
        return;
    node = events->first;
    while (node) {
        data = node->data.animations_event;
        if (animation_event_data(animation, data)) {
            tmp = node;
            node = node->next;
            list_delete(events, tmp);
            continue;
        } 
        node = node->next;
    }
    if (events->len == 0)
        list_delete(animation->events, animation->events->first);
}

void animations_handler(renderer_t *renderer, app_t *app)
{
    (void) renderer;
    animations_event_handler(app->animations);
}
