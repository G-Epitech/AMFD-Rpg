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

void reset_setup_brute(app_t *app)
{
    task_content_t brute = find_task_node(app, 2);

    JUST_STARTED(app) = true;
    SIZE_TEXT(app) = 50;
    sfClock_destroy(CLOCK(brute.force));
    TIME_FLOAT(brute.force) = 0.0;
    NB_CLICK(app) = 0;
}
