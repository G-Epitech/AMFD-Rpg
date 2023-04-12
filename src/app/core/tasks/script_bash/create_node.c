/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include <stdlib.h>
#include "types/list/list.h"
#include "types/list/types.h"
#include "cjson/include/cjson.h"
#include "app/tasks/bash/script_bash.h"
#include "my/include/my.h"

static int init_list(node_data_t bash)
{
    cjson_t *object_file = cjson_parse_file("./configs/tasks/pos_text.json");

    BASH_PATH(bash).cmd_model = list_new();
    if (init_list_cmd_model(BASH_PATH(bash).cmd_model, object_file) == 84)
        return 84;
    BASH_PATH(bash).cmd = list_new();
    if (init_list_cmd(BASH_PATH(bash).cmd, object_file) == 84)
        return 84;
    BASH_PATH(bash).prompt = list_new();
    if (init_list_prompt(BASH_PATH(bash).prompt, object_file) == 84)
        return 84;
    return 0;
}

static int init_placing(node_data_t bash)
{
    BASH_PATH(bash).handler_placing = malloc(sizeof(placing_t));
    if (BASH_PATH(bash).handler_placing == NULL)
        return 84;
    BASH_PATH(bash).handler_placing->just_started = true;
    BASH_PATH(bash).handler_placing->index_cmd = 1;
    BASH_PATH(bash).handler_placing->index_life = 3;
    return 0;
}

static int init_time(node_data_t bash)
{
    BASH_PATH(bash).handler_time = malloc(sizeof(timer_handler_t));
    if (BASH_PATH(bash).handler_time == NULL)
        return 84;
    BASH_PATH(bash).handler_time->time_float = 0.0;
    BASH_PATH(bash).handler_time->timer_int = 20;
    return 0;
}

node_t *task_create_nodes_bash(void)
{
    node_data_t bash;
    task_t *task = malloc(sizeof(task_t));

    if (!task)
        return NULL;
    bash.task = task;
    if (init_list(bash) == 84)
        return NULL;
    if (init_placing(bash) == 84)
        return NULL;
    if (init_time(bash) == 84)
        return NULL;
    BASH_PATH(bash).font_phone = sfFont_createFromFile("assets/pixel.otf");
    return node_new(bash);
}
