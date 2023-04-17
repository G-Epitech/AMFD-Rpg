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

static void icons_load_data_check(icons_r_t *icons, cjson_t *configs)
{
    char *valid = cjson_get_prop_string_unsafe(configs, "valid");
    char *refuse = cjson_get_prop_string_unsafe(configs, "refuse");

    icons->valid = sfTexture_createFromFile(valid, NULL);
    icons->refuse = sfTexture_createFromFile(refuse, NULL);
    free(valid);
    free(refuse);
}

static void icons_load_data(icons_r_t *icons, cjson_t *configs)
{
    char *lock = cjson_get_prop_string_unsafe(configs, "attack_lock");
    char *selector_true = cjson_get_prop_string_unsafe(configs,
    "selector_true");
    char *selector_false = cjson_get_prop_string_unsafe(configs,
    "selector_false");
    char *interaction = cjson_get_prop_string_unsafe(configs,
    "interaction");

    icons->attack_lock = sfTexture_createFromFile(lock, NULL);
    icons->selector_true = sfTexture_createFromFile(selector_true, NULL);
    icons->selector_false = sfTexture_createFromFile(selector_false, NULL);
    icons->interaction = sfTexture_createFromFile(interaction, NULL);
    free(lock);
    free(selector_true);
    free(selector_false);
    free(interaction);
    icons_load_data_check(icons, configs);
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
