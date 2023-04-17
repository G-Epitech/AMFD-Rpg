/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "types/renderer/types.h"
#include "app/tasks/bash/script_bash.h"
#include "app/tasks/bruteforce/bruteforce.h"
#include "app/tasks/flipper/flipper.h"
#include "app/tasks/camera/camera.h"
#include "app/tasks/types.h"
#include "types/renderer/renderer.h"
#include "app/tasks/task.h"
#include "types/list/types.h"
#include "my/include/my.h"


static void task_camera(renderer_t *renderer, app_t *app)
{
    task_t *node = find_task_node(app, 4);

    if (CAMERA_STATE(node) == WIN) {
        display_win(renderer, app);
    } else if (CAMERA_STATE(node) == LOOSE) {
        display_loose(renderer, app);
    } else {
        app_task_camera_display(renderer, app);
    }
}

int display_tasks_handler(renderer_t *renderer, app_t *app)
{
    if (app->state == ST_TASK_BASH) {
        app_task_bash_display(renderer, app);
    }
    if (app->state == ST_TASK_BRUTEFORCE) {
        app_task_brute_display(renderer, app);
    }
    if (app->state == ST_TASK_FLIPPER) {
        app_task_flipper_display(renderer, app);
    }
    if (app->state == ST_TASK_CAMERA) {
        task_camera(renderer, app);
    }
    return 0;
}
