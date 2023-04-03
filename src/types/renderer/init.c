/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init renderer structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/view/view.h"
#include "app/window/window.h"
#include "types/renderer/types.h"
#include "types/components/components.h"
#include "types/ressources/ressources.h"
#include "types/renderer/renderer.h"

renderer_t *renderer_init(void)
{
    renderer_t *renderer = malloc(sizeof(renderer_t));

    if (!renderer)
        return NULL;
    renderer->window = window_init();
    renderer->objects = renderer_objects_init(renderer->window);
    renderer->components = components_load();
    renderer->ressources = ressources_load();
    return renderer;
}
