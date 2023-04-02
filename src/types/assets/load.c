/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load assets
*/

#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/assets/types.h"
#include "types/assets/assets.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

assets_t *assets_init(void)
{
    assets_t *assets = malloc(sizeof(assets_t));

    if (!assets)
        return NULL;
    assets->maps = list_new();
    assets->skins = list_new();
    assets->props = list_new();
    if (!assets->maps || !assets->skins || !assets->props) {
        list_free(assets->maps);
        list_free(assets->skins);
        list_free(assets->props);
        return NULL;
    }
    return assets;
}

assets_t *assets_load(void)
{
    assets_t *assets = assets_init();

    if (!assets)
        return NULL;
    maps_load(assets->maps);
    return assets;
}
