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
#include "app/tasks/script_bash.h"

app_t *app_init(void)
{
    app_t *app = malloc(sizeof(app_t));

    if (!app)
        return NULL;
    app->state = ST_TASK_BASH;
    app->world = WL_VILLAGE;
    app->players = players_list_init();
    if (!app->players) {
        free(app);
        return NULL;
    }
    app->player = players_add(app->players, "Player1");
    if (!app->player) {
        free(app);
        list_free(app->players);
        return NULL;
    }
    app->tasks_setup = task_create();
    return app;
}
