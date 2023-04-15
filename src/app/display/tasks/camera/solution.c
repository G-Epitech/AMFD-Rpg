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

void display_solution(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 4);

    sfText_setPosition(objects->text, (sfVector2f) {1100, 300});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, CAMERA_SOLUTION(node));
    sfText_setCharacterSize(objects->text, 25);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}
