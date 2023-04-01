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

static void button_cjson_color(cjson_t *config, button_t *data)
{
    cjson_t *color_prop = NULL;
    sfColor color = {0, 0, 0, 0};

    color_prop = cjson_get_prop(config, "color");
    if (!color_prop)
        return;
    color.r = cjson_get_prop_int_unsafe(color_prop, "r");
    color.g = cjson_get_prop_int_unsafe(color_prop, "g");
    color.b = cjson_get_prop_int_unsafe(color_prop, "b");
    color.a = cjson_get_prop_int_unsafe(color_prop, "a");
    data->color = color;
}

void buttons_load(components_t *components, cjson_array_t *buttons)
{
    cjson_t *button = buttons->first;
    sfVector2f position = {0, 0};
    app_states_t state = ST_LOADING;
    button_t *data = NULL;

    while (button) {
        position = cjson_vector(button);
        state = cjson_get_prop_int_unsafe(button, "app_state");
        data = buttons_append(components->buttons, position, state);
        if (!data)
            return;
        button_cjson_color(button, data);
        cjson_get_prop_string(button, "title", &data->title);
        cjson_get_prop_string(button, "description", &data->description);
        cjson_get_prop_float(button, "scale", &data->scale);
        button = button->next;
    }
}
