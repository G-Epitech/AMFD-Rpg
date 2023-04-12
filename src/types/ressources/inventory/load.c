/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** load
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "app/loading/loading.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static sfTexture *inventory_load_grid(cjson_t *config, renderer_t *renderer)
{
    char *texture_path = NULL;
    sfTexture *texture = NULL;

    load_screen_add_bar(renderer, 5, "Chargement des ressources...",
    "Chargement de la grille d'inventaire");
    if (cjson_get_prop_string(config, "grid", &texture_path))
        texture = sfTexture_createFromFile(texture_path, NULL);
    return texture;
}

void inventory_load(renderer_t *renderer, inventory_r_t *inventory)
{
    cjson_t *config = NULL;

    load_screen_add_bar(renderer, 5, "Chargement des ressources...",
    "Chargement de l'inventaire");
    config = cjson_parse_file(RESSOURCES_INVENTORY_CONFIG);
    if (!inventory || !config)
        return cjson_free(config);
    inventory->items = NULL;
    inventory->grid = inventory_load_grid(config, renderer);
}
