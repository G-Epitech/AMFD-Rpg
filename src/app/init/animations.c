/*
** EPITECH PROJECT, 2023
** animations.c
** File description:
** Init animations
*/

#include <stdlib.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "app/types.h"
#include "app/animations/types.h"
#include "types/list/list.h"

bool app_init_animations(app_t *app, renderer_t *renderer)
{
    animations_t *animations = malloc(sizeof(animations_t));

    (void) renderer;
    if (!animations)
        return false;
    animations->events = list_new();
    animations->map = list_new();
    if (!animations->events || !animations->map) {
        free(animations);
        return false;
    }
    animations->clock = sfClock_create();
    app->animations = animations;
    return true;
}
