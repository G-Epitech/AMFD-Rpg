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
#include "app/tasks/task.h"
#include "app/tasks/camera/camera.h"
#include "app/app.h"

void event_text_entered(renderer_t *renderer, sfEvent event, app_t *app)
{
    task_t *node = find_task_node(app, 4);

    if (event.type != sfEvtTextEntered)
        return;
    if (app->dialog_box->show)
        return event_dialog_box_ontextentered(app, event);
    if (app->state == ST_TASK_BASH &&
    STRUCT_BASH(app).handler_placing->just_started == false) {
        cmd_write(event, app);
        good_or_bad_result(event, app, renderer);
    }
    if (app->state == ST_TASK_CAMERA && CAMERA_STARTED(node) == false) {
        solution_write(event, app);
        result_camera(renderer, event, app);
    }
}
