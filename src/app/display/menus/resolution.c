/*
** EPITECH PROJECT, 2023
** menu
** File description:
** menu of resolution
*/

#include <stdio.h>
#include "types/renderer/renderer.h"
#include "app/display/types.h"
#include "my/include/my.h"

static void display_title(renderer_t *renderer)
{
    renderer_objects_t *objects = renderer->objects;

    renderer_objects_reset_text(objects);
    sfText_setCharacterSize(objects->text, 64);
    sfText_setPosition(objects->text, (sfVector2f) {696, 308});
    sfText_setColor(objects->text, MAIN_COLOR);
    sfText_setString(objects->text, "Resolutions");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_resolutions(renderer_t *renderer)
{
    renderer_objects_t *objects = renderer->objects;

    renderer_objects_reset_text(objects);
    sfText_setCharacterSize(objects->text, 30);
    sfText_setPosition(objects->text, (sfVector2f) {506, 578});
    sfText_setColor(objects->text, MAIN_COLOR);
    sfText_setString(objects->text, "820x600");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {841, 578});
    sfText_setColor(objects->text, MAIN_COLOR);
    sfText_setString(objects->text, "1920x1080");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {1206, 578});
    sfText_setColor(objects->text, MAIN_COLOR);
    sfText_setString(objects->text, "2560x1600");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

void display_menus_resolution(renderer_t *renderer, app_t *app)
{
    if (app->state != ST_RESOLUTION)
        return;
    display_title(renderer);
    display_resolutions(renderer);
}
