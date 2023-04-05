/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bash/script_bash.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void good_result(int *index_cmd, app_t *app)
{
    (*index_cmd)++;
    if ((*index_cmd) == 6) {
        (*index_cmd)--;
        my_putstr("You win\n");
        app->state = ST_INGAME;
        reset_setup(app);
    }
}

static void bad_result(node_t *current_cmd,
app_t *app, int *index_life)
{
    my_putstr("-1 vie\n");
    (*index_life)--;
    STR_CMD[0] = '\0';
    if ((*index_life) == 0) {
        my_putstr("You lose\n");
        app->state = ST_INGAME;
        reset_setup(app);
    }
}

void good_or_bad_result(sfEvent event, app_t *app)
{
    node_t *current_cmd_model = NULL;
    node_t *current_cmd = NULL;

    if (event.key.code == sfKeyEnter) {
        current_cmd = find_node_cmd(STRUCT_BASH(app).cmd,
        STRUCT_BASH(app).handler_placing->index_cmd);
        current_cmd_model = find_node_cmd(STRUCT_BASH(app).cmd_model,
        STRUCT_BASH(app).handler_placing->index_cmd);
        if (my_strcmp(STR_CMD_MODEL, STR_CMD) == 0) {
            good_result(&INDEX_CMD, app);
        } else {
            bad_result(current_cmd, app, &INDEX_LIFE(app));
        }
    }
}