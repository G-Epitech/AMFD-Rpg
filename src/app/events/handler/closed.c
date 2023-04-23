/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "app/saving/saving.h"
#include "app/events/events.h"

void event_close(sfRenderWindow *window, sfEvent event, app_t *app)
{
    if (event.type != sfEvtClosed)
        return;
    if (save_ask_on_exit(app, window))
        return;
    event_window_close(window);
}
