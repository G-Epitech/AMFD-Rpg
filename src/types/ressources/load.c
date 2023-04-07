/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load ressources
*/

#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"

ressources_t *ressources_init(void)
{
    ressources_t *ressources = malloc(sizeof(ressources_t));

    if (!ressources)
        return NULL;
    ressources->maps = list_new();
    ressources->skins = list_new();
    ressources->props = list_new();
    if (!ressources->maps || !ressources->skins || !ressources->props) {
        list_free(ressources->maps);
        list_free(ressources->skins);
        list_free(ressources->props);
        return NULL;
    }
    return ressources;
}

ressources_t *ressources_load(renderer_t *renderer)
{
    ressources_t *ressources = ressources_init();

    load_screen_add_bar(renderer, 1, "Chargement  Ressources. . .",
    "Initialisation des ressources");
    ressources->components = ressources_components_init();
    if (!ressources || !ressources->components) {
        ressources_free(ressources);
        return NULL;
    }
    load_screen_add_bar(renderer, 2, "Chargement Ressources. . .",
    "Chargement des maps");
    maps_load(ressources->maps, renderer);
    load_screen_add_bar(renderer, 4, "Chargement Ressources. . .",
    "Chargement des skins");
    skins_load(ressources->skins);
    load_screen_add_bar(renderer, 6, "Chargement Ressources. . .",
    "Chargement des composents");
    ressources_components_load(ressources->components);
    return ressources;
}
