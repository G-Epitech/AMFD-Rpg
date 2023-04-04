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
#include "app/loading/loading.h"

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
    loading_preload_screen(renderer);
    load_screen_text_display(renderer, "Loading  Components. . .");
    renderer->components = components_load();
    load_screen_text_display(renderer, "Loading  Ressources. . .");
    renderer->ressources = ressources_load();
    load_screen_text_display(renderer, "Initializing  View. . .");
    renderer->view = view_init();
    return renderer;
}
