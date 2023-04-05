/*
** EPITECH PROJECT, 2023
** handle.c
** File description:
** Handle events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/events/events.h"
#include "app/tasks/bash/script_bash.h"
#include "app/app.h"

static void event_analyse(sfRenderWindow *window, sfEvent event, app_t *app)
{
    if (event.type == sfEvtClosed) {
        event_window_close(window);
    }
    if (event.type == sfEvtKeyPressed) {
        if (app->state == ST_TASK_BASH) {
            cmd_write(event, app);
            good_or_bad_result(event, app);
        }
        if (app->state == ST_INGAME)
            keyboard_move(event, app);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
        sfVector2f wolrd_pos = sfRenderWindow_mapPixelToCoords(window, mouse_pos, NULL);
        printf("clicked on x = [%f] | [%f] = y\n", wolrd_pos.x, wolrd_pos.y);
        fflush(stdout);
        app->state = ST_TASK_BASH;
    }
}

void event_handle(sfRenderWindow *window, sfEvent event, app_t *app)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        event_analyse(window, event, app);
    }
}
