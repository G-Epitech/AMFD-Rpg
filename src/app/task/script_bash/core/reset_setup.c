/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bash/script_bash.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void free_cmd(app_t *app)
{
    node_t *temp = STRUCT_BASH(app).cmd->first;

    for (int index = 0; index < INDEX_CMD; index++) {
        free(temp->data.node_bash->cmd);
        temp = temp->next;
    }
}

static void free_cmd_model(app_t *app)
{
    node_t *temp = STRUCT_BASH(app).cmd_model->first;

    while (temp != NULL) {
        free(temp->data.node_bash->cmd);
        temp = temp->next;
    }
}

void reset_setup(app_t *app)
{
    STRUCT_BASH(app).handler_placing->just_started = true;
    free_cmd(app);
    free_cmd_model(app);
    sfClock_destroy(CLOCK);
    TIME_FLOAT = 0.0;
    TIME_INT = 20;
    INDEX_LIFE = 3;
    INDEX_CMD = 1;
}
