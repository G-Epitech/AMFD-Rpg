/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** @Hackers Quest 💻
** Main file
*/

#include <stdio.h>
#include "types/renderer/renderer.h"
#include "types/components/components.h"
#include "types/list/types.h"
#include "my/include/my.h"

int main(void)
{
    renderer_t *renderer = renderer_init();
    components_t *components = components_load();

    while (sfRenderWindow_isOpen(renderer->window)) {
        sfRenderWindow_clear(renderer->window, sfBlack);
    }
    renderer_destroy(renderer);
    return 0;
}
