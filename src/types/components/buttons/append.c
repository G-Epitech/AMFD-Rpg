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

button_t *buttons_append(list_t *list, sfVector2f position,
app_states_t app_state)
{
    node_data_t data;
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    data.button = button;
    button->color = sfBlack;
    button->position = position;
    button->scale = 1.0;
    button->state = ST_BTN_INACTIVE;
    button->app_state = app_state;
    button->title = NULL;
    button->description = NULL;
    button->texture = NULL;
    list_append(list, node_new(data));
    return button;
}
