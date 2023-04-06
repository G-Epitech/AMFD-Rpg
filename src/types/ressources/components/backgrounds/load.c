/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load backgrounds textures
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/list/types.h"
#include "types/list/list.h"
#include "types/ressources/types.h"
#include "types/ressources/ressources.h"
#include "types/players/types.h"
#include "cjson/include/cjson.h"

static sfVector2f cjson_vector(cjson_t *config)
{
    cjson_t *position_prop = NULL;
    sfVector2f position = {0, 0};

    position_prop = cjson_get_prop(config, "position");
    if (!position_prop)
        return position;
    position.x = cjson_get_prop_float_unsafe(position_prop, "x");
    position.y = cjson_get_prop_float_unsafe(position_prop, "y");
    return position;
}

background_t *background_load(cjson_t *config)
{
    background_t *background = malloc(sizeof(background_t));
    cjson_array_t *array = NULL;
    char *texture = NULL;

    if (!background)
        return NULL;
    cjson_get_prop_string(config, "asset", &texture);
    background->texture = sfTexture_createFromFile(texture, NULL);
    background->scale = cjson_get_prop_float_unsafe(config, "scale");
    array = cjson_get_prop_array_unsafe(config, "state");
    background->app_state = (app_states_t *) cjson_array_to_int_array(array,
    &background->state_size);
    background->position = cjson_vector(config);
    return background;
}

list_t *ressources_components_backgrounds_load(cjson_array_t
*backgrounds_config)
{
    node_data_t data;
    cjson_t *background = backgrounds_config->first;
    list_t *backgrounds = list_new();
    node_t *node = NULL;

    if (!backgrounds)
        return NULL;
    while (background) {
        data.background = background_load(background);
        node = node_new(data);
        list_append(backgrounds, node);
        background = background->next;
    }
    return backgrounds;
}
