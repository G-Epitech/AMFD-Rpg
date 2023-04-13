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
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/flipper/flipper.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "types/list/list.h"

void circle_expension(app_t *app)
{
    task_t *node = find_task_node(app, 3);
    node_t *temp_circle = node->content.flipper.circles->first;

    while (temp_circle) {
        RAYON_CIRCLE(temp_circle) += 3;
        temp_circle = temp_circle->next;
    }
}

static void test_open(node_t *temp_circle, int time_int)
{
    int luck = 0;

    if (TIME_CREATION(temp_circle) + 1 < time_int) {
        srand(time(NULL));
        luck = rand() % 10;
        if (luck != 2) {
            STATUS_CIRCLE(temp_circle) = OPEN;
            TIME_CREATION(temp_circle) = time_int;
        }
    }
}

void open_circle(app_t *app, int time_int)
{
    task_t *node = find_task_node(app, 3);
    node_t *temp_circle = node->content.flipper.circles->first;

    while (temp_circle) {
        if (STATUS_CIRCLE(temp_circle) == CLOSE) {
            test_open(temp_circle, time_int);
        }
        temp_circle = temp_circle->next;
    }
}

static void test_time_out(node_t *temp_circle, int time_int, app_t *app)
{
    task_t *node = find_task_node(app, 3);

    if (TIME_CREATION(temp_circle) + 2 < time_int) {
        list_remove(LIST_CIRCLE(node), temp_circle);
        NB_LIFE_FLIPPER(node)--;
    }
}

void life_loose(app_t *app, int time_int)
{
    task_t *node = find_task_node(app, 3);
    node_t *temp_circle = node->content.flipper.circles->first;

    while (temp_circle) {
        if (STATUS_CIRCLE(temp_circle) == OPEN) {
            test_time_out(temp_circle, time_int, app);
        }
        temp_circle = temp_circle->next;
    }
}
