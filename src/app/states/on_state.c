/*
** EPITECH PROJECT, 2023
** state.c
** File description:
** Check if app is on a speicific state
*/

#include <stdio.h>
#include <stdbool.h>
#include "app/types.h"

bool app_on_state(app_t *app, app_states_t *states, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (states[i] == app->state)
            return true;
    }
    return false;
}
