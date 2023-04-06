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
    sfText_setCharacterSize(objects->text, 30 * button->scale);
    rect = sfText_getGlobalBounds(objects->text);
    sfText_setPosition(objects->text, (sfVector2f) {button->position.x +
    (40 * button->scale), (button->position.y + (button->scale * 132 / 2))
    - rect.height / 2});
    total = ((80 * button->scale) + rect.width) - (40 * button->scale);
    return total / sfTexture_getSize(ressources->button->middle).x;
}

static sfVector2f get_rect_scale(button_t *button, renderer_t *renderer)
{
    float text_scale = setup_text(button, renderer);
    components_r_t *ressources = renderer->ressources->components;
    sfVector2u middle = sfTexture_getSize(ressources->button->middle);
    sfVector2f rect_scale = {0, 0};

    if (!button->texture) {
        rect_scale.x = text_scale * middle.x + 15 * button->scale;
        rect_scale.y = button->scale * 132;
    } else {
        rect_scale.x = button->scale * sfTexture_getSize(button->texture).x;
        rect_scale.y = button->scale * sfTexture_getSize(button->texture).y;
    }
    return rect_scale;
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

static void button_get_extra(cjson_t *config, button_t *button)
{
    char *texture = NULL;
    int event = -1;

    button_cjson_color(config, &button->color, "color");
    button_cjson_color(config, &button->text_color, "color_text");
    cjson_get_prop_string(config, "title", &button->title);
    cjson_get_prop_string(config, "description", &button->description);
    cjson_get_prop_float(config, "scale", &button->scale);
    cjson_get_prop_int(config, "event", &event);
    button->event = event;
    if (!cjson_get_prop_string(config, "icon", &texture))
        return;
    button->texture = sfTexture_createFromFile(texture, NULL);
    free(texture);
}

void buttons_load(renderer_t *renderer, components_t *components,
cjson_array_t *buttons)
{
    cjson_t *button = buttons->first;
    sfVector2f position = {0, 0};
    cjson_array_t *array = NULL;
    app_states_t *state = NULL;
    button_t *data = NULL;
    size_t len = 0;

    while (button) {
        position = cjson_vector(button);
        array = cjson_get_prop_array_unsafe(button, "app_state");
        state = (app_states_t *) cjson_array_to_int_array(array, &len);
        data = buttons_append(components->buttons, position, state);
        if (!data)
            return;
        data->state_size = len;
        button_get_extra(button, data);
        data->rect_scale = get_rect_scale(data, renderer);
        button = button->next;
    }
}
