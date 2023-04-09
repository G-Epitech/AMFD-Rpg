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
    load_screen_add_bar(renderer, 1, "Chargement des ressources...", "");
    renderer->ressources = ressources_load(renderer);
    load_screen_add_bar(renderer, 1, "Chargement des composants...",
    "Composants de l'interface en cours de chargement");
    renderer->components = components_load(renderer);
    load_screen_add_bar(renderer, 4, "Initialisation de la vue...",
    "Definition vue joueur");
    renderer->map_view = view_init();
    load_screen_add_bar(renderer, 6, "Lancement...",
    "Jeu en cours de lancement");
}
