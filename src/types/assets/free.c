/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** Free assets
*/

#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/assets/types.h"
#include "types/assets/assets.h"

void assets_free(assets_t *assets)
{
    if (!assets)
        return;
    maps_free_data(assets->maps);
    list_free(assets->maps);
    list_free(assets->props);
    list_free(assets->skins);
}
