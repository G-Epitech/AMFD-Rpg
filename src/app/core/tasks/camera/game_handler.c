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
#include "my/include/my.h"

static void time_handler(app_t *app)
{
    task_t *camera = find_task_node(app, 4);

    TIME(camera->content.camera) =
    sfClock_getElapsedTime(CLOCK(camera->content.camera));
    TIME_FLOAT(camera->content.camera) =
    TIME(camera->content.camera).microseconds / SECOND_MICRO;
}

int app_task_camera_core(app_t *app)
{
    task_t *node = find_task_node(app, 4);

    if (CAMERA_STARTED(node)) {
        if (init_task_camera(app) == 84)
            return 84;
    }
    time_handler(app);
    if (TIME_FLOAT(node->content.camera) > 30.0) {
        my_putstr("You lose\n");
        reset_setup_camera(app);
        app->state = ST_INGAME;
    }
    return 0;
}
