/*
** EPITECH PROJECT, 2023
** music.c
** File description:
** Music settings
*/

#include <stdio.h>
#include "types/renderer/types.h"
#include "app/types.h"

int settings_fullscreen(renderer_t *renderer, app_t *app, lever_t *lever)
{
    (void) renderer;
    app->settings->full_screen = !app->settings->full_screen;
    lever->active = app->settings->full_screen;
    sfRenderWindow_close(renderer->window);
    sfRenderWindow_destroy(renderer->window);
    renderer->window = window_init(app->settings->full_screen);
    renderer->objects->window = renderer->window;
    renderer->default_view = sfRenderWindow_getDefaultView(renderer->window);
    return 0;
}
