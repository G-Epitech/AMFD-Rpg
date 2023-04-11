/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init the application
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/npc/npc.h"
#include "types/list/list.h"
#include "types/players/players.h"
#include "app/tasks/bash/script_bash.h"

static settings_t *init_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    if (!settings)
        return NULL;
    settings->developer = false;
    settings->fps = 120;
    settings->full_screen = false;
    settings->music = true;
    settings->volume = 15;
    return settings;
}

static control_t *init_controller(void)
{
    control_t *control = malloc(sizeof(control_t) * 4);
    sfKeyCode key_codes[4] = {sfKeyD, sfKeyZ, sfKeyQ, sfKeyS};
    sfVector2f move_offset[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    if (!control)
        return NULL;
    for (size_t i = 0; i < 4; i++) {
        control[i].direction = false;
        control[i].key = key_codes[i];
        control[i].offset = move_offset[i];
    }
    return control;
}

static int init_player(app_t *app)
{
    app->player = players_add(app->players, "Player1");
    app->partner = NULL;
    if (!app->player)
        return 84;
    return 0;
}

app_t *app_init(void)
{
    app_t *app = malloc(sizeof(app_t));

    if (!app)
        return NULL;
    app->state = ST_MAIN_MENU;
    app->world = WL_VILLAGE;
    app->control = init_controller();
    app->players = players_list_init();
    app->npcs = npcs_load();
    app->tasks_setup = task_create();
    app->settings = init_settings();
    app->network = network_init();
    if (!app->players || !app->tasks_setup) {
        free(app);
        return NULL;
    }
    if (init_player(app) == 84)
        return NULL;
    return app;
}
