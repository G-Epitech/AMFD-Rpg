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
#include "app/tasks/bash/types.h"
#include "types/list/types.h"
#include "app/tasks/task.h"
#include "my/include/my.h"

static char *find_cmd(int index_cmd, cjson_t *object_file)
{
    char *index_level = nbr_to_str(index_cmd);
    cjson_t *level_cmd = cjson_get_prop(object_file, index_level);
    int cmd_random = 0;
    char *new_cmd = NULL;
    char *index_random = NULL;

    srand(time(NULL));
    cmd_random = rand() % 8;
    index_random = nbr_to_str(cmd_random);
    new_cmd = cjson_get_prop_string_unsafe(level_cmd, index_random);
    return new_cmd;
}

static int init_cmd_model(app_t *app)
{
    cjson_t *object_file = cjson_parse_file("./configs/tasks/cmd.json");
    node_t *temp = STRUCT_BASH(app).cmd_model->first;
    char *cmd = NULL;

    for (int index = 0; temp != NULL; index++) {
        cmd = find_cmd(index, object_file);
        temp->data.node_bash->cmd = malloc(sizeof(char) * my_strlen(cmd) + 1);
        if (temp->data.node_bash->cmd == NULL)
            return 84;
        my_strcpy(temp->data.node_bash->cmd, cmd);
        temp->data.node_bash->cmd[my_strlen(cmd)] = '\0';
        temp = temp->next;
    }
    return 0;
}

static int init_cmd(app_t *app)
{
    node_t *temp = STRUCT_BASH(app).cmd->first;

    for (int index = 0; temp != NULL; index++) {
        temp->data.node_bash->cmd = malloc(sizeof(char));
        if (temp->data.node_bash->cmd == NULL)
            return 84;
        temp->data.node_bash->cmd[0] = '\0';
        temp = temp->next;
    }
    return 0;
}

int init_task(app_t *app)
{
    STRUCT_BASH(app).handler_time->clock_time = sfClock_create();
    if (STRUCT_BASH(app).handler_time->clock_time == NULL)
        return 84;
    if (init_cmd_model(app) == 84)
        return 84;
    if (init_cmd(app) == 84)
        return 84;
    STRUCT_BASH(app).handler_placing->just_started = false;
    return 0;
}
