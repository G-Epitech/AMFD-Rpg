/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load components ressources
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

void ressources_components_load(renderer_t *renderer,
components_r_t *components)
{
    cjson_t *cmp_config = cjson_parse_file(RESSOURCES_COMPONENTS_CONFIG);
    cjson_t *button_config = cjson_get_prop(cmp_config, "button");
    cjson_t *lever_config = cjson_get_prop(cmp_config, "lever");
    cjson_array_t *backgrounds_config = cjson_get_prop_array_unsafe(
    cmp_config, "backgrounds");

    load_screen_add_bar(renderer, 6, "Chargement des ressources...",
    "Chargement des composents");
    if (!cmp_config || !button_config || !backgrounds_config)
        return cjson_free(cmp_config);
    components->button = ressources_components_button_load(button_config);
    components->lever = ressources_components_lever_load(lever_config);
    components->backgrounds = ressources_components_backgrounds_load
    (backgrounds_config);
    cjson_free(cmp_config);
}
