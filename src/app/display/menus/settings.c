/*
** EPITECH PROJECT, 2023
** settings.c
** File description:
** Display menus
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void display_settings(renderer_t *renderer, app_t *app)
{
    (void) renderer;
    if (app->state != ST_SETTINGS)
        return;
}
