/*
** EPITECH PROJECT, 2023
** destroy.c
** File description:
** Destroy a renderer structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/renderer/renderer.h"
#include "types/ressources/ressources.h"

void renderer_destroy(renderer_t *renderer)
{
    renderer_objects_destroy(renderer->objects);
    ressources_free(renderer->ressources);
    free(renderer);
}
