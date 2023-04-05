/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Load up components, ressources, view in renderer
*/

#include "types/renderer/types.h"
#include "app/loading/loading.h"
#include "types/components/components.h"
#include "types/ressources/ressources.h"
#include "types/view/view.h"

void load_renderer(renderer_t *renderer)
{
    loading_preload_screen(renderer);
    load_screen_text_display(renderer, "Loading  Ressources. . .");
    renderer->ressources = ressources_load();
    load_screen_text_display(renderer, "Loading  Components. . .");
    renderer->components = components_load(renderer);
    load_screen_text_display(renderer, "Initializing  View. . .");
    renderer->view = view_init();
}
