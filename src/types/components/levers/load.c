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

void levers_load(components_t *components, cjson_array_t *levers)
{
    cjson_t *lever = levers->first;
    sfVector2f position = {0, 0};
    app_states_t state = ST_LOADING;
    lever_t *data = NULL;

    while (lever) {
        position = cjson_vector(lever);
        state = cjson_get_prop_int_unsafe(lever, "app_state");
        data = levers_append(components->levers, position, state);
        if (!data)
            return;
        cjson_get_prop_float(lever, "scale", &data->scale);
        cjson_get_prop_int(lever, "event", &data->event);
        lever = lever->next;
    }
}
