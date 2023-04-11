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

int init_task_brute(app_t *app)
{
    task_content_t brute = find_task_node(app, 2);

    CLOCK(brute.force) = sfClock_create();
    if (CLOCK(brute.force) == NULL)
        return 84;
    JUST_STARTED(app) = false;
    return 0;
}
