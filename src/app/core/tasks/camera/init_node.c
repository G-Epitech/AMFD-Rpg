/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/camera/camera.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void realloc_char(char **cmd, char *chr)
{
    char *save_cmd = my_strdup((*cmd));

    (*cmd)[0] = '\0';
    (*cmd) = malloc(sizeof(char) * (my_strlen(save_cmd) + 2));
    my_strcpy((*cmd), save_cmd);
    (*cmd)[my_strlen(save_cmd)] = chr[0];
    (*cmd)[my_strlen(save_cmd) + 1] = '\0';
    free(save_cmd);
}

static void find_solution(char *index_equation,
char *index_solution, app_t *app)
{
    cjson_t *object_file = cjson_parse_file(FILE_REP_EQUATION);
    cjson_t *level_equation = cjson_get_prop(object_file, index_equation);
    task_t *node = find_task_node(app, 4);
    char *solution = NULL;

    solution = cjson_get_prop_string_unsafe(level_equation, index_solution);
    realloc_char(&CAMERA_RESULT(node), solution);
    free(solution);
}

static char *find_equation(int index_equa, cjson_t *object_file, app_t *app)
{
    char *index_equation = nbr_to_str(index_equa);
    cjson_t *level_equation = cjson_get_prop(object_file, index_equation);
    char *equation = NULL;
    char *equa_random = 0;

    srand(time(NULL));
    equa_random = nbr_to_str(rand() % 7);
    find_solution(index_equation, equa_random, app);
    equation = cjson_get_prop_string_unsafe(level_equation, equa_random);
    free(index_equation);
    return equation;
}

int init_equation(app_t *app)
{
    task_t *node = find_task_node(app, 4);
    cjson_t *object_file = cjson_parse_file(FILE_EQUATION);
    node_t *temp = CAMERA_EQUATIONS(node)->first;

    CAMERA_SOLUTION(node) = malloc(sizeof(char) * 1);
    CAMERA_SOLUTION(node)[0] = '\0';
    CAMERA_RESULT(node) = malloc(sizeof(char) * 1);
    CAMERA_RESULT(node)[0] = '\0';
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
