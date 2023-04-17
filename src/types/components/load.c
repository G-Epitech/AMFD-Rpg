/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load all components
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/components/types.h"
#include "types/components/components.h"
#include "types/list/types.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"

components_t *components_init(void)
{
    components_t *components = malloc(sizeof(components_t));

    if (!components)
        return NULL;
    components->buttons = list_new();
    components->levers = list_new();
    components->progresses = list_new();
    return components;
}

components_t *components_load(renderer_t *renderer)
{
    components_t *components = components_init();
    cjson_t *config = cjson_parse_file(COMPONENTS_CONFIG);
    cjson_array_t *buttons = NULL;
    cjson_array_t *levers = NULL;
    cjson_array_t *progresses = NULL;

    if (!components)
        return NULL;
    if (!cjson_get_prop_array(config, "buttons", &buttons))
        return NULL;
    if (!cjson_get_prop_array(config, "levers", &levers))
        return NULL;
    if (!cjson_get_prop_array(config, "progresses", &progresses))
        return NULL;
    buttons_load(renderer, components, buttons);
    levers_load(components, levers);
    progresses_load(components, progresses);
    cjson_free(config);
    return components;
}
