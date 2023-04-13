/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdlib.h>
#include <time.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "types/list/types.h"
#include "app/tasks/flipper/flipper.h"
#include "types/list/list.h"
#include "my/include/my.h"

static void clear_list(app_t *app)
{
    task_t *node = find_task_node(app, 3);
    node_t *temp_circle = node->content.flipper.circles->first;
    node_t *temp_next = NULL;

    while (temp_circle) {
        temp_next = temp_circle->next;
        list_delete(LIST_CIRCLE(node), temp_circle);
        temp_circle = temp_next;
    }
    return;
}

void reset_setup_flipper(app_t *app, int *pres_sec, int *pres_mili_sec)
{
    task_t *node = find_task_node(app, 3);

    FLIPPER_STARTED(node) = true;
    sfClock_destroy(CLOCK(node->content.flipper));
    TIME_FLOAT(node->content.flipper) = 0.0;
    TIME_INT(node->content.flipper) = 0;
    NB_LIFE_FLIPPER(node) = 3;
    srand(time(NULL));
    NB_CIRCLE_FLIPPER(node) = 10 + rand() % 11;
    NB_CIRCLE_CREATE(node) = 0;
    clear_list(app);
    (*pres_sec) = 0;
    (*pres_mili_sec) = 0;
}
