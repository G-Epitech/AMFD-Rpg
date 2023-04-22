/*
** EPITECH PROJECT, 2023
** collisions.c
** File description:
** Display collisions of the map
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "app/types.h"
#include "types/renderer/renderer.h"
#include "types/list/list.h"
#include "my/include/my.h"

static void display_developer_mouse_pos_window(renderer_t *renderer, app_t *app)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(renderer->window);
    char *x = nbr_to_str(position.x);
    char *y = nbr_to_str(position.y);
    char *position_text = my_strcat("Mouse position x: ", x);

    if (!app->settings->developer)
        return;
    position_text = my_strcat(position_text, ", y:");
    position_text = my_strcat(position_text, y);
    sfText_setPosition(renderer->objects->text, (sfVector2f) {600, 990});
    sfText_setCharacterSize(renderer->objects->text, 20);
    sfText_setString(renderer->objects->text, position_text);
    sfText_setColor(renderer->objects->text, sfGreen);
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
    free(position_text);
}

void display_developer_position(renderer_t *renderer, app_t *app)
{
    sfVector2f position = app->player->position;
    char *x = nbr_to_str(position.x);
    char *y = nbr_to_str(position.y);
    char *position_text = my_strcat("Position x: ", x);

    if (!app->settings->developer)
        return;
    position_text = my_strcat(position_text, ", y:");
    position_text = my_strcat(position_text, y);
    renderer_objects_reset_text(renderer->objects);
    sfText_setPosition(renderer->objects->text, (sfVector2f) {70, 990});
    sfText_setCharacterSize(renderer->objects->text, 20);
    sfText_setString(renderer->objects->text, position_text);
    sfText_setColor(renderer->objects->text, sfRed);
    sfRenderWindow_drawText(renderer->window, renderer->objects->text, NULL);
    free(position_text);
    display_developer_mouse_pos_window(renderer, app);
}
