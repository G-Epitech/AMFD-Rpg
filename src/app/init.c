/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init the application
*/

#include <stdlib.h>
#include "app/types.h"
#include "types/list/list.h"
#include "types/players/players.h"
#include "types/npc/npc.h"

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

app_t *app_init(void)
{
    app_t *app = malloc(sizeof(app_t));

    if (!app)
        return NULL;
    app->state = ST_LOADING;
    app->world = WL_VILLAGE;
    app->control = init_controller();
    app->players = players_list_init();
    app->npcs = npcs_load();
    if (!app->players) {
        free(app);
        return NULL;
    }
    app->player = players_add(app->players, "Player1");
    if (!app->player) {
        list_free(app->players);
        free(app);
        return NULL;
    }
    return app;
}
