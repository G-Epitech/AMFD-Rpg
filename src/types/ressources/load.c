/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load ressources
*/

#include <stdlib.h>
#include <stdio.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"

static void free_list(ressources_t *ressources)
{
    list_free(ressources->maps);
    list_free(ressources->skins);
    list_free(ressources->props);
}

ressources_t *ressources_init(void)
{
    ressources_t *ressources = malloc(sizeof(ressources_t));

    if (!ressources)
        return NULL;
    ressources->maps = list_new();
    ressources->skins = list_new();
    ressources->props = list_new();
    ressources->animations = list_new();
    ressources->inventory = malloc(sizeof(inventory_r_t));
    ressources->icons = malloc(sizeof(icons_r_t));
    ressources->icons->tree = malloc(sizeof(icons_competences_t));
    if (!ressources->maps || !ressources->skins || !ressources->props ||
    !ressources->inventory || !ressources->icons || !ressources->icons->tree) {
        free_list(ressources);
        free(ressources->inventory);
        free(ressources->icons);
        return NULL;
    }
    return ressources;
}

ressources_t *ressources_load(renderer_t *renderer)
{
    ressources_t *ressources = ressources_init();

    ressources->components = ressources_components_init(renderer);
    if (!ressources || !ressources->components) {
        ressources_free(ressources);
        return NULL;
    }
    maps_load(ressources->maps, renderer);
    skins_load(renderer, ressources->skins);
    items_texture_load(renderer, ressources);
    inventory_load(renderer, ressources->inventory);
    ressources_components_load(renderer, ressources->components);
    icons_load(renderer, ressources->icons);
    animations_load(renderer, ressources->animations);
    ressources->clock = sfClock_create();
    ressources->elapsed_time = 0.0;
    return ressources;
}
