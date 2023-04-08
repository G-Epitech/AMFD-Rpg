/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init renderer structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/view/view.h"
#include "app/window/window.h"
#include "app/loading/loading.h"
#include "types/renderer/types.h"
#include "types/renderer/renderer.h"
#include "types/components/components.h"
#include "types/ressources/ressources.h"

renderer_t *renderer_init(void)
{
    renderer_t *renderer = malloc(sizeof(renderer_t));

    if (!renderer)
        return NULL;
    renderer->window = window_init(false);
    renderer->objects = renderer_objects_init(renderer->window);
    renderer->components = NULL;
    renderer->ressources = NULL;
    renderer->map_view = NULL;
    renderer->font = sfFont_createFromFile(FONT_FILE);
    renderer->default_view = sfRenderWindow_getDefaultView(renderer->window);
    return renderer;
}
