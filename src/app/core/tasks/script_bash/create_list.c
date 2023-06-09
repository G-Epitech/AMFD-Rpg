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
#include "my/include/my.h"

static node_t *create_node_list_cmd(void)
{
    node_data_t cmd;
    task_bash_node_t *cmd_node = malloc(sizeof(task_bash_node_t));
    node_t *cmd_n = NULL;

    if (!cmd_node)
        return NULL;
    cmd.node_bash = cmd_node;
    cmd_n = node_new(cmd);
    return cmd_n;
}

int init_list_prompt(list_t *prompt, cjson_t *object_file)
{
    node_t *prompt_node = NULL;
    cjson_t *prompt_object = cjson_get_prop(object_file, "prompt");
    cjson_t *pos_prompt = NULL;
    char *prompt_tab[5] = {"first_prompt", "second_prompt", "third_prompt",
    "fourth_prompt", "fifth_prompt"};

    for (int index = 0; index < 5; index++) {
        prompt_node = create_node_list_cmd();
        prompt_node->data.node_bash->cmd = malloc(sizeof(char) * 4);
        if (prompt_node == NULL || prompt_node->data.node_bash->cmd == NULL)
            return 84;
        my_strcpy(prompt_node->data.node_bash->cmd, "$> \0");
        pos_prompt = cjson_get_prop(prompt_object, prompt_tab[index]);
        prompt_node->data.node_bash->pos.x =
        cjson_get_prop_int_unsafe(pos_prompt, "x");
        prompt_node->data.node_bash->pos.y =
        cjson_get_prop_int_unsafe(pos_prompt, "y");
        list_append(prompt, prompt_node);
    }
    return 0;
}

int init_list_cmd(list_t *cmd, cjson_t *object_file)
{
    node_t *cmd_node = NULL;
    cjson_t *cmd_model_object = cjson_get_prop(object_file, "cmd");
    cjson_t *pos_cmd = NULL;
    char *cmd_tab[5] = {"first_cmd", "second_cmd", "third_cmd",
    "fourth_cmd", "fifth_cmd"};

    for (int index = 0; index < 5; index++) {
        cmd_node = create_node_list_cmd();
        if (cmd_node == NULL)
            return 84;
        cmd_node->data.node_bash->cmd = NULL;
        pos_cmd = cjson_get_prop(cmd_model_object, cmd_tab[index]);
        cmd_node->data.node_bash->pos.x =
        cjson_get_prop_int_unsafe(pos_cmd, "x");
        cmd_node->data.node_bash->pos.y =
        cjson_get_prop_int_unsafe(pos_cmd, "y");
        list_append(cmd, cmd_node);
    }
    return 0;
}

int init_list_cmd_model(list_t *cmd_model, cjson_t *object_file)
{
    node_t *cmd_model_node = NULL;
    cjson_t *cmd_model_object = cjson_get_prop(object_file, "cmd_model");
    cjson_t *pos_cmd_model = NULL;
    char *cmd_model_tab[5] = {"first_cmd_model", "second_cmd_model",
    "third_cmd_model", "fourth_cmd_model", "fifth_cmd_model"};

    for (int index = 0; index < 5; index++) {
        cmd_model_node = create_node_list_cmd();
        if (!cmd_model_node)
            return 84;
        cmd_model_node->data.node_bash->cmd = NULL;
        pos_cmd_model = cjson_get_prop(cmd_model_object, cmd_model_tab[index]);
        cmd_model_node->data.node_bash->pos.x =
        cjson_get_prop_int_unsafe(pos_cmd_model, "x");
        cmd_model_node->data.node_bash->pos.y =
        cjson_get_prop_int_unsafe(pos_cmd_model, "y");
        list_append(cmd_model, cmd_model_node);
    }
    return 0;
}
