/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include <stdlib.h>
#include <time.h>
#include "types/list/list.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"
#include "my/include/my.h"

static int init_time(task_t *task)
{
    CAMERA(task).handler_time = malloc(sizeof(timer_handler_t));
    if (CAMERA(task).handler_time == NULL)
        return 84;
    CAMERA(task).handler_time->time_float = 0.0;
    CAMERA(task).handler_time->timer_int = 0;
    return 0;
}

static node_t *create_node_list_equations(void)
{
    node_data_t cmd;
    task_camera_node_t *equations_node = malloc(sizeof(task_camera_node_t));

    if (!equations_node)
        return NULL;
    cmd.node_camera = equations_node;
    return node_new(cmd);
}

int init_list_equations(list_t *equation_list, cjson_t *object_file)
{
    node_t *equation_node = NULL;
    cjson_t *pos_equation = NULL;
    char *equations_tab[5] = {"first_equations", "second_equations",
    "third_equations", "fourth_equations", "fifth_equations"};

    for (int index = 0; index < 4; index++) {
        equation_node = create_node_list_equations();
        if (!equation_node)
            return 84;
        equation_node->data.node_camera->equation = NULL;
        pos_equation = cjson_get_prop(object_file, equations_tab[index]);
        equation_node->data.node_camera->pos.x =
        cjson_get_prop_int_unsafe(pos_equation, "x");
        equation_node->data.node_camera->pos.y =
        cjson_get_prop_int_unsafe(pos_equation, "y");
        list_append(equation_list, equation_node);
    }
    return 0;
}

static int init_equations(task_t *task)
{
    cjson_t *object_file =
    cjson_parse_file("./configs/tasks/pos_equations.json");

    CAMERA_EQUATIONS(task) = list_new();
    if (init_list_equations(CAMERA_EQUATIONS(task), object_file) == 84)
        return 84;
    return 0;
}

node_t *task_create_nodes_camera(void)
{
    task_t *task = malloc(sizeof(task_t));

    if (!task)
        return NULL;
    task->content.camera.just_started = true;
    task->content.camera.nb_lifes = 3;
    task->content.camera.solution = NULL;
    if (init_equations(task) == 84)
        return NULL;
    if (init_time(task) == 84)
        return NULL;
    return node_new((node_data_t) task);
}
