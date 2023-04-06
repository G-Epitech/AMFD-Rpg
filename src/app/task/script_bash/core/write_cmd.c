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

    while (index_cmd != index) {
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

static void char_spec(sfEvent event, node_t *current_cmd)
{
    if (event.key.code == sfKeyHyphen && my_strlen(STR_CMD(app)) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD(app), '|');
    if (event.key.code == sfKeySemicolon &&
    my_strlen(STR_CMD(app)) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD(app), ';');
    if (event.key.code == sfKeyPeriod && my_strlen(STR_CMD(app)) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD(app), '.');
    if (event.key.code == sfKeySlash && my_strlen(STR_CMD(app)) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD(app), '/');
}

void cmd_write(sfEvent event, app_t *app)
{
    node_t *current_cmd = find_node_cmd(STRUCT_BASH(app).cmd, INDEX_CMD(app));

    if (sfKeyA <= event.key.code && event.key.code <= sfKeyZ
    && my_strlen(STR_CMD(app)) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD(app), event.key.code + 'a');
    if (event.key.code == sfKeySpace && my_strlen(STR_CMD(app)) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD(app), ' ');
    if (event.key.code == sfKeySubtract &&
    my_strlen(STR_CMD(app)) <= LEN_MAX_CMD)
        realloc_char(&STR_CMD(app), '-');
    char_spec(event, current_cmd);
    if (event.key.code == sfKeyBackspace)
        (STR_CMD(app))[my_strlen((STR_CMD(app))) - 1] = '\0';
}
