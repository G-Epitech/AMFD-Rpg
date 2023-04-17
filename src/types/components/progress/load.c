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
#include "types/renderer/types.h"
#include "types/list/types.h"
#include "types/list/list.h"
#include "cjson/include/cjson.h"


static void progress_load(list_t *progresses, cjson_t *progress)
{
    progress_t *data = malloc(sizeof(progress_t));
    node_t *node = NULL;
    cjson_array_t *array = NULL;
    size_t len = 0;

    if (!data)
        return;
    cjson_get_prop_array(progress, "app_state", &array);
    data->app_state = (app_states_t *) cjson_array_to_int_array(array, &len);
    data->state_size = len;
    cjson_get_prop_int(progress, "color", (int *) &data->color);
    cjson_get_prop_int(progress, "getter_value", &data->getter_value);
    data->size = cjson_vector(progress, "size");
    data->position = cjson_vector(progress, "position");
    node = node_new((node_data_t) data);
    if (!node)
        free(data);
    else
        list_append(progresses, node);
}

void progresses_load(components_t *components, cjson_array_t *progresses)
{
    cjson_t *progress = progresses ? progresses->first : NULL;

    while (progress) {
        progress_load(components->progresses, progress);
        progress = progress->next;
    }
}
