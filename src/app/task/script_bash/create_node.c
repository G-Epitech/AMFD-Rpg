/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** task
*/

#include "types/list/list.h"
#include "types/list/types.h"



static node_t *create_node_list_cmd(void)
{
    node_data_t cmd;
    task_bash_node_t *cmd_node = malloc(sizeof(task_bash_node_t));
    node_t *cmd_n = NULL;

    cmd.node_bash = cmd_node;
    cmd_n = node_new(cmd);
    return cmd_n;
}

static void init_list_prompt(list_t *prompt)
{
    node_t *prompt_node = NULL;

    for (int index = 0; index < 5; index++) {
        prompt_node = create_node_prompt_list();
        prompt_node->data.node_bash->cmd = malloc(sizeof(char) * 3);
        my_strcpy(prompt_node->data.node_bash->cmd, "$>\0");
        prompt_node->data.node_bash->pos = 
        list_append(prompt_node, prompt_node);
    }
}

list_t *task_create_nodes_bash(list_t *task_bash)
{
    node_data_t bash;
    task_t *task = malloc(sizeof(task_t));
    node_t *script_bash = NULL;

    bash.task = task;
    bash.task->content.script.cmd_model = list_new();
    init_list_prompt(bash.task->content.script.cmd_model);
    bash.task->content.script.cmd = list_new();
    create_node_list_cmd(bash.task->content.script.cmd, list_cmd);
    bash.task->content.script.prompt = list_new();
    create_node_list_cmd(bash.task->content.script.prompt, list_prompt);
    script_bash = node_new(bash);
    list_append(task_bash, script_bash);
}
