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

ressources_t *ressources_load(void)
{
    ressources_t *ressources = ressources_init();

    if (!ressources)
        return NULL;
    maps_load(ressources->maps);
    return ressources;
}
