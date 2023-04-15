/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/camera/camera.h"
#include "types/list/types.h"

int init_task_camera(app_t *app)
{
    task_t *camera = find_task_node(app, 4);

    CLOCK(camera->content.force) = sfClock_create();
    if (CLOCK(camera->content.force) == NULL)
        return 84;
    CAMERA_STARTED(camera) = false;
    return 0;
}
