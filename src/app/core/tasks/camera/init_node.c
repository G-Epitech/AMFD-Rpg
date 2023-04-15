/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/camera/camera.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void find_solution(char *index_equation,
char *index_solution, cjson_t *object_file, app_t *app)
{
    cjson_t *level_equation = cjson_get_prop(object_file, index_equation);
    task_t *node = find_task_node(app, 4);
    char *solution = NULL;

    solution = cjson_get_prop_string_unsafe(level_equation, index_solution);
    my_strcat(CAMERA_SOLUTION(node), solution);
}

static char *find_equation(int index_equa, cjson_t *object_file, app_t *app)
{
    char *index_equation = nbr_to_str(index_equa);
    cjson_t *level_equation = cjson_get_prop(object_file, index_equation);
    char *equation = NULL;
    char *equa_random = 0;

    srand(time(NULL));
    equa_random = nbr_to_str(rand() % 2);
    find_solution(index_equation, equa_random, object_file, app);
    equation = cjson_get_prop_string_unsafe(level_equation, equa_random);
    return equation;
}

int init_equation(app_t *app)
{
    task_t *node = find_task_node(app, 4);
    cjson_t *object_file = cjson_parse_file("./configs/tasks/equation.json");
    node_t *temp = CAMERA_EQUATIONS(node)->first;

    CAMERA_SOLUTION(node) = malloc(sizeof(char) * 1);
    CAMERA_SOLUTION(node)[0] = '\0';
    for (int index = 1; temp != NULL; index++) {
        temp->data.node_camera->equation =
        find_equation(index, object_file, app);
        temp = temp->next;
    }
    return 0;
}

int init_task_camera(app_t *app)
{
    task_t *camera = find_task_node(app, 4);

    CLOCK(camera->content.force) = sfClock_create();
    if (CLOCK(camera->content.force) == NULL)
        return 84;
    CAMERA_STARTED(camera) = false;
    if (init_equation(app) == 84)
        return 84;
    return 0;
}
