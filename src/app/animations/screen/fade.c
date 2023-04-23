/*
** EPITECH PROJECT, 2023
** fade.c
** File description:
** Animation fade screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "app/animations/types.h"
#include "app/types.h"
#include "types/list/list.h"

animation_event_fade_t *animations_screen_fade_init(void)
{
    animation_event_fade_t *fade = malloc(sizeof(animation_event_fade_t));

    if (!fade)
        return NULL;
    fade->last_time = 0;
    fade->total = 0;
    fade->color = sfBlack;
    fade->color.a = 0;
    return fade;
}

void animations_screen_fade_add(list_t *events, bool out)
{
    node_data_t data;
    node_t *node = NULL;

    data.animations_event = malloc(sizeof(animation_event_t));
    if (!data.animations_event)
        return;
    data.animations_event->type = AE_FADE;
    data.animations_event->data.fade = animations_screen_fade_init();
    if (!data.animations_event->data.fade) {
        free(data.animations_event);
        return;
    }
    if (out)
        data.animations_event->data.fade->total = FADE_RATIO;
    node = node_new(data);
    if (!node)
        return;
    list_append(events, node);
}

bool animations_screen_fade(animation_event_fade_t *fade, sfClock *clock)
{
    sfTime elapsed_time;
    sfInt32 time = 0;

    if (!fade || !clock)
        return true;
    elapsed_time = sfClock_getElapsedTime(clock);
    time = sfTime_asMilliseconds(elapsed_time);
    if (time >= fade->last_time + FADE_TIME) {
        if (fade->total < FADE_RATIO)
            fade->color.a += 1;
        else
            fade->color.a -= 1;
        fade->last_time = time;
        fade->total += FADE_TIME;
    }
    if (fade->total >= FADE_RATIO * 2) {
        free(fade);
        return true;
    }
    return false;
}
