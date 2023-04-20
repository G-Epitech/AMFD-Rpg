/*
** EPITECH PROJECT, 2023
** notif.c
** File description:
** Notification animation
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "app/animations/types.h"
#include "app/types.h"
#include "types/list/list.h"

animation_event_notif_t *animations_notif_init(void)
{
    animation_event_notif_t *notif = malloc(sizeof(animation_event_notif_t));

    if (!notif)
        return NULL;
    notif->last_time = 0;
    notif->total_time = 0;
    notif->title = NULL;
    notif->description = NULL;
    notif->icon = NULL;
    notif->position = NOTIF_POSITION_INIT;
    return notif;
}

void animations_notif_add(list_t *events, sfTexture *icon, char *title,
char *description)
{
    node_data_t data;
    node_t *node = NULL;

    data.animations_event = malloc(sizeof(animation_event_t));
    if (!data.animations_event)
        return;
    data.animations_event->type = AE_NOTIF;
    data.animations_event->data.notif = animations_notif_init();
    if (!data.animations_event->data.notif) {
        free(data.animations_event);
        return;
    }
    data.animations_event->data.notif->icon = icon;
    data.animations_event->data.notif->title = title;
    data.animations_event->data.notif->description = description;
    node = node_new(data);
    if (!node)
        return;
    list_append(events, node);
}

static void set_position(animation_event_notif_t *notif)
{
    if (notif->total_time < NOTIF_TARGET_SLIDE) {
        notif->position.x -= (NOTIF_POSITION_INIT.x - NOTIF_POSITION_TARGET.x)
        / (NOTIF_TARGET_SLIDE / NOTIF_TIME);
        return;
    }
    if (notif->total_time < NOTIF_TARGET_AFK)
        return;
    notif->position.x += (NOTIF_POSITION_INIT.x - NOTIF_POSITION_TARGET.x)
    / (NOTIF_TARGET_SLIDE / NOTIF_TIME);
}

bool animations_notif(animation_event_notif_t *notif, sfClock *clock)
{
    sfTime elapsed_time;
    sfInt32 time = 0;

    if (!notif || !notif->title || !notif->description || !notif->icon ||
    !clock)
        return true;
    elapsed_time = sfClock_getElapsedTime(clock);
    time = sfTime_asMilliseconds(elapsed_time);
    if (time >= notif->last_time + NOTIF_TIME) {
        set_position(notif);
        notif->last_time = time;
        notif->total_time += NOTIF_TIME;
    }
    if (notif->total_time >= NOTIF_TARGET_SLIDE * 2 + NOTIF_TARGET_AFK) {
        free(notif);
        return true;
    }
    return false;
}
