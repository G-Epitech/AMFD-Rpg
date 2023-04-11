/*
** EPITECH PROJECT, 2023
** switch.c
** File description:
** Check if app is on a speicific state
*/

#include <stdio.h>
#include <stdbool.h>
#include "app/types.h"
#include "types/renderer/types.h"

int states_switch_left(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    app->state--;
    return 0;
}

int states_switch_right(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) renderer;
    (void) button;
    app->state++;
    return 0;
}
