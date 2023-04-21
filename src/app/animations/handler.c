/*
** EPITECH PROJECT, 2023
** handler.c
** File description:
** Animation handler
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app/animations/animations.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/list/list.h"

static bool animation_event_data(animations_t *animation,
animation_event_t *data)
{
    if (data->type == AE_ZOOM &&
    animations_screen_zoom(data->data.zoom, animation->clock))
        return true;
    if (data->type == AE_SHAKE_ATTACK &&
    animations_shake_attack(data->data.shake_attack, animation->clock))
        return true;
    if (data->type == AE_FLOATING_TEXT &&
    animations_floating_text(data->data.floating_text, animation->clock))
        return true;
    if (data->type == AE_NOTIF &&
    animations_notif(data->data.notif, animation->clock))
        return true;
    return false;
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
    if (app->animations->events->len <= 0)
        return;
    animations_event_handler(app->animations);
}
