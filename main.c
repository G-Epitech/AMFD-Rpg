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

int main(void)
{
    renderer_t *renderer = renderer_init();
    components_t *components = components_load();
    ressources_t *ressources = ressources_load();
    sfEvent event;

    while (sfRenderWindow_isOpen(renderer->window)) {
        event_handle(renderer->window, event);
        sfRenderWindow_clear(renderer->window, sfBlack);
    }
    renderer_destroy(renderer);
    return 0;
}
