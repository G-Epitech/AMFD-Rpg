/*
** EPITECH PROJECT, 2023
** music.c
** File description:
** Music settings
*/

#include "types/renderer/types.h"
#include "app/types.h"

int settings_volume_up(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    if (app->settings->volume < 100) {
        app->settings->volume++;
    }
    return 0;
}

int settings_volume_malus(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    if (app->settings->volume > 0) {
        app->settings->volume--;
    }
    return 0;
}
