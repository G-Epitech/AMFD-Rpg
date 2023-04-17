/*
** EPITECH PROJECT, 2023
** components.c
** File description:
** Display components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/types.h"
#include "types/list/types.h"

void display_components(renderer_t *renderer, app_t *app)
{
    display_components_backgrounds(renderer, app);
    display_components_buttons(renderer, app);
    display_components_levers(renderer, app);
    display_components_interaction(renderer, app);
    display_components_progresses(renderer, app);
}
