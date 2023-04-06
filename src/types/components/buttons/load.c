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

static float setup_text(button_t *button, renderer_t *renderer)
{
    components_r_t *ressources = renderer->ressources->components;
    renderer_objects_t *objects = renderer->objects;
    sfFloatRect rect = {0, 0, 0, 0};
    float total = 0;

    sfText_setString(objects->text, button->title);
    sfText_setFont(objects->text, renderer->font);
    sfText_setColor(objects->text, button->text_color);
    sfText_setCharacterSize(objects->text, 25 * button->scale);
    rect = sfText_getGlobalBounds(objects->text);
    sfText_setPosition(objects->text, (sfVector2f) {button->position.x +
    (25 * button->scale), (button->position.y + (button->scale * 152 / 2))
    - rect.height / 2});
    total = ((50 * button->scale) + rect.width) - (40 * button->scale);
    return total / sfTexture_getSize(ressources->button->middle).x;
}

static sfVector2f get_rect_scale(button_t *button, renderer_t *renderer)
{
    float text_scale = setup_text(button, renderer);
    components_r_t *ressources = renderer->ressources->components;
    sfVector2u middle = sfTexture_getSize(ressources->button->middle);
    sfVector2f rect_scale = {0, 0};

    rect_scale.x = text_scale * middle.x + 15 * button->scale;
    rect_scale.y = button->scale * 152;
    return rect_scale;
}

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

static void button_cjson_color(cjson_t *config, sfColor *color, char *key)
{
    cjson_t *color_prop = NULL;

    color_prop = cjson_get_prop(config, key);
    if (!color_prop)
        return;
    color->r = cjson_get_prop_int_unsafe(color_prop, "r");
    color->g = cjson_get_prop_int_unsafe(color_prop, "g");
    color->b = cjson_get_prop_int_unsafe(color_prop, "b");
    color->a = cjson_get_prop_int_unsafe(color_prop, "a");
}

void buttons_load(renderer_t *renderer, components_t *components,
cjson_array_t *buttons)
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
        button_cjson_color(button, &data->color, "color");
        button_cjson_color(button, &data->text_color, "color_text");
        cjson_get_prop_string(button, "title", &data->title);
        cjson_get_prop_string(button, "description", &data->description);
        cjson_get_prop_float(button, "scale", &data->scale);
        data->rect_scale = get_rect_scale(data, renderer);
        button = button->next;
    }
}
