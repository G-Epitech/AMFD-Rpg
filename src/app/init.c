/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init the application
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/npc/npc.h"
#include "app/items/items.h"
#include "types/list/list.h"
#include "types/players/players.h"
#include "app/tasks/bash/script_bash.h"

static control_t *init_controller(void)
{
    control_t *control = malloc(sizeof(control_t) * 4);
    sfKeyCode key_codes[4] = {sfKeyZ, sfKeyS, sfKeyQ, sfKeyD};
    sfVector2f move_offset[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

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
    if (!app->player) {
        list_free(app->players);
        free(app);
        return 84;
    }
    return 0;
}

app_t *app_init(void)
{
    app_t *app = malloc(sizeof(app_t));

    if (!app)
        return NULL;
    app->state = ST_INVENTORY;
    app->world = WL_VILLAGE;
    app->control = init_controller();
    app->players = players_list_init();
    app->npcs = npcs_load();
    app->items = items_load();
    if (!app->players) {
        free(app);
        return NULL;
    }
    if (init_player(app) == 84)
        return NULL;
    app->tasks_setup = task_create();
    if (app->tasks_setup == NULL)
        return NULL;
    return app;
}
