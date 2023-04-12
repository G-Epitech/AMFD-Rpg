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

static void icons_load_data(icons_r_t *icons, cjson_t *configs)
{
    char *valid = cjson_get_prop_string_unsafe(configs, "valid");
    char *refuse = cjson_get_prop_string_unsafe(configs, "refuse");

    icons->valid = sfTexture_createFromFile(valid, NULL);
    icons->refuse = sfTexture_createFromFile(refuse, NULL);
    free(valid);
    free(refuse);
}

void icons_load(renderer_t *renderer, icons_r_t *icons)
{
    cjson_t *configs = cjson_parse_file(RESSOURCES_ICONS_CONFIG);

    load_screen_add_bar(renderer, 7, "Chargement des ressources...",
    "Chargement des icones");
    if (!icons || !configs)
        return;
    icons_load_data(icons, configs);
}
