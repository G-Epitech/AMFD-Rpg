/*
** EPITECH PROJECT, 2023
** music.c
** File description:
** Music settings
*/

#include "types/renderer/types.h"
#include "app/types.h"

int settings_music(renderer_t *renderer, app_t *app, lever_t *lever)
{
    (void) renderer;
    app->settings->music = !app->settings->music;
    lever->active = app->settings->music;
    return 0;
}
