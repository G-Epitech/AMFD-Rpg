/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** settings
*/


#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/types.h"

bool app_init_settings(app_t *app, renderer_t *renderer)
{
    settings_t *settings = malloc(sizeof(settings_t));

    (void) renderer;
    if (!settings)
        return false;
    settings->developer = false;
    settings->fps = 120;
    settings->full_screen = false;
    settings->music = true;
    settings->volume = 15;
    app->settings = settings;
    return true;
}
