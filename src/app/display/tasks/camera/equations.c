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

static void display_number(int index, renderer_t *renderer, node_t *temp)
{
    renderer_objects_t *objects = renderer->objects;
    sfVector2f pos =
    {temp->data.node_camera->pos.x - 50, temp->data.node_camera->pos.y};

    sfText_setPosition(objects->text, pos);
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, nbr_to_str(index));
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    pos.x += 25;
    sfText_setPosition(objects->text, pos);
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, ")");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

void display_equations(renderer_t *renderer, app_t *app)
{
    renderer_objects_t *objects = renderer->objects;
    task_t *node = find_task_node(app, 4);
    node_t *temp = CAMERA_EQUATIONS(node)->first;

    for (int index = 1; temp != NULL; index++) {
        display_number(index, renderer, temp);
        sfText_setPosition(objects->text, temp->data.node_camera->pos);
        sfText_setColor(objects->text, sfWhite);
        sfText_setString(objects->text, temp->data.node_camera->equation);
        sfRenderWindow_drawText(renderer->window, objects->text, NULL);
        temp = temp->next;
    }
}
