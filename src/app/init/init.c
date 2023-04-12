/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** Init the application
*/

#include <stdio.h>
#include <stdlib.h>
#include "app/types.h"
#include "app/dependencies.h"
#include "types/players/players.h"

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
    size_t member = 0;

    if (!app)
        return NULL;
    app->state = ST_MAIN_MENU;
    app->world = WL_VILLAGE;
    while (app_init_members[member]) {
        if (!(app_init_members[member](app))) {
            app_free(app);
            return NULL;
        }
        member += 1;
    }
    if (init_player(app) == 84)
        return NULL;
    return app;
}
