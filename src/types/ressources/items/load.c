/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** items
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/ressources/types.h"
#include "app/loading/loading.h"
#include "cjson/include/cjson.h"

void items_texture_load(renderer_t *renderer, ressources_t *ressources)
{
    cjson_t *config = cjson_parse_file(ITEMS_CONFIG);
    char *path = cjson_get_prop_string_unsafe(config, "texture");
    sfTexture *items = NULL;

    load_screen_add_bar(renderer, 4, "Chargement des ressources...",
    "Chargement des objets");
    if (path)
        items = sfTexture_createFromFile(path, NULL);
    else
        items = sfTexture_create(1920, 1080);
    if (items)
        ressources->items = items;
    free(path);
    cjson_free(config);
}
