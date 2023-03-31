/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** @Hackers Quest 💻
** Main file
*/

#include "types/renderer/renderer.h"
#include "my.h"

int main(void)
{
    renderer_t *renderer = renderer_init();

    while (sfRenderWindow_isOpen(renderer->window)) {
        sfRenderWindow_clear(renderer->window, sfBlack);
    }
    renderer_destroy(renderer);
    return 0;
}
