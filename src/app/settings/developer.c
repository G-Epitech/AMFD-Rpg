/*
** EPITECH PROJECT, 2023
** music.c
** File description:
** Music settings
*/

#include "types/renderer/types.h"
#include "app/types.h"

int settings_developer(renderer_t *renderer, app_t *app, lever_t *lever)
{
    (void) renderer;
    app->settings->developer = !app->settings->developer;
    lever->active = app->settings->developer;
    return 0;
}
