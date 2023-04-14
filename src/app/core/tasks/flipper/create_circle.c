/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <sys/time.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/flipper/flipper.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "types/list/list.h"


static void init_circle_stat(node_t *circle, int time_int)
{
    sfVector2f pos = {0, 0};

    circle->data.node_flip->rayon = 1 + rand() % 10;
    circle->data.node_flip->status = CLOSE;
    circle->data.node_flip->time_creation = time_int;
    circle->data.node_flip->time_open = 0;
    pos.x = 460 + rand() % 970;
    pos.y = 305 + rand() % 535;
    circle->data.node_flip->pos = pos;
}

static int create_circle(app_t *app, int time_int)
{
    node_t *circle = NULL;
    node_data_t data_circle;
    task_flipper_node_t *circle_node = malloc(sizeof(task_flipper_node_t));
    task_t *node = find_task_node(app, 3);

    if (!circle_node)
        return 84;
    data_circle.node_flip = circle_node;
    circle = node_new(data_circle);
    if (!circle)
        return 84;
    init_circle_stat(circle, time_int);
    list_append(LIST_CIRCLE(node), circle);
    NB_CIRCLE_CREATE(node)++;
    return 0;
}

int handler_create_circle(int time_int, app_t *app,
int pres_mili_int, int time_mili_int)
{
    srand(rand() % RANDOM_NUMBER);
    if (pres_mili_int < time_mili_int && time_mili_int % 5 == 0) {
        if (create_circle(app, time_int) == 84)
            return 84;
    }
    return 0;
}
