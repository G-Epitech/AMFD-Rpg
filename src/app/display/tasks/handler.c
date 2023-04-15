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
        app_task_camera_display(renderer, app);
    }
    return 0;
}
