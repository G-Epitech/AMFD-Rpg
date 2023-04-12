/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bruteforce/bruteforce.h"
#include "app/tasks/bruteforce/types.h"
#include "types/list/types.h"
#include "app/types.h"
#include "types/components/types.h"

int brute_force_released(renderer_t *renderer, app_t *app)
{
    list_t *buttons = renderer->components->buttons;
    node_t *node = buttons->first;
    button_t *button = NULL;

    while (node) {
        button = node->data.button;
        if (button->id == 1) {
            button->scale = 2;
            break;
        }
        node = node->next;
    }
    (void) app;
    return 0;
}
