/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** handler
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "types/renderer/types.h"
#include "app/tasks/task.h"
#include "app/tasks/bash/types.h"
#include "app/tasks/bash/script_bash.h"
#include "types/list/types.h"
#include "my/include/my.h"
#include "app/quests/quests.h"
#include "app/animations/animations.h"

static void good_result(int *index_cmd, app_t *app, renderer_t *renderer)
{
    list_t *events = NULL;

    (*index_cmd)++;
    if ((*index_cmd) == 6) {
        events = animation_event_new(app);
        animations_notif_add(events, renderer->ressources->icons->happy,
        "Script bash", "Vous venez de hack le telephone\navec succes.");
        core_quests_bash(renderer, app);
        (*index_cmd)--;
        app->state = ST_INGAME;
        app->interaction->active = false;
        reset_setup_bash(app);
    }
}

static void bad_result(node_t *current_cmd,
app_t *app, int *index_life, renderer_t *renderer)
{
    list_t *events = NULL;

    (*index_life)--;
    STR_CMD(app)[0] = '\0';
    if ((*index_life) == 0) {
        events = animation_event_new(app);
        animations_notif_add(events, renderer->ressources->icons->hungry,
        "Script bash", "Vous n'avez pas reussi a hack\nle systeme.");
        app->state = ST_INGAME;
        app->interaction->active = false;
        reset_setup_bash(app);
    }
}

void good_or_bad_result(sfEvent event, app_t *app, renderer_t *renderer)
{
    node_t *current_cmd_model = NULL;
    node_t *current_cmd = NULL;

    if (event.text.unicode == '\r' || event.text.unicode == '\n') {
        current_cmd = find_node_cmd(STRUCT_BASH(app).cmd,
        STRUCT_BASH(app).handler_placing->index_cmd);
        current_cmd_model = find_node_cmd(STRUCT_BASH(app).cmd_model,
        STRUCT_BASH(app).handler_placing->index_cmd);
        if (my_strcmp(STR_CMD_MODEL(app), STR_CMD(app)) == 0) {
            good_result(&INDEX_CMD(app), app, renderer);
        } else {
            bad_result(current_cmd, app, &INDEX_LIFE(app), renderer);
        }
    }
}
