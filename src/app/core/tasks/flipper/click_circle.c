/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/flipper/flipper.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "types/list/list.h"

static float distance_click(renderer_t *renderer, node_t *temp_circle)
{
    sfVector2i pos_click = sfMouse_getPositionRenderWindow(renderer->window);
    sfVector2f pos_world =
    sfRenderWindow_mapPixelToCoords(renderer->objects->window, pos_click, NULL);
    sfVector2f pos;

    pos.x = POS_CIRCLE(temp_circle).x;
    pos.y = POS_CIRCLE(temp_circle).y;
    return sqrt(pow(pos_world.x - pos.x, 2) + pow(pos_world.y - pos.y, 2));
}

static bool test_click(renderer_t *renderer, node_t *temp_circle,
bool *good_click, task_t *node)
{
    if (distance_click(renderer, temp_circle) <= RAYON_CIRCLE(temp_circle)) {
        if (STATUS_CIRCLE(temp_circle) == OPEN) {
            (*good_click) = true;
            list_remove(LIST_CIRCLE(node), temp_circle);
            NB_CIRCLE_HIT(node)++;
        } else {
            list_remove(LIST_CIRCLE(node), temp_circle);
        }
        return true;
    }
    return false;
}

void event_task_flipper(renderer_t *renderer, app_t *app)
{
    task_t *node = find_task_node(app, 3);
    node_t *temp_circle = node->content.flipper.circles->first;
    bool good_click = false;

    while (temp_circle) {
        if (test_click(renderer, temp_circle, &good_click, node))
            break;
        temp_circle = temp_circle->next;
    }
    if (good_click == false)
        NB_LIFE_FLIPPER(node)--;
}