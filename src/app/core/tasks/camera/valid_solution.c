/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "types/list/types.h"
#include "app/tasks/camera/camera.h"
#include "types/list/list.h"
#include "my/include/my.h"

static void good_result(renderer_t *renderer, app_t *app)
{
    task_t *node = find_task_node(app, 4);

    (void) renderer;
    my_putstr("You win\n");
    CAMERA_STATE(node) = WIN;
    CAMERA_TIME_ENDED(node) = TIME_FLOAT(node->content.camera);
}

static void bad_result(task_t *node)
{
    my_putstr("-1 vie\n");
    CAMERA_LIFE(node)--;
    CAMERA_SOLUTION(node)[0] = '\0';
    if (CAMERA_LIFE(node) == 0) {
        my_putstr("You lose\n");
        CAMERA_STATE(node) = LOOSE;
        CAMERA_TIME_ENDED(node) = TIME_FLOAT(node->content.camera);
    }
}

void result_camera(renderer_t *renderer, sfEvent event, app_t *app)
{
    task_t *node = find_task_node(app, 4);

    if (event.text.unicode == '\r') {
        if (my_strcmp(CAMERA_SOLUTION(node), CAMERA_RESULT(node)) == 0) {
            good_result(renderer, app);
        } else {
            bad_result(node);
        }
    }
}
