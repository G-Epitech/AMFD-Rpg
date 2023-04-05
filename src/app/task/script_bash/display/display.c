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

    sfText_setPosition(renderer->text, (sfVector2f) {800, 220});
    sfText_setColor(renderer->text, sfWhite);
    sfText_setString(renderer->text, "timer:");
    sfRenderWindow_drawText(renderer->window, renderer->text, NULL);
    sfText_setPosition(renderer->text, (sfVector2f) {880, 220});
    char_second = nbr_to_str(TIME_INT - ((int) TIME_FLOAT));
    sfText_setString(renderer->text, char_second);
    sfRenderWindow_drawText(renderer->window, renderer->text, NULL);
}

static void display_text(renderer_t *renderer, app_t *app, node_t *temp)
{
    for (int index = 0; index < INDEX_CMD; index++) {
        renderer->font = STRUCT_BASH(app).font_phone;
        sfText_setFont(renderer->text, renderer->font);
        sfText_setColor(renderer->text, sfBlack);
        sfText_setCharacterSize(renderer->text, 30);
        sfText_setString(renderer->text, temp->data.node_bash->cmd);
        sfText_setPosition(renderer->text, temp->data.node_bash->pos);
        sfRenderWindow_drawText(renderer->window, renderer->text, NULL);
        temp = temp->next;
    }
}

static void display_life(renderer_t *renderer, app_t *app)
{
    char *char_life = NULL;

    sfText_setPosition(renderer->text, (sfVector2f) {980, 220});
    sfText_setColor(renderer->text, sfWhite);
    sfText_setString(renderer->text, ": life");
    sfRenderWindow_drawText(renderer->window, renderer->text, NULL);
    sfText_setPosition(renderer->text, (sfVector2f) {955, 220});
    char_life = nbr_to_str(INDEX_LIFE(app));
    sfText_setString(renderer->text, char_life);
    sfRenderWindow_drawText(renderer->window, renderer->text, NULL);
}

void app_task_bash_display(renderer_t *renderer, app_t *app)
{
    display_time(renderer, app);
    display_life(renderer, app);
    display_text(renderer, app, STRUCT_BASH(app).cmd_model->first);
    display_text(renderer, app, STRUCT_BASH(app).prompt->first);
    display_text(renderer, app, STRUCT_BASH(app).cmd->first);
}