/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** Free ressources
*/

#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"

void ressources_free(ressources_t *ressources)
{
    if (!ressources)
        return;
    maps_free(ressources->maps);
    skins_free(ressources->skins);
    list_free(ressources->props);
    if (ressources->profiles)
        sfTexture_destroy(ressources->profiles);
}
