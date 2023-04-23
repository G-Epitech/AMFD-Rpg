/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdlib.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "types/list/types.h"
#include "app/tasks/camera/camera.h"
#include "types/list/list.h"
#include "my/include/my.h"

static int realloc_char(char **cmd, char chr)
{
    char *save_cmd = my_strdup((*cmd));

    (*cmd)[0] = '\0';
    (*cmd) = malloc(sizeof(char) * (my_strlen(save_cmd) + 2));
    if (!(*cmd))
        return 84;
    my_strcpy((*cmd), save_cmd);
    (*cmd)[my_strlen(save_cmd)] = chr;
    (*cmd)[my_strlen(save_cmd) + 1] = '\0';
    free(save_cmd);
    return 0;
}

void solution_write(sfEvent event, app_t *app)
{
    task_t *node = find_task_node(app, 4);

    if (0 < event.text.unicode && event.text.unicode < 128 &&
    event.text.unicode != '\r' && event.text.unicode != '\n' &&
    my_strlen(CAMERA_SOLUTION(node))
    <= LENGHT_MAX_SOLUTION && event.text.unicode != '\b')
        realloc_char(&CAMERA_SOLUTION(node), event.text.unicode);
    if (event.text.unicode == '\b')
        (CAMERA_SOLUTION(node))[my_strlen(CAMERA_SOLUTION(node)) - 1] = '\0';
}
