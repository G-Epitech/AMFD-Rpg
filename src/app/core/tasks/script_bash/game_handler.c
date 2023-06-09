/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bash/script_bash.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "app/animations/animations.h"

static void time_handler(app_t *app)
{
    task_t *bash = find_task_node(app, 1);

    TIME(bash->content.script) =
    sfClock_getElapsedTime(CLOCK(bash->content.script));
    TIME_FLOAT(bash->content.script) =
    TIME(bash->content.script).microseconds / SECOND_MICRO;
}

int app_task_bash_core(app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;
    task_t *bash = find_task_node(app, 1);

    if (STRUCT_BASH(app).handler_placing->just_started) {
        if (init_task_bash(app) == 84)
            return 84;
    }
    time_handler(app);
    if (STRUCT_BASH(app).handler_time->time_float >
    TIME_EXPENSIVE(bash->content.script)) {
        events = animation_event_actual(app);
        animations_notif_add(events, renderer->ressources->icons->hungry,
        "Script bash", "Vous n'avez pas reussi a hack\nle systeme.");
        app->state = ST_INGAME;
        app->interaction->active = false;
        reset_setup_bash(app);
    }
    return 0;
}
