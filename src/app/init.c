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

static control_t *init_controller(void)
{
    control_t *control = malloc(sizeof(control_t));

    if (!control)
        exit(84);
    control->down = false;
    control->up = false;
    control->right = false;
    control->left = false;
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
