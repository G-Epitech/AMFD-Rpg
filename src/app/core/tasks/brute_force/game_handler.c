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
#include "app/tasks/bruteforce/bruteforce.h"
#include "app/tasks/bruteforce/types.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "app/animations/animations.h"

static void time_handler(app_t *app)
{
    task_t *brute = find_task_node(app, 2);

    TIME(brute->content.force) =
    sfClock_getElapsedTime(CLOCK(brute->content.force));
    TIME_FLOAT(brute->content.force) =
    TIME(brute->content.force).microseconds / SECOND_MICRO;
}

static void win_game(app_t *app, renderer_t *renderer)
{
    list_t *events = animation_event_actual(app);

    animations_notif_add(events, renderer->ressources->icons->happy,
    "Brute force", "Vous venez de brute force le systeme !\nBravo a vous.");
    reset_setup_brute(app);
    app->state = ST_INGAME;
    app->interaction->active = false;
}

int app_task_brute_core(app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;
    task_t *brute = find_task_node(app, 2);

    if (JUST_STARTED(app)) {
        if (init_task_brute(app) == 84)
            return 84;
    }
    time_handler(app);
    if (NB_CLICK(app) >= OBJECTIF(app))
        win_game(app, renderer);
    if (TIME_FLOAT(brute->content.force) > 10.0) {
        events = animation_event_actual(app);
        animations_notif_add(events, renderer->ressources->icons->happy,
        "Brute force", "Vous n'avez pas reussi a brute force le systeme.");
        reset_setup_brute(app);
        app->state = ST_INGAME;
        app->interaction->active = false;
    }
    return 0;
}
