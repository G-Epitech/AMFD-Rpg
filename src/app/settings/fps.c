/*
** EPITECH PROJECT, 2023
** music.c
** File description:
** Music settings
*/

#include <stdio.h>
#include "types/renderer/types.h"
#include "app/types.h"

int settings_fps_up(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    app->settings->fps++;
    sfRenderWindow_setFramerateLimit(renderer->window, app->settings->fps);
    return 0;
}

int settings_fps_malus(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    if (app->settings->fps > 0) {
        app->settings->fps--;
        sfRenderWindow_setFramerateLimit(renderer->window, app->settings->fps);
    }
    return 0;
}
