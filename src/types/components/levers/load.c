/*
** EPITECH PROJECT, 2023
** load.c
** File description:
** Load buttons
*/

#include <stdio.h>
#include <stdlib.h>
#include "types/components/types.h"
#include "types/components/components.h"
#include "types/list/types.h"
#include "types/list/list.h"
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

void levers_load(components_t *components, cjson_array_t *levers)
{
    cjson_t *lever = levers->first;
    sfVector2f position = {0, 0};
    app_states_t state = 0;
    lever_t *data = NULL;

    while (lever) {
        position = cjson_vector(lever);
        state = cjson_get_prop_int_unsafe(lever, "app_state");
        data = levers_append(components->buttons, position, state);
        if (!data)
            return;
        cjson_get_prop_float(lever, "scale", &data->scale);
        lever = lever->next;
    }
}
