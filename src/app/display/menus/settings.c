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

static void display_title(renderer_t *renderer)
{
    sfText_setString(renderer->objects->text, SETTINGS_TITLE);
    sfText_setFont(renderer->objects->text, renderer->font);
    sfText_setCharacterSize(renderer->objects->text, 64);
    sfText_setPosition(renderer->objects->text, (sfVector2f) {816, 292});
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
}

void display_settings(renderer_t *renderer, app_t *app)
{
    if (app->state != ST_SETTINGS)
        return;
    display_title(renderer);
}
