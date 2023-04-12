/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** Display buttons components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "app/app.h"

void display_buttons_dispatch(button_t *button, renderer_t *renderer)
{
    if (!button->texture) {
        display_button(button, renderer);
    } else {
        display_components_icon(renderer, button);
    }
}
