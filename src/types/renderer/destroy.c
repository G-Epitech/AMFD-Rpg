/*
** EPITECH PROJECT, 2023
** destroy.c
** File description:
** Destroy a renderer structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "types/ressources/ressources.h"

void renderer_destroy(renderer_t *renderer)
{
    sfSprite_destroy(renderer->sprite);
    sfRectangleShape_destroy(renderer->rectangle);
    sfCircleShape_destroy(renderer->circle);
    sfText_destroy(renderer->text);
    sfRenderWindow_close(renderer->window);
    sfView_destroy(renderer->view);
    sfFont_destroy(renderer->font);
    ressources_free(renderer->ressources);
    free(renderer);
}
