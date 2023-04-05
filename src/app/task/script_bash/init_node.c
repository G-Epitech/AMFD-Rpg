/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/bash/types.h"
#include "types/list/types.h"
#include "app/tasks/task.h"
#include "my/include/my.h"
#include <stdlib.h>

static void init_cmd_model(app_t *app)
{
    node_t *temp = STRUCT_BASH(app).cmd_model->first;
    char *tab_cmd[5] = {"ls", "echo", "ls | grep l | grep m",
    "cat makefile", "ls; cat makefile | grep l"};

    for(int index = 0; temp != NULL; index++) {
        temp->data.node_bash->cmd = malloc(sizeof(my_strlen(tab_cmd[index])) + 1);
        my_strcpy(temp->data.node_bash->cmd, tab_cmd[index]);
        temp->data.node_bash->cmd[my_strlen(tab_cmd[index])] = '\0';
        temp = temp->next;
    }
}

void init_task(app_t *app)
{
    STRUCT_BASH(app).handler_time->clock_time = sfClock_create();
    init_cmd_model(app);
    STRUCT_BASH(app).handler_placing->just_started = false;
}
