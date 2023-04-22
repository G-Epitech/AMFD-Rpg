/*
** EPITECH PROJECT, 2023
** active.c
** File description:
** Active animation
*/

#include <stdio.h>
#include "app/animations/animations.h"
#include "types/list/list.h"

bool animations_active(animations_t *animations)
{
    node_t *node = NULL;
    animation_event_t *data = NULL;

    if (animations->events->len <= 0)
        return false;
    node = animations->events->first->data.list->first;
    while (node) {
        data = node->data.animations_event;
        if (data->type != AE_NOTIF)
            return true;
        node = node->next;
    }
    return false;
}
