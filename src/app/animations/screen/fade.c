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
    fade->coords = (sfVector2f) {0, 0};
    fade->world = 0;
    return fade;
}

void animations_screen_fade_add(list_t *events, bool out, int world,
sfVector2f coords)
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
    data.animations_event->data.fade->coords = coords;
    data.animations_event->data.fade->world = world;
    node = node_new(data);
    if (!node)
        return;
    list_append(events, node);
}

static void animation_fade(animation_event_fade_t *fade, app_t *app)
{
    if (fade->total < FADE_RATIO)
        fade->color.a += 1;
    if (fade->total > FADE_RATIO - FADE_TIME &&
    fade->total < FADE_RATIO + FADE_TIME) {
        app->player->position = fade->coords;
        app->world = fade->world;
    }
    if (fade->total >= FADE_RATIO)
        fade->color.a -= 1;
}

bool animations_screen_fade(animation_event_fade_t *fade, sfClock *clock,
app_t *app)
{
    sfTime elapsed_time;
    sfInt32 time = 0;

    if (!fade || !clock)
        return true;
    elapsed_time = sfClock_getElapsedTime(clock);
    time = sfTime_asMilliseconds(elapsed_time);
    if (time >= fade->last_time + FADE_TIME) {
        animation_fade(fade, app);
        fade->last_time = time;
        fade->total += FADE_TIME;
    }
    if (fade->total >= FADE_RATIO * 2) {
        free(fade);
        return true;
    }
    return false;
}
