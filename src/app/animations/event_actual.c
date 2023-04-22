/*
** EPITECH PROJECT, 2023
** new_event.c
** File description:
** Get or add a event
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app/animations/animations.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/list/list.h"

list_t *animation_event_actual(app_t *app)
{
    if (app->animations->events->first != NULL) {
        return app->animations->events->first->data.list;
    } else {
        return animation_event_new(app);
    }
}
