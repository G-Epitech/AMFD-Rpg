/*
** EPITECH PROJECT, 2023
** settings.c
** File description:
** Display menus
*/

#include "app/types.h"
#include "types/list/types.h"
#include "app/display/types.h"
#include "app/display/display.h"
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"
#include "my/include/my.h"

static void display_int_value(renderer_t *renderer, int value,
sfVector2f position)
{
    sfText *text = renderer->objects->text;

    renderer_objects_reset_text(renderer->objects);
    sfText_setPosition(text, position);
    sfText_setString(text, nbr_to_str(value));
    sfText_setCharacterSize(text, 25);
    sfRenderWindow_drawText(renderer->window, text, NULL);
}

void display_settings(renderer_t *renderer, app_t *app)
{
    (void) renderer;
    if (app->state != ST_SETTINGS && app->state != ST_IGSETTINGS)
        return;
    display_int_value(renderer, app->settings->volume, VOLUME_POSITION);
    display_int_value(renderer, app->settings->fps, FPS_POSITION);
}
