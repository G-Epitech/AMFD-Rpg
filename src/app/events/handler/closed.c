/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/events/events.h"
#include "app/tasks/bash/script_bash.h"
#include "app/app.h"

void event_close(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        event_window_close(window);
    }
}
