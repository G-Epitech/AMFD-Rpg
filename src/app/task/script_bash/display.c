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

static void display_text(renderer_t *renderer, app_t *app)
{
    node_t *temp = STRUCT_BASH(app).cmd_model->first;

    for (int index = 0; index < STRUCT_BASH(app).handler_placing->index_cmd; index++) {
        sfText_setString(renderer->text, temp->data.node_bash->cmd);
        sfText_setPosition(renderer->text, temp->data.node_bash->pos);
        sfRenderWindow_drawText(renderer->window, renderer->text, NULL);
        temp = temp->next;
    }
}

static void display_phone(renderer_t *renderer, app_t *app)
{
    sfSprite_setTexture(renderer->sprite, STRUCT_BASH(app).phone, sfFalse);
    sfSprite_setPosition(renderer->sprite, (sfVector2f) {800, 100});
    sfRenderWindow_drawSprite(renderer->window, renderer->sprite, NULL);
}

void app_task_bash_display(renderer_t *renderer, app_t *app)
{
    if (STRUCT_BASH(app).handler_placing->just_started) {
        init_task(app);
    }
    if (STRUCT_BASH(app).handler_time->time_float > 20.0) {
        app->state = ST_INGAME;
        my_putstr("You lose\n");
    }

    display_phone(renderer, app);
    display_text(renderer, app);
}
