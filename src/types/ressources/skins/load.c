/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load maps
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "app/loading/loading.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"
#include "app/loading/loading.h"

static void skins_append(list_t *skins, cjson_t *skin_config)
{
    node_t *node = NULL;
    skin_t skin = { 0, NULL };
    char *skin_file = NULL;

    skin.id = cjson_get_prop_int_unsafe(skin_config, "id");
    if (!cjson_get_prop_string(skin_config, "texture", &skin_file))
        return;
    skin.texture = sfTexture_createFromFile(skin_file, NULL);
    node = node_new((node_data_t) skin);
    if (node) {
        list_append(skins, node);
    } else if (skin.texture) {
        sfTexture_destroy(skin.texture);
    }
    free(skin_file);
}

void skins_load(renderer_t *renderer, list_t *skins)
{
    cjson_t *skins_config = cjson_parse_file(RESSOURCES_SKINS_CONFIG);
    cjson_array_t *array = NULL;
    cjson_t *skin = NULL;

    load_screen_add_bar(renderer, 4, "Chargement des ressources...",
    "Chargement des skins");
    if (!skins_config)
        return;
    if (!cjson_get_array(skins_config, &array)) {
        cjson_free(skins_config);
        return;
    }
    skin = array->first;
    while (skin) {
        skins_append(skins, skin);
        skin = skin->next;
    }
    cjson_free(skins_config);
}
