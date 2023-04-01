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

static void buttons_append_data(button_t *button, node_t *node,
sfVector2f position, app_states_t app_state)
{
    node->data.button = button;
    button->color = sfBlack;
    button->position = position;
    button->scale = 1.0;
    button->state = ST_BTN_INACTIVE;
    button->app_state = app_state;
    button->title = NULL;
    button->description = NULL;
    button->texture = NULL;
}

button_t *buttons_append(list_t *list, sfVector2f position,
app_states_t app_state)
{
    node_data_t data;
    node_t *node = node_new(data);
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    if (!node) {
        free(button);
        return NULL;
    }
    buttons_append_data(button, node, position, app_state);
    list_append(list, node);
    return button;
}
