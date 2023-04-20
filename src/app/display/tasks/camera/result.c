/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdio.h>
#include "types/renderer/renderer.h"
#include "app/tasks/task.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "app/tasks/camera/camera.h"
#include "app/tasks/types.h"

void display_win(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    (void) app;
    sfText_setPosition(objects->text, (sfVector2f) {785, 550});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Vous avez gagne");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

void display_loose(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;

    (void) app;
    sfText_setPosition(objects->text, (sfVector2f) {785, 550});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "Vous avez perdu");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}
