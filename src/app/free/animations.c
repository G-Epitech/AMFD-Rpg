/*
** EPITECH PROJECT, 2023
** animations.c
** File description:
** Free animations
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/list/list.h"
#include "app/animations/types.h"

void app_free_animations(app_t *app)
{
    list_free(app->animations->events);
    list_free(app->animations->map);
    sfClock_destroy(app->animations->clock);
    free(app->animations);
}
