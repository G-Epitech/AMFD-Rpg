/*
** EPITECH PROJECT, 2023
** buttons.c
** File description:
** Display progress bar components
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/display/display.h"
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "app/app.h"

void display_components_progresses(renderer_t *renderer, app_t *app)
{
    list_t *progresses = renderer->components->progresses;
    node_t *node = progresses->first;
    progress_t *progress = NULL;

    while (node) {
        progress = node->data.progress;
        if (progress->app_state == app->state)
            display_progress(progress, renderer, app);
        node = node->next;
    }
}
