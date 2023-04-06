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
    TIME(NODE_BRUTE) = sfClock_getElapsedTime(CLOCK(NODE_BRUTE));
    TIME_FLOAT(NODE_BRUTE) = TIME(NODE_BRUTE).microseconds / (1000000.0);
}

int app_task_brute_core(app_t *app)
{
    if (JUST_STARTED(app)) {
        if (init_task_brute(app) == 84)
            return 84;
    }
    time_handler(app);
    if (TIME_FLOAT(NODE_BRUTE) > 10.0) {
        if (NB_CLICK(app) > 80) {
            my_putstr("You Win\n");
        } else {
            my_putstr("You lose\n");
        }
        reset_setup_brute(app);
        app->state = ST_INGAME;
    }
    return 0;
}
