/*
** EPITECH PROJECT, 2023
** shake_attack.c
** File description:
** Shake attack button
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "app/animations/types.h"
#include "app/types.h"
#include "types/list/list.h"

animation_event_floating_text_t *animations_floting_text_init(void)
{
    animation_event_floating_text_t *text = malloc(sizeof
    (animation_event_floating_text_t));

    if (!text)
        return NULL;
    text->last_time = 0;
    text->total_time = 0;
    text->color = (sfColor) {0, 0, 0, 0};
    text->position = (sfVector2f) {0, 0};
    text->size = 30;
    text->content = NULL;
    return text;
}

void animations_floating_text_add(list_t *events, sfColor color,
sfVector2f position, char *content)
{
    node_data_t data;
    node_t *node = NULL;

    data.animations_event = malloc(sizeof(animation_event_t));
    if (!data.animations_event)
        return;
    data.animations_event->type = AE_FLOATING_TEXT;
    data.animations_event->data.floating_text = animations_floting_text_init();
    if (!data.animations_event->data.floating_text) {
        free(data.animations_event);
        return;
    }
    data.animations_event->data.floating_text->color = color;
    data.animations_event->data.floating_text->position = position;
    data.animations_event->data.floating_text->content = content;
    node = node_new(data);
    if (!node)
        return;
    list_append(events, node);
}

bool animations_floating_text(animation_event_floating_text_t *text,
sfClock *clock)
{
    sfTime elapsed_time;
    sfInt32 time = 0;

    if (!text || !clock)
        return true;
    elapsed_time = sfClock_getElapsedTime(clock);
    time = sfTime_asMilliseconds(elapsed_time);
    if (time >= text->last_time + FLOATING_TEXT_TIME) {
        text->color.a -= 2;
        text->position.y -= 2;
        text->last_time = time;
        text->total_time += FLOATING_TEXT_TIME;
    }
    if (text->total_time >= FLOATING_TEXT_TARGET) {
        free(text);
        return true;
    }
    return false;
}
