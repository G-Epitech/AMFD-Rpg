/*
** EPITECH PROJECT, 2023
** zoom.c
** File description:
** Animation zoom screen
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <math.h>
#include "app/animations/types.h"
#include "app/types.h"
#include "types/list/list.h"

animation_event_zoom_t *animations_screen_zoom_init(void)
{
    animation_event_zoom_t *zoom = malloc(sizeof(animation_event_zoom_t));

    if (!zoom)
        return NULL;
    zoom->last_time = 0;
    zoom->speed = 0;
    zoom->view = NULL;
    zoom->zoom = 0;
    zoom->total = 0;
    return zoom;
}

void animations_screen_zoom_add(list_t *events, sfView *view, float speed,
float zoom)
{
    node_data_t data;
    node_t *node = NULL;

    data.animations_event = malloc(sizeof(animation_event_t));
    if (!data.animations_event)
        return;
    data.animations_event->type = AE_ZOOM;
    data.animations_event->data.zoom = animations_screen_zoom_init();
    if (!data.animations_event->data.zoom) {
        free(data.animations_event);
        return;
    }
    data.animations_event->data.zoom->view = view;
    data.animations_event->data.zoom->speed = speed;
    data.animations_event->data.zoom->zoom = zoom;
    node = node_new(data);
    if (!node)
        return;
    list_append(events, node);
}

bool animations_screen_zoom(animation_event_zoom_t *zoom, sfClock *clock)
{
    sfTime elapsed_time;
    sfInt32 time = 0;
    double new_zoom = 0;

    if (!zoom || !zoom->view || !clock)
        return true;
    elapsed_time = sfClock_getElapsedTime(clock);
    time = sfTime_asMilliseconds(elapsed_time);
    if (time >= zoom->last_time + ZOOM_TIME) {
        new_zoom = pow(zoom->zoom, 1.0 / (ZOOM_RATIO - zoom->speed));
        sfView_zoom(zoom->view, new_zoom);
        zoom->last_time = time;
        zoom->total += 1;
    }
    if (zoom->total >= ZOOM_RATIO - zoom->speed)
        return true;
    return false;
}
