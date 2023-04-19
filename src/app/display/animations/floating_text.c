/*
** EPITECH PROJECT, 2023
** floating_text.c
** File description:
** Dispplay floating texts
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/renderer.h"
#include "app/app.h"
#include "app/animations/animations.h"
#include "types/list/list.h"

static void display_text(renderer_t *renderer,
animation_event_floating_text_t *text_data)
{
    sfText *text = renderer->objects->text;
    sfColor outline = sfBlack;

    outline.a = text_data->color.a;
    renderer_objects_reset_text(renderer->objects);
    sfText_setColor(text, text_data->color);
    sfText_setOutlineColor(text, outline);
    sfText_setOutlineThickness(text, 2);
    sfText_setString(text, text_data->content);
    sfText_setPosition(text, text_data->position);
    sfText_setCharacterSize(text, text_data->size);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

void display_animations_floating_text(renderer_t *renderer, app_t *app)
{
    list_t *events = app->animations->events;
    node_t *node = NULL;
    animation_event_t *event = NULL;

    if (!events->first)
        return;
    node = events->first->data.list->first;
    while (node) {
        event = node->data.animations_event;
        if (event->type == AE_FLOATING_TEXT)
            display_text(renderer, event->data.floating_text);
        node = node->next;
    }
}
