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
#include "app/animations/animations.h"

static void time_handler(app_t *app)
{
    task_t *camera = find_task_node(app, 4);

    TIME(camera->content.camera) =
    sfClock_getElapsedTime(CLOCK(camera->content.camera));
    TIME_FLOAT(camera->content.camera) =
    TIME(camera->content.camera).microseconds / SECOND_MICRO;
}

int app_task_camera_core(app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;
    task_t *node = find_task_node(app, 4);

    if (CAMERA_STARTED(node)) {
        if (init_task_camera(app) == 84)
            return 84;
    }
    time_handler(app);
    if (TIME_FLOAT(node->content.camera) >
    TIME_EXPENSIVE(node->content.camera)) {
        events = animation_event_actual(app);
        animations_notif_add(events, renderer->ressources->icons->hungry,
        "Camera", "Vous n'avez pas reussi à hack les cameras.");
        CAMERA_STATE(node) = LOOSE;
        app->state = ST_INGAME;
        app->interaction->active = false;
        reset_setup_camera(app);
    }
    return 0;
}
