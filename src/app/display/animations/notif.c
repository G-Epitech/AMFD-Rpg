/*
** EPITECH PROJECT, 2023
** notif.c
** File description:
** Display notification animation
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/renderer.h"
#include "app/app.h"
#include "app/display/types.h"
#include "app/animations/animations.h"
#include "types/list/list.h"

static void display_title(renderer_t *renderer, animation_event_notif_t *notif)
{
    sfText *text = renderer->objects->text;

    renderer_objects_reset_text(renderer->objects);
    sfText_setString(text, notif->title);
    sfText_setPosition(text, (sfVector2f) {notif->position.x + 144,
    notif->position.y + 63});
    sfText_setColor(text, TEXT_DEFAULT_COLOR);
    sfText_setCharacterSize(text, 25);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

static void display_description(renderer_t *renderer,
animation_event_notif_t *notif)
{
    sfText *text = renderer->objects->text;

    renderer_objects_reset_text(renderer->objects);
    sfText_setString(text, notif->description);
    sfText_setPosition(text, (sfVector2f) {notif->position.x + 144,
    notif->position.y + 115});
    sfText_setColor(text, TEXT_DEFAULT_COLOR);
    sfText_setCharacterSize(text, 16);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

static void display_icon(renderer_t *renderer, animation_event_notif_t *notif)
{
    sfSprite *sprite = renderer->objects->sprite;

    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, renderer->ressources->icons->notif, sfTrue);
    sfSprite_setPosition(sprite, notif->position);
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
    renderer_objects_reset_sprite(renderer->objects);
    sfSprite_setTexture(sprite, notif->icon, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {notif->position.x + 54,
    notif->position.y + 80});
    sfRenderWindow_drawSprite(renderer->window, sprite, NULL);
}

static void display_notif(renderer_t *renderer, animation_event_notif_t *notif)
{
    display_icon(renderer, notif);
    display_title(renderer, notif);
    display_description(renderer, notif);
}

void display_animations_notif(renderer_t *renderer, app_t *app)
{
    list_t *events = app->animations->events;
    node_t *node = NULL;
    animation_event_t *event = NULL;

    if (!events->first)
        return;
    node = events->first->data.list->first;
    while (node) {
        event = node->data.animations_event;
        if (event->type == AE_NOTIF)
            display_notif(renderer, event->data.notif);
        node = node->next;
    }
}
