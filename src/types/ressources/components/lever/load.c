/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load button ressources
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static void load_textures(lever_r_t *lever, char *on, char *off)
{
    lever->on = sfTexture_createFromFile(on, NULL);
    lever->off = sfTexture_createFromFile(off, NULL);
}

lever_r_t *ressources_components_lever_load(cjson_t *lever_config)
{
    lever_r_t *lever = malloc(sizeof(lever_r_t));
    char *on = NULL;
    char *off = NULL;

    if (!lever)
        return NULL;
    cjson_get_prop_string(lever_config, "on", &on);
    cjson_get_prop_string(lever_config, "off", &off);
    if (!on || !off) {
        free(on);
        free(off);
        free(lever);
        return NULL;
    }
    load_textures(lever, on, off);
    return lever;
}
