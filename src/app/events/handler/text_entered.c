/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/events/events.h"
#include "app/tasks/bash/script_bash.h"
#include "app/tasks/camera/camera.h"
#include "app/app.h"

void event_text_entered(renderer_t *renderer, sfEvent event, app_t *app)
{
    if (app->dialog_box->show)
        return;
    if (event.type == sfEvtTextEntered) {
        if (app->state == ST_TASK_BASH) {
            cmd_write(event, app);
            good_or_bad_result(event, app);
        }
        if (app->state == ST_TASK_CAMERA) {
            solution_write(event, app);
            result_camera(renderer, event, app);
        }
    }
}
