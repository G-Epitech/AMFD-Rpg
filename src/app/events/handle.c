/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/events/events.h"

static void event_analyse(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        event_window_close(window);
    }
}

void event_handle(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        event_analyse(window, event);
    }
}
