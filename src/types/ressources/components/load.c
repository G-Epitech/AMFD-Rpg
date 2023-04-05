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
#include "types/players/types.h"
#include "cjson/include/cjson.h"

void ressources_components_load(components_r_t *components)
{
    cjson_t *cmp_config = cjson_parse_file(RESSOURCES_COMPONENTS_CONFIG);
    cjson_t *button_config = cjson_get_prop(cmp_config, "button");

    if (!cmp_config || !button_config) {
        cjson_free(cmp_config);
        return;
    }
    components->button = ressources_components_button_load(button_config);
    cjson_free(cmp_config);
}