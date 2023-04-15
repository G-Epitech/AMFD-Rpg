/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdlib.h>
#include <time.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "types/list/types.h"
#include "app/tasks/camera/camera.h"
#include "types/list/list.h"
#include "my/include/my.h"

void reset_setup_camera(app_t *app)
{
    task_t *node = find_task_node(app, 4);

    CAMERA_STARTED(node) = true;
    sfClock_destroy(CLOCK(node->content.camera));
    TIME_FLOAT(node->content.camera) = 0.0;
    TIME_INT(node->content.camera) = 0;
    CAMERA_LIFE(node) = 3;
    INDEX_EQUATIONS(node) = 1;
}
