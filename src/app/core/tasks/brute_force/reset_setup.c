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
    JUST_STARTED(app) = true;
    sfClock_destroy(CLOCK(NODE_BRUTE));
    TIME_FLOAT(NODE_BRUTE) = 0.0;
    NB_CLICK(app) = 0;
}
