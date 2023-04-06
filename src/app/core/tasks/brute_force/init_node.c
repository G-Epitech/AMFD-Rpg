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
    CLOCK(NODE_BRUTE) = sfClock_create();
    if (CLOCK(NODE_BRUTE) == NULL)
        return 84;
    JUST_STARTED(app) = false;
    return 0;
}
