/*
** EPITECH PROJECT, 2023
** close.c
** File description:
** Close window
*/

#include <SFML/Window.h>
#include "app/types.h"
#include "types/renderer/types.h"

int window_close(renderer_t *renderer, app_t *app, button_t *button)
{
    (void) button;
    (void) app;
    sfRenderWindow_close(renderer->window);
    return 0;
}
