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

node_t *find_node_cmd(list_t *list, int index_cmd)
{
    node_t *temp = list->first;
    int index = 1;

    while(index_cmd != index) {
        temp = temp->next;
        index++;
    }
    return temp;
}

static void realloc_char(char **cmd, char chr)
{
    char *save_cmd = my_strdup((*cmd));

    (*cmd)[0] = '\0';
    (*cmd) = malloc(sizeof(char) * (my_strlen(save_cmd) + 2));
    my_strcpy((*cmd), save_cmd);
    (*cmd)[my_strlen(save_cmd)] = chr;
    (*cmd)[my_strlen(save_cmd) + 1] = '\0';
    free(save_cmd);
}

void cmd_write(sfEvent event, app_t *app)
{
    node_t *current_cmd = find_node_cmd(STRUCT_BASH(app).cmd,
    STRUCT_BASH(app).handler_placing->index_cmd);

    if (sfKeyA <= event.key.code && event.key.code <= sfKeyZ
    && my_strlen(STR_CMD) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD, event.key.code + 'a');
    if (event.key.code == sfKeySpace && my_strlen(STR_CMD) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD, ' ');
    if (event.key.code == sfKeyHyphen && my_strlen(STR_CMD) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD, '|');
    if (event.key.code == sfKeySemicolon && my_strlen(STR_CMD) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD, ';');
    if (event.key.code == sfKeyBackspace)
        (STR_CMD)[my_strlen((STR_CMD)) - 1] = '\0';
}
