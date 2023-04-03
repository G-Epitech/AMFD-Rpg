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

int main(void)
{
    renderer_t *renderer = renderer_init();
    sfEvent event;
    app_t *app = app_init();

    if (!renderer)
        return 84;
    if (!app) {
        renderer_destroy(renderer);
        return 84;
    }
    while (sfRenderWindow_isOpen(renderer->objects.window)) {
        event_handle(renderer->window, event, app);
        sfRenderWindow_clear(renderer->window, sfBlack);
        display_handle(renderer, app);
    }
    renderer_destroy(renderer);
    return 0;
}
