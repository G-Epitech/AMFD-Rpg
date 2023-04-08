/*
** EPITECH PROJECT, 2023
** append.c
** File description:
** Append a new button to a list of buttons
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "types/components/types.h"
#include "types/list/types.h"
#include "types/list/list.h"

static node_data_t buttons_append_data(button_t *button, sfVector2f position,
app_states_t *app_state)
{
    node_data_t data;

    data.button = button;
    button->color = sfBlack;
    button->text_color = sfBlack;
    button->position = position;
    button->scale = 1.0;
    button->state = ST_BTN_INACTIVE;
    button->app_state = app_state;
    button->title = NULL;
    button->description = NULL;
    button->texture = NULL;
    button->event = 0;
    button->rect_scale = (sfVector2f) {1, 1};
    button->next_state = 0;
    button->always_display = false;
    button->developer = false;
    return data;
}

button_t *buttons_append(list_t *list, sfVector2f position,
app_states_t *app_state)
{
    node_data_t data;
    node_t *node = NULL;
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    data = buttons_append_data(button, position, app_state);
    node = node_new(data);
    if (!node) {
        free(button);
        return NULL;
    }
    list_append(list, node);
    return button;
}
