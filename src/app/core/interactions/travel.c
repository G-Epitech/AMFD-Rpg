/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Functions for travelling throughout maps
*/

#include <stdbool.h>
#include <stdio.h>
#include "app/app.h"
#include "app/core/core.h"
#include "app/travel/travel.h"

void core_interactions_travel(sfColor pixel, app_t *app)
{
    if (core_interaction_detect_color(pixel, EXIT_COLOR) == true)
        travel_exit(app);
}