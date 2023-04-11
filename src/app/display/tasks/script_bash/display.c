/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bash/script_bash.h"
#include "types/list/types.h"
#include "my/include/my.h"

static void display_time(renderer_t *renderer, app_t *app)
{
    char *char_second = NULL;
    renderer_objects_t *objects = renderer->objects;

    sfText_setPosition(objects->text, (sfVector2f) {800, 220});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, "timer:");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {880, 220});
    char_second =
    nbr_to_str(TIME_INT(NODE_BASH) - ((int) TIME_FLOAT(NODE_BASH)));
    sfText_setString(objects->text, char_second);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

static void display_text(renderer_t *renderer, app_t *app, node_t *temp)
{
    renderer_objects_t *objects = renderer->objects;

    for (int index = 0; index < INDEX_CMD(app); index++) {
        sfText_setFont(objects->text, STRUCT_BASH(app).font_phone);
        sfText_setColor(objects->text, sfBlack);
        sfText_setCharacterSize(objects->text, 30);
        sfText_setString(objects->text, temp->data.node_bash->cmd);
        sfText_setPosition(objects->text, temp->data.node_bash->pos);
        sfRenderWindow_drawText(renderer->window, objects->text, NULL);
        temp = temp->next;
    }
}

static void display_life(renderer_t *renderer, app_t *app)
{
    char *char_life = NULL;
    renderer_objects_t *objects = renderer->objects;

    sfText_setPosition(objects->text, (sfVector2f) {980, 220});
    sfText_setColor(objects->text, sfWhite);
    sfText_setString(objects->text, ": life");
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
    sfText_setPosition(objects->text, (sfVector2f) {955, 220});
    char_life = nbr_to_str(INDEX_LIFE(app));
    sfText_setString(objects->text, char_life);
    sfRenderWindow_drawText(renderer->window, objects->text, NULL);
}

void app_task_bash_display(renderer_t *renderer, app_t *app)
{
    display_time(renderer, app);
    display_life(renderer, app);
    display_text(renderer, app, STRUCT_BASH(app).cmd_model->first);
    display_text(renderer, app, STRUCT_BASH(app).prompt->first);
    display_text(renderer, app, STRUCT_BASH(app).cmd->first);
}
