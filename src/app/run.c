/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** @Hackers Quest 💻
** Main file
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/renderer.h"
#include "types/components/components.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "app/events/events.h"
#include "app/app.h"
#include "types/ressources/ressources.h"
#include "app/display/display.h"
#include "app/core/core.h"
#include "app/utils/utils.h"

int app_run(renderer_t *renderer, app_t *app)
{
    event_handler(renderer->objects->window, app, renderer);
    if (core_handler(renderer, app) == 84)
        return 84;
    sfRenderWindow_clear(renderer->window, sfBlack);
    core_handler(renderer, app);
    display_handle(renderer, app);
    return 0;
}
