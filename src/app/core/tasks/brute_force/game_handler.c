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

static void time_handler(app_t *app)
{
    task_content_t brute = find_task_node(app, 2);

    TIME(brute.force) = sfClock_getElapsedTime(CLOCK(brute.force));
    TIME_FLOAT(brute.force) = TIME(brute.force).microseconds / (1000000.0);
}

int app_task_brute_core(app_t *app)
{
    task_content_t brute = find_task_node(app, 2);

    if (JUST_STARTED(app)) {
        if (init_task_brute(app) == 84)
            return 84;
    }
    time_handler(app);
    if (NB_CLICK(app) >= OBJECTIF(app)) {
        my_putstr("You Win\n");
        reset_setup_brute(app);
        app->state = ST_INGAME;
    }
    if (TIME_FLOAT(brute.force) > 10.0) {
        my_putstr("You lose\n");
        reset_setup_brute(app);
        app->state = ST_INGAME;
    }
    return 0;
}
