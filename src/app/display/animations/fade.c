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

static void display_fade(renderer_t *renderer, animation_event_fade_t *fade)
{
    sfRectangleShape *rectangle = renderer->objects->rectangle;

    renderer_objects_reset_rectangle(renderer->objects);
    sfRectangleShape_setPosition(rectangle, (sfVector2f) {0, 0});
    sfRectangleShape_setFillColor(rectangle, fade->color);
    sfRectangleShape_setSize(rectangle, (sfVector2f) {1920, 1080});
    sfRenderWindow_drawRectangleShape(renderer->window, rectangle, NULL);
}

void display_animations_fade(renderer_t *renderer, app_t *app)
{
    list_t *events = app->animations->events;
    node_t *node = NULL;
    animation_event_t *event = NULL;

    if (!events->first)
        return;
    node = events->first->data.list->first;
    while (node) {
        event = node->data.animations_event;
        if (event->type == AE_FADE)
            display_fade(renderer, event->data.fade);
        node = node->next;
    }
}
