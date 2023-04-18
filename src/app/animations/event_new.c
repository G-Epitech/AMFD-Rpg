/*
** EPITECH PROJECT, 2023
** new_event.c
** File description:
** Add new event
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app/animations/animations.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/list/list.h"

list_t *animation_event_new(app_t *app)
{
    node_data_t data;
    node_t *node = NULL;

    data.list = list_new();
    if (!data.list)
        return NULL;
    node = node_new(data);
    if (!node) {
        list_free(data.list);
        return NULL;
    }
    list_append(app->animations->events, node);
    return data.list;
}
