/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdbool.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bruteforce/bruteforce.h"
#include "app/tasks/bruteforce/types.h"
#include "types/list/types.h"
#include "app/types.h"
#include "types/components/types.h"

int brute_force_click(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    NB_CLICK(app)++;
    button->scale += 0.10;
    return 0;
}
