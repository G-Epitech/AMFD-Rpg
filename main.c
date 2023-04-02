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
#include "types/ressources/ressources.h"
#include "app/display/display.h"

int main(void)
{
    renderer_t *renderer = renderer_init();
    sfEvent event;
    app_t app = {ST_INGAME, WL_VILLAGE};

    while (sfRenderWindow_isOpen(renderer->window)) {
        event_handle(renderer->window, event);
        sfRenderWindow_clear(renderer->window, sfBlack);
        display_handle(renderer, &app);
    }
    renderer_destroy(renderer);
    return 0;
}
