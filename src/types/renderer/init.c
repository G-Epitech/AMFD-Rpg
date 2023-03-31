/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init renderer structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "app/window/window.h"
#include "types/renderer/types.h"

renderer_t *renderer_init(void)
{
    renderer_t *renderer = malloc(sizeof(renderer_t));

    if (!renderer)
        return NULL;
    renderer->sprite = sfSprite_create();
    renderer->rectangle = sfRectangleShape_create();
    renderer->circle = sfCircleShape_create();
    renderer->text = sfText_create();
    renderer->window = window_init();
    return renderer;
}
