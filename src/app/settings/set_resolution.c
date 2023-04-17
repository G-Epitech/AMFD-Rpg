/*
** EPITECH PROJECT, 2023
** set_resolution.c
** File description:
** Resolution settings
*/

#include "types/renderer/types.h"
#include "app/types.h"

int settings_resolution_lower(renderer_t *renderer,
app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    sfRenderWindow_close(renderer->window);
    sfRenderWindow_destroy(renderer->window);
    renderer->window = window_init(app->settings->full_screen, LOWER_WIN_VIDEO_MODE);
    renderer->objects->window = renderer->window;
    renderer->default_view = sfRenderWindow_getDefaultView(renderer->window);
    return 0;
}

int settings_resolution_medium(renderer_t *renderer,
app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    sfRenderWindow_close(renderer->window);
    sfRenderWindow_destroy(renderer->window);
    renderer->window = window_init(app->settings->full_screen, MEDIUM_WIN_VIDEO_MODE);
    renderer->objects->window = renderer->window;
    renderer->default_view = sfRenderWindow_getDefaultView(renderer->window);
    return 0;
}

int settings_resolution_high(renderer_t *renderer,
app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    sfRenderWindow_close(renderer->window);
    sfRenderWindow_destroy(renderer->window);
    renderer->window = window_init(app->settings->full_screen, HIGH_WIN_VIDEO_MODE);
    renderer->objects->window = renderer->window;
    renderer->default_view = sfRenderWindow_getDefaultView(renderer->window);
    return 0;
}
